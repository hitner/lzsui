#include "stdafx.h"
#include "lui-view.h"
#include "li-canvas.h"

namespace lui
{

	LuiView::LuiView()
	{
	}

	LuiView::LuiView(const LRect & frame)
		: frame_(frame)
		, borderWidth_(0)
	{
		
	}

	const std::wstring& LuiView::Name()
	{
		return name_;
	}

	void LuiView::SetName(const std::wstring & name)
	{
		name_ = name;
	}

	LRect LuiView::Frame()
	{
		return frame_;
	}

	void LuiView::SetFrame(const LRect & rect)
	{
		frame_ = rect;
	}



	void LuiView::SetBackgroundColor(const LColor & color)
	{
		backgroundColor_ = color;
	}

	LColor LuiView::BackgroundColor()
	{
		return backgroundColor_;
	}

	void LuiView::SetBorderWidth(int width)
	{
		borderWidth_ = width;
	}

	int LuiView::BorderWidth() const
	{
		return borderWidth_;
	}

	void LuiView::SetBorderColor(const LColor & color)
	{
		borderColor_ = color;
	}

	LColor LuiView::BorderColor() const
	{
		return borderColor_;
	}

	void LuiView::AddSubview(std::shared_ptr<LuiView> subview)
	{
		subviews_.push_back(subview);
	}

	const std::list<std::shared_ptr<LuiView>>& LuiView::Subviews()
	{
		return subviews_;
	}
	//origin is the view's cordinate rect is the clipping region
	void LuiView::DoPaint(std::shared_ptr<LICanvas> canvas, const LPoint & origin, const LRect & rect)
	{
		LRect prc = frame_ & rect;
		if (prc.IsEmpty()) {
			return;
		}
		
		canvas->DrawRect(prc + origin, frame_+origin, LRectDecorate(backgroundColor_,borderWidth_,borderColor_));

		// then the paint the subviews
		for (auto subview : subviews_) {
			subview->DoPaint(canvas, origin + Frame().origin(), prc - Frame().origin());
		}

	}

}