#pragma once

class PdfControl : public ui::Control
{
public:
	PdfControl();
	virtual ~PdfControl();

	/**
	* ��д���ؼ����ƺ���
	* @param[in] hDC Ŀ��DC
	* @param[in] rcPaint �ɻ�������
	* @return void	�޷���ֵ
	*/
	virtual void Paint(ui::IRenderContext* pRender, const ui::UiRect& rcPaint) override;

	HBITMAP bitmap_;
};

