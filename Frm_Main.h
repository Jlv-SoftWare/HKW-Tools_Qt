#ifndef FRM_MAIN_H
#define FRM_MAIN_H

#include <QDialog>
#include <QCloseEvent>
#include <QShowEvent>
#include <QFuture>
#include <QFutureWatcher>

QT_BEGIN_NAMESPACE
namespace Ui {
class Frm_Main;
}
QT_END_NAMESPACE

class Frm_Main : public QDialog
{
    Q_OBJECT

public:
    Frm_Main(QWidget *parent = nullptr);
    ~Frm_Main();
    
protected:
    void connectFuns();
    
    void showEvent(QShowEvent *event) override;
    void closeEvent(QCloseEvent *event) override;
    
    std::vector<QString> getComboItems() const;
    
    QString getSelectID();
    
    void initCombo();
    void initFunsWidgets();
    
    void addID(const QString& id);
    void removeID(const QString& id);
    
    void syncCombo();
    void syncInfos();
    
    void clearCombo();
    void clearInfos();
    
    void closeSyncServe();
    

private:
    Ui::Frm_Main *ui;
    QFuture<void>* syncComboTask;
    QFuture<void>* syncInfosTask;
    
    bool exitSyncServe;
    bool syncComboTask_IsExit;
    bool syncInfosTask_IsExit;
    
signals:
    void addID_signal(const QString& id);
    void removeID_signal(const QString& id);
    void setSelectID_signal();
    void clearCombo_signal();
    void clearInfos_signal();
    void set_showNumOfDevices_LableText_signal(const QString& text);
    
    void ui_show_DeviceModel_LineEdit_setText_signal(const QString& text);
    void ui_show_CpuModel_LineEdit_setText_signal(const QString& text);
    void ui_show_Manufacturer_LineEdit_setText_signal(const QString& text);
    void ui_show_AndroidVersion_LineEdit_setText_signal(const QString& text);
    void ui_show_CurrentDpi_LineEdit_setText_signal(const QString& text);
    void ui_show_CurrentResolution_LineEdit_setText_signal(const QString& text);
    void ui_show_UsedStorage_ProgressBar_setValue_signal(const int& value);
    void ui_show_StorageSize_LineEdit_setText_signal(const QString& text);
    void ui_show_UsedStorage_LineEdit_setText_signal(const QString& text);
    
public slots:
    
    void set_showNumOfDevices_LableText(const QString& text);
    
    void ui_show_DeviceModel_LineEdit_setText(const QString& text);
    void ui_show_CpuModel_LineEdit_setText(const QString& text);
    void ui_show_Manufacturer_LineEdit_setText(const QString& text);
    void ui_show_AndroidVersion_LineEdit_setText(const QString& text);
    void ui_show_CurrentDpi_LineEdit_setText(const QString& text);
    void ui_show_CurrentResolution_LineEdit_setText(const QString& text);
    void ui_show_UsedStorage_ProgressBar_setValue(const int& value);
    void ui_show_StorageSize_LineEdit_setText(const QString& text);
    void ui_show_UsedStorage_LineEdit_setText(const QString& text);

};
#endif // FRM_MAIN_H
