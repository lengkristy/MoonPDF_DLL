#include "MoonPDFView.h"
#include "../GlobalDefine.h"
#include "../Common/stringhelper.h"
#include "../mupdf/pdfapp.h"

//static wchar_t wbuf[PATH_MAX];
//static char filename[PATH_MAX];


//pdf���Ƶ�������
void WinBlit(HDC hdc)
{
	int justcopied = 0;
	if (!g_moonPdfApp.image)
	{
		return;
	}
	int image_w = fz_pixmap_width(g_moonPdfApp.ctx, g_moonPdfApp.image);
	int image_h = fz_pixmap_height(g_moonPdfApp.ctx, g_moonPdfApp.image);
	int image_n = fz_pixmap_components(g_moonPdfApp.ctx, g_moonPdfApp.image);
	unsigned char *samples = fz_pixmap_samples(g_moonPdfApp.ctx, g_moonPdfApp.image);
	int x0 = g_moonPdfApp.panx;
	int y0 = g_moonPdfApp.pany;
	int x1 = g_moonPdfApp.panx + image_w;
	int y1 = g_moonPdfApp.pany + image_h;
	RECT r;
	HBRUSH brush;
	
	if (g_moonPdfApp.image)
	{
		if (g_moonPdfApp.iscopying || justcopied)
		{
			pdfapp_invert(&g_moonPdfApp, g_moonPdfApp.selr);
			justcopied = 1;
		}

		pdfapp_inverthit(&g_moonPdfApp);

		g_dibinf->bmiHeader.biWidth = image_w;
		g_dibinf->bmiHeader.biHeight = -image_h;
		g_dibinf->bmiHeader.biSizeImage = image_h * 4;

		if (image_n == 2)
		{
			int i = image_w * image_h;
			unsigned char *color = (unsigned char*)malloc(i * 4);
			unsigned char *s = samples;
			unsigned char *d = color;
			for (; i > 0; i--)
			{
				d[2] = d[1] = d[0] = *s++;
				d[3] = *s++;
				d += 4;
			}
			SetDIBitsToDevice(hdc,
				g_moonPdfApp.panx, g_moonPdfApp.pany, image_w, image_h,
				0, 0, 0, image_h, color,
				g_dibinf, DIB_RGB_COLORS);
			free(color);
		}
		if (image_n == 4)
		{
			SetDIBitsToDevice(hdc,
				g_moonPdfApp.panx, g_moonPdfApp.pany, image_w, image_h,
				0, 0, 0, image_h, samples,
				g_dibinf, DIB_RGB_COLORS);
		}

		pdfapp_inverthit(&g_moonPdfApp);

		if (g_moonPdfApp.iscopying || justcopied)
		{
			pdfapp_invert(&g_moonPdfApp, g_moonPdfApp.selr);
			justcopied = 1;
		}
	}

	if (g_moonPdfApp.invert)
		brush = (HBRUSH)GetStockObject(BLACK_BRUSH);
	else
		brush = g_bgbrush;

	/* Grey background */
	r.top = 0; r.bottom = g_moonPdfApp.winh;
	r.left = 0; r.right = x0;
	FillRect(hdc, &r, brush);
	r.left = x1; r.right = g_moonPdfApp.winw;
	FillRect(hdc, &r, brush);
	r.left = 0; r.right = g_moonPdfApp.winw;
	r.top = 0; r.bottom = y0;
	FillRect(hdc, &r, brush);
	r.top = y1; r.bottom = g_moonPdfApp.winh;
	FillRect(hdc, &r, brush);
}

