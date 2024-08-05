#include "../StringBox.h"
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <cwchar>
#include <cstdlib>
#include <cstring>
#include <sstream>

using namespace HKW_Tools::Data;

std::string StringBox::WideString2String(const std::wstring& wstr)
{
	return std::string(wstr.begin(), wstr.end());
}

std::wstring StringBox::String2WideString(const std::string& str)
{
	return std::wstring(str.begin(), str.end());
}

std::string StringBox::CharPtrString2String(const char* str)
{
	return std::string(str);
}

char* StringBox::String2CharPtrString(const std::string& str)
{
	int len = static_cast<int>(str.length());
	char* p = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		p[i] = str[i];
	}
	p[len] = '\0';
	return p;
}

std::string StringBox::String() const
{
	return _dataString;
}

std::wstring StringBox::WideString() const
{
	return String2WideString(_dataString);
}

wchar_t* StringBox::WideCharPtrString() const
{
	return CharPtrString2WideCharPtrString(_dataString.c_str());
}

char* StringBox::CharPtrString() const
{
	return String2CharPtrString(_dataString);
}

char* StringBox::WideCharPtrString2CharPtrString(const wchar_t* str)
{
	size_t len = std::wcstombs(nullptr, str, 0);
	if (len == static_cast<size_t>(-1)) 
	{
		return nullptr;
	}
	char* dest = new char[len + 1];
	std::wcstombs(dest, str, len);
	dest[len] = '\0';
	return dest;

}

wchar_t* StringBox::CharPtrString2WideCharPtrString(const char* str)
{
	size_t len = mbstowcs(nullptr, str, 0);
	if (len == static_cast<size_t>(-1)) 
	{
		return nullptr;
	}
	wchar_t* dest = new wchar_t[len + 1];
	mbstowcs(dest, str, len);
	dest[len] = L'\0';
	return dest;
}


std::vector<StringBox> StringBox::Split() const
{
	const char delimiter = ' ';
	std::vector<StringBox> tokens;
	std::string token;
	std::istringstream tokenStream(_dataString);
	while (std::getline(tokenStream, token, delimiter)) {
		tokens.push_back(token);
	}
	tokens.erase(std::remove(tokens.begin(), tokens.end(), StringBox("")), tokens.end());
	return tokens;
}

std::vector<StringBox> StringBox::Split(const std::string& delimiter) const
{
	std::vector<StringBox> tokens;
	size_t pos = 0;
	size_t lastPos = 0;
	while ((pos = _dataString.find(delimiter, lastPos)) != std::string::npos) {
		tokens.push_back(_dataString.substr(lastPos, pos - lastPos));
		lastPos = pos + delimiter.length();
	}
	tokens.push_back(_dataString.substr(lastPos));
	tokens.erase(std::remove(tokens.begin(), tokens.end(), StringBox("")), tokens.end());
	return tokens;
}

std::vector<StringBox> StringBox::Split(const std::wstring& delimiter) const
{
	std::vector<StringBox> tokens;
	size_t pos = 0;
	size_t lastPos = 0;
	while ((pos = _dataString.find(std::string(delimiter.begin(), delimiter.end()), lastPos)) != std::wstring::npos)
	{
		tokens.push_back(_dataString.substr(lastPos, pos - lastPos));
		lastPos = pos + delimiter.length();
	}
	tokens.push_back(_dataString.substr(lastPos));
	tokens.erase(std::remove(tokens.begin(), tokens.end(), StringBox("")), tokens.end());
	return tokens;
}

std::vector<StringBox> StringBox::Split(const wchar_t* delimiter) const
{
	std::vector<StringBox> tokens;
	size_t pos = 0;
	size_t lastPos = 0;
	while ((pos = _dataString.find(WideCharPtrString2CharPtrString(delimiter), lastPos)) != std::wstring::npos)
	{
		tokens.push_back(_dataString.substr(lastPos, pos - lastPos));
		lastPos = pos + std::string(WideCharPtrString2CharPtrString(delimiter)).length();
	}
	tokens.push_back(_dataString.substr(lastPos));
	tokens.erase(std::remove(tokens.begin(), tokens.end(), StringBox("")), tokens.end());
	return tokens;
}

std::vector<StringBox> StringBox::Split(const char* delimiter) const
{
	std::vector<StringBox> tokens;
	size_t pos = 0;
	size_t lastPos = 0;
	while ((pos = _dataString.find(delimiter, lastPos)) != std::wstring::npos)
	{
		tokens.push_back(_dataString.substr(lastPos, pos - lastPos));
		lastPos = pos + std::string(delimiter).length();
	}
	tokens.push_back(_dataString.substr(lastPos));
	tokens.erase(std::remove(tokens.begin(), tokens.end(), StringBox("")), tokens.end());
	return tokens;
}

