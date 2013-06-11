// DBZUTResigner.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

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

inline DWORD LoadWord(PBYTE Data)
{
	return (Data[3]) | (Data[2] << 8)  | (Data[1] << 16) | (Data[0] << 24);
}

inline void StoreWord(PBYTE Data, DWORD Dword)
{
	Data[3] = Dword & 0xFF;
	Data[2] = (Dword & 0xFF00) >> 8;
	Data[1] = (Dword & 0xFF0000) >> 16;
	Data[0] = (Dword & 0xFF000000) >> 24;
}

inline BYTE LoadByte(PBYTE Data, DWORD Offset)
{
	return Data[Offset];
}

VOID DoRound(DWORD &A, PBYTE B, DWORD C, DWORD &D, DWORD &E, DWORD &F)
{
	if (A != 0)
	{
		D = LoadByte(B, C);
		E = (D << 8) | (D >> 24);
	}
	else
		E = LoadByte(B, C);

	F = E + F;

	if (F > -1)
		F++;
}

BOOL ChecksumDBZ(PBYTE Data, BOOL Fix)
{
	DWORD dwXRound = 0, dwYRound = 0, dwFinalValue = 0;
	PBYTE pbDataPointer4 = NULL, pbDataPointer3 = NULL, pbDataPointer1 = NULL, pbDataPointer2 = NULL;

	if (Fix)
	{
		StoreWord(Data, 0);
		StoreWord(Data+4, 0);
	}

	pbDataPointer1 = Data + 8;
	pbDataPointer2 = pbDataPointer1 + 1;
	pbDataPointer3 = pbDataPointer1 + 2;
	pbDataPointer4 = pbDataPointer1 + 3;

	for (DWORD i = 0, dwIndexer = 0; i < 0x927A ; i++, dwIndexer += 4)
	{
		DWORD dwTmpValue;

		dwXRound = dwIndexer & 1;
		pbDataPointer1 = pbDataPointer2 + dwIndexer;

		DoRound(dwXRound, pbDataPointer1, -1, dwYRound, dwTmpValue, dwFinalValue);

		dwTmpValue = dwIndexer - 1;
		dwYRound = dwTmpValue & 1;

		DoRound(dwYRound, pbDataPointer2, dwIndexer, dwTmpValue, dwTmpValue, dwFinalValue);
		DoRound(dwXRound, pbDataPointer3, dwIndexer, dwTmpValue, dwTmpValue, dwFinalValue);
		DoRound(dwYRound, pbDataPointer4, dwIndexer, dwTmpValue, dwTmpValue, dwFinalValue);
	}

	if (Fix)
	{
		DWORD CSum1 = dwFinalValue >> 8;
		DWORD CSum2 = dwFinalValue & 0xFF;

		StoreWord(Data, CSum1);
		StoreWord(Data+4, CSum2);

		return TRUE;
	}
	else
	{
		DWORD CSum1 = LoadWord(Data);
		DWORD CSum2 = LoadWord(Data+4);

		DWORD Calc1 = dwFinalValue >> 8;
		DWORD Calc2 = dwFinalValue & 0xFF;

		if (CSum1 == Calc1 || CSum2 == Calc2)
			return TRUE;
	}

	return FALSE;
}

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc < 2)
	{
		printf("Usage: %s <dbzsavegame>\n", argv[0]);
		return 1;
	}

	DWORD dwSize = 0;
	PBYTE pbData = GetFile(argv[1], &dwSize);

	if (!pbData || dwSize != 0x249F0)
	{
		printf("Invalid file!\n");
		return 1;
	}

	ChecksumDBZ(pbData, TRUE);

	if (!DumpFile(argv[1], pbData, 0x249F0))
	{
		printf("Unable to output file!\n");
		return 1;
	}

	return 0;
}