/***
* ����˵����
*   ���������ʼ��
* ������
*   hWnd����ʾ�Ĵ�����
*/
int WindowCompentInit(HWND hWnd)
{
	if (g_moonPdfCtx == NULL)
	{
		MessageBox(NULL, L"����δ��ʼ��", L"", MB_OK);
		return -1;
	}
	g_hShowPdfWnd = hWnd;
	/* ������ˢ������ɫ */
	g_bgbrush = CreateSolidBrush(RGB(0x70, 0x70, 0x70));

	/* Init DIB info for buffer */
	g_dibinf = (BITMAPINFO*)malloc(sizeof(BITMAPINFO) + 12);
	g_dibinf->bmiHeader.biSize = sizeof(g_dibinf->bmiHeader);
	g_dibinf->bmiHeader.biPlanes = 1;
	g_dibinf->bmiHeader.biBitCount = 32;
	g_dibinf->bmiHeader.biCompression = BI_RGB;
	g_dibinf->bmiHeader.biXPelsPerMeter = 2834;
	g_dibinf->bmiHeader.biYPelsPerMeter = 2834;
	g_dibinf->bmiHeader.biClrUsed = 0;
	g_dibinf->bmiHeader.biClrImportant = 0;
	g_dibinf->bmiHeader.biClrUsed = 0;

	//�������
	arrowcurs = LoadCursor(NULL, IDC_ARROW);
	handcurs = LoadCursor(NULL, IDC_HAND);
	waitcurs = LoadCursor(NULL, IDC_WAIT);
	caretcurs = LoadCursor(NULL, IDC_IBEAM);
	SetCursor(arrowcurs);

	return 0;
}

/***
* ����˵����
*   ʹ��hdc������Ⱦ�����ʼ��
* ������
*   hWnd����ʾ�Ĵ�����
*/
int WindowCompentInitByHdc(HDC hdc)
{
	if (g_moonPdfCtx == NULL)
	{
		MessageBox(NULL, L"����δ��ʼ��", L"", MB_OK);
		return -1;
	}
	g_hdc = hdc;
	/* ������ˢ������ɫ */
	g_bgbrush = CreateSolidBrush(RGB(0x70, 0x70, 0x70));

	/* Init DIB info for buffer */
	g_dibinf = (BITMAPINFO*)malloc(sizeof(BITMAPINFO)+12);
	g_dibinf->bmiHeader.biSize = sizeof(g_dibinf->bmiHeader);
	g_dibinf->bmiHeader.biPlanes = 1;
	g_dibinf->bmiHeader.biBitCount = 32;
	g_dibinf->bmiHeader.biCompression = BI_RGB;
	g_dibinf->bmiHeader.biXPelsPerMeter = 2834;
	g_dibinf->bmiHeader.biYPelsPerMeter = 2834;
	g_dibinf->bmiHeader.biClrUsed = 0;
	g_dibinf->bmiHeader.biClrImportant = 0;
	g_dibinf->bmiHeader.biClrUsed = 0;

	//�������
	arrowcurs = LoadCursor(NULL, IDC_ARROW);
	handcurs = LoadCursor(NULL, IDC_HAND);
	waitcurs = LoadCursor(NULL, IDC_WAIT);
	caretcurs = LoadCursor(NULL, IDC_IBEAM);
	SetCursor(arrowcurs);

	return 0;
}

/***
* ����˵����
*   ������ʾPDF
* ����˵����
*   hWnd�����صĴ�����
*   pdfPath:�ļ�·��
*/
int MoonPDFLoad(char *pdfPath)
{
	if (g_moonPdfCtx == NULL)
	{
		MessageBox(NULL, L"����δ��ʼ��", L"", MB_OK);
		return -1;
	}
	string srcStrPath = UnicodeToUTF8(ANSIToUnicode(pdfPath)).c_str();
	char cpath[1024] = { 0 };
	sprintf(cpath, "%s", srcStrPath.c_str());

	pdfapp_init(g_moonPdfCtx, &g_moonPdfApp);

	pdfapp_open(&g_moonPdfApp, cpath, 1);//��pdf
	return 0;
}


/***
* ����˵��
*   ��pdf��ʾ������
*/
void MoonPaintPDF()
{
	HDC hdc = NULL;
	if (g_hShowPdfWnd != NULL)
	{
		hdc = GetDC(g_hShowPdfWnd);
		WinBlit(hdc);
		ReleaseDC(g_hShowPdfWnd, hdc);
	}
	else if (g_hdc != NULL)
	{
		WinBlit(g_hdc);
	}
}


