/********************************************************************************
** Form generated from reading UI file 'Frm_Main.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRM_MAIN_H
#define UI_FRM_MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Frm_MainClass
{
public:
    QGroupBox *devicesInfos_GroupBox;
    QComboBox *syncDevices_ComboBox;
    QLabel *showNumOfDevices_Lable;
    QCommandLinkButton *clickTo_Open_Frm_ConnectDevice_PushButton;
    QPushButton *clickTo_Open_Frm_DeviceInfo_PushButton;
    QPushButton *clickTo_Open_Frm_ScreenManger_PushButton;
    QGroupBox *Funs_GroupBox;
    QPushButton *clickTo_Open_Frm_InstallApp_PushButton;
    QPushButton *clickTo_Open_Frm_AppsManger_PushButton;
    QPushButton *clickTo_Open_Frm_FileManger_PushButton;
    QPushButton *clickTo_Open_Frm_OthersFuns_PushButton;

    void setupUi(QDialog *Frm_MainClass)
    {
        if (Frm_MainClass->objectName().isEmpty())
            Frm_MainClass->setObjectName("Frm_MainClass");
        Frm_MainClass->resize(526, 195);
        devicesInfos_GroupBox = new QGroupBox(Frm_MainClass);
        devicesInfos_GroupBox->setObjectName("devicesInfos_GroupBox");
        devicesInfos_GroupBox->setGeometry(QRect(10, 10, 191, 181));
        syncDevices_ComboBox = new QComboBox(devicesInfos_GroupBox);
        syncDevices_ComboBox->setObjectName("syncDevices_ComboBox");
        syncDevices_ComboBox->setGeometry(QRect(10, 40, 171, 21));
        showNumOfDevices_Lable = new QLabel(devicesInfos_GroupBox);
        showNumOfDevices_Lable->setObjectName("showNumOfDevices_Lable");
        showNumOfDevices_Lable->setGeometry(QRect(10, 20, 141, 16));
        clickTo_Open_Frm_ConnectDevice_PushButton = new QCommandLinkButton(devicesInfos_GroupBox);
        clickTo_Open_Frm_ConnectDevice_PushButton->setObjectName("clickTo_Open_Frm_ConnectDevice_PushButton");
        clickTo_Open_Frm_ConnectDevice_PushButton->setGeometry(QRect(10, 130, 171, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei UI")});
        clickTo_Open_Frm_ConnectDevice_PushButton->setFont(font);
        clickTo_Open_Frm_DeviceInfo_PushButton = new QPushButton(devicesInfos_GroupBox);
        clickTo_Open_Frm_DeviceInfo_PushButton->setObjectName("clickTo_Open_Frm_DeviceInfo_PushButton");
        clickTo_Open_Frm_DeviceInfo_PushButton->setGeometry(QRect(10, 70, 170, 25));
        clickTo_Open_Frm_ScreenManger_PushButton = new QPushButton(devicesInfos_GroupBox);
        clickTo_Open_Frm_ScreenManger_PushButton->setObjectName("clickTo_Open_Frm_ScreenManger_PushButton");
        clickTo_Open_Frm_ScreenManger_PushButton->setGeometry(QRect(10, 100, 170, 25));
        Funs_GroupBox = new QGroupBox(Frm_MainClass);
        Funs_GroupBox->setObjectName("Funs_GroupBox");
        Funs_GroupBox->setGeometry(QRect(210, 10, 311, 181));
        clickTo_Open_Frm_InstallApp_PushButton = new QPushButton(Funs_GroupBox);
        clickTo_Open_Frm_InstallApp_PushButton->setObjectName("clickTo_Open_Frm_InstallApp_PushButton");
        clickTo_Open_Frm_InstallApp_PushButton->setGeometry(QRect(10, 20, 141, 71));
        clickTo_Open_Frm_AppsManger_PushButton = new QPushButton(Funs_GroupBox);
        clickTo_Open_Frm_AppsManger_PushButton->setObjectName("clickTo_Open_Frm_AppsManger_PushButton");
        clickTo_Open_Frm_AppsManger_PushButton->setGeometry(QRect(160, 20, 141, 71));
        clickTo_Open_Frm_FileManger_PushButton = new QPushButton(Funs_GroupBox);
        clickTo_Open_Frm_FileManger_PushButton->setObjectName("clickTo_Open_Frm_FileManger_PushButton");
        clickTo_Open_Frm_FileManger_PushButton->setGeometry(QRect(10, 100, 141, 71));
        clickTo_Open_Frm_OthersFuns_PushButton = new QPushButton(Funs_GroupBox);
        clickTo_Open_Frm_OthersFuns_PushButton->setObjectName("clickTo_Open_Frm_OthersFuns_PushButton");
        clickTo_Open_Frm_OthersFuns_PushButton->setGeometry(QRect(160, 100, 141, 71));

        retranslateUi(Frm_MainClass);

        QMetaObject::connectSlotsByName(Frm_MainClass);
    } // setupUi

    void retranslateUi(QDialog *Frm_MainClass)
    {
        Frm_MainClass->setWindowTitle(QCoreApplication::translate("Frm_MainClass", "HKW\345\267\245\345\205\267\347\256\261", nullptr));
        devicesInfos_GroupBox->setTitle(QCoreApplication::translate("Frm_MainClass", "\350\256\276\345\244\207\351\200\211\351\241\271", nullptr));
        showNumOfDevices_Lable->setText(QCoreApplication::translate("Frm_MainClass", "\345\275\223\345\211\215\350\277\236\346\216\245\344\272\206 0 \344\270\252\350\256\276\345\244\207", nullptr));
        clickTo_Open_Frm_ConnectDevice_PushButton->setText(QCoreApplication::translate("Frm_MainClass", "\350\277\236\346\216\245&&\351\205\215\345\257\271\350\256\276\345\244\207", nullptr));
        clickTo_Open_Frm_DeviceInfo_PushButton->setText(QCoreApplication::translate("Frm_MainClass", "\350\256\276\345\244\207\344\277\241\346\201\257", nullptr));
        clickTo_Open_Frm_ScreenManger_PushButton->setText(QCoreApplication::translate("Frm_MainClass", "\345\261\217\345\271\225\347\256\241\347\220\206", nullptr));
        Funs_GroupBox->setTitle(QCoreApplication::translate("Frm_MainClass", "\345\212\237\350\203\275", nullptr));
        clickTo_Open_Frm_InstallApp_PushButton->setText(QCoreApplication::translate("Frm_MainClass", "\345\256\211\350\243\205Apk", nullptr));
        clickTo_Open_Frm_AppsManger_PushButton->setText(QCoreApplication::translate("Frm_MainClass", "\347\256\241\347\220\206App", nullptr));
        clickTo_Open_Frm_FileManger_PushButton->setText(QCoreApplication::translate("Frm_MainClass", "\346\226\207\344\273\266\347\256\241\347\220\206", nullptr));
        clickTo_Open_Frm_OthersFuns_PushButton->setText(QCoreApplication::translate("Frm_MainClass", "\345\205\266\344\273\226\345\212\237\350\203\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Frm_MainClass: public Ui_Frm_MainClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRM_MAIN_H
