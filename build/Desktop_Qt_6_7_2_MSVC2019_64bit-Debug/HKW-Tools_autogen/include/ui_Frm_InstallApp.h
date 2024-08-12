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

class Ui_Frm_InstallApp
{
public:

    void setupUi(QDialog *Frm_InstallApp)
    {
        if (Frm_InstallApp->objectName().isEmpty())
            Frm_InstallApp->setObjectName("Frm_InstallApp");
        Frm_InstallApp->resize(400, 300);

        retranslateUi(Frm_InstallApp);

        QMetaObject::connectSlotsByName(Frm_InstallApp);
    } // setupUi

    void retranslateUi(QDialog *Frm_InstallApp)
    {
        Frm_InstallApp->setWindowTitle(QCoreApplication::translate("Frm_InstallApp", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Frm_InstallApp: public Ui_Frm_InstallApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRM_INSTALLAPP_H
