#pragma once

#define _IN_  //定义输入参数
#define _OUT_ //定义输出参数
#define _GLOBAL_ //定义全局变量

//定义函数导出
#ifndef MOONPDF_API_
#define MOONPDF_API_ extern "C" _declspec (dllimport)
#else
#define MOONPDF_API_ extern "C" _declspec (dllexport)
#endif