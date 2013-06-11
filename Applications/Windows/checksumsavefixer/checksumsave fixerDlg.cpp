// checksumsave fixerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "checksumsave fixer.h"
#include "checksumsave fixerDlg.h"
#include "FolderDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CchecksumsavefixerDlg dialog




CchecksumsavefixerDlg::CchecksumsavefixerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CchecksumsavefixerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CchecksumsavefixerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CchecksumsavefixerDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CchecksumsavefixerDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CchecksumsavefixerDlg message handlers

BOOL CchecksumsavefixerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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

void CchecksumsavefixerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CchecksumsavefixerDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CchecksumsavefixerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CchecksumsavefixerDlg::OnBnClickedOk()
{

	CString p_FileNames[8] = { 
		"saveuid.bin", 
		"mainsave.bin", 
		"leaderboardstatssave.bin", 
		"herosave.bin", 
		"failquestmainsave.bin", 
		"failquestherosave.bin", 
		"entityuid.bin",
		"chaptersave.bin"
	};

	CString p_ChecksumSave = "checksumsave.bin";


	CFolderDialog openfolder("Open your savegame files directory.", "C:\\", this);

	if (openfolder.DoModal() != IDOK)
		return;

	CString folderpath = openfolder.GetFolderPath();

	if (strlen(folderpath) <= 0)
		return;

	unsigned int finalchecksum = 0;

	for (int i = 0; i < 8; i++) {
		CString full = folderpath;
		full.Append("\\");
		full.Append(p_FileNames[i]);
		
		FILE* f = fopen(full, "rb");
		if (!f) {
			continue;
			/*CString errormsg;
			errormsg.Format("Unable to open file \'%s\'", full);
			MessageBox(errormsg, "Error", NULL);
			return;*/
		}

		fseek(f, 0, SEEK_END);
		int size = ftell(f);
		fclose(f);

		finalchecksum += size;
	}

	CString fullchecksumsave = folderpath;
	fullchecksumsave.Append("\\");
	fullchecksumsave.Append(p_ChecksumSave);

	FILE* f = fopen(fullchecksumsave, "wb");

	BYTE p_buffer[4];

	p_buffer[0] = (BYTE)((finalchecksum & 0xFF000000) >> 24);
	p_buffer[1] = (BYTE)((finalchecksum & 0x00FF0000) >> 16);
	p_buffer[2] = (BYTE)((finalchecksum & 0x0000FF00) >> 8);
	p_buffer[3] = (BYTE)(finalchecksum & 0x000000FF);

	fwrite(p_buffer, 1, 4, f);
	fflush(f);
	fclose(f);

	MessageBox("Done!", "Done", NULL);
}
