/*
	2011  mojobojo
*/


#pragma once
#ifndef MC02_H
#define MC02_H

#include <intrin.h>
#include <stdio.h>
#include <string.h>

typedef struct _MC02_HEADER {
	DWORD HeaderMagic;
	DWORD FileSize;
	DWORD FistFileSize;
	DWORD SecondFileSize;
	DWORD FirstFileChecksum;
	DWORD SecondFileChecksum;
	DWORD HeaderChecksum;
} MC02_HEADER;

class CEAResigner {
public:
	CEAResigner();
	~CEAResigner();

	BOOL	ResignFile(FILE* infile);
	DWORD	CalculateEAChecksum(BYTE* data, DWORD size);
};

#endif