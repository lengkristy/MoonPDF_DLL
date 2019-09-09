// MoonPDFCPP_Test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "../MoonPDF_DLL/Externel/MoonPDF.h"

#pragma comment(lib,"../Debug/MoonPDF_DLL.lib")

int main()
{
	int ret = InitMoonPDFEnvironment();
	if (ret == -1)
	{
		return -1;
	}
	ret = MoonToolsExtractPageToSave("E:\\技术资料\\ORANGE’S：一个操作系统的实现（高清晰版）1.pdf", "E:\\技术资料\\123.pdf", 1);
	DestoryMoonPDFEnvironment();

	ret = InitMoonPDFEnvironment();
	if (ret == -1)
	{
		return -1;
	}
	ret = MoonToolsExtractPageToSave("E:\\技术资料\\ORANGE’S：一个操作系统的实现（高清晰版）1.pdf", "E:\\技术资料\\444.pdf", 1);
	DestoryMoonPDFEnvironment();
    return 0;
}

