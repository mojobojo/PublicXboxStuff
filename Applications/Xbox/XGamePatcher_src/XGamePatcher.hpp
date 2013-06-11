#pragma once
#include <xtl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <kernelp.h>
#include <kernel.h>

extern "C" const TCHAR szModuleName[] = TEXT( "XGamePatcher.dll" );
extern "C" const FLOAT dwModuleVer = 1.1;

extern "C"
{
	VOID ExRegisterThreadNotification( PEX_THREAD_REGISTRATION, BOOL );
	DWORD XamGetCurrentTitleId();

	VOID KeSweepIcacheRange( PVOID Address, DWORD cbBytes );

	extern PLDR_DATA_TABLE_ENTRY* XexExecutableModuleHandle;

	extern PKERNEL_VERSION XboxKrnlVersion;
}
