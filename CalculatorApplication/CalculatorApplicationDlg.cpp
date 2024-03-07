
// CalculatorApplicationDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "CalculatorApplication.h"
#include "CalculatorApplicationDlg.h"
#include "afxdialogex.h"
#include "../CalculatorOperations/COperations.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculatorApplicationDlg dialog



CCalculatorApplicationDlg::CCalculatorApplicationDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATORAPPLICATION_DIALOG, pParent)
	, EditResult(_T(""))
{
	flag = true;
	num1 = num2 = result = 0;
	str1 = _T("");
	str2 = _T("");
	op = _T("");
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorApplicationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, EditResult);
}

BEGIN_MESSAGE_MAP(CCalculatorApplicationDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_B0, &CCalculatorApplicationDlg::OnBnClickedB0)
	ON_BN_CLICKED(IDC_B1, &CCalculatorApplicationDlg::OnBnClickedB1)
	ON_BN_CLICKED(IDC_B2, &CCalculatorApplicationDlg::OnBnClickedB2)
	ON_BN_CLICKED(IDC_B3, &CCalculatorApplicationDlg::OnBnClickedB3)
	ON_BN_CLICKED(IDC_B4, &CCalculatorApplicationDlg::OnBnClickedB4)
	ON_BN_CLICKED(IDC_B5, &CCalculatorApplicationDlg::OnBnClickedB5)
	ON_BN_CLICKED(IDC_B6, &CCalculatorApplicationDlg::OnBnClickedB6)
	ON_BN_CLICKED(IDC_B7, &CCalculatorApplicationDlg::OnBnClickedB7)
	ON_BN_CLICKED(IDC_B9, &CCalculatorApplicationDlg::OnBnClickedB9)
	ON_BN_CLICKED(IDC_B_DOT, &CCalculatorApplicationDlg::OnBnClickedBDot)
	ON_BN_CLICKED(IDC_B_PLUS, &CCalculatorApplicationDlg::OnBnClickedBPlus)
	ON_BN_CLICKED(IDC_B_MINUS, &CCalculatorApplicationDlg::OnBnClickedBMinus)
	ON_BN_CLICKED(IDC_B_STAR, &CCalculatorApplicationDlg::OnBnClickedBStar)
	ON_BN_CLICKED(IDC_B_SLASH, &CCalculatorApplicationDlg::OnBnClickedBSlash)
	ON_BN_CLICKED(IDC_B_EQUAL, &CCalculatorApplicationDlg::OnBnClickedBEqual)
	ON_BN_CLICKED(IDC_B_CLEAR, &CCalculatorApplicationDlg::OnBnClickedBClear)
	ON_BN_CLICKED(IDC_B8, &CCalculatorApplicationDlg::OnBnClickedB8)
END_MESSAGE_MAP()


// CCalculatorApplicationDlg message handlers

BOOL CCalculatorApplicationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalculatorApplicationDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCalculatorApplicationDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalculatorApplicationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculatorApplicationDlg::OnBnClickedB0()
{
	// TODO: Add your control notification handler code here
	if (flag == true)
	{
		str1 += _T("0");
		EditResult = str1;
	}
	else
	{
		str2 += _T("0");
		EditResult = str2;
	}
	UpdateData(false);
}


void CCalculatorApplicationDlg::OnBnClickedB1()
{
	// TODO: Add your control notification handler code here
	if (flag == true)
	{
		str1 += _T("1");
		EditResult = str1;
	}
	else
	{
		str2 += _T("1");
		EditResult = str2;
	}
	UpdateData(false);
}


void CCalculatorApplicationDlg::OnBnClickedB2()
{
	// TODO: Add your control notification handler code here
	if (flag == true)
	{
		str1 += _T("2");
		EditResult = str1;
	}
	else
	{
		str2 += _T("2");
		EditResult = str2;
	}
	UpdateData(false);
}


void CCalculatorApplicationDlg::OnBnClickedB3()
{
	// TODO: Add your control notification handler code here
	if (flag == true)
	{
		str1 += _T("3");
		EditResult = str1;
	}
	else
	{
		str2 += _T("3");
		EditResult = str2;
	}
	UpdateData(false);
}


