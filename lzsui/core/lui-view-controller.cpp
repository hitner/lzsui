#include "lui-view-controller.h"

namespace lui
{
	void LuiViewController::SetView(std::shared_ptr<LuiView> view)
	{
		view_ = view;
	}
	std::shared_ptr<LuiView> LuiViewController::View()
	{
		return view_;
	}
}