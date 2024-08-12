#include "Dlg_Loading.h"
#include "ui_Dlg_Loading.h"

Dlg_Loading::Dlg_Loading(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dlg_Loading)
{
    ui->setupUi(this);
}

Dlg_Loading::~Dlg_Loading()
{
    delete ui;
}
