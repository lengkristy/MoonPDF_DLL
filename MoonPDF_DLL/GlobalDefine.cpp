/**********************************************
 * ȫ�ֶ���
 **/

#include "Externel\ExternelDefine.h"
#include "GlobalDefine.h"
/**
 * ȫ�ֵ�MUPDF�����ģ�������Ŀֻ��ʼ��һ��
 */
_GLOBAL_ fz_context * g_moonPdfCtx = NULL;

/**
 * ȫ�ֵ�pdfapp����
 */
_GLOBAL_ pdfapp_t g_moonPdfApp;

/***
 * λͼ��Ϣ�����ڴ洢��ʾ��pdf
 */
_GLOBAL_ BITMAPINFO *g_dibinf = NULL;

/***
 * ����pdf�Ļ�ˢ
 */
_GLOBAL_ HBRUSH g_bgbrush;

/**
 * �Ƿ���
 */
_GLOBAL_ int g_justcopied = 0;

/**
 * Ҫ��ʾ��pdf������
 */
_GLOBAL_ HWND g_hShowPdfWnd = NULL;

/**
 *���ڻ�pdf�������ʹ�ô���������ʹ��hdc��pdf
 */
_GLOBAL_ HDC g_hdc = NULL;

/**
 *
 */
_GLOBAL_ HCURSOR arrowcurs, handcurs, waitcurs, caretcurs;//