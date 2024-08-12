#include <filesystem>
#include "../../../Core/Terminal.h"
#include "../../ADB.h"

namespace fs = std::filesystem;

using namespace HKW_Tools::Core;
using namespace ADB;

std::vector<std::string> App::PackageList(const std::string& deviceID, const std::string findMode)
{
	std::string command = Server::AdbPath() + " -s " + deviceID + " shell pm list packages " + findMode;
	CmdResult result = Terminal::Run(command);
	if (result.ExitCode() != 0)
	{
		throw ErrMessage("列表获取失败");
	}
	 std::vector<StringBox> packageList_stringbox = StringBox(result.Output()).Remove("package:").Split("\n");
	 std::vector<std::string> packageList;
	 for (StringBox package : packageList_stringbox)
	 {
		 packageList.push_back(package.String());
	 }
	 return packageList;
	
}

std::vector<std::string> App::PackageList(const Device& device, const std::string findMode)
{
	std::string command = Server::AdbPath() + " -s " + device.ID() + " shell pm list packages " + findMode;
	CmdResult result = Terminal::Run(command);
	if (result.ExitCode() != 0)
	{
		throw ErrMessage("列表获取失败");
	}
	std::vector<StringBox> packageList_stringbox = StringBox(result.Output()).Remove("package:").Split("\n");
	std::vector<std::string> packageList;
	for (StringBox package : packageList_stringbox)
	{
		packageList.push_back(package.String());
	}
	return packageList;
}

bool App::Have(const std::string& deviceID, const std::string& appPackage)
{
	for (std::string package : PackageList(deviceID))
	{
		if (package == appPackage)
		{
			return true;
		}
	}
	return false;
}

bool HKW_Tools::Core::ADB::App::Have(const Device& device, const std::string& appPackage)
{
	for (std::string package : PackageList(device.ID()))
	{
		if (package == appPackage)
		{
			return true;
		}
	}
	return false;
}

CmdResult App::Install(const std::string& deviceID, const std::string& apkPath)
{
	if (!fs::exists(apkPath) || fs::is_directory(apkPath))
	{
		throw Data::ErrMessage("找不到" + apkPath + "或是一个文件夹 ");
	}
	if (ADB::Device::Have(deviceID) || ADB::Device::GetStatus(deviceID) != ADB::Device::device)
	{
		throw Data::ErrMessage("指定的设备不存在或无效");
	}
	return Terminal::Run(Server::AdbPath() + " -s " + deviceID + " install -r -t -d \"" + apkPath + "\"");
}

CmdResult App::Install(const Device& device, const std::string& apkPath)
{
	if (!fs::exists(apkPath) || fs::is_directory(apkPath))
	{
		throw Data::ErrMessage("找不到" + apkPath + "或是一个文件夹 ");
	}
	if (device.Status() != ADB::Device::device)
	{
		throw Data::ErrMessage("指定的设备无效");
	}
	std::string command = Server::AdbPath() + " -s " + device.ID() + " install -r -t -d \"" + apkPath + "\"";
	return Terminal::Run(command);
}

CmdResult App::Uninstall(const std::string& deviceID, const std::string& appPackage, const bool keepData)
{
	if (!Have(deviceID, appPackage))
	{
		throw ErrMessage("没有" + appPackage + "这个应用");
	}
	std::string command = !keepData ? Server::AdbPath() + " -s " + deviceID + " uninstall " + appPackage : 
		                              Server::AdbPath() + " -s " + deviceID + " shell cmd package uninstall -k " + appPackage;
	return Terminal::Run(command);
}

CmdResult App::Uninstall(const Device& device, const std::string& appPackage, const bool keepData)
{
	if (!Have(device, appPackage))
	{
		throw ErrMessage("没有" + appPackage + "这个应用");
	}
	std::string command = !keepData ? Server::AdbPath() + " -s " + device.ID() + " uninstall " + appPackage :
		Server::AdbPath() + " -s " + device.ID() + " shell cmd package uninstall -k " + appPackage;
	return Terminal::Run(command);
}