/*����˵����
*   ����PDF��С
* ������
*   width�����
*   height���߶�
*/
void MoonResizePDF(int width, int height)
{
	pdfapp_onresize(&g_moonPdfApp, width, height);
}


/***
* ����˵����
*   ��pdf�������Ŵ�
*/
void MoonZoomIn()
{
	pdfapp_zoom_in(&g_moonPdfApp);
}

/***
* ����˵����
*   ��pdf��������С
*/
void MoonZoomOut()
{
	pdfapp_zoom_out(&g_moonPdfApp);
}

/***
* ����˵����
*   ��pdf˳ʱ����ת90��
*/
void MoonClockwiseRotation()
{
	pdf_clockwise_rotation(&g_moonPdfApp);
}

/***
* ����˵����
*   ��pdf��ʱ����ת90��
*/
void MoonContrarotate()
{
	pdf_contrarotate(&g_moonPdfApp);
}

/***
* ����˵����
*   ��ȡpdf��ҳ��
* ����ֵ��
*   ������ҳ��
*/
int MoonGetPDFPageCount()
{
	return g_moonPdfApp.pagecount;
}


/***
* ����˵����
*   ��ת�������ҳ
* ������
*   pageIndex��ҳ����
*/
void MoonGotoPage(int pageIndex)
{
	pdfapp_gotopage(&g_moonPdfApp, pageIndex);//ҳ����ת
}

/**
* ����˵����
*	����ı�ע��
* ������
*  context���ı�����
*  author������
*  pageIndex��ҳ����
*  leftTopX���󶥵�xֵ
*  leftTopY���󶥵�yֵ
*  rightBottomX���ҵ׵�xֵ
*  rightBottomY���ҵ׵�yֵ
* ����ֵ��
*   �ɹ�����1��ʧ�ܷ���0
*/
void MoonAddTextAnnotation(char* context, char* author, int pageIndex, float leftTopX, float leftTopY, float rightBottomX, float rightBottomY)
{
	pdf_document *idoc;
	idoc = pdf_specifics(g_moonPdfApp.ctx, g_moonPdfApp.doc);
	pdf_page* page = pdf_load_page(g_moonPdfApp.ctx, idoc, pageIndex);
	pdf_annot* annot = pdf_create_annot(g_moonPdfApp.ctx, page, PDF_ANNOT_TEXT);
	//��contextת��utf8
	string utf8Content = UnicodeToUTF8(ANSIToUnicode(context));
	pdf_set_annot_contents(g_moonPdfApp.ctx, annot, utf8Content.c_str());
	string utf8Author = UnicodeToUTF8(ANSIToUnicode(author));
	pdf_set_annot_author(g_moonPdfApp.ctx, annot, utf8Author.c_str());
	pdf_set_annot_is_open(g_moonPdfApp.ctx, annot, TRUE);
	pdf_set_annot_border(g_moonPdfApp.ctx, annot, 4);
	fz_rect rect;
	rect.x0 = leftTopX;
	rect.y0 = leftTopY;
	rect.x1 = rightBottomX;
	rect.y1 = rightBottomY;
	pdf_set_annot_rect(g_moonPdfApp.ctx, annot, rect);
	pdfapp_save_draw(&g_moonPdfApp);
}

/**
* ����˵����
*   ��ȡpdf��ע�͵�����
* ����ֵ��
*	�ɹ�����ע�͵�������ʧ�ܷ���-1
*/
int MoonGetAnnotationCount()
{
	int annotAccount = 0;
	int pageCount = 0;
	pdf_document *idoc;
	pdf_page* pPage = NULL;
	pdf_annot* pAnnot = NULL;
	int index = 0;
	idoc = pdf_specifics(g_moonPdfApp.ctx, g_moonPdfApp.doc);
	//��ȡ��ҳ��
	pageCount = MoonGetPDFPageCount();
	for (int index = 0; index < pageCount; index++)
	{
		pPage = pdf_load_page(g_moonPdfApp.ctx, idoc, index);
		pAnnot = pdf_first_annot(g_moonPdfApp.ctx, pPage);
		if (pAnnot != NULL)
		{
			annotAccount++;
			while ((pAnnot = pdf_next_annot(g_moonPdfApp.ctx, pAnnot)) != NULL){
				annotAccount++;
			}
		}
	}
	
	return 0;
}


