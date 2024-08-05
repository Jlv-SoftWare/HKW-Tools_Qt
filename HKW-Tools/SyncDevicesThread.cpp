#include "syncDevicesThread.h"
#include "HKW_Tools.h"
#include <QMessageBox>

using namespace HKW_Tools::Core;

void SyncDevicesThread::run()
{
	while (!is_exit_)
	{
        emit I_Need_Combo();
        std::vector<ADB::Device> deviceList = ADB::Device::List();
        emit send_showNumOfDevices_Lable_Text((std::string("当前连接了 ") + std::to_string(static_cast<int>(deviceList.size())) + std::string(" 个设备")).c_str());
        if (static_cast<int>(ADB::Device::List().size()) != 0)
        {
            for (ADB::Device device : deviceList)
            {
                for (QString deviceOnCombo : _comboList)
                {
                    if (!containsItem(_comboList, device.ID().c_str()))
                    {
                        emit addID(QString(device.ID().c_str()));
                    }
                    if (!ADB::Device::Have(deviceOnCombo.toStdString()))
                    {
                        emit removeID(deviceOnCombo);
                    }
                }
            }
        }
        else
        {
            if (!containsItem(_comboList, QString("无")))
            {
                emit clearIDs();
                emit addID("无");
            }
        }
        QThread::sleep(5);
	}
}



bool SyncDevicesThread::containsItem(const std::vector<QString> list, const QString& value)
{
    return std::find(list.begin(), list.end(), value) != list.end();
}

void SyncDevicesThread::getCombo(const std::vector<QString>& list)
{
    _comboList.clear();
    _comboList = list;
}

SyncDevicesThread::~SyncDevicesThread()
{
    stop();
}

void SyncDevicesThread::stop()
{
    is_exit_ = true;
}
