#include "Frm_Main.h"
#include "Frm_InstallApp.h"
#include "HKW_Tools.h"
#include <QComboBox>

using namespace HKW_Tools::Core;

Frm_Main::Frm_Main(QWidget* parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    InitComboBox();
    SyncDevicesThread* thread = new SyncDevicesThread();
    connect(thread, &SyncDevicesThread::send_showNumOfDevices_Lable_Text, this, &Frm_Main::set_showNumOfDevices_Lable_Text);
    connect(thread, &SyncDevicesThread::addID, this, &Frm_Main::addID);
    connect(thread, &SyncDevicesThread::removeID, this, &Frm_Main::removeID);
    connect(thread, &SyncDevicesThread::clearIDs, this, &Frm_Main::clearIDs);
    connect(this, &Frm_Main::sendCombo, thread, &SyncDevicesThread::getCombo);
    connect(thread, &SyncDevicesThread::I_Need_Combo, this, &Frm_Main::OK_bro);

    connect(ui.clickTo_Open_Frm_InstallApp_PushButton, &QPushButton::clicked, this, &Frm_Main::Open_Frm_InstallApp);

    thread->start();
}

std::vector<QString> Frm_Main::getComboBoxItems(const QComboBox& comboBox) const
{
    std::vector<QString> items;

    if (&comboBox)
    {
        int count = comboBox.count();
        for (int i = 0; i < count; ++i)
        {
            items.push_back(comboBox.itemText(i));
        }
    }

    return items;
}

void Frm_Main::InitComboBox() const
{
    ui.syncDevices_ComboBox->clear();
    ui.syncDevices_ComboBox->addItem("无");
}

QString Frm_Main::SelectedDevice() const
{
    QString device = ui.syncDevices_ComboBox->currentText();
    return device == "无" ? "" : device;
}

void Frm_Main::Open_Frm_InstallApp()
{
    Frm_InstallApp dialog(SelectedDevice(), this);
    hide();
    dialog.exec();
    show();
}

Frm_Main::~Frm_Main()
{

}

void Frm_Main::addID(const QString& id)
{
    ui.syncDevices_ComboBox->addItem(id);
}

void Frm_Main::removeID(const QString& id)
{
    ui.syncDevices_ComboBox->removeItem(ui.syncDevices_ComboBox->findText(id));
}

void Frm_Main::clearIDs()
{
    ui.syncDevices_ComboBox->clear();
}
void Frm_Main::set_showNumOfDevices_Lable_Text(const QString& text)
{
    ui.showNumOfDevices_Lable->setText(text);
}

void Frm_Main::Here_you_are()
{
    emit sendSelectedDeviceID(ui.syncDevices_ComboBox->currentText());
}

void Frm_Main::OK_bro()
{
    emit sendCombo(getComboBoxItems(*ui.syncDevices_ComboBox));
}

void Frm_Main::ZhanShi()
{
    this->show();
}


