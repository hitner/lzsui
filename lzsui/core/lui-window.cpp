#include "stdafx.h"
#include "lui-window.h"
#include "utility\lzs-debug.hpp"
namespace lui
{

	LuiWindow::LuiWindow(HWND hWnd)
		: hWnd_(hWnd)
	{
		assert(hWnd_);
	}
	LuiWindow::~LuiWindow()
	{
	}
	//------------------------------\\
	// the most important WndProc   \\
	//------------------------------\\

	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		return 0;
	}

	//------------------\\
	// LuiWindowFactory \\
	//------------------\\

	LuiWindowFactory::LuiWindowFactory()
		:hInstance_(NULL)
		,atom_(0)
	{
	}

	void LuiWindowFactory::registerWindowClass()
	{
		WNDCLASSEX wcex;
		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
		wcex.lpfnWndProc = WndProc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = hInstance_;
		wcex.hCursor = ::LoadCursor(NULL, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wcex.lpszClassName = C_RegisterClassName;
		wcex.lpszMenuName = NULL;
		wcex.hIconSm = NULL; //will be set later
		wcex.hIcon = NULL; //will be set later
		atom_ = ::RegisterClassEx(&wcex);
		SystemFunctionAssert(atom_);
	}
	HWND LuiWindowFactory::createWindow()
	{
		assert(atom_);
		HWND hWnd = ::CreateWindowEx(WS_EX_LAYERED, 
			(LPCWSTR)atom_, L"lzsui_window",
			 WS_TABSTOP | WS_OVERLAPPED, 
			CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance_, NULL); //default size overlapped window with layered
		SystemFunctionAssert(hWnd);
		return hWnd;
	}
	LuiWindowFactory * LuiWindowFactory::Instance()
	{
		static LuiWindowFactory staticWindowFactory;
		return &staticWindowFactory;
	}
	bool LuiWindowFactory::Init(HINSTANCE hInstance)
	{
		hInstance_ = hInstance;
		assert(hInstance);
		return true;
	}
	std::shared_ptr<LuiWindow> LuiWindowFactory::CreateLuiWindow()
	{
		if (atom_ == 0) {
			registerWindowClass();
		}
		if (atom_ == 0) {
			return NULL;
		}
		HWND hWnd = createWindow();
		return std::shared_ptr<LuiWindow>(new LuiWindow(hWnd));
	}
}