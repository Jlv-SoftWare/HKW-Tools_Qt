#ifndef FRM_INSTALLAPP_H
#define FRM_INSTALLAPP_H

#include <QDialog>

namespace Ui {
class Frm_InstallApp;
}

class Frm_InstallApp : public QDialog
{
    Q_OBJECT

public:
    explicit Frm_InstallApp(QWidget *parent = nullptr);
    ~Frm_InstallApp();

private:
    Ui::Frm_InstallApp *ui;
};

#endif // FRM_INSTALLAPP_H
