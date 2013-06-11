// AccountCryptor.cpp : Defines the entry point for the console application.
//

#include <windows.h>
#include <stdio.h>
#include <tchar.h>

extern "C"
{
#include "sha1.h"
#include "memxor.h"
#include "rc4.h"
}

BYTE RetailKey[] = { 0xE1, 0xBC, 0x15, 0x9C, 0x73, 0xB1, 0xEA, 0xE9, 0xAB, 0x31, 0x70, 0xF3, 0xAD, 0x47, 0xEB, 0xF3 };
BYTE DevKey[] = { 0xDA, 0xB6, 0x9A, 0xD9, 0x8E, 0x28, 0x76, 0x4F, 0x97, 0x7E, 0xE2, 0x48, 0x7E, 0x4F, 0x3F, 0x68 };

enum ProfileType
{
	ProfileRetail,
	ProfileDevkit
};

enum ProcessType
{
	ProfileDecrypt,
	ProfileEncrypt
};

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

VOID XeCryptRc4(const BYTE * pbKey, DWORD cbKey, BYTE * pbInpOut, DWORD cbInpOut)
{
	rc4_key rc4key;
	ZeroMemory(&rc4key, sizeof(rc4_key));
	prepare_key((unsigned char*)pbKey, cbKey, &rc4key);
	rc4(pbInpOut, cbInpOut, &rc4key);
}

VOID XeCryptHmacSha(const BYTE * pbKey, DWORD cbKey, const BYTE * pbInp1, DWORD cbInp1, const BYTE * pbInp2, DWORD cbInp2, const BYTE * pbInp3, DWORD cbInp3, BYTE * pbOut, DWORD cbOut)
{
	struct sha1_ctx IpadCtx;
	struct sha1_ctx OpadCtx;
	BYTE IPAD[64];
	BYTE OPAD[64];

	if (cbKey > 64)
		cbKey = 64;

	// Setup IPAD
	memset (IPAD, 0x36, 64);
	memxor (IPAD, pbKey, cbKey);

	// Setup OPAD
	memset (OPAD, 0x5c, 64);
	memxor (OPAD, pbKey, cbKey);

	// IPAD process
	sha1_init_ctx (&IpadCtx);

	sha1_process_block(IPAD, 64, &IpadCtx);

	if (pbInp1)
		sha1_process_bytes(pbInp1, cbInp1, &IpadCtx);

	if (pbInp2)
		sha1_process_bytes(pbInp2, cbInp2, &IpadCtx);

	if (pbInp3)
		sha1_process_bytes(pbInp3, cbInp3, &IpadCtx);

	BYTE IpadHash[20];
	sha1_finish_ctx(&IpadCtx, IpadHash);

	// OPAD Process
	sha1_init_ctx(&OpadCtx);

	sha1_process_block(OPAD, 64, &OpadCtx);
	sha1_process_bytes (IpadHash, 20, &OpadCtx);

	BYTE FinalHash[20];
	sha1_finish_ctx (&OpadCtx, FinalHash);

	if (cbOut > 20)
		cbOut = 20;

	memcpy(pbOut, FinalHash, cbOut);
}

void DecryptProfile(PCHAR InFile, PCHAR OutFile, DWORD ProfileType)
{
	DWORD ProfileDataSize = 0;
	PBYTE ProfileData = GetFile(InFile, &ProfileDataSize);

	if (ProfileDataSize == 0 || ProfileData == NULL)
	{
		printf("Unable to open profile '%s'!\n", InFile);
		return;
	}

	PBYTE EncryptionKey = NULL;
	if (ProfileType == ProfileRetail)
		EncryptionKey = RetailKey;
	else if (ProfileType == ProfileDevkit)
		EncryptionKey = DevKey;
	else
	{
		printf("Unknown Console Type\n");
		return;
	}

	BYTE RC4Key[16];
	XeCryptHmacSha(EncryptionKey, 16, ProfileData, 16, NULL, NULL, NULL, NULL, RC4Key, 16);

	rc4_key rc4key;
	ZeroMemory(&rc4key, sizeof(rc4_key));
	prepare_key((unsigned char*)RC4Key, 16, &rc4key);

	rc4(ProfileData + 0x10, 8, &rc4key);
	rc4(ProfileData + 0x18, 380, &rc4key);

	BYTE DidDecrypt[16];
	XeCryptHmacSha(EncryptionKey, 16, ProfileData + 0x10, 8, ProfileData + 0x18, 380, NULL, NULL, DidDecrypt, 16);

	if (memcmp(DidDecrypt, ProfileData, 0x10) != 0)
	{
		printf("Profiled failed to decrypt!\n");
	}
	else
	{
		if (DumpFile(OutFile, ProfileData, ProfileDataSize))
		{
			printf("Decrypt Success!\n");
		}
		else
		{
			printf("Failed to write file!\n");
		}
	}

	free(ProfileData);
}

int _tmain(int argc, _TCHAR* argv[])
{
	DWORD ConsoleType = -1;
	DWORD ProcessType = -1;
	if (argc < 5)
	{
		printf("Usage: %s <console type> <encrypt/decrypt> <infile> <outfile>\n\n", argv[0]);
		printf("Console Types:\n    -r    Retail\n    -k    Devkit\n\n");
		printf("Encryption Options:\n    -d    Decrypt\n    -e    Encrypt\n\n");
		return 1;
	}

	if(argv[1][0] != '-' || argv[2][0] != '-')
	{
		printf("Invalid Option\n");
		return 1;
	}

	switch(argv[1][1])
	{
	case 'r':
		ConsoleType = ProfileRetail;
		break;
	case 'k':
		ConsoleType = ProfileDevkit;
		break;
	default:
		printf("Unknown option");
		return 1;
	}

	switch(argv[2][1])
	{
	case 'd':
		ProcessType = ProfileDecrypt;
		break;
	case 'e':
		ProcessType = ProfileEncrypt;
		break;
	default:
		printf("Unknown option");
		return 1;
	}

	if (ProcessType == ProfileDecrypt)
		DecryptProfile(argv[3], argv[4], ConsoleType);
	else if (ProcessType == ProfileEncrypt)
	{
		printf("Encryption currently unsupported\n");
		return 1;
	}

	return 0;
}

