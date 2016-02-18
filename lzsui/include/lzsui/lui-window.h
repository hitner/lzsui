#pragma once
#include "stdafx.h"
#include "l-common.h"

namespace lui
{
	class LICanvas;
	class LuiView;
	//class LuiViewController;

	class LuiWindow {
	public:
		~LuiWindow();
		void ShowWindow(int nCmdShow);
		//void ShowWindow(bool visible);
		void UpdateWindow();

		void LuiWindow::SetView(std::shared_ptr<LuiView> view);
		auto View();

		//handle to window messages 
		void OnSize(WPARAM wParam, LPARAM lParam);
		void OnPaint(WPARAM wParam, LPARAM lParam);

	protected:
		LuiWindow(HWND hWnd);

		//will do internal things
		void DoPaint(RECT rc);
	public:
		//std::shared_ptr<LuiViewController> viewController_;
	protected:
		enum Wnd_Size_State {SS_OTHER = 0, SS_MINIMIZE, SS_MAXIMIZE};
		//HINSTANCE hInstance_;
		HWND hWnd_;
		std::shared_ptr<LICanvas> canvas_;
		LSize clientSize_;
		Wnd_Size_State sizeState_;
		std::shared_ptr<LuiView> view_;

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