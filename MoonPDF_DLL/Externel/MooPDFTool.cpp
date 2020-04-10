
#include "MooPDFTool.h"
#include "../Tools/MoonPdfUtils.h"
#include "../GlobalDefine.h"
#include "../Common/stringhelper.h"
#include <Windows.h>
#include <string>
using namespace std;

int MoonToolsExtractPageToSave(const char* srcPath, const char* tagPath, int pageIndex)
{
	pdf_document* srcDoc = NULL;//源文档
	pdf_document* tagDoc = NULL;//目标文档
	pdf_graft_map *graft_map = NULL;
	pdf_write_options opts = { 0 };
	string srcStrPath = UnicodeToUTF8(ANSIToUnicode(srcPath)).c_str();
	string savePath = UnicodeToUTF8(ANSIToUnicode(tagPath)).c_str();
	pdf_parse_write_options(g_moonPdfCtx, &opts, "");
	if (g_moonPdfCtx == NULL)
	{
		MessageBox(NULL,L"环境未初始化",L"",MB_OK);
		return -1;
	}
	fz_try(g_moonPdfCtx)
	{
		tagDoc = pdf_create_document(g_moonPdfCtx);
		srcDoc = pdf_open_document(g_moonPdfCtx, srcStrPath.c_str());
	}
	fz_catch(g_moonPdfCtx)
	{
		return -1;
	}
	graft_map = pdf_new_graft_map(g_moonPdfCtx, tagDoc);
	fz_try(g_moonPdfCtx)
	{
		PageMerge(g_moonPdfCtx, srcDoc, tagDoc, pageIndex, -1, graft_map);
	}
	fz_always(g_moonPdfCtx)
	{
		pdf_drop_document(g_moonPdfCtx, srcDoc);
		pdf_drop_graft_map(g_moonPdfCtx, graft_map);
	}
	fz_catch(g_moonPdfCtx)
	{
		pdf_drop_document(g_moonPdfCtx, tagDoc);
		return -1;
	}
	fz_try(g_moonPdfCtx)
	{
		pdf_save_document(g_moonPdfCtx, tagDoc, savePath.c_str(), &opts);
	}
	fz_always(g_moonPdfCtx)
	{
		pdf_drop_document(g_moonPdfCtx, tagDoc);
	}
	fz_catch(g_moonPdfCtx)
	{
		return -1;
	}
	return 0;
}

int MoonToolsGetPDFPageCount(const char* srcPath)
{
	int pageCount = 0;
	pdf_document* srcDoc = NULL;//源文档
	string srcStrPath = UnicodeToUTF8(ANSIToUnicode(srcPath)).c_str();
	if (g_moonPdfCtx == NULL)
	{
		MessageBox(NULL, L"环境未初始化", L"", MB_OK);
		return -1;
	}
	fz_try(g_moonPdfCtx)
	{
		srcDoc = pdf_open_document(g_moonPdfCtx, srcStrPath.c_str());
	}
	fz_catch(g_moonPdfCtx)
	{
		return -1;
	}
	pageCount = pdf_count_pages(g_moonPdfCtx, srcDoc);
	pdf_drop_document(g_moonPdfCtx, srcDoc);
	return pageCount;
}

/**
* 函数说明：
*   转到pdf的某一页到png图片
* 参数：
*   srcPath:pdf源文件地址
*   pageIndex:要转换的页索引，从0开始
*   zoom:
*   rotation:
* 返回值：
*   成功返回0，失败返回-1
*/
int MoonToolsPdfToPng(const char* srcPath, const int pageIndex, const int zoom, const int rotation)
{
	int ret = 0;
	//int alphabits_text = 8;
	//int alphabits_graphics = 8;
	//float min_line_width = 0.0f;
	//int layout_use_doc_css = 1;
	//fz_colorspace* colorspace = NULL;
	//fz_output* out = NULL;
	//Timing timing;
	//fz_document* doc = NULL;
	//fz_colorspace* oi = NULL;
	//fz_cmm_engine *icc_engine = &fz_cmm_engine_lcms;
	//if (g_moonPdfCtx == NULL)
	//{
	//	MessageBox(NULL, L"环境未初始化", L"", MB_OK);
	//	return -1;
	//}
	//fz_try(g_moonPdfCtx)
	//{
	//	fz_set_text_aa_level(g_moonPdfCtx, alphabits_text);
	//	fz_set_graphics_aa_level(g_moonPdfCtx, alphabits_graphics);
	//	fz_set_graphics_min_line_width(g_moonPdfCtx, min_line_width);
	//	fz_set_cmm_engine(g_moonPdfCtx, icc_engine);
	//	fz_set_use_document_css(g_moonPdfCtx, layout_use_doc_css);
	//	colorspace = fz_device_rgb(g_moonPdfCtx);
	//	colorspace = fz_keep_colorspace(g_moonPdfCtx, colorspace);
	//	out = fz_new_output_with_path(g_moonPdfCtx, "C:\\Users\\lengkristy\\Desktop\\1234.png", 0);
	//	timing.count = 0;
	//	timing.total = 0;
	//	timing.min = 1 << 30;
	//	timing.max = 0;
	//	timing.mininterp = 1 << 30;
	//	timing.maxinterp = 0;
	//	timing.minpage = 0;
	//	timing.maxpage = 0;
	//	timing.minfilename = "";
	//	timing.maxfilename = "";
	//	fz_try(g_moonPdfCtx)
	//	{
	//		fz_register_document_handlers(g_moonPdfCtx);
	//		doc = fz_open_document(g_moonPdfCtx, srcPath);
	//		/* Once document is open check for output intent colorspace */
	//		oi = fz_document_output_intent(g_moonPdfCtx, doc);
	//		fz_layout_document(g_moonPdfCtx, doc, 450, 600, 12.0f);
	//		drawrange(g_moonPdfCtx, doc, "1-N");
	//	}
	//	

	//}
	//fz_always(g_moonPdfCtx)
	//{
	//	//fz_drop_colorspace(g_moonPdfCtx, colorspace);
	//	//fz_drop_colorspace(g_moonPdfCtx, proof_cs);
	//}
	//fz_catch(g_moonPdfCtx)
	//{
	//}
	return ret;
}