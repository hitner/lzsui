#pragma once
#include "l-common.h"

namespace lui {
	class LIImage;
	class LImage
	{
	public:
		//LImage();
		//LImage(const std::wstring & filename);
		// the data is the raw file binary content!
		LImage(const char * data);
		LSize Size();

	protected:
		LIImage * image_;
		friend class LICanvas;
		//LSize size_;
		//HBITMAP bitmap_; //a DIB to save the image

	};
}