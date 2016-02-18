#pragma once
#include "stdafx.h"
#include "l-window-canvas.h"
namespace lui
{
	class LGdiCanvas : public LWindowCanvas
	{
	public:
		LGdiCanvas(HWND hWnd);
		virtual bool DrawBitmap(const LRect & rect, HBITMAP bitmap, const LPoint & ori, BYTE alpha) override;
		virtual bool DrawRect(const LRect & rect, const LRectGraph & rectGraph) override;
		virtual bool DrawRoundRect(const LRect & rect, const LRoundRectGraph & roundGraph) override;
		
	};
}
