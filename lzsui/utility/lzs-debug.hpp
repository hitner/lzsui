#pragma once
#include <Windows.h>
#include <tchar.h>
#include <cassert>

#ifdef _DEBUG
inline void PrintToVSOutputWindow(wchar_t * format, ...)
{
	va_list args;
	va_start(args, format);
	WCHAR buf[2560];
	_vstprintf_s(buf, 2560, format, args);
	::OutputDebugString(buf);
	va_end(args);
}
#else
inline void PrintToVSOutputWindow(wchar_t * format, ...)
{ }
#endif

#ifdef _DEBUG
inline void PrintLastErrorMessage()
{
	DWORD dwError = ::GetLastError();
	HLOCAL hLocal = NULL;
	BOOL fOk = ::FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_ALLOCATE_BUFFER,
		NULL, dwError, MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL), (LPWSTR)&hLocal, 0, NULL);
	if (fOk && (hLocal != NULL)) {
		::OutputDebugString((LPCWSTR)LocalLock(hLocal));
		::LocalUnlock(hLocal);
		HLOCAL hRet = ::LocalFree(hLocal);
		assert(hRet == NULL);
	}
}
#else
inline void PrintLastErrorMessage()
{
}
#endif


#ifdef _DEBUG
#define SystemFunctionAssert(x) \
while ( !(x) ) {\
	PrintLastErrorMessage();\
	assert(false);\
	break;\
}
#else
#define SystemFunctionAssert(x) __noop;
#endif