#pragma once
#include <iostream>
#include "../Data/CmdResult.h"

namespace HKW_Tools
{
    namespace Core
    {
        using namespace Data;
        class Terminal
        {
        private:
#if defined(_WIN32)
            static void Purn();
#endif
        public:
#if defined(_WIN32)
            static CmdResult Run(const std::string& command, const bool utf8 = true);
#else
            static CmdResult Run(const std::string& command);
#endif
            static std::string Input(const std::string& tips = "");

        };
    }
}
