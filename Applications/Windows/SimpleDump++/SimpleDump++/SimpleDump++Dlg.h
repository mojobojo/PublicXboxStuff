
// SimpleDump++Dlg.h : header file
//

#pragma once


// CSimpleDumpDlg dialog
class CSimpleDumpDlg : public CDialogEx
{
// Construction
public:
	CSimpleDumpDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_SIMPLEDUMP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CProgressCtrl ProgressControl;
	CButton GetMemExCheckbox;
	CEdit AddressBox;
	CEdit LengthBox;
	CButton Connect;
	CButton Disconnect;
	CButton Dump;

	afx_msg void OnBnClickedButtonconnect();
	afx_msg void OnBnClickedButtondisconnect();
	afx_msg void OnBnClickedButtondump();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
};
