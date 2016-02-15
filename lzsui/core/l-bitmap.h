#pragma once
#include "stdafx.h"

namespace lui
{
	class LBitmap
	{
	public:
		HBITMAP HBitmap();
	protected:
		HBITMAP hBm;
	};

	class LBitmapFactory
	{
	public:
		static LBitmapFactory * Instance();
		//LBit
	protected:
		LBitmapFactory() {}

	};
}