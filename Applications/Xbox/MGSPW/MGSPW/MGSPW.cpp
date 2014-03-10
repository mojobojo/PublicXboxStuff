// MGSPW.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include "MGSCryptShared.h"
#include "MGSDecryptor.h"
#include "MGSEncryptor.h"

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

void Decrypt(char *str, char *out) {
	DWORD dwSize;
	PBYTE data = GetFile(str, &dwSize);
	Decrypt_NA_00000000(data);

	DumpFile(out, data, dwSize);
}

void Encrypt(char *str, char *out) {
	DWORD dwSize;
	PBYTE data = GetFile(str, &dwSize);
	extern unsigned int dword_834A73A4[];
	extern unsigned char unk_835C4AA0[];
	extern unsigned char unk_83441544[];

	// setting up some stuff
	dword_834A73A4[0] = *(unsigned int*)(data + 0x40);
	memcpy(unk_835C4AA0, data + 0x44, 0x4CAA4);	
	memcpy(unk_83441544, data + 0x44, 0x4CAA4);	

	Encrypt_NA_00000000(data);

	DumpFile(out, data, 0x4CAE8);
}

//-------------------------------------------------------------------------------------
// Name: main()
// Desc: The application's entry point
//-------------------------------------------------------------------------------------
void __cdecl main()
{
	Decrypt("GAME:\\NA_00000000.000", "GAME:\\NA_00000000.000.decrypted");
	//Encrypt("GAME:\\NA_00000000.000.decrypted", "GAME:\\NA_00000000.000.encrypted");
	//Decrypt("GAME:\\NA_00000000.000.encrypted", "GAME:\\NA_00000000.000.decryptedagain");

	__asm {
		nop
	}
}

