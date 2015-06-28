/*
    2011 mojobojo
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