#include "Frm_InstallApp.h"
#include "Frm_Main.h"

Frm_InstallApp::Frm_InstallApp(const QString& deviceID, QWidget *parent)
	: device(deviceID), QDialog(parent)
{
	ui.setupUi(this);
}

Frm_InstallApp::~Frm_InstallApp()
{

}
