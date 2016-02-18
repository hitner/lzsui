#pragma once 
#include "lui-view.h"
namespace lui
{
	class LuiImageView : public LuiView
	{
	public:
		LuiImageView();
		LuiImageView(const LRect & rect);
		virtual void DoPaint(std::shared_ptr<LICanvas> canvas, const LPoint & origin, const LRect & rect)override;
	protected:
		HBITMAP bm_;
	};
}