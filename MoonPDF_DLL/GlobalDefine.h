#pragma once
/***
 * ȫ�ֶ���
 */
#include "../mupdf/pdfapp.h"
#include <Windows.h>

 //����mupdf��ؿ⣬ʹ�õĿ�汾Ϊ��mupdf-1.15.0
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

extern fz_context *g_moonPdfCtx;//ʹ��ȫ�ֶ������

extern pdfapp_t g_moonPdfApp;//ʹ��ȫ�ֶ������

extern BITMAPINFO *g_dibinf;//λͼ��Ϣ

extern HBRUSH g_bgbrush;//��ˢ

extern int g_justcopied;//

extern HWND g_hShowPdfWnd;//��ʾpdf�Ĵ�����

extern HDC  g_hdc;//���ڻ�pdf�������ʹ�ô���������ʹ��hdc��pdf

extern HCURSOR arrowcurs, handcurs, waitcurs, caretcurs;//���