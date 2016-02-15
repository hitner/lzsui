#pragma once
#include <memory>
#include <lzsui\lui-application.h>
#include <lzsui\lui-window.h>

using namespace lui;
class SimpleWindowDelegate : public LuiApplicationDelegate {
public:
	virtual void WillEnterGetMessageLoop(int nCmdShow) override;
	//virtual  LuiWindowInfo GetWindowInfo();
	//virtual void DidCreateWindow(std::shared_ptr<LuiWindow> lWindow) override;
protected:
	std::shared_ptr<LuiWindow> hostWindow_;
};