/*
    Copyright (C) 2011 mojobojo

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
	any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
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