//////////////////////////////////////////////////////����pdf ��Ϣ��///////////////////////////////////////////////////////////////////
/*
* Dialog boxes
*/

void winwarn(pdfapp_t *app, char *msg)
{
	//MessageBoxA(hwndframe, msg, "MuPDF: Warning", MB_ICONWARNING);
}

void winerror(pdfapp_t *app, char *msg)
{
	//MessageBoxA(hwndframe, msg, "MuPDF: Error", MB_ICONERROR);
	exit(1);
}

void wintitle(pdfapp_t *app, char *title)
{
	wchar_t wide[256], *dp;
	char *sp;
	int rune;

	dp = wide;
	sp = title;
	while (*sp && dp < wide + 255)
	{
		sp += fz_chartorune(&rune, sp);
		*dp++ = rune;
	}
	*dp = 0;

	SetWindowTextW(g_hShowPdfWnd, wide);
}

void winresize(pdfapp_t *app, int w, int h)
{
	ShowWindow(g_hShowPdfWnd, SW_SHOWDEFAULT);
	w += GetSystemMetrics(SM_CXFRAME) * 2;
	h += GetSystemMetrics(SM_CYFRAME) * 2;
	h += GetSystemMetrics(SM_CYCAPTION);
	SetWindowPos(g_hShowPdfWnd, 0, 0, 0, w, h, SWP_NOZORDER | SWP_NOMOVE);
}

void winrepaint(pdfapp_t *app)
{
	InvalidateRect(g_hShowPdfWnd, NULL, 0);
}

void winrepaintsearch(pdfapp_t *app)
{
	// TODO: invalidate only search area and
	// call only search redraw routine.
	InvalidateRect(g_hShowPdfWnd, NULL, 0);
}

char *winpassword(pdfapp_t *app, char *filename)
{
	return NULL;
}

char *wintextinput(pdfapp_t *app, char *inittext, int retry)
{
	return NULL;
}

int winchoiceinput(pdfapp_t *app, int nopts, const char *opts[], int *nvals, const char *vals[])
{
	return 0;
}
void winopenuri(pdfapp_t *app, char *buf)
{
	//ShellExecuteA(hwndframe, "open", buf, 0, 0, SW_SHOWNORMAL);
}

void wincursor(pdfapp_t *app, int curs)
{
	if (curs == ARROW)
		SetCursor(arrowcurs);
	if (curs == HAND)
		SetCursor(handcurs);
	if (curs == WAIT)
		SetCursor(waitcurs);
	if (curs == CARET)
		SetCursor(caretcurs);
}

/*
* Event handling
*/

void windocopy(pdfapp_t *app)
{
	HGLOBAL handle;
	unsigned short *ucsbuf;

	if (!OpenClipboard(g_hShowPdfWnd))
		return;
	EmptyClipboard();

	handle = GlobalAlloc(GMEM_MOVEABLE, 4096 * sizeof(unsigned short));
	if (!handle)
	{
		CloseClipboard();
		return;
	}

	ucsbuf = (unsigned short *)GlobalLock(handle);
	pdfapp_oncopy(&g_moonPdfApp, ucsbuf, 4096);
	GlobalUnlock(handle);

	SetClipboardData(CF_UNICODETEXT, handle);
	CloseClipboard();

	g_justcopied = 1;	/* keep inversion around for a while... */
}

void windrawrect(pdfapp_t *app, int x0, int y0, int x1, int y1)
{
	HDC hdc = GetDC(g_hShowPdfWnd);
	RECT r;
	r.left = x0;
	r.top = y0;
	r.right = x1;
	r.bottom = y1;
	FillRect(hdc, &r, (HBRUSH)GetStockObject(WHITE_BRUSH));
	ReleaseDC(g_hShowPdfWnd,hdc);
}

