#include "stdafx.h"
#include "lui-window.h"
#include "l-gdi-canvas.h"
#include "utility\lzs-debug.hpp"

using namespace std;
namespace lui
{

	LuiWindow::LuiWindow(HWND hWnd)
		: hWnd_(hWnd)
	{
		assert(hWnd_);
		::SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)this);
		windowCanvas_.reset(new LGdiCanvas(hWnd));
	}
	LuiWindow::~LuiWindow()
	{
	}
	void LuiWindow::OnSize(WPARAM wParam, LPARAM lParam)
	{
		clientSize_.cx = HIWORD(lParam);
		clientSize_.cy = LOWORD(lParam);
		switch (wParam)
		{
		case SIZE_MAXIMIZED: 
			sizeState_ = SS_MAXIMIZE;
			break;
		case SIZE_MINIMIZED:
			sizeState_ = SS_MINIMIZE;
			break;
		default:
			sizeState_ = SS_OTHER;
			break;
		}
		windowCanvas_->OnSize(clientSize_);
	}
	void LuiWindow::ShowWindow(int nCmdShow)
	{
		::ShowWindow(hWnd_, nCmdShow);
	}
	//void LuiWindow::ShowWindow(bool visible)
	//{
	//	::ShowWindow(hWnd_, visible);
	//}
	void LuiWindow::UpdateWindow()
	{
		::UpdateWindow(hWnd_);
	}
	//------------------------------\\
	// the most important WndProc   \\
	//------------------------------\\

	LRESULT CALLBACK LuiWindow::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		LONG_PTR pWnd = ::GetWindowLongPtr(hWnd, GWLP_USERDATA);
		std::shared_ptr<LuiWindow> lWindow(reinterpret_cast<LuiWindow*>(pWnd));
		if (!lWindow) {
			return DefWindowProc(hWnd, message, wParam, lParam);
		}

		switch (message)
		{
		case WM_DESTROY:
			::PostQuitMessage(0);
			break;
		case WM_SIZE:
			lWindow->OnSize(wParam, lParam);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
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
		wcex.lpfnWndProc = LuiWindow::WndProc;
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
		HWND hWnd = ::CreateWindowEx(0, 
			C_RegisterClassName, L"lzsui_window",
			 WS_TABSTOP | WS_OVERLAPPEDWINDOW, //system default style, can be removed later
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