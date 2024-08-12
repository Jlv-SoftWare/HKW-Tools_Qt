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
    explicit Dlg_Loading(const QString& text, const QString& title, QWidget *parent = nullptr);
    explicit Dlg_Loading(const QString& text, const QString& title, const int& minValue, const int& maxValue, QWidget *parent = nullptr);
    ~Dlg_Loading();
    
    void Update(const int& updateValue);

private:
    Ui::Dlg_Loading *ui;
    QString* tipText;
};

#endif // DLG_LOADING_H
