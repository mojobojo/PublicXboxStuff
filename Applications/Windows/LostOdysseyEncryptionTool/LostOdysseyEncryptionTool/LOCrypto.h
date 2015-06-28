/*
    2011 mojobojo
*/

#pragma once
#ifndef LOCRYPTO_H
#define LOCRYPTO_H

#include <stdio.h>

#define bswap32(x) ((x << 24) & 0xff000000 ) | ((x <<  8) & 0x00ff0000 ) | ((x >>  8) & 0x0000ff00 ) | ((x >> 24) & 0x000000ff )

typedef struct _LostOdysseyHeader {
	DWORD	Magic1;
	DWORD	Magic2;
	WORD	Padding;
	WORD	Unk1;
	WORD	EncryptedDataPtr1;
	WORD	EncryptedDataPtr2;
	DWORD	EncryptedDataSize;
	DWORD	DataChecksum;
	DWORD	HeaderChecksum;
} LostOdysseyHeader;

class CLostOdysseyCrypto {
public:
	CLostOdysseyCrypto();
	~CLostOdysseyCrypto();

	DWORD	CalculateChecksum(BYTE* data, DWORD length);
	VOID	DecryptData(BYTE* data, DWORD length);
	VOID	EncryptData(BYTE* data, DWORD length);
};

#endif