#pragma once
#include "stdafx.h"

namespace lui
{
	class LuiView
	{
	public:
		LuiView();

		std::wstring Name();
		void SetName(const std::wstring & name);

		void AddSubview(std::shared_ptr<LuiView> subview);
		const std::list<std::shared_ptr<LuiView>> & Subviews();

		void SetBackgroundColor(const LColor & color);
		LColor BackgroundColor();

		bool UpdateLayout();
	protected:
		enum LayoutState {LS_None, LS_Finished, LS_NeedUpdate, LS_WaitNext};

		std::list<std::shared_ptr<LuiView>> subviews_;
		std::wstring name_;
	};
}