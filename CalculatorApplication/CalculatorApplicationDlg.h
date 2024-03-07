
// CalculatorApplicationDlg.h : header file
//

#pragma once


// CCalculatorApplicationDlg dialog
class CCalculatorApplicationDlg : public CDialogEx
{
// Construction
public:
	CCalculatorApplicationDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATORAPPLICATION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString EditResult;

	bool flag;
	float num1, num2, result;
	CString op;
	CString str1, str2;
	afx_msg void OnBnClickedB0();
	afx_msg void OnBnClickedB1();
	afx_msg void OnBnClickedB2();
	afx_msg void OnBnClickedB3();
	afx_msg void OnBnClickedB4();
	afx_msg void OnBnClickedB5();
	afx_msg void OnBnClickedB6();
	afx_msg void OnBnClickedB7();
	afx_msg void OnBnClickedB8();
	afx_msg void OnBnClickedB9();
	afx_msg void OnBnClickedBDot();
	afx_msg void OnBnClickedBPlus();
	afx_msg void OnBnClickedBMinus();
	afx_msg void OnBnClickedBStar();
	afx_msg void OnBnClickedBSlash();
	afx_msg void OnBnClickedBEqual();
	afx_msg void OnBnClickedBClear();
};
