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
		//::BitBlt(hCompatibleDC_, rect.x, rect.y,rect.width, rect.height, hdc, ori.x, ori.y, SRCCOPY);
		this->AlphaBlend(rect, hdc, ori, alpha);
		::DeleteDC(hdc);
		return true;
	}
	bool LGdiCanvas::DrawRect(const LRect & paintRC, const LRect & rect, const LRectDecorate & decorate)
	{
		BOOL bOK;
		LRect rc;
		rc = paintRC & rect;
		if (rc.IsEmpty()) {
			assert(false);
			return false;
		}
		LGdiMemoryDC memDC(hWnd_, rect.width, rect.height);
		::SetBkMode(memDC.MemDC(), TRANSPARENT);
		LGdiSolidBrush sBrush(decorate.filledColor);
		if (sBrush.hBrush == NULL)
		{
			LGdiPen gPen(decorate.borderWidth, decorate.borderColor);
			HGDIOBJ oldPen = ::SelectObject(hCompatibleDC_, gPen.hPen);
			HGDIOBJ oldBrush = ::SelectObject(hCompatibleDC_, GetStockObject(NULL_BRUSH));
			::Rectangle(hCompatibleDC_, rect.x, rect.y, rect.right(), rect.bottom());
			::SelectObject(hCompatibleDC_, oldPen);
			::SelectObject(hCompatibleDC_, oldBrush);
			return true;
		}
		::SelectObject(memDC.MemDC(), sBrush.hBrush);
		LGdiPen gPen(decorate.borderWidth,decorate.borderColor);
		::SelectObject(memDC.MemDC(), gPen.hPen);
		
		::Rectangle(memDC.MemDC(), 0, 0, rect.width, rect.height);
		bOK = ::BitBlt(hCompatibleDC_, rc.x, rc.y, rc.width, rc.height, memDC.MemDC(), 0, 0, SRCCOPY);
		//BLENDFUNCTION ftn = { AC_SRC_OVER,0,1,AC_SRC_ALPHA };
		//bOK = ::AlphaBlend(hCompatibleDC_, rc.x, rc.y, rc.width, rc.height, memDC.MemDC(),);
		assert(bOK);
		return false;
	}

	bool LGdiCanvas::AlphaBlend(const LRect & dstRect, HDC srcDC, const LPoint & srcOri, unsigned char alpha)
	{
		BLENDFUNCTION ftn = { AC_SRC_OVER,0,alpha,AC_SRC_ALPHA };
		return ::AlphaBlend(hCompatibleDC_, dstRect.x, dstRect.y, dstRect.width, dstRect.height, srcDC, srcOri.x, srcOri.y,
			dstRect.width, dstRect.height, ftn);
	}

	//bool LGdiCanvas::DrawRoundRect(const LRect & rect, const LRoundRectGraph & roundGraph)
	//{
	//	return false;
	//}

}
