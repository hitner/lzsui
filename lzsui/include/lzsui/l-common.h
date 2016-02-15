#pragma once
#include "stdafx.h"

namespace lui
{
	typedef long lt_int;
	struct LPoint
	{
		lt_int x;
		lt_int y;
		LPoint() :x(0), y(0) {}
		LPoint(lt_int lx, lt_int ly) :x(lx), y(ly) {}
		LPoint(const LPoint & pt) {
			x = pt.x;
			y = pt.y;
		}
		LPoint(const POINT &pt) {
			x = pt.x;
			y = pt.y;
		}
	};

	struct LSize
	{
		lt_int width;
		lt_int height;

		LSize() :width(0), height(0) {}
		LSize(lt_int lw, lt_int lh) : width(lw), height(lh) {}
		LSize(const LSize & sz) {
			width = sz.width;
			height = sz.height;
		}
		LSize(const SIZE & sz) {
			width = sz.cx;
			height = sz.cy;
		}
	};

	struct LRect
	{
		lt_int x;
		lt_int y;
		lt_int width;
		lt_int height;
		LRect():x(0),y(0),width(0), height(0) {}
		LRect(lt_int px, lt_int py) : x(px), y(py), width(0), height(0) {}
		LRect(lt_int px, lt_int py, lt_int pw, lt_int ph): x(px), y(py), width(pw), height(ph) {}
		LRect(const RECT &rc) {
			x = rc.left;
			y = rc.top;
			width = rc.right - rc.left;
			height = rc.bottom - rc.top;
		}

		lt_int right() {
			return x + width;
		}
		lt_int bottom() {
			return y + height;
		}
		LSize size() {
			return LSize(width, height);
		}
		LPoint origin() {
			return LPoint(x, y);
		}

		RECT operator() () {
			RECT rc;
			rc.left = x;
			rc.right = x + width;
			rc.top = y;
			rc.bottom = y + height;
			return rc;
		}
	};

	struct LColor {
		unsigned char red;
		unsigned char green;
		unsigned char blue;
		unsigned char alpha;
		LColor() :red(0), green(0), blue(0), alpha(0) {}
		LColor(unsigned int x) {
			red = x >> 24;
			green = 0x00FF & (x >> 16);
			blue = 0x00FF & (x >> 8);
			alpha = 0x00FF & x;
		}
	};
}