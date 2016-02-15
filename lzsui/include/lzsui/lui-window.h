#pragma once
#include "stdafx.h"

namespace lui
{
	class LICanvas;
	class LuiView;
	class LuiViewController;

	class LuiWindow {
	public:
		~LuiWindow();
		void ShowWindow(int nCmdShow);
		//void ShowWindow(bool visible);
		void UpdateWindow();

		//handle to window messages 
		void OnSize(WPARAM wParam, LPARAM lParam);
		void OnPaint(WPARAM wParam, LPARAM lParam);

		bool SetViewController(std::shared_ptr<LuiViewController> viewCtrl);
		auto GetViewController();

	protected:
		LuiWindow(HWND hWnd);

		//will do internal things
		void DoPaint(RECT rc);
	protected:
		enum Wnd_Size_State {SS_OTHER = 0, SS_MINIMIZE, SS_MAXIMIZE};
		//HINSTANCE hInstance_;
		HWND hWnd_;
		std::unique_ptr<LICanvas> canvas_;
		SIZE clientSize_;
		Wnd_Size_State sizeState_;
		HBITMAP bm;

		std::shared_ptr<LuiViewController> viewController_;
		static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
		friend class LuiWindowFactory; //make sure only the LuiWindowFactory can create LuiWindow instance
	};

	

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