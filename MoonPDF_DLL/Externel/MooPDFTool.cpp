
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