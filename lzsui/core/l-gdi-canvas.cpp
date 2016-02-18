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
		//::StretchBlt(hCompatibleDC_, rect.x, rect.y, rect.width, rect.height, hdc, ori.x, ori.y, rect.width, rect.height, SRCCOPY);
		::BitBlt(hCompatibleDC_, rect.x, rect.y,rect.width, rect.height, hdc, ori.x, ori.y, SRCCOPY);
		::DeleteDC(hdc);
		return true;
	}
	bool LGdiCanvas::DrawRect(const LRect & rect, const LRectGraph & rectGraph)
	{
		LRect rc;
		rc = rect & rectGraph.rect;
		if (rc.IsEmpty()) {
			assert(false);
			return false;
		}
		HDC hdc = ::GetDC(hWnd_);
		HDC tempDC = ::CreateCompatibleDC(hdc);
		HBITMAP btmap = ::CreateCompatibleBitmap(hdc, rectGraph.rect.width, rectGraph.rect.height);
		::ReleaseDC(hWnd_, hdc);
		::SelectObject(tempDC, btmap);
		::SelectObject(tempDC, ::GetStockObject(LTGRAY_BRUSH));
		::Rectangle(tempDC, 0, 0, rectGraph.rect.width, rectGraph.rect.height);
		::BitBlt(hCompatibleDC_, rc.x, rc.y, rc.width, rc.height, tempDC, 0, 0, SRCCOPY);
		::DeleteDC(tempDC);
		return false;
	}
	bool LGdiCanvas::DrawRoundRect(const LRect & rect, const LRoundRectGraph & roundGraph)
	{
		return false;
	}

}
