#include "l-render-factory.h"

namespace lui {
	LRenderFactory * LRenderFactory::Instance()
	{
		static LRenderFactory aStaticRender;
		return &aStaticRender;
	}
	bool LRenderFactory::ConfigureEngine(RenderEngine engine)
	{
		engine_ = engine;
		return true;
	}
	LIImage * LRenderFactory::CreateImage(const char * data)
	{
		switch (engine_)
		{
		case RenderEngine::GDI:
			return CreateGdiImage(data);
			break;
		case RenderEngine::SKIA:
			break;
		case RenderEngine::GDIPLUS:
			break;
		default:
			break;
		}
		return nullptr;
	}
}