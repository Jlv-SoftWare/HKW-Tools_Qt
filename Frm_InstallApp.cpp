#include "Frm_InstallApp.h"
#include "ui_Frm_InstallApp.h"

Frm_InstallApp::Frm_InstallApp(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Frm_InstallApp)
{
    ui->setupUi(this);
}

Frm_InstallApp::~Frm_InstallApp()
{
    delete ui;
}
