
// SimpleDump++Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "SimpleDump++.h"
#include "SimpleDump++Dlg.h"
#include "afxdialogex.h"
#include <xbdm.h>
#include <fstream>
#include <math.h>
#include <dbghelp.h>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSimpleDumpDlg dialog
CButton *cdumpbtn = NULL;
CProgressCtrl *ctrl = NULL;
CButton *cdisconbtn = NULL;
PDM_CONNECTION m_Xbox = NULL;

void DumpMiniDump(HANDLE hFile, PEXCEPTION_POINTERS excpInfo)
{
    MINIDUMP_EXCEPTION_INFORMATION eInfo;
    eInfo.ThreadId = GetCurrentThreadId();
    eInfo.ExceptionPointers = excpInfo;
    eInfo.ClientPointers = FALSE;

    // note:  MiniDumpWithIndirectlyReferencedMemory does not work on Win98
    MiniDumpWriteDump(
        GetCurrentProcess(),
        GetCurrentProcessId(),
        hFile,
        MiniDumpNormal,
        excpInfo ? &eInfo : NULL,
        NULL,
        NULL);
}

LONG WINAPI Exception(PEXCEPTION_POINTERS pExcepPointers)
{
	char msg[512];
	sprintf_s(msg, 512, "An unhandled exception (0x%08X) has occured at address 0x%08X.\nWould you like to create a dump file? (Suggested)\n", 
		pExcepPointers->ExceptionRecord->ExceptionCode, 
		pExcepPointers->ExceptionRecord->ExceptionAddress
		);

	if (MessageBox(NULL, msg, NULL, MB_YESNO) != IDYES)
		goto end;

	HANDLE h = CreateFile("minidump.dmp", GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, NULL, NULL);

	if (h != INVALID_HANDLE_VALUE)
	{
		//printf("Making minidump\n");
		DumpMiniDump(h, pExcepPointers);

		MessageBox(NULL, "Dump file created. Please send it to the developer.\nThe name of it is \'minidump.dmp\' and its in the same directory as where you launched the application\n", NULL, NULL);
	}
	else
	{
		//printf("Unable to create file");
	}

end:
	ExitProcess(-1);
}

CSimpleDumpDlg::CSimpleDumpDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSimpleDumpDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSimpleDumpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_PROGRESS1, ProgressControl);
	DDX_Control(pDX, IDC_EDIT1, AddressBox);
	DDX_Control(pDX, IDC_EDIT2, LengthBox);
	DDX_Control(pDX, IDC_BUTTONCONNECT, Connect);
	DDX_Control(pDX, IDC_BUTTONDISCONNECT, Disconnect);
	DDX_Control(pDX, IDC_BUTTONDUMP, Dump);
}

