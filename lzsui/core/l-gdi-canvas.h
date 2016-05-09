#pragma once
#include "stdafx.h"
#include "l-window-canvas.h"
namespace lui
{
	struct LGdiSolidBrush {
		LGdiSolidBrush(const LColor & cr) :color(cr),hBrush(NULL) {
			if (color.alpha != 0) {
				hBrush = ::CreateSolidBrush(COLORREF(cr));
				assert(hBrush);
			}
		}
		~LGdiSolidBrush() {
			if (hBrush) {
				::DeleteObject(hBrush);
			}
		}
		LColor color;
		HBRUSH hBrush;
	};

	struct LGdiPen {
		LGdiPen(int wd, const LColor &cr): width(wd), color(cr), hPen(NULL){
			if (wd > 0 && color.alpha != 0) {
				hPen = ::CreatePen(PS_SOLID, width, COLORREF(color));
			}
		}

		~LGdiPen() {
			if (hPen) {
				::DeleteObject(hPen);
			}
		}
		int width;
		LColor color;
		HPEN hPen;
	};

	class LGdiMemoryDC {
	public:
		LGdiMemoryDC(HWND hWnd, int width, int height) {
			HDC hdc = ::GetDC(hWnd);
			memoryDC_ = ::CreateCompatibleDC(hdc);
			sizeBitmap_ = ::CreateCompatibleBitmap(hdc, width, height);
			::ReleaseDC(hWnd, hdc);
			::SelectObject(memoryDC_, sizeBitmap_);
		}
		~LGdiMemoryDC() {
			::DeleteDC(memoryDC_);
			::DeleteObject(sizeBitmap_);
		}
		HDC MemDC() {
			return memoryDC_;
		}
	protected:
		HDC memoryDC_;
		HBITMAP sizeBitmap_;
	};
	class LGdiCanvas : public LWindowCanvas
	{
	public:
		LGdiCanvas(HWND hWnd);
		virtual bool DrawBitmap(const LRect & rect, HBITMAP bitmap, const LPoint & ori, BYTE alpha) override;
		virtual bool DrawRect(const LRect & paintRC, const LRect & rect, const LRectDecorate & decorate) override;
		//virtual bool DrawRoundRect(const LRect & rect, const LRoundRectGraph & roundGraph) override;
	protected:
		bool AlphaBlend(const LRect & dstRect, HDC srcDC, const LPoint & srcOri, unsigned char alpha);
	};
}
