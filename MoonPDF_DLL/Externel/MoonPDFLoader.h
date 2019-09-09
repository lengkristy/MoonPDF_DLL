#pragma once
/****************************************
 * MoonPDF加载器，使用初始化环境和释放环境
 */

#include "ExternelDefine.h"

/***
 * 函数说明：
 *	初始化moonpdf使用环境，
 * 返回值：
 *  成功返回0，失败返回-1
 */
MOONPDF_API_ int InitMoonPDFEnvironment();

/***
 * 函数说明：
 *	释放MoonPdf资源
 */
MOONPDF_API_ void DestoryMoonPDFEnvironment();