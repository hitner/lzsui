#pragma once
#include "stdafx.h"
#include "l-gdi-canvas.h"
namespace lui
{
	LGdiCanvas::LGdiCanvas(HWND hWnd)
		: LWindowCanvas(hWnd)
	{
	}
	void LGdiCanvas::DrawBitmap(LPCRECT pDestRect, LBitmap * bitmap, POINT src, BYTE alpha)
	{
	}
}
