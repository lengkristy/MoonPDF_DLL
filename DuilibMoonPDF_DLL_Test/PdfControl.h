#pragma once

class PdfControl : public ui::Control
{
public:
	PdfControl();
	virtual ~PdfControl();

	/**
	* 重写父控件绘制函数
	* @param[in] hDC 目标DC
	* @param[in] rcPaint 可绘制区域
	* @return void	无返回值
	*/
	virtual void Paint(ui::IRenderContext* pRender, const ui::UiRect& rcPaint) override;

	HBITMAP bitmap_;
};