void CCalculatorApplicationDlg::OnBnClickedB4()
{
	// TODO: Add your control notification handler code here
	if (flag == true)
	{
		str1 += _T("4");
		EditResult = str1;
	}
	else
	{
		str2 += _T("4");
		EditResult = str2;
	}
	UpdateData(false);
}


void CCalculatorApplicationDlg::OnBnClickedB5()
{
	// TODO: Add your control notification handler code here
	if (flag == true)
	{
		str1 += _T("5");
		EditResult = str1;
	}
	else
	{
		str2 += _T("5");
		EditResult = str2;
	}
	UpdateData(false);
}


void CCalculatorApplicationDlg::OnBnClickedB6()
{
	// TODO: Add your control notification handler code here
	if (flag == true)
	{
		str1 += _T("6");
		EditResult = str1;
	}
	else
	{
		str2 += _T("6");
		EditResult = str2;
	}
	UpdateData(false);
}


void CCalculatorApplicationDlg::OnBnClickedB7()
{
	// TODO: Add your control notification handler code here
	if (flag == true)
	{
		str1 += _T("7");
		EditResult = str1;
	}
	else
	{
		str2 += _T("7");
		EditResult = str2;
	}
	UpdateData(false);
}


void CCalculatorApplicationDlg::OnBnClickedB8()
{
	// TODO: Add your control notification handler code here
	if (flag == true)
	{
		str1 += _T("8");
		EditResult = str1;
	}
	else
	{
		str2 += _T("8");
		EditResult = str2;
	}
	UpdateData(false);
}


void CCalculatorApplicationDlg::OnBnClickedB9()
{
	// TODO: Add your control notification handler code here
	if (flag == true)
	{
		str1 += _T("9");
		EditResult = str1;
	}
	else
	{
		str2 += _T("9");
		EditResult = str2;
	}
	UpdateData(false);
}


void CCalculatorApplicationDlg::OnBnClickedBDot()
{
	// TODO: Add your control notification handler code here
	if (flag == true)
	{
		str1 += _T(".");
		EditResult = str1;
	}
	else
	{
		str2 += _T(".");
		EditResult = str2;
	}
	UpdateData(false);
}


void CCalculatorApplicationDlg::OnBnClickedBPlus()
{
	// TODO: Add your control notification handler code here
	if (EditResult != _T(""))
	{
		num1 = _ttof(EditResult);
		op = _T("+");
		flag = !flag;
		EditResult = _T("");
	}
}


void CCalculatorApplicationDlg::OnBnClickedBMinus()
{
	// TODO: Add your control notification handler code here
	if (EditResult != _T(""))
	{
		num1 = _ttof(EditResult);
		op = _T("-");
		flag = !flag;
		EditResult = _T("");
	}
}


void CCalculatorApplicationDlg::OnBnClickedBStar()
{
	// TODO: Add your control notification handler code here
	if (EditResult != _T(""))
	{
		num1 = _ttof(EditResult);
		op = _T("*");
		flag = !flag;
		EditResult = _T("");
	}
}


void CCalculatorApplicationDlg::OnBnClickedBSlash()
{
	// TODO: Add your control notification handler code here
	if (EditResult != _T(""))
	{
		num1 = _ttof(EditResult);
		op = _T("/");
		flag = !flag;
		EditResult = _T("");
	}
}


void CCalculatorApplicationDlg::OnBnClickedBEqual()
{
	// TODO: Add your control notification handler code here
	if (EditResult != _T(""))
	{
		num2 = _ttof(EditResult);
		flag = !flag;
		EditResult = _T("");
	}

	COperations operations;
	if (op == _T("+"))
	{
		result = operations.add(num1, num2);
	}
	else if (op == _T("-"))
	{
		result = operations.subtract(num1, num2);
	}
	else if (op == _T("*"))
	{
		result = operations.multiply(num1, num2);
	}
	else if (op == _T("/"))
	{
		result = operations.divide(num1, num2);
	}
	else
	{
		result = num1;
	}

	EditResult.Format(_T("%.2f"), result);
	UpdateData(false);
	str1 = _T("");
	str2 = _T("");
}


void CCalculatorApplicationDlg::OnBnClickedBClear()
{
	// TODO: Add your control notification handler code here
	EditResult = _T("");
	UpdateData(false);
}



