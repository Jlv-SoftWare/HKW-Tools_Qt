#include "Frm_ConnectDevice.h"
#include "ui_Frm_ConnectDevice.h"

Frm_ConnectDevice::Frm_ConnectDevice(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Frm_ConnectDevice)
{
    ui->setupUi(this);
}

Frm_ConnectDevice::~Frm_ConnectDevice()
{
    delete ui;
}
