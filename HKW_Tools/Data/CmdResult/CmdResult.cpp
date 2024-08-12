#include "../CmdResult.h"

using namespace HKW_Tools::Data;

CmdResult::CmdResult()
{
    _outPut.clear();
    _exitCode_ptr = 0;
}

CmdResult::CmdResult(const std::string& out, const int exitCode)
{
    _outPut = out;
    CopyInt(&exitCode);
}

CmdResult::CmdResult(const CmdResult& cmdresult)
{
    _outPut = cmdresult._outPut;
    CopyInt(cmdresult._exitCode_ptr);
}

void CmdResult::CopyInt(const int* num_ptr)
{
    _exitCode_ptr = new int;
    memcpy(_exitCode_ptr, num_ptr, sizeof(int));
}

std::string CmdResult::Output() const
{
    return _outPut;
}

int CmdResult::ExitCode() const
{
    return *_exitCode_ptr;
}