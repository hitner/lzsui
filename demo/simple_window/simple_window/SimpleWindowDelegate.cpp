
#include "lzsui\lui-window.h"
#include "SimpleWindowDelegate.h"
#include "lzsui\lui-view-controller.h"
#include "lzsui\lui-view.h"
#include "lzsui\lui-image-view.h"
using namespace lui;

void SimpleWindowDelegate::WillEnterGetMessageLoop(int nCmdShow)
{

	hostWindow_ = LuiWindowFactory::Instance()->CreateLuiWindow();
	std::shared_ptr<LuiView> aView(new LuiView(LRect(0, 0, 800, 477)));
	aView->SetBackgroundColor(LColor::RedColor());

	std::shared_ptr<LuiView> bView(new LuiImageView(LRect(10, 10, 500, 400)));
	aView->AddSubview(bView);
	hostWindow_->SetView(aView);
	hostWindow_->ShowWindow(nCmdShow);
	hostWindow_->UpdateWindow();


	//vc->SetView(aView);
	
}
