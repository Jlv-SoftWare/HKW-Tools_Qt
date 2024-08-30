#ifndef FRM_CONNECTDEVICE_H
#define FRM_CONNECTDEVICE_H

#include <QDialog>
#include "Frm_GetIP.h"

namespace Ui {
class Frm_ConnectDevice;
}

class Frm_ConnectDevice : public QDialog
{
    Q_OBJECT

public:
    explicit Frm_ConnectDevice(QWidget *parent = nullptr);
    ~Frm_ConnectDevice();
    

private:
    Ui::Frm_ConnectDevice *ui;
    Frm_GetIP* getIpFrm;
    
private slots:
    void setIp(const QString& ip);
    void setTcpIp(const QString& tcpip);
};

#endif // FRM_CONNECTDEVICE_H
