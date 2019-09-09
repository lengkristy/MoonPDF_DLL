/**********************************************
 * 全局定义
 **/

#include "Externel\ExternelDefine.h"
#include "GlobalDefine.h"
/**
 * 全局的MUPDF上下文，整个项目只初始化一次
 */
_GLOBAL_ fz_context * g_moonPdfCtx = NULL;

/**
 * 全局的pdfapp变量
 */
_GLOBAL_ pdfapp_t g_moonPdfApp;

/***
 * 位图信息，用于存储显示的pdf
 */
_GLOBAL_ BITMAPINFO *g_dibinf = NULL;

/***
 * 用于pdf的画刷
 */
_GLOBAL_ HBRUSH g_bgbrush;

/**
 * 是否复制
 */
_GLOBAL_ int g_justcopied = 0;

/**
 * 要显示的pdf窗体句柄
 */
_GLOBAL_ HWND g_hShowPdfWnd = NULL;

/**
 *
 */
_GLOBAL_ HCURSOR arrowcurs, handcurs, waitcurs, caretcurs;//