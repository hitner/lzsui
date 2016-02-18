#pragma once
#include <memory>
namespace lui
{
	class LuiView;

	class LuiViewController
	{
	public:
		LuiViewController() {}
		void SetView(std::shared_ptr<LuiView> view);
		std::shared_ptr<LuiView> View();
	protected:
		std::shared_ptr<LuiView> view_;
	};
}