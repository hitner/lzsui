#pragma once
#include "stdafx.h"

namespace lui
{
	class LuiWindow {
	public:
		~LuiWindow();
	protected:
		LuiWindow(HWND hWnd);


	protected:
		//HINSTANCE hInstance_;
		HWND hWnd_;

		friend class LuiWindowFactory; //make sure only the LuiWindowFactory can create LuiWindow instance
	};

	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	class LuiWindowFactory
	{
	public:
		static LuiWindowFactory * Instance();
		bool Init(HINSTANCE hInstance);
		std::shared_ptr<LuiWindow> CreateLuiWindow();
	protected:
		LuiWindowFactory();
		void registerWindowClass();
		HWND createWindow();

		LPCTSTR C_RegisterClassName = L"LZSUI_WND_REGISTER_NAME";

		HINSTANCE hInstance_;
		ATOM atom_;
	};
}