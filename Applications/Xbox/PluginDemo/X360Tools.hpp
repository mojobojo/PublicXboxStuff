#pragma once
#ifndef X360TOOLS_H
#define X360TOOLS_H

#include <xtl.h>
#include <ppcintrinsics.h>

#include <kernel.h>

#ifdef __cplusplus
extern "C"
{
#endif
	DWORD	__stdcall	ExCreateThread(
		PHANDLE					pHandle, 
		DWORD					dwStackSize, 
		LPDWORD					lpThreadId, 
		VOID*					apiThreadStartup , 
		LPTHREAD_START_ROUTINE	lpStartAddress, 
		LPVOID					lpParameter, 
		DWORD					dwCreationFlagsMod
		);

	DWORD MmIsAddressValid(PVOID addr);

	HRESULT XeKeysGetKey(unsigned int Key, void* Buf, unsigned int * Size);

	void XeCryptBnQw_SwapDwQwLeBe(void *ptr1, void *ptr2, unsigned int anint);

	HRESULT XeCryptBnQwNeRsaPubCrypt(void *r3, void *r4, void *r5);

	void XeKeysGetConsoleID(char *r3, int r4);

	HRESULT XeKeysGetConsoleCertificate(unsigned char *data);

	unsigned int XexLoadImageFromMemory(unsigned int r3, unsigned int r4, char *r5, unsigned int r6, unsigned int r7, unsigned int r8);

	void NetDll_XNetRandom(unsigned int r3, void *r4, unsigned int r5);

	void HalReturnToFirmware(unsigned int r3);
#ifdef __cplusplus
}
#endif

void	MessageBox(LPCWSTR Text, LPCWSTR Caption);
UINT32	ResolveFunct(char* modname, UINT32 ord);
DWORD	GetPressedButtons();

#endif