#ifndef FRM_GETIP_H
#define FRM_GETIP_H

#include <QDialog>
#include <QString>
#include <QShowEvent>
#include <QCloseEvent>
#include <QNetworkInterface>

namespace Ui {
class Frm_GetIP;
}

class Frm_GetIP : public QDialog
{
    Q_OBJECT
    
public:
    explicit Frm_GetIP(QString* ipVarPtr, QString* tcpipVarPtr, QWidget *parent = nullptr);
    ~Frm_GetIP();
    
    static void getSelectIp_And_Tcpip(QString* ipPtr, QString* tcpipPtr, QWidget* parent = nullptr);
    
protected:
    void showEvent(QShowEvent* event) override;
    std::vector<size_t> scan_ports(const std::string& ip_address);
    
private:
    Ui::Frm_GetIP *ui;
    QString* ipPtr;
    QString* tcpipPtr;
    
    void initWidgets();
    
private slots:
    void onOkButtonClicked();
};

#endif // FRM_GETIP_H
