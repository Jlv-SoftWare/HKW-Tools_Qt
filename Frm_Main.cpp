#include "./ui_Frm_Main.h"
#include "Frm_Main.h"
#include "HKW_Tools.h"
#include "Dlg_Loading.h"
#include "JMessageBox.h"
#include <QPainter>
#include <QPixmap>
#if defined(_WIN32)
#include <Windows.h>
#endif

using namespace HKW_Tools::Core;
using namespace HKW_Tools::Data;

Frm_Main::Frm_Main(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Frm_Main)
{
    ui->setupUi(this);
    setFixedSize(size());
    
#if defined(_WIN32)
    AllocConsole();
    ShowWindow(GetConsoleWindow(), SW_HIDE);
#endif
    startServer();
    updateDevicesTimer = new QTimer(this);
    
    initCombo();
    initFunsWidgets();
    loadDeviceInfo();
    
    connect(updateDevicesTimer, &QTimer::timeout, this, &Frm_Main::updateCombo);
    connect(ui->clickTo_ReloadDeviceInfo_PushButton, &QPushButton::clicked, this, &Frm_Main::loadDeviceInfo);
    connect(ui->syncDevices_ComboBox, &QComboBox::currentIndexChanged, this, &Frm_Main::loadDeviceInfo);
    
    updateDevicesTimer->start(2500);
}

Frm_Main::~Frm_Main()
{
    delete updateDevicesTimer;
    delete ui;
}

