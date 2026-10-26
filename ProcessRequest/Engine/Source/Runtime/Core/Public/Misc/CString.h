#pragma once

#include "HAL/PlatformString.h"

struct FCString
{
	static int32 Strcmp(const TCHAR* String1, const TCHAR* String2)
	{
		return _tcscmp(String1, String2);
	}

	static int32 Strlen(const TCHAR* String)
	{
		return (int32)_tcslen(String);
	}

	static const TCHAR* Strstr(const TCHAR* String, const TCHAR* Find)
	{
		return _tcsstr(String, Find);
	}

	static TCHAR* Strstr(TCHAR* String, const TCHAR* Find)
	{
		return (TCHAR*)_tcsstr(String, Find);
	}

	static const TCHAR* Strchr(const TCHAR* String, TCHAR c)
	{
		return _tcschr(String, c);
	}

	static TCHAR* Strchr(TCHAR* String, TCHAR c)
	{
		return (TCHAR*)_tcschr(String, c);
	}
};
