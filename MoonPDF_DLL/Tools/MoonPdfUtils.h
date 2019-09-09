#pragma once

/*******************************
 * 操作pdf相关的工具接口
 */

#include "../mupdf/pdfapp.h"

/***
 * 合并页
 */
void PageMerge(fz_context *ctx, pdf_document * doc_src, pdf_document *doc_des, int page_from, int page_to, pdf_graft_map *graft_map);