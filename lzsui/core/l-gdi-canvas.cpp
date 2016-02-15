#pragma once
#include "stdafx.h"
#include "l-gdi-canvas.h"
namespace lui
{
	LGdiCanvas::LGdiCanvas(HWND hWnd)
		: LWindowCanvas(hWnd)
	{
	}
	bool LGdiCanvas::DrawBitmap(const LRect & rect, HBITMAP bitmap, const LPoint & ori, BYTE alpha)
	{
		HDC hdc = ::CreateCompatibleDC(hCompatibleDC_);
		assert(hdc);
		::SelectObject(hdc, bitmap);
		//BLENDFUNCTION bf = { AC_SRC_OVER, 0, alpha, AC_SRC_ALPHA };
		//BOOL bRet = ::AlphaBlend(hCompatibleDC_, rect.x, rect.y, rect.width, rect.height, 
		//	hdc, ori.x, ori.y, rect.width, rect.height, bf);
		//assert(bRet);
		::StretchBlt(hCompatibleDC_, rect.x, rect.y, rect.width, rect.height, hdc, ori.x, ori.y, rect.width, rect.height, SRCCOPY);

		::DeleteDC(hdc);
		return true;
	}
}
