#include "JMessageBox.h"
#include "Frm_ConnectDevice.h"
#include "ui_Frm_ConnectDevice.h"

Frm_ConnectDevice::Frm_ConnectDevice(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Frm_ConnectDevice)
    , getIpFrm(nullptr)
{
    ui->setupUi(this);
    connect(ui->clickTo_Open_Frm_GetIP_PushButton, &QPushButton::clicked, this, [this](){
        QString ip, tcpip;
        getIpFrm = new Frm_GetIP(&ip, &tcpip, this);
        getIpFrm->exec();
        delete getIpFrm;
        ui->get_Ip_LineEdit->setText(ip);
        ui->get_Tcpip_LineEdit->setText(tcpip);
    });
}

Frm_ConnectDevice::~Frm_ConnectDevice()
{
    delete ui;
}

void Frm_ConnectDevice::setIp(const QString &ip)
{
    ui->get_Ip_LineEdit->setText(ip);
}

void Frm_ConnectDevice::setTcpIp(const QString &tcpip)
{
    ui->get_Tcpip_LineEdit->setText(tcpip);
}
