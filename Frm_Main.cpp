#include "Frm_ConnectDevice.h"
#include "Frm_Main.h"
#include "ui_Frm_Main.h"
#include "HKW_Tools.h"
#include "JMessageBox.h"
#include <QtConcurrent/QtConcurrent>
#if defined(_WIN32)
#include <Windows.h>
#pragma comment(lib, "User32.lib")
#endif

using namespace HKW_Tools::Core;
using namespace HKW_Tools::Data;

Frm_Main::Frm_Main()
    : ui(new Ui::Frm_Main)
    , exitSyncServe(false)
    , syncComboTask_IsExit(false)
    , syncInfosTask_IsExit(false)
{
    ui->setupUi(this);
    setFixedSize(size());
    connectFuns();
#if defined(_WIN32)
    AllocConsole();
    ShowWindow(GetConsoleWindow(), SW_HIDE);
#endif
    initCombo();
    initFunsWidgets();
    clearInfos();
}

Frm_Main::~Frm_Main()
{
    syncComboTask->pause();
    syncInfosTask->pause();
    ADB::Server::Kill();
#if defined(_WIN32)
    FreeConsole();
#endif

    delete ui;
    delete syncComboTask;
    delete syncInfosTask;
    
}

void Frm_Main::connectFuns()
{
    connect(this, &Frm_Main::addID_signal, this, &Frm_Main::addID);
    connect(this, &Frm_Main::removeID_signal, this, &Frm_Main::removeID);
    connect(this, &Frm_Main::clearCombo_signal, this, &Frm_Main::clearCombo);
    connect(this, &Frm_Main::clearInfos_signal, this, &Frm_Main::clearInfos);
    connect(this, &Frm_Main::set_showNumOfDevices_LableText_signal, this, &Frm_Main::set_showNumOfDevices_LableText);
    
    connect(this, &Frm_Main::ui_show_AndroidVersion_LineEdit_setText_signal, this, &Frm_Main::ui_show_AndroidVersion_LineEdit_setText);
    connect(this, &Frm_Main::ui_show_CpuModel_LineEdit_setText_signal, this, &Frm_Main::ui_show_CpuModel_LineEdit_setText);
    connect(this, &Frm_Main::ui_show_CurrentDpi_LineEdit_setText_signal, this, &Frm_Main::ui_show_CurrentDpi_LineEdit_setText);
    connect(this, &Frm_Main::ui_show_CurrentResolution_LineEdit_setText_signal, this, &Frm_Main::ui_show_CurrentResolution_LineEdit_setText);
    connect(this, &Frm_Main::ui_show_DeviceModel_LineEdit_setText_signal, this, &Frm_Main::ui_show_DeviceModel_LineEdit_setText);
    connect(this, &Frm_Main::ui_show_Manufacturer_LineEdit_setText_signal, this, &Frm_Main::ui_show_Manufacturer_LineEdit_setText);
    connect(this, &Frm_Main::ui_show_StorageSize_LineEdit_setText_signal, this, &Frm_Main::ui_show_StorageSize_LineEdit_setText);
    connect(this, &Frm_Main::ui_show_UsedStorage_LineEdit_setText_signal, this, &Frm_Main::ui_show_UsedStorage_LineEdit_setText);
    connect(this, &Frm_Main::ui_show_UsedStorage_ProgressBar_setValue_signal, this, &Frm_Main::ui_show_UsedStorage_ProgressBar_setValue);
    
    connect(ui->clickTo_Open_Frm_ConnectDevice_CommandLinkButton, &QCommandLinkButton::clicked, this, [this](){
        Frm_ConnectDevice* frm = new Frm_ConnectDevice(this);
        frm->exec();
        delete frm;
    });
}

void Frm_Main::showEvent(QShowEvent *event)
{
    ADB::Server::Start();
    syncComboTask = new QFuture<void>(QtConcurrent::run([this](){
        syncCombo();
    }));
    syncInfosTask = new QFuture<void>(QtConcurrent::run([this](){
        syncInfos();
    }));
    event->accept();
}

