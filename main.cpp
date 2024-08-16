#include "Frm_Main.h"
#include "HKW_Tools.h"
#include "Debuger.cpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Frm_Main w;
    qInstallMessageHandler(Qt::CustomMessageHandler);
    HKW_Tools::Core::ADB::Server::SetAdbPath("D:\\ADB\\adb.exe");
    w.show();
    return a.exec();
}
