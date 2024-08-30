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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Frm_Main
{
public:
    QGroupBox *funs_GroupBox;
    QListWidget *funs_ListWidget;
    QGroupBox *devicesInfos_GroupBox;
    QComboBox *syncDevices_ComboBox;
    QLabel *showNumOfDevices_Lable;
    QCommandLinkButton *clickTo_Open_Frm_ConnectDevice_CommandLinkButton;
    QGroupBox *deviceInfo_GroupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QProgressBar *show_UsedStorage_ProgressBar;
    QLineEdit *show_DeviceModel_LineEdit;
    QLineEdit *show_CpuModel_LineEdit;
    QLineEdit *show_Manufacturer_LineEdit;
    QLineEdit *show_AndroidVersion_LineEdit;
    QLineEdit *show_CurrentDpi_LineEdit;
    QLineEdit *show_CurrentResolution_LineEdit;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *show_StorageSize_LineEdit;
    QLineEdit *show_UsedStorage_LineEdit;

    void setupUi(QWidget *Frm_Main)
    {
        if (Frm_Main->objectName().isEmpty())
            Frm_Main->setObjectName("Frm_Main");
        Frm_Main->resize(362, 419);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icon/Icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Frm_Main->setWindowIcon(icon);
        funs_GroupBox = new QGroupBox(Frm_Main);
        funs_GroupBox->setObjectName("funs_GroupBox");
        funs_GroupBox->setGeometry(QRect(240, 10, 111, 401));
        funs_ListWidget = new QListWidget(funs_GroupBox);
        funs_ListWidget->setObjectName("funs_ListWidget");
        funs_ListWidget->setGeometry(QRect(10, 20, 91, 371));
        QFont font;
        font.setPointSize(10);
        funs_ListWidget->setFont(font);
        devicesInfos_GroupBox = new QGroupBox(Frm_Main);
        devicesInfos_GroupBox->setObjectName("devicesInfos_GroupBox");
        devicesInfos_GroupBox->setGeometry(QRect(10, 10, 221, 401));
        syncDevices_ComboBox = new QComboBox(devicesInfos_GroupBox);
        syncDevices_ComboBox->setObjectName("syncDevices_ComboBox");
        syncDevices_ComboBox->setGeometry(QRect(10, 40, 201, 21));
        showNumOfDevices_Lable = new QLabel(devicesInfos_GroupBox);
        showNumOfDevices_Lable->setObjectName("showNumOfDevices_Lable");
        showNumOfDevices_Lable->setGeometry(QRect(10, 20, 141, 16));
        clickTo_Open_Frm_ConnectDevice_CommandLinkButton = new QCommandLinkButton(devicesInfos_GroupBox);
        clickTo_Open_Frm_ConnectDevice_CommandLinkButton->setObjectName("clickTo_Open_Frm_ConnectDevice_CommandLinkButton");
        clickTo_Open_Frm_ConnectDevice_CommandLinkButton->setGeometry(QRect(10, 350, 201, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        clickTo_Open_Frm_ConnectDevice_CommandLinkButton->setFont(font1);
        deviceInfo_GroupBox = new QGroupBox(devicesInfos_GroupBox);
        deviceInfo_GroupBox->setObjectName("deviceInfo_GroupBox");
        deviceInfo_GroupBox->setGeometry(QRect(10, 70, 201, 271));
        label = new QLabel(deviceInfo_GroupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 71, 16));
        label_2 = new QLabel(deviceInfo_GroupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 50, 71, 16));
        label_3 = new QLabel(deviceInfo_GroupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 80, 71, 16));
        label_4 = new QLabel(deviceInfo_GroupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 110, 71, 16));
        label_5 = new QLabel(deviceInfo_GroupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 140, 71, 16));
        label_6 = new QLabel(deviceInfo_GroupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 170, 71, 16));
        label_7 = new QLabel(deviceInfo_GroupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 200, 71, 16));
        show_UsedStorage_ProgressBar = new QProgressBar(deviceInfo_GroupBox);
        show_UsedStorage_ProgressBar->setObjectName("show_UsedStorage_ProgressBar");
        show_UsedStorage_ProgressBar->setGeometry(QRect(10, 220, 181, 16));
        show_UsedStorage_ProgressBar->setValue(0);
        show_UsedStorage_ProgressBar->setTextVisible(true);
        show_DeviceModel_LineEdit = new QLineEdit(deviceInfo_GroupBox);
        show_DeviceModel_LineEdit->setObjectName("show_DeviceModel_LineEdit");
        show_DeviceModel_LineEdit->setGeometry(QRect(82, 20, 101, 20));
        show_DeviceModel_LineEdit->setFrame(false);
        show_DeviceModel_LineEdit->setReadOnly(true);
        show_CpuModel_LineEdit = new QLineEdit(deviceInfo_GroupBox);
        show_CpuModel_LineEdit->setObjectName("show_CpuModel_LineEdit");
        show_CpuModel_LineEdit->setGeometry(QRect(82, 50, 101, 20));
        show_CpuModel_LineEdit->setFrame(false);
        show_CpuModel_LineEdit->setReadOnly(true);
        show_Manufacturer_LineEdit = new QLineEdit(deviceInfo_GroupBox);
        show_Manufacturer_LineEdit->setObjectName("show_Manufacturer_LineEdit");
        show_Manufacturer_LineEdit->setGeometry(QRect(82, 80, 101, 20));
        show_Manufacturer_LineEdit->setFrame(false);
        show_Manufacturer_LineEdit->setReadOnly(true);
        show_AndroidVersion_LineEdit = new QLineEdit(deviceInfo_GroupBox);
        show_AndroidVersion_LineEdit->setObjectName("show_AndroidVersion_LineEdit");
        show_AndroidVersion_LineEdit->setGeometry(QRect(82, 110, 101, 20));
        show_AndroidVersion_LineEdit->setFrame(false);
        show_AndroidVersion_LineEdit->setReadOnly(true);
        show_CurrentDpi_LineEdit = new QLineEdit(deviceInfo_GroupBox);
        show_CurrentDpi_LineEdit->setObjectName("show_CurrentDpi_LineEdit");
        show_CurrentDpi_LineEdit->setGeometry(QRect(82, 140, 101, 20));
        show_CurrentDpi_LineEdit->setFrame(false);
        show_CurrentDpi_LineEdit->setReadOnly(true);
        show_CurrentResolution_LineEdit = new QLineEdit(deviceInfo_GroupBox);
        show_CurrentResolution_LineEdit->setObjectName("show_CurrentResolution_LineEdit");
        show_CurrentResolution_LineEdit->setGeometry(QRect(82, 170, 101, 20));
        show_CurrentResolution_LineEdit->setFrame(false);
        show_CurrentResolution_LineEdit->setReadOnly(true);
        label_8 = new QLabel(deviceInfo_GroupBox);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 240, 31, 16));
        label_9 = new QLabel(deviceInfo_GroupBox);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(110, 240, 31, 16));
        show_StorageSize_LineEdit = new QLineEdit(deviceInfo_GroupBox);
        show_StorageSize_LineEdit->setObjectName("show_StorageSize_LineEdit");
        show_StorageSize_LineEdit->setGeometry(QRect(40, 240, 40, 20));
        show_StorageSize_LineEdit->setFrame(false);
        show_StorageSize_LineEdit->setReadOnly(true);
        show_UsedStorage_LineEdit = new QLineEdit(deviceInfo_GroupBox);
        show_UsedStorage_LineEdit->setObjectName("show_UsedStorage_LineEdit");
        show_UsedStorage_LineEdit->setGeometry(QRect(140, 240, 40, 20));
        show_UsedStorage_LineEdit->setFrame(false);
        show_UsedStorage_LineEdit->setReadOnly(true);

        retranslateUi(Frm_Main);

        QMetaObject::connectSlotsByName(Frm_Main);
    } // setupUi

    void retranslateUi(QWidget *Frm_Main)
    {
        Frm_Main->setWindowTitle(QCoreApplication::translate("Frm_Main", "HKW\345\267\245\345\205\267\347\256\261", nullptr));
        funs_GroupBox->setTitle(QCoreApplication::translate("Frm_Main", "\345\212\237\350\203\275\345\210\227\350\241\250", nullptr));
        devicesInfos_GroupBox->setTitle(QCoreApplication::translate("Frm_Main", "\350\256\276\345\244\207\351\200\211\351\241\271", nullptr));
        showNumOfDevices_Lable->setText(QCoreApplication::translate("Frm_Main", "\345\275\223\345\211\215\350\277\236\346\216\245\344\272\206 0 \344\270\252\350\256\276\345\244\207", nullptr));
        clickTo_Open_Frm_ConnectDevice_CommandLinkButton->setText(QCoreApplication::translate("Frm_Main", "\350\277\236\346\216\245&&\351\205\215\345\257\271\350\256\276\345\244\207", nullptr));
        deviceInfo_GroupBox->setTitle(QCoreApplication::translate("Frm_Main", "\350\256\276\345\244\207\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("Frm_Main", "\345\236\213\345\217\267:", nullptr));
        label_2->setText(QCoreApplication::translate("Frm_Main", "CPU\345\236\213\345\217\267:", nullptr));
        label_3->setText(QCoreApplication::translate("Frm_Main", "\347\224\237\344\272\247\345\225\206:", nullptr));
        label_4->setText(QCoreApplication::translate("Frm_Main", "\345\256\211\345\215\223\347\211\210\346\234\254:", nullptr));
        label_5->setText(QCoreApplication::translate("Frm_Main", "\345\275\223\345\211\215Dpi:", nullptr));
        label_6->setText(QCoreApplication::translate("Frm_Main", "\345\275\223\345\211\215\345\210\206\350\276\250\347\216\207:", nullptr));
        label_7->setText(QCoreApplication::translate("Frm_Main", "\345\202\250\345\255\230\347\251\272\351\227\264:", nullptr));
        label_8->setText(QCoreApplication::translate("Frm_Main", "\346\200\273\345\205\261:", nullptr));
        label_9->setText(QCoreApplication::translate("Frm_Main", "\345\267\262\347\224\250:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Frm_Main: public Ui_Frm_Main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRM_MAIN_H
