/********************************************************************************
** Form generated from reading UI file 'Frm_InstallApp.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRM_INSTALLAPP_H
#define UI_FRM_INSTALLAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Frm_InstallAppClass
{
public:
    QLineEdit *lineEdit;
    QPushButton *clickTo_Open_QFileDialog_PushButton;
    QCommandLinkButton *clickTo_InstallApk_CommandLinkButton;
    QCommandLinkButton *clickTo_InstallApk_CommandLinkButton_2;

    void setupUi(QDialog *Frm_InstallAppClass)
    {
        if (Frm_InstallAppClass->objectName().isEmpty())
            Frm_InstallAppClass->setObjectName("Frm_InstallAppClass");
        Frm_InstallAppClass->resize(359, 129);
        lineEdit = new QLineEdit(Frm_InstallAppClass);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(90, 10, 251, 21));
        clickTo_Open_QFileDialog_PushButton = new QPushButton(Frm_InstallAppClass);
        clickTo_Open_QFileDialog_PushButton->setObjectName("clickTo_Open_QFileDialog_PushButton");
        clickTo_Open_QFileDialog_PushButton->setGeometry(QRect(10, 10, 75, 24));
        clickTo_InstallApk_CommandLinkButton = new QCommandLinkButton(Frm_InstallAppClass);
        clickTo_InstallApk_CommandLinkButton->setObjectName("clickTo_InstallApk_CommandLinkButton");
        clickTo_InstallApk_CommandLinkButton->setGeometry(QRect(10, 40, 341, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei UI")});
        clickTo_InstallApk_CommandLinkButton->setFont(font);
        clickTo_InstallApk_CommandLinkButton_2 = new QCommandLinkButton(Frm_InstallAppClass);
        clickTo_InstallApk_CommandLinkButton_2->setObjectName("clickTo_InstallApk_CommandLinkButton_2");
        clickTo_InstallApk_CommandLinkButton_2->setGeometry(QRect(10, 80, 341, 41));
        clickTo_InstallApk_CommandLinkButton_2->setFont(font);

        retranslateUi(Frm_InstallAppClass);

        QMetaObject::connectSlotsByName(Frm_InstallAppClass);
    } // setupUi

    void retranslateUi(QDialog *Frm_InstallAppClass)
    {
        Frm_InstallAppClass->setWindowTitle(QCoreApplication::translate("Frm_InstallAppClass", "Frm_InstallApp", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("Frm_InstallAppClass", "Apk\350\267\257\345\276\204", nullptr));
        clickTo_Open_QFileDialog_PushButton->setText(QCoreApplication::translate("Frm_InstallAppClass", "\351\200\211\346\213\251Apk:", nullptr));
        clickTo_InstallApk_CommandLinkButton->setText(QCoreApplication::translate("Frm_InstallAppClass", "\345\277\253\351\200\237\345\256\211\350\243\205", nullptr));
        clickTo_InstallApk_CommandLinkButton_2->setText(QCoreApplication::translate("Frm_InstallAppClass", "\347\255\276\345\220\215\345\271\266\345\256\211\350\243\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Frm_InstallAppClass: public Ui_Frm_InstallAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRM_INSTALLAPP_H
