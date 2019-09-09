#pragma once

/********************
 * PDF视图阅读器
 */

#include "ExternelDefine.h"
#include <Windows.h>


/***
 * 函数说明：
 *   窗体组件初始化
 * 参数：
 *   hWnd：显示的窗体句柄
 */
MOONPDF_API_ int WindowCompentInit(HWND hWnd);

/***
 * 函数说明：
 *   加载PDF
 * 参数说明：
 *   pdfPath:文件路径
 */
MOONPDF_API_ int MoonPDFLoad(char *pdfPath);

/***
 * 函数说明
 *   绘制pdf显示到界面
 */
MOONPDF_API_ void MoonPaintPDF();

/**
 * 函数说明：
 *   重置PDF大小
 * 参数：
 *   width：宽度
 *   height：高度
 */
MOONPDF_API_ void MoonResizePDF(int width,int height);

/***
 * 函数说明：
 *   将pdf按比例放大
 */
MOONPDF_API_ void MoonZoomIn();

/***
 * 函数说明：
 *   将pdf按比例缩小
 */
MOONPDF_API_ void MoonZoomOut();

/***
 * 函数说明：
 *   将pdf顺时针旋转90度
 */
MOONPDF_API_ void MoonClockwiseRotation();

/***
 * 函数说明：
 *   将pdf逆时针旋转90度
 */
MOONPDF_API_ void MoonContrarotate();

/***
 * 函数说明：
 *   获取pdf总页数
 * 返回值：
 *   返回总页数
 */
MOONPDF_API_ int MoonGetPDFPageCount();

/***
 * 函数说明：
 *   跳转到具体的页
 * 参数：
 *   pageIndex：页索引
 */
MOONPDF_API_ void MoonGotoPage(int pageIndex);