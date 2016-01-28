#pragma once
#include "stdafx.h"
#include "l-window-canvas.h"
namespace lui
{
	class LGdiCanvas : public LWindowCanvas
	{
	public:
		LGdiCanvas(HWND hWnd);
		virtual void DrawBitmap(LPCRECT pDestRect, LBitmap * bitmap, POINT src, BYTE alpha);
	};
}
