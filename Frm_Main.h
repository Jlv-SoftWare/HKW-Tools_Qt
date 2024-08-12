#ifndef FRM_MAIN_H
#define FRM_MAIN_H

#include <QPaintEvent>
#include <QCloseEvent>
#include <QVBoxLayout>
#include <QDialog>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Frm_Main; }
QT_END_NAMESPACE

class Frm_Main : public QDialog
{
    Q_OBJECT

public:
    Frm_Main(QWidget *parent = nullptr);
    ~Frm_Main();
    
protected:
    void closeEvent(QCloseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    
    std::vector<QString> getComboItems() const;
    void initCombo();
    void initFunsWidgets();
    
    void clearDeviceInfo();
    void loadDeviceInfo();
    
    void updateCombo();
    
    void startServer();
    void killServer();
    
private:
    Ui::Frm_Main* ui;
    QTimer* updateDevicesTimer;
    
signals:
    void selectDeviceStatusChance();
    
};
#endif // FRM_MAIN_H
