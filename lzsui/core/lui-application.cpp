#include "stdafx.h"
#include "lui-application.h"
#include "lui-window.h"

using namespace std;
namespace lui {
	
	int LuiRunApplication(HINSTANCE hInstance, int nCmdShow, std::shared_ptr<LuiApplicationDelegate> appDelegate) 
	{
		LuiApplication app(hInstance, nCmdShow, appDelegate);
		return app.run();
	}

	LuiApplication::LuiApplication(HINSTANCE hInstance, int nCmdShow, std::shared_ptr<LuiApplicationDelegate> delegate)
		: hInstance_(hInstance)
		, nCmdShow_(nCmdShow)
		, delegate_(delegate)
	{
		assert(hInstance);
		assert(delegate);
	}

	int LuiApplication::run()
	{
		//rootWindow_ = new LuiWindow;

		return 0;
	}

}








