#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string>
#include <vector>

namespace HKW_Tools
{
	namespace Data
	{
		class StringBox
		{
		protected:
			mutable std::string _dataString;

		private:

			static std::string WideString2String(const std::wstring& wstr);
			static std::wstring String2WideString(const std::string& str);

			static std::string CharPtrString2String(const char* str);
			static char* String2CharPtrString(const std::string& str);

		public:

			StringBox() : _dataString("") {}

			StringBox(const std::string& str) : _dataString(str) {}

			StringBox(const char* str) : _dataString(str) {}

			StringBox(const wchar_t* str) : _dataString(WideCharPtrString2CharPtrString(str)) {}

			StringBox(const std::wstring& str) : _dataString(str.begin(), str.end()) {}

			StringBox(const StringBox& other) : _dataString(other._dataString) {}

			std::string String() const;
			std::wstring WideString() const;
			wchar_t* WideCharPtrString() const;
			char* CharPtrString() const;

			static char* WideCharPtrString2CharPtrString(const wchar_t* str);
			static wchar_t* CharPtrString2WideCharPtrString(const char* str);

			StringBox Append(const std::string& str) const;
			StringBox Append(const std::wstring& str) const;
			StringBox Append(const wchar_t* str) const;
			StringBox Append(const char& str) const;
			StringBox Append(const char* str) const;
			StringBox Append(const StringBox& superStr) const;

			StringBox Remove(const std::string& value) const;
			StringBox Remove(const std::wstring& value) const;
			StringBox Remove(const char* value) const;
			StringBox Remove(const char& value) const;
			StringBox Remove(const wchar_t* value) const;
			StringBox Remove(const StringBox& value) const;

			StringBox Remove(const int& startIndex) const;
			StringBox Remove(const int& startIndex, const int& count) const;

			StringBox ToUpper() const;
			StringBox ToLower() const;

			std::vector<StringBox> Split() const;
			std::vector<StringBox> Split(const std::string& delimiter) const;
			std::vector<StringBox> Split(const std::wstring& delimiter) const;
			std::vector<StringBox> Split(const wchar_t* delimiter) const;
			std::vector<StringBox> Split(const char* delimiter) const;
			std::vector<StringBox> Split(const char& delimiter) const;
			std::vector<StringBox> Split(const StringBox& delimiter) const;


			bool Contains(const std::string& value) const;
			bool Contains(const std::wstring& value) const;
			bool Contains(const wchar_t* value) const;
			bool Contains(const char* value) const;
			bool Contains(const char& value) const;
			bool Contains(const StringBox& value) const;

			bool StartsWith(const std::string& value) const;
			bool StartsWith(const std::wstring& value) const;
			bool StartsWith(const wchar_t* value) const;
			bool StartsWith(const char* value) const;
			bool StartsWith(const char& value) const;
			bool StartsWith(const StringBox& value) const;

			bool EndsWith(const std::string& value) const;
			bool EndsWith(const std::wstring& value) const;
			bool EndsWith(const wchar_t* value) const;
			bool EndsWith(const char* value) const;
			bool EndsWith(const char& value) const;
			bool EndsWith(const StringBox& value) const;
            
            unsigned int Length();



			StringBox operator<<(const std::string& str)
			{
				_dataString += str;
				return *this;
			}

			StringBox operator<<(const std::wstring& str)
			{
				_dataString += WideString2String(str);
				return *this;
			}

			StringBox operator<<(const wchar_t* str)
			{
				_dataString += WideCharPtrString2CharPtrString(str);
				return *this;
			}

			StringBox operator<<(const char* str)
			{
				_dataString += str;
				return *this;
			}

			StringBox operator<<(const char& str)
			{
				_dataString += str;
				return *this;
			}

			StringBox operator<<(const StringBox& superStr)
			{
				_dataString += superStr._dataString;
				return *this;
			}

			StringBox operator<<(const int& numStr)
			{
				_dataString += std::to_string(numStr);
				return *this;
			}



			StringBox operator+(const std::string& str) const
			{
				StringBox plusResult = _dataString + str;
				return plusResult;
			}

			StringBox operator+(const std::wstring& str) const
			{
				StringBox plusResult = _dataString + WideString2String(str);
				return plusResult;
			}

			StringBox operator+(const wchar_t* str) const
			{
				StringBox plusResult = _dataString + WideCharPtrString2CharPtrString(str);
				return plusResult;
			}

			StringBox operator+(const char* str) const
			{
				StringBox plusResult = _dataString + str;
				return plusResult;
			}

			StringBox operator+(const char& str) const
			{
				StringBox plusResult = _dataString + str;
				return plusResult;
			}

			StringBox operator+(const StringBox& superStr) const
			{
				StringBox plusResult = _dataString + superStr._dataString;
				return plusResult;
			}

			StringBox operator+(const int& numStr)
			{
				StringBox plusResult = _dataString + std::to_string(numStr);
				return plusResult;;
			}



			StringBox operator+=(const std::string& str)
			{
				_dataString += str;
				return *this;
			}

			StringBox operator+=(const std::wstring& str)
			{
				_dataString += WideString2String(str);
				return *this;
			}

			StringBox operator+=(const wchar_t* str)
			{
				_dataString += WideCharPtrString2CharPtrString(str);
				return *this;
			}

			StringBox operator+=(const char* str)
			{
				_dataString += str;
				return *this;
			}

			StringBox operator+=(const char& str)
			{
				_dataString += str;
				return *this;
			}

			StringBox operator+=(const StringBox& superStr)
			{
				_dataString += superStr._dataString;
				return *this;
			}

			StringBox operator+=(const int& numStr)
			{
				_dataString += std::to_string(numStr);
				return *this;
			}

			bool operator==(const StringBox& str) const
			{
				return _dataString == str._dataString;
			}

			bool operator==(const std::string& str) const
			{
				return _dataString == str;
			}

			bool operator==(const std::wstring& str) const
			{
				return _dataString == WideString2String(str);
			}

			bool operator==(const char* str) const
			{
				return _dataString == str;
			}

			bool operator==(const wchar_t* str) const
			{
				return _dataString == WideCharPtrString2CharPtrString(str);
			}

			friend std::ostream& operator<<(std::ostream& os, const StringBox& superStr)
			{
				os << superStr._dataString;
				return os;
			}
		};
	}
}
