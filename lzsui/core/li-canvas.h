#pragma once
#include "stdafx.h"
#include "l-common.h"

namespace lui
{
	class LBitmap;
	class LICanvas
	{
	public:
		virtual ~LICanvas() {};
		virtual HDC GetMemoryDC() = 0;

		virtual void OnSize(SIZE size) = 0;
		//virtual void OnPaint(RECT rect) = 0;

		//draw function
		virtual bool DrawBitmap(const LRect & rect, HBITMAP bitmap, const LPoint & ori, BYTE alpha) = 0;
		
	};


}