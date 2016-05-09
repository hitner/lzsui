#pragma once

namespace lui {
	class LIImage;
	class LRenderFactory {
	public:
		enum class RenderEngine {GDI,SKIA,GDIPLUS};
		static LRenderFactory * Instance();
		bool ConfigureEngine(RenderEngine engine);
		LIImage * CreateImage(const char * data);
	protected:
		LRenderFactory():engine_(RenderEngine::GDI){}

		LIImage * CreateGdiImage(const char *data);
	protected:
		RenderEngine engine_;

	};
}