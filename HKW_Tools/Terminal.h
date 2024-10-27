#pragma once
#include <iostream>
#include "./CmdResult.h"

namespace HKW_Tools
{
    namespace Core
    {
        using namespace Data;
        class Terminal
        {
        public:
            static CmdResult Run(const std::string& command);
            static std::string Input(const std::string& tips = "");

        };
    }
}
