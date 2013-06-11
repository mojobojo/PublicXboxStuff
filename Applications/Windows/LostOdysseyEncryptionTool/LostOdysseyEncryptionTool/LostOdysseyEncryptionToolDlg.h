// LostOdysseyEncryptionToolDlg.h : header file
//

#pragma once


// CLostOdysseyEncryptionToolDlg dialog
class CLostOdysseyEncryptionToolDlg : public CDialog
{
// Construction
public:
	CLostOdysseyEncryptionToolDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_LOSTODYSSEYENCRYPTIONTOOL_DIALOG };

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
	CEdit FilePathInTheTextBox;
	afx_msg void OnBnClickedBrowsebutton();
	afx_msg void OnBnClickedDecryptbutton();
	afx_msg void OnBnClickedEncryptbutton();
};
