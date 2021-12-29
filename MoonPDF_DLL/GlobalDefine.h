#pragma once
/***
 * 全局定义
 */
#include "../mupdf/pdfapp.h"
#include <Windows.h>

 //导入mupdf相关库，使用的库版本为：mupdf-1.15.0
#ifdef _DEBUG
#pragma comment(lib, "lib\\debug\\libmupdf.lib")
#pragma comment(lib, "lib\\debug\\libresources.lib")
#pragma comment(lib, "lib\\debug\\libthirdparty.lib")
#else
#pragma comment(lib, "lib\\release\\libmupdf.lib")
#pragma comment(lib, "lib\\release\\libresources.lib")
#pragma comment(lib, "lib\\release\\libthirdparty.lib")
#endif

#ifndef PATH_MAX
#define PATH_MAX 4096
#endif
#define MIN(x,y) ((x) < (y) ? (x) : (y))

extern fz_context *g_moonPdfCtx;//使用全局定义变量

extern pdfapp_t g_moonPdfApp;//使用全局定义变量

extern BITMAPINFO *g_dibinf;//位图信息

extern HBRUSH g_bgbrush;//画刷

extern int g_justcopied;//

extern HWND g_hShowPdfWnd;//显示pdf的窗体句柄

extern HDC  g_hdc;//用于画pdf，如果不使用窗体句柄，则使用hdc画pdf

extern HCURSOR arrowcurs, handcurs, waitcurs, caretcurs;//光标