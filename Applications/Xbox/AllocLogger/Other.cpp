#include <xtl.h>
#include <stdio.h>
#include <stdlib.h>
#include <kernel.h>
#include <ppcintrinsics.h>
#include <string.h>

#include "Other.hpp"

DWORD ResolveFunct(PCHAR modname, DWORD ord)
{
	DWORD ret=0, ptr2=0;
	HANDLE hand;
	ret = XexGetModuleHandle(modname, &hand); //xboxkrnl.exe xam.dll?
	if(ret == 0)
	{
		ret = XexGetProcedureAddress(hand, ord, &ptr2 );
		if(ptr2 != 0)
			return ptr2;
	}
	return 0; // function not found
}

VOID PatchInJump(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3D600000 + (((dest >> 16) & 0xFFFF) + 1); // lis 	%r11, dest>>16 + 1
	else
		addr[0] = 0x3D600000 + ((dest >> 16) & 0xFFFF); // lis 	%r11, dest>>16

	addr[1] = 0x396B0000 + (dest & 0xFFFF); // addi	%r11, %r11, dest&0xFFFF
	addr[2] = 0x7D6903A6; // mtctr	%r11

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
}

HRESULT doMountPath(const char* szDrive, const char* szDevice, const char* sysStr)
{
	CHAR szDestinationDrive[MAX_PATH];
	sprintf_s(szDestinationDrive, MAX_PATH, sysStr, szDrive);
	STRING DeviceName = MAKE_STRING(szDevice);
	STRING LinkName = MAKE_STRING(szDestinationDrive);
	ObDeleteSymbolicLink(&LinkName);
	return (HRESULT)ObCreateSymbolicLink(&LinkName, &DeviceName);
}

HRESULT MountPath(const char* szDrive, const char* szDevice, BOOL both)
{
	HRESULT res;
	if(both)
	{
		res = doMountPath(szDrive, szDevice, "\\System??\\%s");
		res = doMountPath(szDrive, szDevice, "\\??\\%s");
	}
	else
	{
		if(KeGetCurrentProcessType() == SYSTEM_PROC)
			res = doMountPath(szDrive, szDevice, "\\System??\\%s");
		else
			res = doMountPath(szDrive, szDevice, "\\??\\%s");
	}
	return res;
}

BYTE *GetFile(CHAR *szPath, PDWORD pdwOutSize)
{
	FILE *f = fopen(szPath, "rb");

	if (!f)
	{
		*pdwOutSize = 0;
		return NULL;
	}

	fseek(f, 0, SEEK_END);
	*pdwOutSize = ftell(f);
	rewind(f);

	BYTE *pbReturnData = (BYTE*)malloc(*pdwOutSize);

	fread(pbReturnData, 1, *pdwOutSize, f);

	fclose(f);

	return pbReturnData;
}

BOOL DumpFile(CHAR *szFileName, BYTE *pbData, DWORD dwSize)
{
	FILE *f = fopen(szFileName, "wb");

	if (f)
	{
		fwrite(pbData, 1, dwSize, f);
		fflush(f);
		fclose(f);
		return TRUE;
	}

	return FALSE;
}

VOID BinaryDump(BYTE *pbData, DWORD dwSize)
{
	printf("\n");

	for (DWORD i = 0; i < dwSize; i++)
	{
		printf("%02X ", pbData[i]);
	}

	printf("\n");
}
