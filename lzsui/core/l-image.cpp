#include "l-image.h"
#include "l-render-factory.h"
#include "li-canvas.h"

namespace lui {



	LImage::LImage(const char * data) :image_(nullptr)
	{
		image_ =LRenderFactory::Instance()->CreateImage(data);
	}
	LSize LImage::Size()
	{
		return image_->Size();
	}
}