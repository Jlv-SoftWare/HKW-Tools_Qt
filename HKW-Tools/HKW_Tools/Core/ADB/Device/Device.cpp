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

float Device::AndroidVersion() const
{
	return static_cast<float>(std::stof(Terminal::Run(Server::AdbPath() + " -s " + _name + " shell getprop ro.build.version.release").Output()));
}

std::string Device::Model() const
{
	return Terminal::Run(Server::AdbPath() + " -s " + _name + " shell getprop ro.product.model").Output();
}

std::string Device::GetModel(const std::string& deviceID)
{
	checkDevice(deviceID);
	return Terminal::Run(Server::AdbPath() + " -s " + deviceID + " shell getprop ro.product.model").Output();
}

std::string Device::Manufacturer() const
{
	return Terminal::Run(Server::AdbPath() + " -s " + _name + " shell getprop ro.product.manufacturer").Output();
}

std::string Device::GetManufacturer(const std::string& deviceID)
{
	checkDevice(deviceID);
	return Terminal::Run(Server::AdbPath() + " -s " + deviceID + " shell getprop ro.product.manufacturer").Output();
}

std::string Device::CPU_Info() const
{
	return Terminal::Run(Server::AdbPath() + " -s " + _name + " shell cat /proc/cpuinfo").Output();
}

std::string Device::GetCPU_Info(const std::string& deviceID)
{
	checkDevice(deviceID);
	return Terminal::Run(Server::AdbPath() + " -s " + deviceID + " shell cat /proc/cpuinfo").Output();
}

std::string Device::Storage_Space() const
{
	return Terminal::Run(Server::AdbPath() + " -s " + _name + " shell cat /proc/meminfo").Output();
}

std::string Device::GetStorage_Space(const std::string& deviceID)
{
	checkDevice(deviceID);
	return Terminal::Run(Server::AdbPath() + " -s " + deviceID + " shell cat /proc/meminfo").Output();
}

std::string Device::Battery_Info() const
{
	return Terminal::Run(Server::AdbPath() + " -s " + _name + " shell dumpsys battery").Output();
}

std::string Device::GetBattery_Info(const std::string& deviceID)
{
	checkDevice(deviceID);
	return Terminal::Run(Server::AdbPath() + " -s " + deviceID + " shell dumpsys battery").Output();
}

short Device::Dpi() const
{
	return static_cast<short>(std::stof(StringBox(Terminal::Run(Server::AdbPath() + " -s " + _name + " shell wm density").Output()).Split(": ").back().String()));
}

short Device::NormalDpi() const
{
	std::vector<StringBox> data = StringBox(Terminal::Run(Server::AdbPath() + " -s " + _name + " shell wm density").Output()).Split(": ");
	if (static_cast<int>(data.size()) < 4)
	{
		return static_cast<short>(std::stof(data[1].String()));
	}
	else
	{
		return static_cast<short>(std::stof(data.back().String()));
	}
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

std::string Device::WindowSize() const
{
	return StringBox(Terminal::Run(Server::AdbPath() + " -s " + _name + " shell wm size").Output()).Split(": ").back().String();
}

std::string Device::NormalWindowSize() const
{
	std::vector<StringBox> data = StringBox(Terminal::Run(Server::AdbPath() + " -s " + _name + " shell wm size").Output()).Split(": ");
	if (static_cast<int>(data.size()) < 4)
	{
		return data[1].String();
	}
	else
	{
		return data.back().String();
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
	for (Device device : List())
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
	for (Device dev : List())
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
	for (Device device : List())
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
		for (StringBox item : sources.Split('\n'))
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