std::vector<StringBox> StringBox::Split(const char& delimiter) const
{
	std::vector<StringBox> tokens;
	std::string token;
	std::istringstream tokenStream(_dataString);
	while (std::getline(tokenStream, token, delimiter)) {
		tokens.push_back(token);
	}
	tokens.erase(std::remove(tokens.begin(), tokens.end(), StringBox("")), tokens.end());
	return tokens;
}

std::vector<StringBox> StringBox::Split(const StringBox& delimiter) const
{
	std::vector<StringBox> tokens;
	size_t pos = 0;
	size_t lastPos = 0;
	while ((pos = _dataString.find(delimiter._dataString, lastPos)) != std::string::npos) {
		tokens.push_back(_dataString.substr(lastPos, pos - lastPos));
		lastPos = pos + delimiter._dataString.length();
	}
	tokens.push_back(_dataString.substr(lastPos));
	tokens.erase(std::remove(tokens.begin(), tokens.end(), StringBox("")), tokens.end());
	return tokens;
}




bool StringBox::Contains(const std::string& value) const
{
	return _dataString.find(value) != std::string::npos;
}

bool StringBox::Contains(const std::wstring& value) const
{
	return _dataString.find(WideString2String(value)) != std::string::npos;
}

bool StringBox::Contains(const wchar_t* value) const
{
	return _dataString.find(WideCharPtrString2CharPtrString(value)) != std::string::npos;
}

bool StringBox::Contains(const char* value) const
{
	return _dataString.find(value) != std::string::npos;
}

bool StringBox::Contains(const char& value) const
{
	return _dataString.find(value) != std::string::npos;
}

bool StringBox::Contains(const StringBox& value) const
{
	return _dataString.find(value._dataString) != std::string::npos;
}

bool StringBox::StartsWith(const std::string& value) const
{
	if (_dataString.length() > _dataString.length()) 
	{
		return false;
	}
	return _dataString.compare(0, value.length(), value) == 0;
}

bool StringBox::StartsWith(const std::wstring& value) const
{
	if (_dataString.length() > _dataString.length())
	{
		return false;
	}
	std::string valueString = this->WideString2String(value);
	return _dataString.compare(0, valueString.length(), valueString) == 0;
}

bool StringBox::StartsWith(const wchar_t* value) const
{
	if (_dataString.length() > _dataString.length())
	{
		return false;
	}
	std::string valueString = this->WideCharPtrString2CharPtrString(value);
	return _dataString.compare(0, valueString.length(), valueString) == 0;
}

bool StringBox::StartsWith(const char* value) const
{
	if (_dataString.length() > _dataString.length())
	{
		return false;
	}
	std::string valueString = value;
	return _dataString.compare(0, valueString.length(), valueString) == 0;
}

bool StringBox::StartsWith(const char& value) const
{
	if (_dataString.length() > _dataString.length())
	{
		return false;
	}
	std::string valueString = std::string(1, value);
	return _dataString.compare(0, valueString.length(), valueString) == 0;
}

bool StringBox::StartsWith(const StringBox& value) const
{
	if (_dataString.length() > _dataString.length())
	{
		return false;
	}
	std::string valueString = value._dataString;
	return _dataString.compare(0, valueString.length(), valueString) == 0;
}


StringBox StringBox::Append(const std::string& str) const
{
	return StringBox(_dataString + str);
}

StringBox StringBox::Append(const std::wstring& str) const
{
	return StringBox(_dataString + WideString2String(str));
}

StringBox StringBox::Append(const wchar_t* str) const
{
	return StringBox(_dataString + WideCharPtrString2CharPtrString(str));
}

StringBox StringBox::Append(const char& str) const
{
	return StringBox(_dataString + str);
}

StringBox StringBox::Append(const char* str) const
{
	return StringBox(_dataString + str);
}

StringBox StringBox::Append(const StringBox& superStr) const
{
	return StringBox(_dataString + superStr._dataString);
}

StringBox StringBox::Remove(const std::string& value) const
{
	std::string out_dataString = _dataString;
	size_t pos = out_dataString.find(value);
	while (pos != std::string::npos)
	{
		out_dataString.erase(pos, value.length());
		pos = out_dataString.find(value, pos);
	}
	return StringBox(out_dataString);
}

StringBox StringBox::Remove(const std::wstring& value) const
{
	std::string string_value(value.begin(), value.end());
	std::string out_dataString = _dataString;
	size_t pos = out_dataString.find(string_value);
	while (pos != std::string::npos)
	{
		out_dataString.erase(pos, value.length());
		pos = out_dataString.find(string_value, pos);
	}
	return StringBox(out_dataString);
}

