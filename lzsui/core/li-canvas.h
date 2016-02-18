#pragma once
#include "stdafx.h"
#include "l-common.h"

namespace lui
{
	class LBitmap;
	struct LLineGraph {

	};

	struct LRectGraph {
		LRect rect;
		LColor filledColor;
		int borderWidth;
		LColor borderColor;
		
		LRectGraph(const LRect& rc, const LColor & fColor, int bw, const LColor & bColor)
			: rect(rc), filledColor(fColor), borderWidth(bw), borderColor(bColor) {}
		LRectGraph(const LRect & rc, const LColor & fColor = LColor::TransparentColor())
			: rect(rc), filledColor(fColor), borderWidth(0) {}
	};

	struct LRoundRectGraph :public LRectGraph {
		LRoundRectGraph(const LRect & rc, int rw, int rh, const LColor & fColor = LColor::TransparentColor())
			: LRectGraph(rc, fColor), roundWidth(rw), roundHeight(rh) {}
		int roundWidth;
		int roundHeight;
	};

	struct LEcillipseGraph;

	class LICanvas
	{
	public:
		virtual ~LICanvas() {};
		virtual HDC GetMemoryDC() = 0;

		virtual void OnSize(LSize size) = 0;
		//virtual void OnPaint(RECT rect) = 0;

		//draw function
		virtual bool DrawBitmap(const LRect & rect, HBITMAP bitmap, const LPoint & ori, BYTE alpha) = 0;
		

		// filledColor can be nullptr,
		// borderWidth can be 0
		virtual bool DrawRect(const LRect & rect, const LRectGraph & rectGraph) = 0;

		virtual bool DrawRoundRect(const LRect & rect, const LRoundRectGraph & roundGraph) = 0;
		
	};


}