void Frm_Main::closeEvent(QCloseEvent *event)
{
    if (JMessageBox::Show("确定退出工具箱?", "确定退出?", JMessageBoxButtons::YesNo, JMessageBoxIcon::Question) == QMessageBox::Yes)
    {
        hide();
        updateDevicesTimer->stop();
        killServer();
#if defined(_WIN32)
        FreeConsole();
#endif
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void Frm_Main::paintEvent(QPaintEvent *event)
{
    // 创建离屏缓冲区
    QPixmap buffer(size());
    QPainter painter(&buffer);
    
    // 使用离屏缓冲区绘制ComboBox的背景和内容
    painter.fillRect(rect(), palette().window()); // 绘制背景
    // 其他绘制操作，比如绘制边框、文本等
    
    // 将离屏缓冲区的内容绘制到屏幕上
    QPainter widgetPainter(this);
    widgetPainter.drawPixmap(0, 0, buffer);
}

std::vector<QString> Frm_Main::getComboItems() const
{
    std::vector<QString> items;
    
    int count = ui->syncDevices_ComboBox->count();
    for (int i = 0; i < count; ++i)
    {
        items.push_back(ui->syncDevices_ComboBox->itemText(i));
    }
    
    return items;
}

void Frm_Main::initCombo()
{
    
    ui->syncDevices_ComboBox->clear();
    ui->syncDevices_ComboBox->addItem("无");
    updateCombo();
}

void Frm_Main::initFunsWidgets()
{
    ui->funs_ListWidget->addItem("安装应用");
    ui->funs_ListWidget->addItem("应用管理"); 
    ui->funs_ListWidget->addItem("屏幕管理");
    ui->funs_ListWidget->addItem("文件管理");
    ui->funs_ListWidget->addItem("高级功能");
}

void Frm_Main::clearDeviceInfo()
{
    ui->show_DeviceModel_LineEdit->setText("");
    ui->show_CpuModel_LineEdit->setText("");
    ui->show_Manufacturer_LineEdit->setText("");
    ui->show_AndroidVersion_LineEdit->setText("");
    ui->show_CurrentDpi_LineEdit->setText("");
    ui->show_CurrentResolution_LineEdit->setText("");
    ui->show_UsedStorage_ProgressBar->setValue(0);
    ui->show_StorageSize_LineEdit->setText("");
    ui->show_UsedStorage_LineEdit->setText("");
}

void Frm_Main::loadDeviceInfo()
{
    clearDeviceInfo();
    std::string* selectID = new std::string(ui->syncDevices_ComboBox->currentText().toStdString());
    try
    {
        if (*selectID != "无")
        {
            ui->show_DeviceModel_LineEdit->setText(ADB::Device::GetModel(*selectID).c_str());
            ui->show_CpuModel_LineEdit->setText(ADB::Device::GetCPU_Model(*selectID).c_str());
            ui->show_Manufacturer_LineEdit->setText(ADB::Device::GetManufacturer(*selectID).c_str());
            ui->show_AndroidVersion_LineEdit->setText(std::to_string(ADB::Device::GetAndroidVersion(*selectID)).c_str());
            ui->show_CurrentDpi_LineEdit->setText(std::to_string(ADB::Device::GetDpi(*selectID)).c_str());
            ui->show_CurrentResolution_LineEdit->setText(ADB::Device::GetWindowSize(*selectID).c_str());
            ui->show_UsedStorage_ProgressBar->setValue(ADB::Device::GetStorage_UsePercent(*selectID));
            ui->show_StorageSize_LineEdit->setText(ADB::Device::GetStorage_Size(*selectID).c_str());
            ui->show_UsedStorage_LineEdit->setText(ADB::Device::GetStorage_Used(*selectID).c_str());
        }
    }
    catch (ErrMessage& err)
    {
        if (ADB::Device::GetStatus(*selectID) == ADB::Device::offline)
        {
            ui->show_DeviceModel_LineEdit->setText("设备离线");
            ui->show_CpuModel_LineEdit->setText("设备离线");
            ui->show_Manufacturer_LineEdit->setText("设备离线");
            ui->show_AndroidVersion_LineEdit->setText("设备离线");
            ui->show_CurrentDpi_LineEdit->setText("设备离线");
            ui->show_CurrentResolution_LineEdit->setText("设备离线");
            ui->show_UsedStorage_ProgressBar->setValue(0);
            ui->show_StorageSize_LineEdit->setText("离线");
            ui->show_UsedStorage_LineEdit->setText("离线");
        }
    }

    delete selectID;
    
}

void Frm_Main::updateCombo()
{
    QString* lastID = new QString(ui->syncDevices_ComboBox->currentText());
    if (ADB::Device::Have())
    {
        ui->showNumOfDevices_Lable->setText(QString("当前连接了 ") + std::to_string(static_cast<int>(ADB::Device::List().size())).c_str() + " 个设备");
        for (const auto& id : getComboItems())
        {
            for (const auto& device : ADB::Device::List())
            {
                if (ui->syncDevices_ComboBox->findText(device.ID().c_str()) == -1)
                {
                    ui->syncDevices_ComboBox->addItem(device.ID().c_str());
                }
                if (!ADB::Device::Have(id.toStdString()))
                {
                    ui->syncDevices_ComboBox->removeItem(ui->syncDevices_ComboBox->findText(id));
                }
                if (*lastID == "无")
                {
                    loadDeviceInfo();
                }
            }
        }
    }
    else
    {
        if (ui->syncDevices_ComboBox->findText("无") == -1)
        {
            ui->showNumOfDevices_Lable->setText("当前连接了 0 个设备");
            ui->syncDevices_ComboBox->clear();
            clearDeviceInfo();
            ui->syncDevices_ComboBox->addItem("无");
        }
    }
    delete lastID;
}

void Frm_Main::startServer()
{
    Dlg_Loading* dlg = new Dlg_Loading("正在启动ADB服务", "请稍候", this);
    dlg->show();
    ADB::Server::Start();
    dlg->close();
    delete dlg;
}

void Frm_Main::killServer()
{
    Dlg_Loading* dlg = new Dlg_Loading("正在关闭ADB服务", "请稍候", this);
    dlg->show();
    ADB::Server::Kill();
    dlg->close();
    delete dlg;
}
