QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Debuger.cpp \
    HKW_Tools/Core/ADB/App/App.cpp \
    HKW_Tools/Core/ADB/Device/Device.cpp \
    HKW_Tools/Core/ADB/Server/Server.cpp \
    HKW_Tools/Core/Terminal/Terminal.cpp \
    HKW_Tools/Data/CmdResult/CmdResult.cpp \
    HKW_Tools/Data/ErrMessage/ErrMessage.cpp \
    HKW_Tools/Data/StringBox/StringBox.cpp \
    JMessageBox.cpp \
    main.cpp \
    Frm_Main.cpp

HEADERS += \
    Frm_Main.h \
    HKW_Tools.h \
    HKW_Tools/Core/ADB.h \
    HKW_Tools/Core/Terminal.h \
    HKW_Tools/Data/CmdResult.h \
    HKW_Tools/Data/ErrMessage.h \
    HKW_Tools/Data/StringBox.h \
    JMessageBox.h

FORMS += \
    Frm_Main.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    HKW-Tools.qrc
    Icon.png
