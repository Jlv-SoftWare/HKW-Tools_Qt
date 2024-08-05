#pragma once

#include <QtWidgets/QDialog>
#include "ui_Frm_Main.h"
#include "SyncDevicesThread.h"

class Frm_Main : public QDialog
{
    Q_OBJECT

protected:
    std::vector<QString> getComboBoxItems(const QComboBox& comboBox) const;
    void InitComboBox() const;
    QString SelectedDevice() const;

    void Open_Frm_InstallApp();

public:
    Ui::Frm_MainClass ui;
    Frm_Main(QWidget *parent = nullptr);
    ~Frm_Main();

    

signals:
    void sendCombo(const std::vector<QString>& list);

signals:
    void sendSelectedDeviceID(const QString& id);

public slots:
    void addID(const QString& id);
    void removeID(const QString& id);
    void clearIDs();

    void set_showNumOfDevices_Lable_Text(const QString& text);
    void Here_you_are();
    void OK_bro();
    void ZhanShi();

};
