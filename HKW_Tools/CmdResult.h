#pragma once
#include <iostream>

namespace HKW_Tools
{
    namespace Data
    {
        class CmdResult
        {
        protected:
            std::string _outPut;
            int* _exitCode_ptr;
        private:
            void CopyInt(const int* num_ptr); //深拷贝int数据到_exitCode_ptr的函数
        public:

            CmdResult();
            CmdResult(const std::string& out, const int exitCode);
            CmdResult(const CmdResult& cmdresult);

            std::string Output() const;
            int ExitCode() const;
        };
    }    
}