void Frm_Main::closeEvent(QCloseEvent *event)
{
    if (JMessageBox::Show("确定退出工具箱?", "真的要return 0吗?", JMessageBoxButtons::YesNo, JMessageBoxIcon::Question) == QMessageBox::Yes)
    {
        hide();
        closeSyncServe();
        while (!syncComboTask_IsExit)
        {
            qDebug() << "等待同步设备进程退出...";
            QThread::sleep(1);
        }
        while (!syncInfosTask_IsExit)
        {
            qDebug() << "等待同步设备信息进程退出...";
            QThread::sleep(1);
        }
        event->accept();
    }
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

QString Frm_Main::getSelectID()
{
    QString id = ui->syncDevices_ComboBox->currentText();
    return id != "无"? id : "";
}

void Frm_Main::syncCombo()
{
    qDebug() << "开始同步设备";
    while (!exitSyncServe)
    {
        std::vector<ADB::Device> devices(ADB::Device::List());
        std::vector<QString> comboItems(getComboItems());
        if (ADB::Device::Have())
        {
            emit set_showNumOfDevices_LableText_signal(QString("当前连接了 ")
                                                      + std::to_string(static_cast<int>(ADB::Device::List().size()))
                                                      .c_str()
                                                      + " 个设备");
            for (const auto& device : devices)
            {
                for (const auto& item : comboItems)
                {
                    if (ui->syncDevices_ComboBox->findText(device.ID().c_str()) == -1)
                    {
                        emit addID_signal(device.ID().c_str());
                    }
                    if (!ADB::Device::Have(item.toStdString()))
                    {
                        emit removeID_signal(item);
                    }
                }
            }
        }
        else
        {
            if (ui->syncDevices_ComboBox->findText("无") == -1)
            {
                emit set_showNumOfDevices_LableText_signal("当前连接了 0 个设备");
                emit clearCombo_signal();
                emit clearInfos_signal();
                emit addID_signal("无");
            }
        }
        QApplication::processEvents();
        QThread::sleep(2);
    }
    qDebug() << "同步设备进程退出" ;
    syncComboTask_IsExit = true;
}

void Frm_Main::initCombo()
{
    ui->syncDevices_ComboBox->clear();
    ui->syncDevices_ComboBox->addItem("无");
}

void Frm_Main::syncInfos()
{
    qDebug() << "开始同步设备信息";
    while (!exitSyncServe)
    {
        std::string* selectID = new std::string(getSelectID().toStdString());
        try
        {
            if (*selectID != "")
            {
                QString* model = new QString(ADB::Device::GetModel(*selectID).c_str());
                QString* cpuModel = new QString(ADB::Device::GetCPU_Model(*selectID).c_str());
                QString* manufacturer = new QString(ADB::Device::GetManufacturer(*selectID).c_str());
                StringBox* androidVer = new StringBox(std::to_string(ADB::Device::GetAndroidVersion(*selectID)));
                QString* valueToSet = new QString(androidVer->Length() > 4?(*androidVer).Remove(4).CharPtrString() : (*androidVer).CharPtrString());
                QString* currentDpi = new QString(std::to_string(ADB::Device::GetDpi(*selectID)).c_str());
                QString* currentResolution = new QString(ADB::Device::GetWindowSize(*selectID).c_str());
                int* usedStorageValue = new int;
                *usedStorageValue = ADB::Device::GetStorage_UsePercent(*selectID);
                QString* storageSize = new QString(ADB::Device::GetStorage_Size(*selectID).c_str());
                QString* usedStorage = new QString(ADB::Device::GetStorage_Used(*selectID).c_str());
                
                if (ui->show_DeviceModel_LineEdit->text() != *model)
                    emit ui_show_DeviceModel_LineEdit_setText_signal(*model);
                
                if (ui->show_CpuModel_LineEdit->text() != *cpuModel)
                    emit ui_show_CpuModel_LineEdit_setText_signal(*cpuModel);
                
                if (ui->show_Manufacturer_LineEdit->text() != *manufacturer)
                    emit ui_show_Manufacturer_LineEdit_setText_signal(*manufacturer);
                
                if (ui->show_AndroidVersion_LineEdit->text() != *valueToSet)
                {
                    emit ui_show_AndroidVersion_LineEdit_setText_signal(*valueToSet);
                }
                
                if (ui->show_CurrentDpi_LineEdit->text() != *currentDpi)
                    emit ui_show_CurrentDpi_LineEdit_setText_signal(*currentDpi);
                
                if (ui->show_CurrentResolution_LineEdit->text() != *currentResolution)
                    emit ui_show_CurrentResolution_LineEdit_setText_signal(*currentResolution);
                
                if (ui->show_UsedStorage_ProgressBar->value() != *usedStorageValue)
                    emit ui_show_UsedStorage_ProgressBar_setValue_signal(*usedStorageValue);
                
                if (ui->show_StorageSize_LineEdit->text() != *storageSize)
                    emit ui_show_StorageSize_LineEdit_setText_signal(*storageSize);
                
                if (ui->show_UsedStorage_LineEdit->text() != *usedStorage)
                    emit ui_show_UsedStorage_LineEdit_setText_signal(*usedStorage);
                
                delete model; delete cpuModel; delete manufacturer; delete androidVer;
                delete currentDpi; delete currentResolution; delete usedStorageValue;
                delete storageSize; delete usedStorage; delete valueToSet;
            }
            else
            {
                emit clearInfos_signal();
            }
        }
        catch (ErrMessage& err)
        {
            emit ui_show_DeviceModel_LineEdit_setText_signal("设备不可用");
            emit ui_show_CpuModel_LineEdit_setText_signal("设备不可用");
            emit ui_show_Manufacturer_LineEdit_setText_signal("设备不可用");
            emit ui_show_AndroidVersion_LineEdit_setText_signal("设备不可用");
            emit ui_show_CurrentDpi_LineEdit_setText_signal("设备不可用");
            emit ui_show_CurrentResolution_LineEdit_setText_signal("设备不可用");
            emit ui_show_UsedStorage_ProgressBar_setValue_signal(0);
            emit ui_show_StorageSize_LineEdit_setText_signal("设备不可用");
            emit ui_show_UsedStorage_LineEdit_setText_signal("设备不可用");
        }
        QApplication::processEvents();
        delete selectID;
        QThread::sleep(2);
    }
    qDebug() << "同步信息进程退出" ;
    syncInfosTask_IsExit = true;
}

void Frm_Main::clearCombo()
{
    ui->syncDevices_ComboBox->clear();
}

void Frm_Main::clearInfos()
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

void Frm_Main::initFunsWidgets()
{
    ui->funs_ListWidget->addItem("安装应用");
    ui->funs_ListWidget->addItem("应用管理"); 
    ui->funs_ListWidget->addItem("屏幕管理");
    ui->funs_ListWidget->addItem("文件管理");
    ui->funs_ListWidget->addItem("高级功能");
}

void Frm_Main::addID(const QString& id)
{
    ui->syncDevices_ComboBox->addItem(id);
}

void Frm_Main::removeID(const QString &id)
{
    ui->syncDevices_ComboBox->removeItem(ui->syncDevices_ComboBox->findText(id));
}

void Frm_Main::closeSyncServe()
{
    exitSyncServe = true;
}

void Frm_Main::set_showNumOfDevices_LableText(const QString& text)
{
    ui->showNumOfDevices_Lable->setText(text);
}

void Frm_Main::ui_show_DeviceModel_LineEdit_setText(const QString &text)
{
    ui->show_DeviceModel_LineEdit->setText(text);
}

void Frm_Main::ui_show_CpuModel_LineEdit_setText(const QString &text)
{
    ui->show_CpuModel_LineEdit->setText(text);
}

void Frm_Main::ui_show_Manufacturer_LineEdit_setText(const QString &text)
{
    ui->show_Manufacturer_LineEdit->setText(text);
}

void Frm_Main::ui_show_AndroidVersion_LineEdit_setText(const QString &text)
{
    ui->show_AndroidVersion_LineEdit->setText(text);
}

void Frm_Main::ui_show_CurrentDpi_LineEdit_setText(const QString &text)
{
    ui->show_CurrentDpi_LineEdit->setText(text);
}

void Frm_Main::ui_show_CurrentResolution_LineEdit_setText(const QString &text)
{
    ui->show_CurrentResolution_LineEdit->setText(text);
}

void Frm_Main::ui_show_UsedStorage_ProgressBar_setValue(const int &value)
{
    ui->show_UsedStorage_ProgressBar->setValue(value);
}

void Frm_Main::ui_show_StorageSize_LineEdit_setText(const QString &text)
{
    ui->show_StorageSize_LineEdit->setText(text);
}

void Frm_Main::ui_show_UsedStorage_LineEdit_setText(const QString &text)
{
    ui->show_UsedStorage_LineEdit->setText(text);
}