StringBox StringBox::Remove(const char* value) const
{
	std::string out_dataString = _dataString;
	size_t pos = out_dataString.find(value);
	while (pos != std::string::npos)
	{
		out_dataString.erase(pos, strlen(value));
		pos = out_dataString.find(value, pos);
	}
	return StringBox(out_dataString);
}

StringBox StringBox::Remove(const char& value) const
{
	std::string out_dataString = _dataString;
	size_t pos = out_dataString.find(value);
	while (pos != std::string::npos)
	{
		out_dataString.erase(pos, 1);
		pos = out_dataString.find(value, pos);
	}
	return StringBox(out_dataString);
}

StringBox StringBox::Remove(const wchar_t* value) const
{
	std::string string_value(WideCharPtrString2CharPtrString(value));
	std::string out_dataString = _dataString;
	size_t pos = out_dataString.find(string_value);
	while (pos != std::string::npos)
	{
		out_dataString.erase(pos, strlen(WideCharPtrString2CharPtrString(value)));
		pos = out_dataString.find(string_value, pos);
	}
	return StringBox(out_dataString);
}

StringBox StringBox::Remove(const StringBox& value) const
{
	std::string out_dataString = _dataString;
	size_t pos = out_dataString.find(value._dataString);
	while (pos != std::string::npos)
	{
		out_dataString.erase(pos, value._dataString.length());
		pos = out_dataString.find(value._dataString, pos);
	}
	return StringBox(out_dataString);
}

StringBox StringBox::Remove(const int& startIndex) const
{
	if (startIndex < 0)
	{
		throw std::runtime_error("startIndex 小于零");
	}
	if (startIndex > static_cast<int>(_dataString.length()))
	{
		throw std::runtime_error("startIndex 指定不在此字符串中的位置");
	}
	return StringBox(_dataString.erase(startIndex));
}

StringBox StringBox::Remove(const int& startIndex, const int& count) const
{
	if (startIndex < 0 || count < 0)
	{
		throw std::runtime_error("startIndex 或 count 小于零");
	}
	if (startIndex > static_cast<int>(_dataString.length()) || count > static_cast<int>(_dataString.length()))
	{
		throw std::runtime_error("startIndex 加 count 指定此实例之外的位置");
	}
	return StringBox(_dataString.erase(startIndex, count));
}

StringBox StringBox::ToUpper() const
{
	std::string result = _dataString;
	std::transform(result.begin(), result.end(), result.begin(),
		[](unsigned char c) { return std::toupper(c); });
	return StringBox(result);
}

StringBox HKW_Tools::Data::StringBox::ToLower() const
{
	std::string result = _dataString;
	std::transform(result.begin(), result.end(), result.begin(),
		[](unsigned char c) { return std::tolower(c); });
	return StringBox(result);
}

bool StringBox::EndsWith(const std::string& value) const
{
	if (_dataString.length() > _dataString.length())
	{
		return false;
	}
	return _dataString.compare(_dataString.length() - value.length(), value.length(), value) == 0;
}

bool StringBox::EndsWith(const std::wstring& value) const
{
	if (_dataString.length() > _dataString.length())
	{
		return false;
	}
	std::string valueString = this->WideString2String(value);
	return _dataString.compare(_dataString.length() - valueString.length(), valueString.length(), valueString) == 0;
}

bool StringBox::EndsWith(const wchar_t* value) const
{
	if (_dataString.length() > _dataString.length())
	{
		return false;
	}
	std::string valueString = this->WideCharPtrString2CharPtrString(value);
	return _dataString.compare(_dataString.length() - valueString.length(), valueString.length(), valueString) == 0;
}

bool StringBox::EndsWith(const char* value) const
{
	if (_dataString.length() > _dataString.length())
	{
		return false;
	}
	std::string valueString = value;
	return _dataString.compare(_dataString.length() - valueString.length(), valueString.length(), valueString) == 0;
}

bool StringBox::EndsWith(const char& value) const
{
	if (_dataString.length() > _dataString.length())
	{
		return false;
	}
	std::string valueString = std::string(1, value);
	return _dataString.compare(_dataString.length() - valueString.length(), valueString.length(), valueString) == 0;
}

bool StringBox::EndsWith(const StringBox& value) const
{
	if (_dataString.length() > _dataString.length())
	{
		return false;
	}
	std::string valueString = value._dataString;
	return _dataString.compare(_dataString.length() - valueString.length(), valueString.length(), valueString) == 0;
}
