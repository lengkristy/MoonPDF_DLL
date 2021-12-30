#include "stdafx.h"
#include "PdfControl.h"
#include "MoonPDFView.h"

HBITMAP GetScreenBmp()
{
	HWND hwnd = ::GetDesktopWindow();
	HDC hsrc = ::GetDC(hwnd);
	HDC hmemdc = ::CreateCompatibleDC(hsrc);
	RECT rc; ::GetWindowRect(hwnd, &rc);
	SIZE sz; sz.cx = rc.right - rc.left; sz.cy = rc.bottom - rc.top;
	HBITMAP hbmp = ::CreateCompatibleBitmap(hsrc, sz.cx, sz.cy);
	HGDIOBJ holdbmp = ::SelectObject(hmemdc, hbmp);
	::BitBlt(hmemdc, 0, 0, sz.cx, sz.cy, hsrc, rc.left, rc.top, SRCCOPY);
	::SelectObject(hmemdc, holdbmp);
	::DeleteObject(hmemdc);
	::ReleaseDC(hwnd, hsrc);
	return hbmp;
}

PdfControl::PdfControl()
{
	bitmap_ = GetScreenBmp();
}


PdfControl::~PdfControl()
{
}


void PdfControl::Paint(ui::IRenderContext* pRender, const ui::UiRect& rcPaint)
{
	if (!::IntersectRect(&m_rcPaint, &rcPaint, &m_rcItem)) return;
	__super::Paint(pRender, rcPaint);

	if (NULL == bitmap_)
		return;

	HDC hCloneDC = pRender->GetDC();
	
	MoonPaintPDF(hCloneDC);
}