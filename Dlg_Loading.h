#ifndef DLG_LOADING_H
#define DLG_LOADING_H

#include <QDialog>

namespace Ui {
class Dlg_Loading;
}

class Dlg_Loading : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_Loading(QWidget *parent = nullptr);
    ~Dlg_Loading();

private:
    Ui::Dlg_Loading *ui;
};

#endif // DLG_LOADING_H
