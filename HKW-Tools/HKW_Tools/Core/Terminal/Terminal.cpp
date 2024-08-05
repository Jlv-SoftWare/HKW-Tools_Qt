#include "../Terminal.h"
#include "../../Data/CmdResult.h"
#include <iostream>
#include <array>
#include <string>
#if defined(_WIN32)
#include <Windows.h>
#endif


using namespace HKW_Tools::Core;

void HKW_Tools::Core::Terminal::Purn()
{
    FILE* pipe = _popen("chcp 936>nul", "r");
    _pclose(pipe);
}

#if defined(_WIN32)
CmdResult Terminal::Run(const std::string& command, const bool utf8)
{
    std::array<char, 128> buffer{};
    std::string stdout_str;
    int exit_code = -1;
    const std::string inputCommand = utf8 ? ("cmd /c chcp 65001>nul && " + command).c_str() : command.c_str();

    FILE* pipe = _popen(inputCommand.c_str(), "r");
    if (!pipe)
    {
        throw std::runtime_error("管道创建失败");
    }

    // 读数据
    while (!feof(pipe))
    {
        if (fgets(buffer.data(), 128, pipe) != nullptr)
        {
            stdout_str += buffer.data();
        }
    }

    // 关掉管道并获取退出代码
    exit_code = _pclose(pipe);
    if (utf8)
    {
        if (static_cast<int>(GetUserDefaultUILanguage()) == 2052)
        {
            Purn();
        }
    }

    //返回CmdResult类型(输出和退出代码)
    return CmdResult(stdout_str, exit_code);

}
#else
CmdResult Terminal::Run(const std::string& command)
{
    std::array<char, 128> buffer{};
    std::string stdout_str;
    int exit_code = -1;

    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe)
    {
        throw std::runtime_error("管道创建失败");
    }

    // 读数据
    while (!feof(pipe))
    {
        if (fgets(buffer.data(), 128, pipe) != nullptr)
        {
            stdout_str += buffer.data();
        }
    }

    // 关掉管道并获取退出代码
    exit_code = pclose(pipe);

    //返回CmdResult类型(输出和退出代码)
    return CmdResult(stdout_str, exit_code);

}
#endif

std::string Terminal::Input(const std::string& tips)
{
    std::string outPut;
    std::cout << tips;
    getline(std::cin, outPut);
    return outPut;
}