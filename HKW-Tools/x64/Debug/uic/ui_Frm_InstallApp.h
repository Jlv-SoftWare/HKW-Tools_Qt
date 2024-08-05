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
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Frm_InstallAppClass
{
public:

    void setupUi(QDialog *Frm_InstallAppClass)
    {
        if (Frm_InstallAppClass->objectName().isEmpty())
            Frm_InstallAppClass->setObjectName("Frm_InstallAppClass");
        Frm_InstallAppClass->resize(600, 400);

        retranslateUi(Frm_InstallAppClass);

        QMetaObject::connectSlotsByName(Frm_InstallAppClass);
    } // setupUi

    void retranslateUi(QDialog *Frm_InstallAppClass)
    {
        Frm_InstallAppClass->setWindowTitle(QCoreApplication::translate("Frm_InstallAppClass", "Frm_InstallApp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Frm_InstallAppClass: public Ui_Frm_InstallAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRM_INSTALLAPP_H
