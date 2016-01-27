#pragma once
#include "stdafx.h"


namespace lui 
{
	class LuiWindow;
	class LuiApplicationDelegate;
	int LuiRunApplication(HINSTANCE hInstance, int nCmdShow, std::shared_ptr<LuiApplicationDelegate> appDelegate);

	
	class LuiApplicationDelegate {
	public:
		struct LuiWindowInfo {
			RECT rect_;
		};
		virtual void WillCreateWindow() {}
		virtual  LuiWindowInfo GetWindowInfo() = 0;
		virtual void DidCreateWindow(std::shared_ptr<LuiWindow> lWindow) {};
		virtual void WillEnterGetMessageLoop() {};
		virtual void WillSendQuitMessage() {};
		virtual void DidEndGetMessageLoop() {};

	};




	class LuiApplication {
	public:
		LuiApplication(HINSTANCE hInstance, int nCmdShow, std::shared_ptr<LuiApplicationDelegate> delegate);
		int run();

	protected:
		HINSTANCE hInstance_;
		int nCmdShow_;
		std::weak_ptr<LuiApplicationDelegate> delegate_;

		std::shared_ptr<LuiWindow> rootWindow_;
		
	};
}