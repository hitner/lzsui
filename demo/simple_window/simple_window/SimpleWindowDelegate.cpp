
#include "lzsui\lui-window.h"
#include "SimpleWindowDelegate.h"

using namespace lui;

void SimpleWindowDelegate::WillEnterGetMessageLoop(int nCmdShow)
{

	hostWindow_ = LuiWindowFactory::Instance()->CreateLuiWindow();
	hostWindow_->ShowWindow(nCmdShow);
	hostWindow_->UpdateWindow();
}