void windrawstring(pdfapp_t *app, int x, int y, char *s)
{
	HDC hdc = GetDC(g_hShowPdfWnd);
	HFONT font = (HFONT)GetStockObject(ANSI_FIXED_FONT);
	SelectObject(hdc, font);
	TextOutA(hdc, x, y - 12, s, (int)strlen(s));
	ReleaseDC(g_hShowPdfWnd, hdc);
}

static void
do_close(pdfapp_t *app)
{
	fz_context *ctx = app->ctx;
	pdfapp_close(app);
	free(g_hShowPdfWnd);
	fz_drop_context(ctx);
}

void winclose(pdfapp_t *app)
{
	if (pdfapp_preclose(app))
	{
		do_close(app);
		exit(0);
	}
}

void winfullscreen(pdfapp_t *app, int state)
{
	static WINDOWPLACEMENT savedplace;
	static int isfullscreen = 0;
	if (state && !isfullscreen)
	{
		GetWindowPlacement(g_hShowPdfWnd, &savedplace);
		SetWindowLong(g_hShowPdfWnd, GWL_STYLE, WS_POPUP | WS_VISIBLE);
		SetWindowPos(g_hShowPdfWnd, NULL, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_FRAMECHANGED);
		ShowWindow(g_hShowPdfWnd, SW_SHOWMAXIMIZED);
		isfullscreen = 1;
	}
	if (!state && isfullscreen)
	{
		SetWindowLong(g_hShowPdfWnd, GWL_STYLE, WS_OVERLAPPEDWINDOW);
		SetWindowPos(g_hShowPdfWnd, NULL, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_FRAMECHANGED);
		SetWindowPlacement(g_hShowPdfWnd, &savedplace);
		isfullscreen = 0;
	}
}

int winsavequery(pdfapp_t *app)
{
	switch (MessageBoxA(g_hShowPdfWnd, "File has unsaved changes. Do you want to save", "MuPDF", MB_YESNOCANCEL))
	{
	case IDYES: return SAVE;
	case IDNO: return DISCARD;
	default: return CANCEL;
	}
}

int winquery(pdfapp_t *app, const char *query)
{
	switch (MessageBoxA(g_hShowPdfWnd, query, "MuPDF", MB_YESNOCANCEL))
	{
	case IDYES: return QUERY_YES;
	case IDNO:
	default: return QUERY_NO;
	}
}

int wingetcertpath(char *buf, int len)
{
	return 0;
}

int wingetsavepath(pdfapp_t *app, char *buf, int len)
{
	wchar_t wbuf[PATH_MAX];
	char filename[PATH_MAX];
	wchar_t twbuf[PATH_MAX];
	OPENFILENAME ofn;

	wcscpy(twbuf, wbuf);
	memset(&ofn, 0, sizeof(OPENFILENAME));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = g_hShowPdfWnd;
	ofn.lpstrFile = twbuf;
	ofn.nMaxFile = PATH_MAX;
	ofn.lpstrInitialDir = NULL;
	ofn.lpstrTitle = L"MuPDF: Save PDF file";
	ofn.lpstrFilter = L"PDF Documents (*.pdf)\0*.pdf\0All Files\0*\0\0";
	ofn.Flags = OFN_HIDEREADONLY;
	if (GetSaveFileName(&ofn))
	{
		int code = WideCharToMultiByte(CP_UTF8, 0, twbuf, -1, buf, MIN(PATH_MAX, len), NULL, NULL);
		if (code == 0)
		{
			winerror(&g_moonPdfApp, "cannot convert filename to utf-8");
			return 0;
		}

		wcscpy(wbuf, twbuf);
		strcpy(filename, buf);
		return 1;
	}
	else
	{
		return 0;
	}
}

