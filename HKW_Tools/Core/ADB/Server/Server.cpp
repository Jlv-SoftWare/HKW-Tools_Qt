#include <filesystem>
#include "../../ADB.h"
#include "../../../Core/Terminal.h"

namespace fs = std::filesystem;

using namespace HKW_Tools::Core;

std::string ADB::Server::adbPath = "";

bool ADB::Server::Start()
{
	return Terminal::Run(adbPath + " start-server").ExitCode() == 0;
}

bool ADB::Server::Kill()
{
	return Terminal::Run(adbPath + " kill-server").ExitCode() == 0;
}

bool ADB::Server::ReStart()
{
	return Terminal::Run(adbPath + " kill-server").ExitCode() == 0 && Terminal::Run(adbPath + " start-server").ExitCode() == 0;
}

std::string ADB::Server::AdbPath()
{
	return "\"" + adbPath + "\"";
}

bool ADB::Server::SetAdbPath(const std::string& path)
{
	if (StringBox(fs::path(path).stem().string()).ToLower() == "adb" && fs::exists(path) && !fs::is_directory(path))
	{
		adbPath = path; return true;
	}
	return false;
}