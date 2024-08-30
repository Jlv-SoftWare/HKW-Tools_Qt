/********************************************************************************
** Form generated from reading UI file 'Frm_ConnectDevice.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRM_CONNECTDEVICE_H
#define UI_FRM_CONNECTDEVICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Frm_ConnectDevice
{
public:
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QLineEdit *get_Ip_LineEdit;
    QGroupBox *groupBox_3;
    QLineEdit *get_Tcpip_LineEdit;
    QPushButton *pushButton_2;
    QPushButton *clickTo_Open_Frm_GetIP_PushButton;

    void setupUi(QDialog *Frm_ConnectDevice)
    {
        if (Frm_ConnectDevice->objectName().isEmpty())
            Frm_ConnectDevice->setObjectName(QString::fromUtf8("Frm_ConnectDevice"));
        Frm_ConnectDevice->resize(412, 150);
        groupBox = new QGroupBox(Frm_ConnectDevice);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 391, 131));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 20, 241, 51));
        get_Ip_LineEdit = new QLineEdit(groupBox_2);
        get_Ip_LineEdit->setObjectName(QString::fromUtf8("get_Ip_LineEdit"));
        get_Ip_LineEdit->setGeometry(QRect(10, 20, 221, 20));
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(270, 20, 111, 51));
        get_Tcpip_LineEdit = new QLineEdit(groupBox_3);
        get_Tcpip_LineEdit->setObjectName(QString::fromUtf8("get_Tcpip_LineEdit"));
        get_Tcpip_LineEdit->setGeometry(QRect(10, 20, 91, 20));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(280, 90, 101, 24));
        clickTo_Open_Frm_GetIP_PushButton = new QPushButton(groupBox);
        clickTo_Open_Frm_GetIP_PushButton->setObjectName(QString::fromUtf8("clickTo_Open_Frm_GetIP_PushButton"));
        clickTo_Open_Frm_GetIP_PushButton->setGeometry(QRect(20, 90, 75, 24));

        retranslateUi(Frm_ConnectDevice);

        QMetaObject::connectSlotsByName(Frm_ConnectDevice);
    } // setupUi

    void retranslateUi(QDialog *Frm_ConnectDevice)
    {
        Frm_ConnectDevice->setWindowTitle(QCoreApplication::translate("Frm_ConnectDevice", "\350\277\236\346\216\245\350\256\276\345\244\207", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Frm_ConnectDevice", "\350\277\236\346\216\245", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Frm_ConnectDevice", "IP\345\234\260\345\235\200", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Frm_ConnectDevice", "\347\253\257\345\217\243", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Frm_ConnectDevice", "\350\277\236\346\216\245", nullptr));
        clickTo_Open_Frm_GetIP_PushButton->setText(QCoreApplication::translate("Frm_ConnectDevice", "\351\200\211\346\213\251IP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Frm_ConnectDevice: public Ui_Frm_ConnectDevice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRM_CONNECTDEVICE_H
