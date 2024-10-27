QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Debuger.cpp \
    Frm_ConnectDevice.cpp \
    Frm_GetIP.cpp \
    HKW_Tools/ADB/App/App.cpp \
    HKW_Tools/ADB/Device/Device.cpp \
    HKW_Tools/ADB/Server/Server.cpp \
    HKW_Tools/CmdResult/CmdResult.cpp \
    HKW_Tools/ErrMessage/ErrMessage.cpp \
    HKW_Tools/StringBox/StringBox.cpp \
    HKW_Tools/Terminal/Terminal.cpp \
    JMessageBox.cpp \
    main.cpp \
    Frm_Main.cpp

HEADERS += \
    Frm_ConnectDevice.h \
    Frm_GetIP.h \
    Frm_Main.h \
    HKW_Tools.h \
    HKW_Tools/ADB.h \
    HKW_Tools/CmdResult.h \
    HKW_Tools/ErrMessage.h \
    HKW_Tools/StringBox.h \
    HKW_Tools/Terminal.h \
    JMessageBox.h

FORMS += \
    Frm_ConnectDevice.ui \
    Frm_GetIP.ui \
    Frm_Main.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    HKW-Tools.qrc
    Icon.png

