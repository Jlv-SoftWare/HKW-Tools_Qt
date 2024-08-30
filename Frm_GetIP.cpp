#include "Frm_GetIP.h"
#include "ui_Frm_GetIP.h"

Frm_GetIP::Frm_GetIP(QString* ipVarPtr, QString* tcpipVarPtr, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Frm_GetIP)
    , ipPtr(ipVarPtr)
    , tcpipPtr(tcpipVarPtr)
{
    ui->setupUi(this);
    connect(ui->OK_PushButton, &QPushButton::clicked, this, &Frm_GetIP::onOkButtonClicked);
}

Frm_GetIP::~Frm_GetIP()
{
    delete ui;
}

void Frm_GetIP::showEvent(QShowEvent *event)
{
    initWidgets();
    event->accept();
}

void Frm_GetIP::initWidgets()
{
    QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
    for (const auto& interface : interfaces)
    {
        QList<QNetworkAddressEntry> entries = interface.addressEntries();
        for (const auto& entry : entries)
        {
            if (entry.ip().protocol() == QAbstractSocket::IPv4Protocol)
            {
                if (entry.ip().toString() != "127.0.0.1")
                {
                    ui->show_IPs_ListWidget->addItem(entry.ip().toString());
                }
            }
        }
    }
}

void Frm_GetIP::onOkButtonClicked()
{
    if (ui->show_IPs_ListWidget->currentItem() != nullptr)
    {
        *ipPtr = ui->show_IPs_ListWidget->currentItem()->text();
        *tcpipPtr = ui->get_TcpIp_LineEdit->text().isEmpty() ? "5555" : ui->get_TcpIp_LineEdit->text();
        accept();
    }
}

void Frm_GetIP::getSelectIp_And_Tcpip(QString* ipPtr, QString* tcpipPtr, QWidget* parent)
{
    Frm_GetIP dlg(ipPtr, tcpipPtr, parent);
    dlg.exec();
}