BEGIN_MESSAGE_MAP(CSimpleDumpDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTONCONNECT, &CSimpleDumpDlg::OnBnClickedButtonconnect)
	ON_BN_CLICKED(IDC_BUTTONDISCONNECT, &CSimpleDumpDlg::OnBnClickedButtondisconnect)
	ON_BN_CLICKED(IDC_BUTTONDUMP, &CSimpleDumpDlg::OnBnClickedButtondump)
	ON_BN_CLICKED(IDC_BUTTON4, &CSimpleDumpDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CSimpleDumpDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CSimpleDumpDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CSimpleDumpDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CSimpleDumpDlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// CSimpleDumpDlg message handlers

BOOL CSimpleDumpDlg::OnInitDialog()
{
	SetUnhandledExceptionFilter(Exception);

	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	if (!LoadXBDM())
	{
		MessageBox("Unable to load xbdm.dll. Please ensure you have the Xbox 360 SDK installed.", "Error", NULL);
		ExitProcess(-1);
	}

	ProgressControl.SetRange(0, 100);
	ProgressControl.SetStep(1);

	ctrl = &ProgressControl;
	cdumpbtn = &Dump;
	cdisconbtn = &Disconnect;

	Disconnect.EnableWindow(FALSE);
	Dump.EnableWindow(FALSE);

	this->AddressBox.SetWindowTextA("0x82000000");
	this->LengthBox.SetWindowTextA("0x5000000");

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSimpleDumpDlg::OnPaint()
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
HCURSOR CSimpleDumpDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSimpleDumpDlg::OnBnClickedButtonconnect()
{
	DWORD devkitNameSize = MAX_PATH;
    char devkitName[MAX_PATH];

	HRESULT hRet = DmGetNameOfXbox(devkitName, &devkitNameSize, TRUE);

	hRet = DmOpenConnection(&m_Xbox);

	if (FAILED(hRet))
	{
		MessageBox(
			"Failed to connect to your Xbox 360!\n"
			"Please make sure you have a valid connection and\n"
			"your Xbox 360 has the XBDM plugin or is a devkit.", "Error", NULL);
		return;
	}

	string str = "";
	str.append("Connected - ");
	str.append(devkitName);

	this->SetWindowTextA(str.c_str());

	Connect.EnableWindow(FALSE);
	Disconnect.EnableWindow(TRUE);
	Dump.EnableWindow(TRUE);
}


void CSimpleDumpDlg::OnBnClickedButtondisconnect()
{
	DmCloseConnection(m_Xbox);
	m_Xbox = NULL;
	this->SetWindowTextA("Disconnected");
	Connect.EnableWindow(TRUE);
	Disconnect.EnableWindow(FALSE);
	Dump.EnableWindow(FALSE);
}

DWORD WINAPI DumpThread(LPVOID lpParam)
{
	DWORD *params = (DWORD*)lpParam;

	DWORD dwAddress = params[0];
	DWORD dwLength = params[1];
	PCHAR strOutPath = (PCHAR)params[2];

	DWORD PageSize = XMemGetPageSize((PVOID)dwAddress);

	//FILE *f = fopen(strOutPath, "wb");

	FILE *f = NULL;
	fopen_s(&f, strOutPath, "wb");

	if (!f)
	{
		MessageBox(NULL, "Unable to create file!", "Error", NULL);
		cdumpbtn->EnableWindow(TRUE);
		cdisconbtn->EnableWindow(TRUE);
		return 1;
	}

	PBYTE Data = new BYTE[PageSize];

	for (DWORD i = 0; i < dwLength / PageSize; i++)
	{
		ZeroMemory(Data, PageSize);

		double percentage = ((double)(i * PageSize) / (double)(dwLength)) * 100;

		ctrl->SetPos((int)floor(percentage));

		DmGetMemory((LPCVOID)(dwAddress + (i * PageSize)), PageSize, Data, NULL);

		fwrite(Data, 1, PageSize, f);
	}

	DWORD remainder = dwLength % PageSize;
	DmGetMemory((LPCVOID)(dwAddress + (dwLength - remainder)), remainder, Data, NULL);
	
	fwrite(Data, 1, remainder, f);

	fflush(f);
	fclose(f);

	delete Data;

	ctrl->SetPos(0);

	MessageBox(NULL, "Done!", "Success", NULL);

	cdumpbtn->EnableWindow(TRUE);
	cdisconbtn->EnableWindow(TRUE);
	return 0;
}

void CSimpleDumpDlg::OnBnClickedButtondump()
{
	CHAR address_str[512];
	CHAR length_str[512];

	this->AddressBox.GetWindowTextA(address_str, 512);
	this->LengthBox.GetWindowTextA(length_str, 512);

	if (strlen(address_str) < 1 || strlen(length_str) < 1)
	{
		MessageBox("Please specify a valid length and address", "Error", NULL);
		return;
	}

	DWORD dwAddress = strtoul(address_str, NULL, NULL);
	DWORD dwLength = strtoul(length_str, NULL, NULL);

	if (dwLength < 1)
		return;

	CFileDialog dialog(FALSE, "", "", NULL, "", this);

	if (dialog.DoModal() != IDOK)
		return;

	CString filename = dialog.GetPathName();
	CHAR *fname = new CHAR[MAX_PATH];
	strcpy_s(fname, MAX_PATH, filename);

	DWORD *params = new DWORD[3];
	params[0] = dwAddress;
	params[1] = dwLength;
	params[2] = (DWORD)fname;

	Dump.EnableWindow(FALSE);
	Disconnect.EnableWindow(FALSE);
	CreateThread(NULL, NULL, DumpThread, params, NULL, NULL);
}


void CSimpleDumpDlg::OnBnClickedButton4()
{
	this->AddressBox.SetWindowTextA("0xC0000000");
	this->LengthBox.SetWindowTextA("0x1FFF0FFF");
}


void CSimpleDumpDlg::OnBnClickedButton5()
{
	this->AddressBox.SetWindowTextA("0x82000000");
	this->LengthBox.SetWindowTextA("0x5000000");
}


void CSimpleDumpDlg::OnBnClickedButton6()
{
	this->AddressBox.SetWindowTextA("0x40000000");
	this->LengthBox.SetWindowTextA("0x5000000");
}


void CSimpleDumpDlg::OnBnClickedButton7()
{
	this->AddressBox.SetWindowTextA("0x30000000");
	this->LengthBox.SetWindowTextA("0x5000000");
}


void CSimpleDumpDlg::OnBnClickedButton8()
{
	this->AddressBox.SetWindowTextA("0x70000000");
	this->LengthBox.SetWindowTextA("0x5000000");
}
