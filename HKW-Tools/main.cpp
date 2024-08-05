#include <QtWidgets/QApplication>
#include <QMessageBox>
#include <filesystem>
#if defined(_WIN32)
#include <Windows.h>
#endif
#include "Frm_Main.h"
#include "HKW_Tools.h"
#include "Debuger.cpp"

static void HideTheConsole();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qInstallMessageHandler(Qt::CustomMessageHandler);
    HideTheConsole();
    HKW_Tools::Core::ADB::Server::SetAdbPath("D:\\ADB\\adb.exe");
    Frm_Main w;
    w.show();
    return a.exec();
}

static void HideTheConsole()
{
#if defined(_WIN32)
    AllocConsole();
    ShowWindow(GetConsoleWindow(), SW_HIDE);
#endif 
}