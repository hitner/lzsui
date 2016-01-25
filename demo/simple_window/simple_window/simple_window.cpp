#include "stdafx.h"
#include <lzsui/lui-library.h>
#include "SimpleWindowDelegate.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	SimpleWindowDelegate windowDelegate;
	return lui::LuiRunApplication(hInstance, nCmdShow, windowDelegate);
}