#ifndef FRM_CONNECTDEVICE_H
#define FRM_CONNECTDEVICE_H

#include <QDialog>

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
};

#endif // FRM_CONNECTDEVICE_H
