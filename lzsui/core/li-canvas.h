#pragma once
#include "stdafx.h"
#include "l-common.h"

namespace lui
{
	class LIImage {
	public:
		virtual LSize Size() = 0;
	};

	struct LPen {
		int width;
		LColor penColor;
	};
	struct LBrush {
		LColor filledColor;
	};

	struct LLineGraph {

	};

	struct LRectDecorate {
		LColor filledColor;
		int borderWidth;
		LColor borderColor;

		LRectDecorate(const LColor & fColor)
			: filledColor(fColor), borderWidth(0) {}
		LRectDecorate(const LColor & fColor, int bw, const LColor & bColor)
			: filledColor(fColor), borderWidth(bw), borderColor(bColor) {}
	};
	struct LRectDecorateEx {
		LPen pen;
		LBrush brush;
	};



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
		virtual bool DrawRect(const LRect & paintRC, const LRect & rect, const LRectDecorate & decorate) = 0;

		//virtual bool DrawRect(const LRect & paintRC, const LRect & rect, const LRectDecorateEx & decorate) = 0;
		//virtual bool DrawRoundRect(const LRect & rect, const LRoundRectGraph & roundGraph) = 0;


		
	};


}