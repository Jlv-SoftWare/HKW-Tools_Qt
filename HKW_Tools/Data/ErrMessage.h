#pragma once
#include <iostream>

namespace HKW_Tools
{
	namespace Data
	{
		class ErrMessage
		{
		private:
			std::string _Message;
		public:
			const char* What() const;

			ErrMessage(const std::string& message) : _Message(message) {}
            ErrMessage(const char* message) : _Message(message) {}
			ErrMessage(const ErrMessage& message) { _Message.clear(); _Message = message._Message; }
		};
	}
}
