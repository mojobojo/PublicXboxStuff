#include <xtl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "Tools.hpp"

VOID MainThread()
{
	// Do code here
}

BOOL APIENTRY DllMain( HANDLE hModule, DWORD dwReason, LPVOID lpReserved ) 
{
	if ( dwReason == DLL_PROCESS_ATTACH ) 
	{
		HANDLE hThread;
		DWORD dwThreadId;
		
		ExCreateThread( &hThread, 0, &dwThreadId, ( PVOID )XapiThreadStartup , ( LPTHREAD_START_ROUTINE )MainThread, 0, 0x2 );

		ResumeThread( hThread );
		CloseHandle( hThread );
	}

	return TRUE;
}

