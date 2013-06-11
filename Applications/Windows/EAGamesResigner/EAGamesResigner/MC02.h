/*
	Copyright (C) 2011  mojobojo

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

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