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

#include "stdafx.h"
#include "LOCrypto.h"

CLostOdysseyCrypto::CLostOdysseyCrypto() {
}

CLostOdysseyCrypto::~CLostOdysseyCrypto() {
}

DWORD CLostOdysseyCrypto::CalculateChecksum(BYTE *data, DWORD length) {
	DWORD ret = 0;
	for (DWORD i = 0; i < length; i++)
		ret += (data[i] ^ i);
	return ret;
}

VOID CLostOdysseyCrypto::DecryptData(BYTE *data, DWORD length) {
	DWORD i, r8, r9, r10;
	r8 = r9 = r10 = 0;

	for (i = 0; i < length; i++) {
		r10 = data[i];
		r8 = r9 & 0xFF;
		r9 = r10;
		r10 ^= 0xBB;
		r10 -= i;
		r10 ^= r8;
		data[i] = r10;
	}
}

VOID CLostOdysseyCrypto::EncryptData(BYTE *data, DWORD length) {
	DWORD i, r8, r9, r10;
	r8 = r9 = r10 = 0;

	for (i = 0; i < length; i++) {
		r8 = data[i];
		r10 &= 0xFF;
		r10 ^= r8;
		r10 += i;
		r10 &= 0xFF;
		r10 ^= 0xBB;
		data[i] = r10;
	}
}