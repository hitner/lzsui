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

		LPoint operator + (const LPoint& pt) const {
			LPoint a;
			a.x = x + pt.x;
			a.y = y + pt.y;
			return a;
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

		lt_int right() const{
			return x + width;
		}
		lt_int bottom() const{
			return y + height;
		}
		LSize size() const{
			return LSize(width, height);
		}
		LPoint origin() const{
			return LPoint(x, y);
		}

		operator RECT () {
			RECT rc;
			rc.left = x;
			rc.right = x + width;
			rc.top = y;
			rc.bottom = y + height;
			return rc;
		}
		operator RECT () const{
			RECT rc;
			rc.left = x;
			rc.right = x + width;
			rc.top = y;
			rc.bottom = y + height;
			return rc;
		}


		LRect operator & (const LRect & rect) const{
			RECT r1 = RECT(*this);
			const RECT r2 = RECT(rect);
			RECT rslt;
			::IntersectRect(&rslt, &r1, &r2);
			return rslt;
		}
		LRect operator + (const LPoint & pt) const {
			LRect rc(*this);
			rc.x += pt.x;
			rc.y += pt.y;
			return rc;
		}

		LRect operator - (const LPoint & pt) const {
			LRect rc(*this);
			rc.x -= pt.x;
			rc.y -= pt.y;
			return rc;
		}

		bool IsEmpty() const {
			return (width == 0 && height == 0);
		}
	};

	struct LRoundRect : public LRect
	{
		lt_int roundWidth;
		lt_int roundHeight;
	};
	struct LColor {
		unsigned char red;
		unsigned char green;
		unsigned char blue;
		unsigned char alpha;
		LColor() :red(0), green(0), blue(0), alpha(0xFF) {}
		LColor(unsigned int x) {
			red = x >> 24;
			green = 0x00FF & (x >> 16);
			blue = 0x00FF & (x >> 8);
			alpha = 0x00FF & x;
		}

		operator COLORREF () const{
			return RGB(red, green, blue);
		}
		inline static LColor RedColor() {
			return LColor(0xFF0000FF);
		}
		inline static LColor GreenColor() {
			return LColor(0x00FF00FF);
		}
		inline static LColor BlueColor() {
			return LColor(0x0000FFFF);
		}
		inline static LColor TransparentColor() {
			return LColor(0xFFFFFF00);
		}

	};
}