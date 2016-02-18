#pragma once
#include "stdafx.h"
#include "l-common.h"

namespace lui
{
	class LICanvas;
	class LuiView
	{
	public:
		LuiView();
		LuiView(const LRect & frame);

		const std::wstring& Name();
		void SetName(const std::wstring & name);

		LRect Frame();
		void SetFrame(const LRect & rect);

		void AddSubview(std::shared_ptr<LuiView> subview);
		const std::list<std::shared_ptr<LuiView>> & Subviews();

		void SetBackgroundColor(const LColor & color);
		LColor BackgroundColor();

		// origin :父view在canvas中的原点坐标
		// rect ： 父view中的更新区域
		virtual void DoPaint(std::shared_ptr<LICanvas> canvas, const LPoint & origin, const LRect & rect);
		bool UpdateLayout();
	protected:

	protected:
		enum class LayoutState {LS_None, LS_Finished, LS_NeedUpdate, LS_WaitNext};

		std::list<std::shared_ptr<LuiView>> subviews_;
		std::wstring name_;
		LRect frame_;
		LColor backgroundColor_;

	};
}