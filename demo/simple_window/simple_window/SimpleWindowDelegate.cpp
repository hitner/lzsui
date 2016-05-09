
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
	aView->SetBorderWidth(2);
	aView->SetBorderColor(LColor::GreenColor());

	std::shared_ptr<LuiView> bView(new LuiImageView(LRect(10, 10, 500, 400)));
	aView->AddSubview(bView);

	std::shared_ptr<LuiView> cc(new LuiView(LRect(530, 100, 30, 20)));
	cc->SetBackgroundColor(LColor::TransparentColor());
	cc->SetBorderColor(LColor::BlueColor());
	cc->SetBorderWidth(5);
	aView->AddSubview(cc);

	hostWindow_->SetView(aView);
	hostWindow_->ShowWindow(nCmdShow);
	hostWindow_->UpdateWindow();


	//vc->SetView(aView);
	
}
