/********************************************************************************
** Form generated from reading UI file 'Frm_GetIP.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRM_GETIP_H
#define UI_FRM_GETIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Frm_GetIP
{
public:
    QGroupBox *groupBox;
    QListWidget *show_IPs_ListWidget;
    QGroupBox *groupBox_2;
    QLineEdit *get_TcpIp_LineEdit;
    QPushButton *OK_PushButton;

    void setupUi(QDialog *Frm_GetIP)
    {
        if (Frm_GetIP->objectName().isEmpty())
            Frm_GetIP->setObjectName("Frm_GetIP");
        Frm_GetIP->resize(242, 349);
        groupBox = new QGroupBox(Frm_GetIP);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 10, 221, 281));
        show_IPs_ListWidget = new QListWidget(groupBox);
        show_IPs_ListWidget->setObjectName("show_IPs_ListWidget");
        show_IPs_ListWidget->setGeometry(QRect(10, 20, 201, 251));
        groupBox_2 = new QGroupBox(Frm_GetIP);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 290, 91, 51));
        get_TcpIp_LineEdit = new QLineEdit(groupBox_2);
        get_TcpIp_LineEdit->setObjectName("get_TcpIp_LineEdit");
        get_TcpIp_LineEdit->setGeometry(QRect(10, 20, 71, 20));
        OK_PushButton = new QPushButton(Frm_GetIP);
        OK_PushButton->setObjectName("OK_PushButton");
        OK_PushButton->setGeometry(QRect(120, 300, 91, 31));

        retranslateUi(Frm_GetIP);

        QMetaObject::connectSlotsByName(Frm_GetIP);
    } // setupUi

    void retranslateUi(QDialog *Frm_GetIP)
    {
        Frm_GetIP->setWindowTitle(QCoreApplication::translate("Frm_GetIP", "\351\200\211\346\213\251IP", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Frm_GetIP", "IP\345\210\227\350\241\250", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Frm_GetIP", "\347\253\257\345\217\243", nullptr));
        get_TcpIp_LineEdit->setText(QString());
        OK_PushButton->setText(QCoreApplication::translate("Frm_GetIP", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Frm_GetIP: public Ui_Frm_GetIP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRM_GETIP_H
