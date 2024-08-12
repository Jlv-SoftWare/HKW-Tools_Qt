#include "Frm_Main.h"
#include "HKW_Tools.h"
#include "Debuger.cpp"
#if defined(_WIN32)
#include <Windows.h>
#endif
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qInstallMessageHandler(Qt::CustomMessageHandler);
    HKW_Tools::Core::ADB::Server::SetAdbPath("D:\\ADB\\adb.exe");
    Frm_Main w;
    w.show();
    return a.exec();
}
