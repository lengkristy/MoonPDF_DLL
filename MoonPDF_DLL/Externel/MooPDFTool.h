#pragma once
/***
 * 用于导出所有关于PDF工具操作的接口
 */

#include "ExternelDefine.h"

/*****
 * 函数说明：
 *   提取页保存
 * 参数说明：
 *   srcPath:源文件路径
 *   tagPath:需要保存的文件路径
 *   pageIndex:提取的页索引
 * 返回值：
 *   成功返回0，失败返回-1
 */
MOONPDF_API_ int MoonToolsExtractPageToSave(const char* srcPath, const char* tagPath, int pageIndex);

/***
 * 函数说明：
 *   获取pdf页的总数
 * 参数：
 *   srcPath:返回pdf的页数
 * 返回值：
 *   返回pdf页总数
 */
MOONPDF_API_ int MoonToolsGetPDFPageCount(const char* srcPath);

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
MOONPDF_API_ int MoonToolsPdfToPng(const char* srcPath, const int pageIndex, const int zoom, const int rotation);