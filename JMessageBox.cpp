#pragma warning(disable:4996)
#include "JMessageBox.h"

QString JMessageBox::GetButtonText(QMessageBox::StandardButton standar)
{
    switch (standar)
    {
    case QMessageBox::Ok:
        return QString("确定");
    case QMessageBox::Cancel:
        return QString("取消");
    case QMessageBox::Abort:
        return QString("终止");
    case QMessageBox::Retry:
        return QString("重试");
    case QMessageBox::Ignore:
        return QString("忽略");
    case QMessageBox::Yes:
        return QString("是");
    case QMessageBox::No:
        return QString("否");
    default:
        return QString("OK");
    }
}

QMap<QString, QMessageBox::StandardButton> JMessageBox::GetButton(JMessageBoxButtons type)
{
    QMap<QString, QMessageBox::StandardButton> map;
    switch (type)
    {
    case JMessageBoxButtons(0):
    default:
        map.insert(GetButtonText(QMessageBox::Ok), QMessageBox::Ok);
        break;
    case JMessageBoxButtons(1):
        map.insert(GetButtonText(QMessageBox::Ok), QMessageBox::Ok);
        map.insert(GetButtonText(QMessageBox::Cancel), QMessageBox::Cancel);
        break;
    case JMessageBoxButtons(2):
        map.insert(GetButtonText(QMessageBox::Abort), QMessageBox::Abort);
        map.insert(GetButtonText(QMessageBox::Retry), QMessageBox::Retry);
        map.insert(GetButtonText(QMessageBox::Ignore), QMessageBox::Ignore);
        break;
    case JMessageBoxButtons(3):
        map.insert(GetButtonText(QMessageBox::Yes), QMessageBox::Yes);
        map.insert(GetButtonText(QMessageBox::No), QMessageBox::No);
        map.insert(GetButtonText(QMessageBox::Cancel), QMessageBox::Cancel);
        break;
    case JMessageBoxButtons(4):
        map.insert(GetButtonText(QMessageBox::Yes), QMessageBox::Yes);
        map.insert(GetButtonText(QMessageBox::No), QMessageBox::No);
        break;
    case JMessageBoxButtons(5):
        map.insert(GetButtonText(QMessageBox::Retry), QMessageBox::Retry);
        map.insert(GetButtonText(QMessageBox::Cancel), QMessageBox::Cancel);
        break;
    }
    return map;
}

int JMessageBox::Show(const QString& content, const QString& caption, JMessageBoxButtons button,
    JMessageBoxIcon icon, QWidget* parent)
{
    QMessageBox::Icon con;
    switch (icon)
    {
    case JMessageBoxIcon(0):
        con = QMessageBox::NoIcon;
        break;
    case JMessageBoxIcon(1):
    case JMessageBoxIcon(5):
    case JMessageBoxIcon(6):
        con = QMessageBox::Critical;
        break;
    case JMessageBoxIcon(2):
        con = QMessageBox::Question;
        break;
    case JMessageBoxIcon(3):
    case JMessageBoxIcon(7):
        con = QMessageBox::Warning;
        break;
    default:
        con = QMessageBox::Information;
        break;
    }
    QMap<QString, QMessageBox::StandardButton> ms = GetButton(button);
    QMessageBox box(con, caption, content);
    if (parent != nullptr)
    {
        box.setParent(parent);
    }
    int size = ms.size();
    switch (size)
    {
    case 1:
        box.setStandardButtons(ms.first());
        box.setButtonText(ms.values().at(0), ms.keys().at(0));
        break;
    case 2:
        box.setStandardButtons(ms.first() | ms.last());
        box.setButtonText(ms.values().at(0), ms.keys().at(0));
        box.setButtonText(ms.values().at(1), ms.keys().at(1));
        break;
    case 3:
        box.setStandardButtons(ms.values().at(0) | ms.values().at(1) | ms.values().at(2));
        box.setButtonText(ms.values().at(0), ms.keys().at(0));
        box.setButtonText(ms.values().at(1), ms.keys().at(1));
        box.setButtonText(ms.values().at(2), ms.keys().at(2));
        break;
    }
    return box.exec();
}

int JMessageBox::Show(const QString& content, const QString& caption, JMessageBoxButtons button, QWidget* parent)
{
    return Show(content, caption, button, JMessageBoxIcon(0), parent);
}

int JMessageBox::Show(const QString& content, const QString& caption, QWidget* parent)
{
    return Show(content, caption, JMessageBoxButtons(0), parent);
}

int JMessageBox::Show(const QString& content, QWidget* parent)
{
    return Show(content, " ", parent);
}
