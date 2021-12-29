#pragma once

/********************
 * PDF��ͼ�Ķ���
 */

#include "ExternelDefine.h"
#include <Windows.h>


/***
 * ����˵����
 *   ʹ��HWND������Ⱦ�����ʼ��
 * ������
 *   hWnd����ʾ�Ĵ�����
 */
MOONPDF_API_ int WindowCompentInit(HWND hWnd);

/***
* ����˵����
*   ʹ��hdc������Ⱦ�����ʼ��
* ������
*   hWnd����ʾ�Ĵ�����
*/
MOONPDF_API_ int WindowCompentInitByHdc(HDC hdc);

/***
 * ����˵����
 *   ����PDF
 * ����˵����
 *   pdfPath:�ļ�·��
 */
MOONPDF_API_ int MoonPDFLoad(char *pdfPath);

/***
 * ����˵��
 *   ����pdf��ʾ������
 */
MOONPDF_API_ void MoonPaintPDF();

/**
 * ����˵����
 *   ����PDF��С
 * ������
 *   width�����
 *   height���߶�
 */
MOONPDF_API_ void MoonResizePDF(int width,int height);

/***
 * ����˵����
 *   ��pdf�������Ŵ�
 */
MOONPDF_API_ void MoonZoomIn();

/***
 * ����˵����
 *   ��pdf��������С
 */
MOONPDF_API_ void MoonZoomOut();

/***
 * ����˵����
 *   ��pdf˳ʱ����ת90��
 */
MOONPDF_API_ void MoonClockwiseRotation();

/***
 * ����˵����
 *   ��pdf��ʱ����ת90��
 */
MOONPDF_API_ void MoonContrarotate();

/***
 * ����˵����
 *   ��ȡpdf��ҳ��
 * ����ֵ��
 *   ������ҳ��
 */
MOONPDF_API_ int MoonGetPDFPageCount();

/***
 * ����˵����
 *   ��ת�������ҳ
 * ������
 *   pageIndex��ҳ����
 */
MOONPDF_API_ void MoonGotoPage(int pageIndex);

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
 */
MOONPDF_API_ void MoonAddTextAnnotation(char* context,char* author,int pageIndex,float leftTopX,float leftTopY,float rightBottomX,float rightBottomY);

/**
 * ����˵����
 *   ��ȡpdf��ע�͵�����
 * ����ֵ��
 *   �ɹ�����ע�͵�������ʧ�ܷ���-1
 */
MOONPDF_API_ int MoonGetAnnotationCount();