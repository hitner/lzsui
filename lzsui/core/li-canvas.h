#pragma once
#include "stdafx.h"

namespace lui
{
	class LBitmap;
	class LICanvas
	{
	public:
		virtual ~LICanvas() = 0;
		virtual HDC GetMemoryDC() = 0;
		virtual void OnSize(SIZE size) = 0;
		virtual void DrawBitmap(LPCRECT pDestRect, LBitmap * bitmap, POINT src, BYTE alpha) = 0;
	};


}