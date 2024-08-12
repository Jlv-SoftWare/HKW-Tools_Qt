#include "Dlg_Loading.h"
#include "ui_Dlg_Loading.h"

Dlg_Loading::Dlg_Loading(const QString& text, const QString& title, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dlg_Loading)
{
    ui->setupUi(this);
    setFixedSize(size());
    ui->textLabel->setText(text);
    setWindowTitle(title);
    ui->progressBar->setRange(0, 0);
}

Dlg_Loading::Dlg_Loading(const QString &text, const QString &title, const int &minValue, const int &maxValue, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dlg_Loading)
{
    ui->setupUi(this);
    setFixedSize(size());
    ui->textLabel->setText(text);
    setWindowTitle(title);
    ui->progressBar->setRange(minValue, maxValue);
}

Dlg_Loading::~Dlg_Loading()
{
    delete ui;
}

void Dlg_Loading::Update(const int &updateValue)
{
    ui->progressBar->setValue(updateValue);
}
