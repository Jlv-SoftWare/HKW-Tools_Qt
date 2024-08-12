﻿#pragma once
#include "../Data/CmdResult.h"
#include "../Data/StringBox.h"
#include "../Data/ErrMessage.h"

using namespace HKW_Tools::Data;

namespace HKW_Tools
{
	namespace Core
	{
		namespace ADB
		{
			class Device
			{
			protected:
				std::string _name;
				std::string _status;

			private:
				static void checkDevice(const std::string& deviceID);

			public:

				static std::string device;
				static std::string offline;
				static std::string unauthorized;

				Device();
				Device(const std::string& name, const std::string& status);

				std::string ID() const;
				std::string Status() const;

                static float GetAndroidVersion(const std::string& deviceID);

				static std::string GetModel(const std::string& deviceID);
                
				static std::string GetManufacturer(const std::string& deviceID);

				static std::string GetCPU_Info(const std::string& deviceID);
                
                static std::string GetCPU_Model(const std::string& deviceID);
                
                static std::string GetStorage_Info(const std::string& deviceID);
                static std::string GetStorage_Size(const std::string& deviceID);
                static std::string GetStorage_Used(const std::string& deviceID);
                static std::string GetStorage_Avail(const std::string& deviceID);
                static unsigned short GetStorage_UsePercent(const std::string& deviceID);
                
				std::string Battery_Info() const;
				static std::string GetBattery_Info(const std::string& deviceID);

				short Dpi() const;
				short NormalDpi() const;
				static short GetDpi(const std::string& deviceID);
				static short GetNormalDpi(const std::string& deviceID);

				std::string WindowSize() const;
				std::string NormalWindowSize() const;
				static std::string GetWindowSize(const std::string& deviceID);
				static std::string GetNormalWindowSize(const std::string& deviceID);

				static bool Have();
				static bool Have(const std::string& deviceID);
				static bool Have(const Device& device);

				static std::string GetStatus(const std::string& deviceID);

				static std::vector<Device> List();
				static bool Connect(const std::string& ip, const std::string& tcpip = "5555");
				static bool Pair(const std::string& pairIpWithTcpip, const std::string& pairCode);
			};

			class App
			{
			private:
				//static bool SignApk();
			public:

				static std::vector<std::string> PackageList(const std::string& deviceID, const std::string findMode = "");
				static std::vector<std::string> PackageList(const Device& device, const std::string findMode = "");

				static bool Have(const std::string& deviceID, const std::string& appPackage);
				static bool Have(const Device& device, const std::string& appPackage);

				static CmdResult Install(const std::string& deviceID, const std::string& apkPath);
				static CmdResult Install(const Device& device, const std::string& apkPath);

				static CmdResult Uninstall(const std::string& deviceID, const std::string& appPackage, const bool keepData = false);
				static CmdResult Uninstall(const Device& device, const std::string& appPackage, const bool keepData = false);
			};

			class Server
			{
			public:
				static std::string adbPath;

				static bool Start();
				static bool Kill();
				static bool ReStart();

				static std::string AdbPath();
				
				static bool SetAdbPath(const std::string& path);
			};
		}
	}
}
