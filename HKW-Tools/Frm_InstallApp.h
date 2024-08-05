#pragma once

#include <QDialog>
#include "ui_Frm_InstallApp.h"

class Frm_InstallApp : public QDialog
{
	Q_OBJECT

public:
	Frm_InstallApp(const QString& deviceID, QWidget *parent = nullptr);
	~Frm_InstallApp();

signals:
	void ShowMasterFrm();

private:
	Ui::Frm_InstallAppClass ui;
	QString device;
};
