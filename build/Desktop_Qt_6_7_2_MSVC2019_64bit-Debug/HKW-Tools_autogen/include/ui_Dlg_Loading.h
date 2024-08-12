/********************************************************************************
** Form generated from reading UI file 'Dlg_Loading.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLG_LOADING_H
#define UI_DLG_LOADING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>

QT_BEGIN_NAMESPACE

class Ui_Dlg_Loading
{
public:
    QProgressBar *progressBar;
    QLabel *textLabel;

    void setupUi(QDialog *Dlg_Loading)
    {
        if (Dlg_Loading->objectName().isEmpty())
            Dlg_Loading->setObjectName("Dlg_Loading");
        Dlg_Loading->resize(268, 64);
        progressBar = new QProgressBar(Dlg_Loading);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(10, 30, 251, 23));
        progressBar->setValue(0);
        progressBar->setTextVisible(false);
        progressBar->setOrientation(Qt::Orientation::Horizontal);
        textLabel = new QLabel(Dlg_Loading);
        textLabel->setObjectName("textLabel");
        textLabel->setGeometry(QRect(10, 10, 251, 16));

        retranslateUi(Dlg_Loading);

        QMetaObject::connectSlotsByName(Dlg_Loading);
    } // setupUi

    void retranslateUi(QDialog *Dlg_Loading)
    {
        Dlg_Loading->setWindowTitle(QCoreApplication::translate("Dlg_Loading", "TITLE", nullptr));
        textLabel->setText(QCoreApplication::translate("Dlg_Loading", "TEXT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dlg_Loading: public Ui_Dlg_Loading {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLG_LOADING_H
