#include "../../ADB.h"
#include "../../../Data/CmdResult.h"
#include "../../../Data/StringBox.h"
#include "../../Terminal.h"

using namespace HKW_Tools::Core;
using namespace ADB;

std::string Device::device = "device";
std::string Device::offline = "offline";
std::string Device::unauthorized = "unauthorized";

void Device::checkDevice(const std::string& deviceID)
{
	if (!Have(deviceID))
	{
		throw ErrMessage("不存在设备" + deviceID);
	}
	if (GetStatus(deviceID) != Device::device)
	{
		throw ErrMessage("设备" + deviceID + "无效");
	}
}

Device::Device()
{
	_name.clear();
	_status.clear();
}

Device::Device(const std::string& name, const std::string& status)
{
	_name = name;
	_status = status;
}

std::string Device::ID() const
{
	return _name;
}

std::string Device::Status() const
{
	return _status;
}

float Device::GetAndroidVersion(const std::string& deviceID)
{
    return static_cast<float>(std::stof(Terminal::Run(Server::AdbPath() + " -s " + deviceID + " shell getprop ro.build.version.release").Output()));
}

std::string Device::GetModel(const std::string& deviceID)
{
	checkDevice(deviceID);
	return Terminal::Run(Server::AdbPath() + " -s " + deviceID + " shell getprop ro.product.model").Output();
}

std::string Device::GetManufacturer(const std::string& deviceID)
{
	checkDevice(deviceID);
	return Terminal::Run(Server::AdbPath() + " -s " + deviceID + " shell getprop ro.product.manufacturer").Output();
}

std::string Device::GetCPU_Info(const std::string& deviceID)
{
	checkDevice(deviceID);
	return Terminal::Run(Server::AdbPath() + " -s " + deviceID + " shell cat /proc/cpuinfo").Output();
}

std::string Device::GetCPU_Model(const std::string &deviceID)
{
    StringBox* data = new StringBox(GetCPU_Info(deviceID));
    std::string result = data->Split("\n")[4].Remove("model name	: ").String();
    delete data;
    return result;
}

std::string Device::GetStorage_Info(const std::string &deviceID)
{
    checkDevice(deviceID);
    return Terminal::Run(Server::AdbPath() + " -s " + deviceID + " shell df -h /data").Output();
}

std::string Device::GetStorage_Size(const std::string &deviceID)
{
    StringBox* info = new StringBox(GetStorage_Info(deviceID));
    std::string size = info->Split("\n")[1].Split()[1].String();
    delete info;
    return size;
}

std::string Device::GetStorage_Used(const std::string &deviceID)
{
    StringBox* info = new StringBox(GetStorage_Info(deviceID));
    std::string size = info->Split("\n")[1].Split()[2].String();
    delete info;
    return size;
}

std::string Device::GetStorage_Avail(const std::string &deviceID)
{
    StringBox* info = new StringBox(GetStorage_Info(deviceID));
    std::string size = info->Split("\n")[1].Split()[3].String();
    delete info;
    return size;
}

unsigned short Device::GetStorage_UsePercent(const std::string &deviceID)
{
    StringBox* info = new StringBox(GetStorage_Info(deviceID));
    unsigned short size = static_cast<unsigned short>(std::stoi(info->Split("\n")[1].Split()[4].Remove("%").String()));
    delete info;
    return size;
}

std::string Device::GetBattery_Info(const std::string& deviceID)
{
	checkDevice(deviceID);
	return Terminal::Run(Server::AdbPath() + " -s " + deviceID + " shell dumpsys battery").Output();
}

short Device::GetDpi(const std::string& deviceID)
{
	checkDevice(deviceID);
	return static_cast<short>(std::stof(StringBox(Terminal::Run(Server::AdbPath() + " -s " + deviceID + " shell wm density").Output()).Split(": ").back().String()));
}

short Device::GetNormalDpi(const std::string& deviceID)
{
	checkDevice(deviceID);
	std::vector<StringBox> data = StringBox(Terminal::Run(Server::AdbPath() + " -s " + deviceID + " shell wm density").Output()).Split(": ");
	if (static_cast<int>(data.size()) < 4)
	{
		return static_cast<short>(std::stof(data[1].String()));
	}
	else
	{
		return static_cast<short>(std::stof(data.back().String()));
	}
}

std::string Device::GetWindowSize(const std::string& deviceID)
{
	checkDevice(deviceID);
	return StringBox(Terminal::Run(Server::AdbPath() + " -s " + deviceID + " shell wm size").Output()).Split(": ").back().String();
}

std::string Device::GetNormalWindowSize(const std::string& deviceID)
{
	checkDevice(deviceID);
	std::vector<StringBox> data = StringBox(Terminal::Run(Server::AdbPath() + " -s " + deviceID + " shell wm size").Output()).Split(": ");
	if (static_cast<int>(data.size()) < 4)
	{
		return data[1].String();
	}
	else
	{
		return data.back().String();
	}
}

bool Device::TurnOnWirelessDebug(const std::string &deviceID, const std::string &tcpip)
{
    return StringBox(Terminal::Run(Server::AdbPath() + " -s " + deviceID + " tcpip " + tcpip).Output()).StartsWith("restarting in TCP mode port");
}

bool Device::TurnOnWirelessDebug(const Device &device, const std::string &tcpip)
{
    return StringBox(Terminal::Run(Server::AdbPath() + " -s " + device.ID() + " tcpip " + tcpip).Output()).StartsWith("restarting in TCP mode port");
}

bool Device::Have()
{
	return static_cast<int>(List().size()) != 0;
}

bool Device::Have(const std::string& deviceID)
{
	if (static_cast<int>(List().size()) == 0)
	{
		return false;
	}
	for (const auto& device : List())
	{
		if (device.ID() == deviceID)
		{
			return true;
		}
	}
	return false;
}

bool HKW_Tools::Core::ADB::Device::Have(const Device& device)
{
	if (static_cast<int>(List().size()) == 0)
	{
		return false;
	}
	for (const auto& dev : List())
	{
		if (dev.ID() == device.ID())
		{
			return true;
		}
	}
	return false;
}

std::string Device::GetStatus(const std::string& deviceID)
{
	for (const auto& device : List())
	{
		if (device.ID() == deviceID)
		{
			return device.Status();
		}
	}
	return std::string("");
}

std::vector<Device> Device::List()
{
	Data::CmdResult cmdSources = Core::Terminal::Run(Server::AdbPath() + " devices");
	std::vector<Device> devices;
	if (cmdSources.ExitCode() == 0)
	{
		Data::StringBox sources = cmdSources.Output();
		sources = sources.Remove("List of devices attached\n");
		for (const auto& item : sources.Split('\n'))
		{
			std::vector<StringBox> deviceWithStatus = item.Split('\t');
			devices.push_back(Device(deviceWithStatus[0].String(), deviceWithStatus[1].String()));
		}
	}
	if (static_cast<int>(devices.size()) == 0)
	{
		devices.clear();
	}
	return devices;
}

bool Device::Connect(const std::string& ip, const std::string& tcpip)
{
	return StringBox(Terminal::Run(Server::AdbPath() + " connect " + ip + ":" + tcpip).Output()).StartsWith("connect to");
}

bool Device::Pair(const std::string& pairIpWithTcpip, const std::string& pairCode)
{
	return StringBox(Terminal::Run(Server::AdbPath() + " pair " + pairIpWithTcpip + " " + pairCode).Output()).StartsWith("Success");
}
