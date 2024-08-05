#include "../ErrMessage.h"

using namespace HKW_Tools::Data;

const char* ErrMessage::What() const
{
	return _Message.c_str();
}