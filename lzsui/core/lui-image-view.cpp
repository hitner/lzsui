#include "lui-image-view.h"
#include "utility\png\fluid.h"
#include "utility\lzs-file.hpp"
#include "li-canvas.h"

namespace lui {
	LuiImageView::LuiImageView()
		:bm_(NULL)
	{
	}
	LuiImageView::LuiImageView(const LRect & rect)
		:LuiView(rect), bm_(NULL)
	{
	}
	void LuiImageView::
		DoPaint(std::shared_ptr<LICanvas> canvas, const LPoint & origin, const LRect & rect)
	{
		LRect prc = frame_ & rect;
		if (prc.IsEmpty()) {
			return;
		}
		if (!bm_) {
			void * bmbit;
			int bufSize = 1 * 1024 * 1024;
			char * buf = new char[bufSize];// max 4M png
			int readnum = read_file(L"E:\\lzsui\\prelive.png", buf, bufSize);
			int width, height;
			char * decoded = fluid_decode(buf, readnum, &width, &height);
			delete[] buf;
			buf = NULL;
			rgba2argb(decoded, width, height);

			BITMAPINFO bmi;
			memset(&bmi, 0, sizeof(bmi));
			bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
			bmi.bmiHeader.biWidth = width;
			bmi.bmiHeader.biHeight = -height;
			bmi.bmiHeader.biPlanes = 1;
			bmi.bmiHeader.biBitCount = 32;
			bmi.bmiHeader.biCompression = BI_RGB;
			bmi.bmiHeader.biSizeImage = 0; // it was not used in BI_RGB mode
			bm_ = ::CreateDIBSection(NULL, &bmi, DIB_RGB_COLORS, &bmbit, NULL, 0);
			assert(bmbit);
			memcpy(bmbit, decoded, width * height * 4);

		}
		canvas->DrawBitmap(prc, bm_, LPoint(0, 0), 0xFF);
	}
}