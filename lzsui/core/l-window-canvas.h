#pragma once
#include "stdafx.h"
#include "li-canvas.h"

namespace lui
{
	//In Windows canvas is a common canvas in Win32 system that have a compatible DC
	//
	class LWindowCanvas : public LICanvas
	{
	public:
		LWindowCanvas(HWND hWnd);
		virtual HDC GetMemoryDC();
		virtual void OnSize(SIZE size);
		
	protected:
		HWND hWnd_;
		HDC hCompatibleDC_;
		HBITMAP hBitmap_;

	};

}