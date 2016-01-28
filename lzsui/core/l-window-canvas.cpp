#include "stdafx.h"
#include "utility\lzs-debug.hpp"

#include "l-window-canvas.h"

namespace lui
{

	LWindowCanvas::LWindowCanvas(HWND hWnd)
		: hWnd_(hWnd)
	{
		assert(hWnd);
		HDC hdc = ::GetDC(hWnd);
		hCompatibleDC_ = ::CreateCompatibleDC(hdc);
		SystemFunctionAssert(hCompatibleDC_);
		::ReleaseDC(hWnd, hdc);
	}

	HDC LWindowCanvas::GetMemoryDC()
	{
		return hCompatibleDC_;
	}

	void LWindowCanvas::OnSize(SIZE size)
	{
		//select a new bitmap into it
		HDC hdc = ::GetDC(hWnd_);
		HBITMAP newBitmap = ::CreateCompatibleBitmap(hdc, size.cx, size.cy);
		::SelectObject(hCompatibleDC_, newBitmap);
		::ReleaseDC(hWnd_, hdc);
		if (hBitmap_) {
			::DeleteObject(hBitmap_);
		}
		hBitmap_ = newBitmap;
	}


}