void winalert(pdfapp_t *app, pdf_alert_event *alert)
{
	int buttons = MB_OK;
	int icon = MB_ICONWARNING;
	int pressed = PDF_ALERT_BUTTON_NONE;

	switch (alert->icon_type)
	{
	case PDF_ALERT_ICON_ERROR:
		icon = MB_ICONERROR;
		break;
	case PDF_ALERT_ICON_WARNING:
		icon = MB_ICONWARNING;
		break;
	case PDF_ALERT_ICON_QUESTION:
		icon = MB_ICONQUESTION;
		break;
	case PDF_ALERT_ICON_STATUS:
		icon = MB_ICONINFORMATION;
		break;
	}

	switch (alert->button_group_type)
	{
	case PDF_ALERT_BUTTON_GROUP_OK:
		buttons = MB_OK;
		break;
	case PDF_ALERT_BUTTON_GROUP_OK_CANCEL:
		buttons = MB_OKCANCEL;
		break;
	case PDF_ALERT_BUTTON_GROUP_YES_NO:
		buttons = MB_YESNO;
		break;
	case PDF_ALERT_BUTTON_GROUP_YES_NO_CANCEL:
		buttons = MB_YESNOCANCEL;
		break;
	}

	pressed = MessageBoxA(g_hShowPdfWnd, alert->message, alert->title, icon | buttons);

	switch (pressed)
	{
	case IDOK:
		alert->button_pressed = PDF_ALERT_BUTTON_OK;
		break;
	case IDCANCEL:
		alert->button_pressed = PDF_ALERT_BUTTON_CANCEL;
		break;
	case IDNO:
		alert->button_pressed = PDF_ALERT_BUTTON_NO;
		break;
	case IDYES:
		alert->button_pressed = PDF_ALERT_BUTTON_YES;
	}
}


void winprint(pdfapp_t *app)
{
	MessageBoxA(g_hShowPdfWnd, "The MuPDF library supports printing, but this application currently does not", "Print document", MB_ICONWARNING);
}

void messagebox(char* msg)
{
	MessageBoxA(g_hShowPdfWnd, msg, "��Ϣ", MB_OK);
}

#define OUR_TIMER_ID 1

void winadvancetimer(pdfapp_t *app, float delay)
{
	int timer_pending = 1;
	SetTimer(g_hShowPdfWnd, OUR_TIMER_ID, (unsigned int)(1000 * delay), NULL);
}

void winreplacefile(char *source, char *target)
{
	wchar_t wsource[PATH_MAX];
	wchar_t wtarget[PATH_MAX];

	int sz = MultiByteToWideChar(CP_UTF8, 0, source, -1, wsource, PATH_MAX);
	if (sz == 0)
	{
		winerror(&g_moonPdfApp, "cannot convert filename to Unicode");
		return;
	}

	sz = MultiByteToWideChar(CP_UTF8, 0, target, -1, wtarget, PATH_MAX);
	if (sz == 0)
	{
		winerror(&g_moonPdfApp, "cannot convert filename to Unicode");
		return;
	}

#if (_WIN32_WINNT >= 0x0500)
	ReplaceFile(wtarget, wsource, NULL, REPLACEFILE_IGNORE_MERGE_ERRORS, NULL, NULL);
#else
	DeleteFile(wtarget);
	MoveFile(wsource, wtarget);
#endif
}

void wincopyfile(char *source, char *target)
{
	wchar_t wsource[PATH_MAX];
	wchar_t wtarget[PATH_MAX];

	int sz = MultiByteToWideChar(CP_UTF8, 0, source, -1, wsource, PATH_MAX);
	if (sz == 0)
	{
		winerror(&g_moonPdfApp, "cannot convert filename to Unicode");
		return;
	}

	sz = MultiByteToWideChar(CP_UTF8, 0, target, -1, wtarget, PATH_MAX);
	if (sz == 0)
	{
		winerror(&g_moonPdfApp, "cannot convert filename to Unicode");
		return;
	}

	CopyFile(wsource, wtarget, FALSE);
}

void winreloadpage(pdfapp_t *app)
{
	SendMessage(g_hShowPdfWnd, WM_APP, 0, 0);
}