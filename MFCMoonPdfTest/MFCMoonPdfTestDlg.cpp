
// MFCMoonPdfTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCMoonPdfTest.h"
#include "MFCMoonPdfTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCMoonPdfTestDlg 对话框



CMFCMoonPdfTestDlg::CMFCMoonPdfTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCMoonPdfTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCMoonPdfTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BTN_PDF, m_btnpdfview);
}

BEGIN_MESSAGE_MAP(CMFCMoonPdfTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_SELECT_FILE, &CMFCMoonPdfTestDlg::OnBnClickedBtnSelectFile)
END_MESSAGE_MAP()


// CMFCMoonPdfTestDlg 消息处理程序

BOOL CMFCMoonPdfTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	//初始化pdf环境
	int ret = InitMoonPDFEnvironment();
	if (ret == -1){
		MessageBox(L"初始化pdf环境失败", L"失败", MB_OK);
	}

	//
	WindowCompentInit(NULL); 
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCMoonPdfTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCMoonPdfTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
	CWnd * pWnd = GetDlgItem(IDC_BTN_PDF);
	CDC *pDC = pWnd->GetDC();
	HDC hdc = pDC->GetSafeHdc();

	MoonPaintPDF(hdc);
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCMoonPdfTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCMoonPdfTestDlg::OnBnClickedBtnSelectFile()
{
	// TODO:  在此添加控件通知处理程序代码
	//打开文件
	CString filter = L"文件 (*.pdf)|*.pdf||";	//文件过虑的类型
	CFileDialog openFileDlg(1, L"", L"", OFN_HIDEREADONLY | OFN_READONLY, filter, NULL);
	CString filePath = L"";
	INT_PTR result = openFileDlg.DoModal();
	if (result ==IDOK) {
		filePath = openFileDlg.GetPathName();
	}
	
	char *ch;

	ch = (char*)malloc(wcslen(filePath) * 2);
	::WideCharToMultiByte(CP_ACP, 0, filePath, -1, ch, wcslen(filePath) * 2, NULL, NULL);


	MoonPDFLoad(ch);

	CRect rectCtrl;
	//this->GetDlgItem(IDC_STATIC_PDF_VIEW)->GetClientRect(rectCtrl);
	m_btnpdfview.GetClientRect(&rectCtrl);
	//重绘界面
	MoonResizePDF(rectCtrl.Width(),rectCtrl.Height());
	delete ch;
}
