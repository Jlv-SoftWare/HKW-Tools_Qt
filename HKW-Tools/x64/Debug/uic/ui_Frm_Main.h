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
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Frm_MainClass
{
public:
    QGroupBox *devicesInfos_GroupBox;
    QComboBox *syncDevices_ComboBox;
    QLabel *showNumOfDevices_Lable;
    QLabel *label1;
    QLabel *showDeviceModel_Label;

    void setupUi(QDialog *Frm_MainClass)
    {
        if (Frm_MainClass->objectName().isEmpty())
            Frm_MainClass->setObjectName("Frm_MainClass");
        Frm_MainClass->resize(722, 382);
        devicesInfos_GroupBox = new QGroupBox(Frm_MainClass);
        devicesInfos_GroupBox->setObjectName("devicesInfos_GroupBox");
        devicesInfos_GroupBox->setGeometry(QRect(20, 20, 201, 351));
        syncDevices_ComboBox = new QComboBox(devicesInfos_GroupBox);
        syncDevices_ComboBox->setObjectName("syncDevices_ComboBox");
        syncDevices_ComboBox->setGeometry(QRect(10, 40, 181, 21));
        showNumOfDevices_Lable = new QLabel(devicesInfos_GroupBox);
        showNumOfDevices_Lable->setObjectName("showNumOfDevices_Lable");
        showNumOfDevices_Lable->setGeometry(QRect(10, 20, 141, 16));
        label1 = new QLabel(devicesInfos_GroupBox);
        label1->setObjectName("label1");
        label1->setGeometry(QRect(10, 80, 61, 16));
        showDeviceModel_Label = new QLabel(devicesInfos_GroupBox);
        showDeviceModel_Label->setObjectName("showDeviceModel_Label");
        showDeviceModel_Label->setGeometry(QRect(70, 80, 121, 16));

        retranslateUi(Frm_MainClass);

        QMetaObject::connectSlotsByName(Frm_MainClass);
    } // setupUi

    void retranslateUi(QDialog *Frm_MainClass)
    {
        Frm_MainClass->setWindowTitle(QCoreApplication::translate("Frm_MainClass", "HKW\345\267\245\345\205\267\347\256\261", nullptr));
        devicesInfos_GroupBox->setTitle(QCoreApplication::translate("Frm_MainClass", "\350\256\276\345\244\207\351\200\211\351\241\271", nullptr));
        showNumOfDevices_Lable->setText(QCoreApplication::translate("Frm_MainClass", "\345\275\223\345\211\215\350\277\236\346\216\245\344\272\206 0 \344\270\252\350\256\276\345\244\207", nullptr));
        label1->setText(QCoreApplication::translate("Frm_MainClass", "\350\256\276\345\244\207\345\220\215\347\247\260:", nullptr));
        showDeviceModel_Label->setText(QCoreApplication::translate("Frm_MainClass", "{deviceName}", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Frm_MainClass: public Ui_Frm_MainClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRM_MAIN_H
