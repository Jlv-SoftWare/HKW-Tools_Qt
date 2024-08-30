#include <iostream>
#include <array>
#include <string>
#include "../Terminal.h"
#include "../../Data/CmdResult.h"
#include "../../Data/ErrMessage.h"
#include "../../Data/StringBox.h"

using namespace HKW_Tools::Core;

CmdResult Terminal::Run(const std::string& command)
{
    std::array<char, 128> buffer{};
    std::string stdout_str;
    int exit_code = -1;
    std::string inputCommand;

#if defined(_WIN32)
    inputCommand = "cmd /c chcp 65001>nul && " + command;
    FILE* pipe = _popen(inputCommand.c_str(), "r");
#else
    inputCommand = command;
    FILE* pipe = popen(inputCommand.c_str(), "r");
#endif
    
    if (!pipe)
    {
        throw ErrMessage("管道创建失败");
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
#if defined(_WIN32)
    exit_code = _pclose(pipe);
#else
    exit_code = pclose(pipe);
#endif
    
    
    //返回CmdResult类型(输出和退出代码)
    return CmdResult(stdout_str, exit_code);
}


std::string Terminal::Input(const std::string& tips)
{
    std::string outPut;
    std::cout << tips;
    getline(std::cin, outPut);
    return outPut;
}
