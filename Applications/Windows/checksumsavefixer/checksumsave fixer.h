// checksumsave fixer.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CchecksumsavefixerApp:
// See checksumsave fixer.cpp for the implementation of this class
//

class CchecksumsavefixerApp : public CWinApp
{
public:
	CchecksumsavefixerApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CchecksumsavefixerApp theApp;