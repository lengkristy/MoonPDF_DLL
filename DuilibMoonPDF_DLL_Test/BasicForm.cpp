#include "stdafx.h"
#include "BasicForm.h"
#include "PdfControl.h"
#include "MoonPDFView.h"

const std::wstring BasicForm::kClassName = L"Basic";

BasicForm::BasicForm()
{
}


BasicForm::~BasicForm()
{
}

std::wstring BasicForm::GetSkinFolder()
{
	return L"pdf";
}

std::wstring BasicForm::GetSkinFile()
{
	return L"pdf.xml";
}

std::wstring BasicForm::GetWindowClassName() const
{
	return kClassName;
}

void BasicForm::InitWindow()
{
	m_pBtnMax = (ui::Button*)FindControl(L"btnMax");
	m_pBtnMax->AttachClick(nbase::Bind(&BasicForm::MainMenuButtonClick, this, std::placeholders::_1));
}

LRESULT BasicForm::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	PostQuitMessage(0L);
	return __super::OnClose(uMsg, wParam, lParam, bHandled);
}

ui::Control* BasicForm::CreateControl(const std::wstring& pstrClass)
{
	if (pstrClass == L"PdfControl")
	{
		return new PdfControl;
	}

	return NULL;
}

bool BasicForm::MainMenuButtonClick(ui::EventArgs* param)
{
	MoonZoomIn();
	return true;
}