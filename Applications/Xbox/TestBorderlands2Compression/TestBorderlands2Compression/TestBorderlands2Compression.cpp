// TestBorderlands2Compression.cpp : Defines the entry point for the application.
//

#include <xtl.h>
#include <xboxmath.h>
#include <stdio.h>

extern "C"
{
	#include "minilzo.h"
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

int __declspec(naked) sub_82D8E3C8()
{
	__asm
	{
		std		r30, -0x10(r1)
		std		r31, -8(r1)
		li		r6, 1
		lwz		r10, 0(r3)
		addi	r9, r5, -1
		lwz		r11, 4(r3)
		cmplwi	cr6, r5, 0
		slw		r7, r6, r9
		beq		cr6, loc_82D8E434
		mtspr	CTR, r5

loc_82D8E3F0:				// CODE XREF: sub_82D8E3C8:loc_82D8E430j
		and		r8, r7, r4
		lbz		r5, 0(r10)
		subfic	r9, r11, 7
		addic	r31, r8, -1
		slw		r30, r6, r9
		subfe	r31, r31, r8
		andc	r8, r5, r30
		addi	r11, r11, 1
		slw		r9, r31, r9
		clrlwi	r11, r11, 29
		add		r9, r9, r8
		slwi	r4, r4, 1
		stb		r9, 0(r10)
		cmplwi	cr6, r11, 0
		bne		cr6, loc_82D8E430
		addi	r10, r10, 1

loc_82D8E430:				// CODE XREF: sub_82D8E3C8+60j
		bdnz	loc_82D8E3F0

loc_82D8E434:				// CODE XREF: sub_82D8E3C8+20j
		stw		r11, 4(r3)
		stw		r10, 0(r3)
		ld		r30, -0x10(r1)
		ld		r31, -8(r1)
		blr
	}
}

int __declspec(naked) sub_82D8E448()
{
	__asm
	{
		mfspr	r12, LR
		std		r27, -0x30(r1)
		std		r28, -0x28(r1)
		std		r29, -0x20(r1)
		std		r30, -0x18(r1)
		std		r31, -0x10(r1)
		stw		r12, -8(r1)
		stwu	r1, -0x80(r1)

		lwz		r11, 0xC(r3)
		mr		r31, r3
		mr		r27, r4
		mr		r30, r5
		mr		r28, r6
		mr		r29, r7
		cmpwi	cr6, r11, 0
		bge		cr6, loc_82D8E4B8

loc_82D8E474:				// CODE XREF: sub_82D8E448+6Cj
		li		r5, 1
		li		r4, 0
		mr		r3, r30
		bl		sub_82D8E3C8
		addi	r29, r29, 1
		slwi	r6, r28, 1
		mr		r7, r29
		mr		r5, r30
		mr		r4, r27
		lwz		r3, 0(r31)
		bl		sub_82D8E448
		slwi	r11, r28, 1
		addi	r28, r11, 1
		lwz		r31, 4(r31)
		lwz		r11, 0xC(r31)
		cmpwi	cr6, r11, 0
		blt		cr6, loc_82D8E474

loc_82D8E4B8:				// CODE XREF: sub_82D8E448+28j
		li		r5, 1
		li		r4, 1
		mr		r3, r30
		bl		sub_82D8E3C8
		li		r5, 8
		lwz		r4, 0xC(r31)
		bl		sub_82D8E3C8
		lwz		r10, 0xC(r31)
		li		r9, 0
		addi	r11, r27, 0x20

loc_82D8E4E0:				// CODE XREF: sub_82D8E448+D4j
		lwz		r8, -0x20(r11)
		cmpw	cr6, r8, r10
		beq		cr6, loc_82D8E538
		lwz		r8, -0x10(r11)
		cmpw	cr6, r8, r10
		beq		cr6, loc_82D8E524
		lwz		r8, 0(r11)
		cmpw	cr6, r8, r10
		beq		cr6, loc_82D8E52C
		lwz		r8, 0x10(r11)
		cmpw	cr6, r8, r10
		beq		cr6, loc_82D8E534
		addi	r9, r9, 4
		addi	r11, r11, 0x40
		cmplwi	cr6, r9, 0x100
		blt		cr6, loc_82D8E4E0
		b		loc_82D8E538
// ---------------------------------------------------------------------------

loc_82D8E524:				// CODE XREF: sub_82D8E448+ACj
		addi	r9, r9, 1
		b		loc_82D8E538
// ---------------------------------------------------------------------------

loc_82D8E52C:				// CODE XREF: sub_82D8E448+B8j
		addi	r9, r9, 2
		b		loc_82D8E538
// ---------------------------------------------------------------------------

loc_82D8E534:				// CODE XREF: sub_82D8E448+C4j
		addi	r9, r9, 3

loc_82D8E538:				// CODE XREF: sub_82D8E448+A0j
					// sub_82D8E448+D8j ...
		slwi	r11, r9, 4
		add		r11, r11, r27
		stw		r28, 8(r11)
		stw		r29, 0xC(r11)

		addi	r1, r1, 0x80
		ld		r27, -0x30(r1)
		ld		r28, -0x28(r1)
		ld		r29, -0x20(r1)
		ld		r30, -0x18(r1)
		ld		r31, -0x10(r1)
		lwz		r12, -8(r1)
		mtspr	LR, r12
		blr
	}
}

int __declspec(naked) sub_82D8E550()
{
	__asm
	{
		mfspr	r12, LR
		std		r28, -0x28(r1)
		std		r29, -0x20(r1)
		std		r30, -0x18(r1)
		std		r31, -0x10(r1)
		stw		r12, -8(r1)
		ld		r12, -0x1000(r1)
		ld		r12, -0x2000(r1)
		stwu	r1, -0x2070(r1)

		li		r11, 0x40
		addi	r10, r1, 0x54
		addi	r7, r1, 0x58
		li		r31, 0
		addi	r9, r1, 0x40
		addi	r30, r1, 0x5C
		mtspr	CTR, r11
		addi	r8, r10, -0x10
		addi	r10, r7, -0x10
		mr		r28, r3
		mr		r5, r4
		mr		r6, r31
		addi	r11, r30, -0x10
		addi	r7, r3, 4

loc_82D8E59C:				// CODE XREF: sub_82D8E550+120j
		lwz		r4, 0(r7)
		cmplwi	cr6, r4, 0
		beq		cr6, loc_82D8E5D4
		lwz		r4, -4(r7)
		addi	r6, r6, 1
		lwz		r3, 0(r7)
		stw		r31, 0x10(r9)
		addi	r9, r9, 0x10
		stw		r31, 0x10(r8)
		addi	r8, r8, 0x10
		stw		r4, 0x10(r11)
		addi	r11, r11, 0x10
		stw		r3, 0x10(r10)
		addi	r10, r10, 0x10

loc_82D8E5D4:				// CODE XREF: sub_82D8E550+54j
		lwz		r4, 0x10(r7)
		cmplwi	cr6, r4, 0
		beq		cr6, loc_82D8E60C
		lwz		r4, 0xC(r7)
		addi	r6, r6, 1
		lwz		r3, 0x10(r7)
		stw		r4, 0x10(r11)
		addi	r11, r11, 0x10
		stw		r3, 0x10(r10)
		addi	r10, r10, 0x10
		stw		r31, 0x10(r9)
		addi	r9, r9, 0x10
		stw		r31, 0x10(r8)
		addi	r8, r8, 0x10

loc_82D8E60C:				// CODE XREF: sub_82D8E550+8Cj
		lwz		r4, 0x20(r7)
		cmplwi	cr6, r4, 0
		beq		cr6, loc_82D8E644
		lwz		r4, 0x1C(r7)
		addi	r6, r6, 1
		lwz		r3, 0x20(r7)
		stw		r4, 0x10(r11)
		addi	r11, r11, 0x10
		stw		r3, 0x10(r10)
		addi	r10, r10, 0x10
		stw		r31, 0x10(r9)
		addi	r9, r9, 0x10
		stw		r31, 0x10(r8)
		addi	r8, r8, 0x10

loc_82D8E644:				// CODE XREF: sub_82D8E550+C4j
		lwz		r4, 0x30(r7)
		cmplwi	cr6, r4, 0
		beq		cr6, loc_82D8E66C
		lwz		r4, 0x2C(r7)
		addi	r6, r6, 1
		lwz		r3, 0x30(r7)
		stwu	r4, 0x10(r11)
		stwu	r3, 0x10(r10)
		stwu	r31, 0x10(r9)
		stwu	r31, 0x10(r8)

loc_82D8E66C:				// CODE XREF: sub_82D8E550+FCj
		addi	r7, r7, 0x40
		bdnz	loc_82D8E59C
		mr		r30, r6
		cmplwi	cr6, r6, 1
		ble		cr6, loc_82D8E748
		slwi	r10, r6, 4
		addi	r11, r1, 0x58
		addi	r6, r6, -1
		add		r11, r10, r11
		li		r29, -1

loc_82D8E694:				// CODE XREF: sub_82D8E550+1DCj
		mr		r9, r31
		mr		r10, r31
		cmplwi	cr6, r30, 0
		beq		cr6, loc_82D8E6F8
		addi	r7, r1, 0x58
		mtspr	CTR, r30

loc_82D8E6AC:				// CODE XREF: sub_82D8E550+1A4j
		lwz		r8, 0(r7)
		cmpwi	cr6, r8, 0
		ble		cr6, loc_82D8E6F0
		cmplwi	cr6, r9, 0
		beq		cr6, loc_82D8E6E8
		lwz		r4, 8(r9)
		cmpw	cr6, r8, r4
		ble		cr6, loc_82D8E6E8
		cmplwi	cr6, r10, 0
		beq		cr6, loc_82D8E6E0
		lwz		r4, 8(r10)
		cmpw	cr6, r8, r4
		bgt		cr6, loc_82D8E6F0

loc_82D8E6E0:				// CODE XREF: sub_82D8E550+180j
		addi	r10, r7, -8
		b		loc_82D8E6F0
// ---------------------------------------------------------------------------

loc_82D8E6E8:				// CODE XREF: sub_82D8E550+16Cj
					// sub_82D8E550+178j
		mr		r10, r9
		addi	r9, r7, -8

loc_82D8E6F0:				// CODE XREF: sub_82D8E550+164j
					// sub_82D8E550+18Cj ...
		addi	r7, r7, 0x10
		bdnz	loc_82D8E6AC

loc_82D8E6F8:				// CODE XREF: sub_82D8E550+150j
		stw		r9, -8(r11)
		addi	r3, r11, -8
		stw		r10, -4(r11)
		addic.	r6, r6, -1
		lwz		r7, 8(r10)
		addi	r30, r30, 1
		lwz		r8, 8(r9)
		add		r8, r7, r8
		stw		r29, 4(r11)
		stw		r8, 0(r11)
		addi	r11, r11, 0x10
		stw		r31, 8(r9)
		stw		r31, 8(r10)
		bne		loc_82D8E694
		li		r7, 0
		li		r6, 0
		mr		r4, r28
		bl		sub_82D8E448

		addi	r1, r1, 0x2070
		ld		r28, -0x28(r1)
		ld		r29, -0x20(r1)
		ld		r30, -0x18(r1)
		ld		r31, -0x10(r1)
		lwz		r12, -8(r1)
		mtspr   LR, r12
		blr

// ---------------------------------------------------------------------------

loc_82D8E748:				// CODE XREF: sub_82D8E550+12Cj
		li		r7, 1
		addi	r3, r1, 0x50
		li		r6, 0
		mr		r4, r28
		bl		sub_82D8E448

		addi	r1, r1, 0x2070
		ld		r28, -0x28(r1)
		ld		r29, -0x20(r1)
		ld		r30, -0x18(r1)
		ld		r31, -0x10(r1)
		lwz		r12, -8(r1)
		mtspr	LR, r12
		blr
	}
}

int __declspec(naked) Compress(void *in, void *out, unsigned int length)
{
	__asm
	{
		mfspr	r12, LR
		std		r26, -0x38(r1)
		std		r27, -0x30(r1)
		std		r28, -0x28(r1)
		std		r29, -0x20(r1)
		std		r30, -0x18(r1)
		std		r31, -0x10(r1)
		stw		r12, -8(r1)
		ld		r12, -0x1000(r1)
		stwu	r1, -0x10B0(r1)

		mr		r29, r3
		mr		r28, r4
		mr		r30, r5
		cmplwi	cr6, r5, 1
		bge		cr6, loc_82D8E890
		li		r3, 0

		addi	r1, r1, 0x10B0	
		ld		r26, -0x38(r1)
		ld		r27, -0x30(r1)
		ld		r28, -0x28(r1)
		ld		r29, -0x20(r1)
		ld		r30, -0x18(r1)
		ld		r31, -0x10(r1)
		lwz		r12, -8(r1)
		mtspr	LR, r12
		blr
// ---------------------------------------------------------------------------

loc_82D8E890:				// CODE XREF: Compress+20j
		li		r11, 0x100
		stw		r28, 0x50(r1)
		li		r31, 0
		addi	r9, r1, 0x74
		stw		r31, 0x54(r1)
		mr		r10, r31
		mtspr	CTR, r11
		addi	r11, r9, -8

loc_82D8E8B0:				// CODE XREF: Compress+64j
		stw		r10, 4(r11)
		addi	r10, r10, 1
		stw		r31, 8(r11)
		stw		r31, 0xC(r11)
		stwu	r31, 0x10(r11)
		bdnz	loc_82D8E8B0
		cmpwi	cr6, r30, 0
		beq		cr6, loc_82D8E8F4
		mtspr	CTR, r30
		addi	r9, r29, -1

loc_82D8E8D8:				// CODE XREF: Compress+90j
		lbzu	r10, 1(r9)
		addi	r11, r1, 0x74
		rotlwi	r10, r10, 4
		lwzx	r8, r10, r11
		addi	r8, r8, 1
		stwx	r8, r10, r11
		bdnz	loc_82D8E8D8

loc_82D8E8F4:				// CODE XREF: Compress+6Cj
		addi	r4, r1, 0x50
		addi	r3, r1, 0x70
		bl		sub_82D8E550

loc_82D8E900:				// CODE XREF: Compress+338j
		mr		r10, r31
		addi	r11, r1, 0x80
		li		r9, 0x33

loc_82D8E90C:				// CODE XREF: Compress+330j
		lwz		r8, -0x10(r11)
		lwz		r7, 0(r11)
		cmpw	cr6, r8, r7
		ble		cr6, loc_82D8E98C
		addi	r7, r1, 0x60
		lwz		r6, -0xC(r11)
		lwz		r4, -8(r11)
		addi	r3, r11, -0x10
		lwz		r3, -4(r11)
		clrlwi	r8, r8, 0
		addi	r5, r1, 0x60
		lwz		r27, 0(r11)
		lwz		r26, 0xC(r11)
		li		r10, 1
		stw		r8, 0(r7)
		stw		r6, 4(r7)
		stw		r4, 8(r7)
		stw		r3, 0xC(r7)
		lwz		r8, 0xC(r5)
		lwz		r7, 0(r5)
		lwz		r6, 4(r5)
		lwz		r5, 8(r5)
		lwz		r4, 4(r11)
		lwz		r3, 8(r11)
		stw		r27, -0x10(r11)
		stw		r26, -4(r11)
		stw		r8, 0xC(r11)
		stw		r4, -0xC(r11)
		stw		r3, -8(r11)
		stw		r5, 8(r11)
		stw		r6, 4(r11)
		stw		r7, 0(r11)

loc_82D8E98C:				// CODE XREF: Compress+B8j
		lwz		r8, 0(r11)
		lwz		r7, 0x10(r11)
		cmpw	cr6, r8, r7
		ble		cr6, loc_82D8EA08
		addi	r7, r1, 0x60
		lwz		r6, 4(r11)
		lwz		r4, 8(r11)
		clrlwi	r8, r8, 0
		lwz		r3, 0xC(r11)
		addi	r5, r1, 0x60
		lwz		r27, 0x10(r11)
		li		r10, 1
		stw		r8, 0(r7)
		stw		r6, 4(r7)
		stw		r4, 8(r7)
		stw		r3, 0xC(r7)
		lwz		r7, 0x18(r11)
		lwz		r8, 0x14(r11)
		lwz		r6, 0x1C(r11)
		lwz		r3, 8(r5)
		stw		r27, 0(r11)
		stw		r7, 8(r11)
		lwz		r7, 4(r5)
		stw		r8, 4(r11)
		stw		r6, 0xC(r11)
		stw		r3, 0x18(r11)
		lwz		r4, 0xC(r5)
		lwz		r8, 0(r5)
		stw		r7, 0x14(r11)
		stw		r8, 0x10(r11)
		stw		r4, 0x1C(r11)

loc_82D8EA08:				// CODE XREF: Compress+138j
		lwz		r8, 0x10(r11)
		lwz		r7, 0x20(r11)
		cmpw	cr6, r8, r7
		ble		cr6, loc_82D8EA88
		addi	r7, r1, 0x60
		lwz		r6, 0x14(r11)
		clrlwi	r8, r8, 0
		lwz		r4, 0x18(r11)
		addi	r3, r11, 0x10
		lwz		r3, 0x1C(r11)
		addi	r5, r1, 0x60
		lwz		r27, 0x20(r11)
		li		r10, 1
		stw		r8, 0(r7)
		stw		r6, 4(r7)
		stw		r4, 8(r7)
		stw		r3, 0xC(r7)
		lwz		r7, 0x28(r11)
		lwz		r8, 0x24(r11)
		lwz		r6, 0x2C(r11)
		stw		r27, 0x10(r11)
		stw		r7, 0x18(r11)
		stw		r8, 0x14(r11)
		stw		r6, 0x1C(r11)
		lwz		r8, 0(r5)
		lwz		r7, 8(r5)
		stw		r8, 0x20(r11)
		lwz		r3, 0xC(r5)
		lwz		r4, 4(r5)
		stw		r4, 0x24(r11)
		stw		r7, 0x28(r11)
		stw		r3, 0x2C(r11)

loc_82D8EA88:				// CODE XREF: Compress+1B4j
		lwz		r8, 0x20(r11)
		lwz		r7, 0x30(r11)
		cmpw	cr6, r8, r7
		ble		cr6, loc_82D8EB08
		addi	r7, r1, 0x60
		lwz		r6, 0x24(r11)
		lwz		r4, 0x28(r11)
		addi	r3, r11, 0x20
		lwz		r3, 0x2C(r11)
		clrlwi	r8, r8, 0
		addi	r5, r1, 0x60
		lwz		r27, 0x30(r11)
		li		r10, 1
		stw		r8, 0(r7)
		stw		r6, 4(r7)
		stw		r4, 8(r7)
		stw		r3, 0xC(r7)
		lwz		r8, 0x34(r11)
		lwz		r7, 0x38(r11)
		lwz		r6, 0x3C(r11)
		stw		r27, 0x20(r11)
		stw		r8, 0x24(r11)
		stw		r7, 0x28(r11)
		stw		r6, 0x2C(r11)
		lwz		r4, 0xC(r5)
		stw		r4, 0x3C(r11)
		lwz		r8, 4(r5)
		lwz		r7, 8(r5)
		lwz		r3, 0(r5)
		stw		r3, 0x30(r11)
		stw		r8, 0x34(r11)
		stw		r7, 0x38(r11)

loc_82D8EB08:				// CODE XREF: Compress+234j
		lwz		r8, 0x30(r11)
		lwz		r7, 0x40(r11)
		cmpw	cr6, r8, r7
		ble		cr6, loc_82D8EB88
		addi	r7, r1, 0x60
		lwz		r6, 0x34(r11)
		lwz		r4, 0x38(r11)
		addi	r3, r11, 0x30
		lwz		r3, 0x3C(r11)
		clrlwi	r8, r8, 0
		addi	r5, r1, 0x60
		lwz		r27, 0x40(r11)
		li		r10, 1
		stw		r8, 0(r7)
		stw		r6, 4(r7)
		stw		r4, 8(r7)
		stw		r3, 0xC(r7)
		lwz		r8, 0x44(r11)
		lwz		r7, 0x48(r11)
		lwz		r6, 0x4C(r11)
		stw		r27, 0x30(r11)
		stw		r8, 0x34(r11)
		stw		r7, 0x38(r11)
		stw		r6, 0x3C(r11)
		lwz		r4, 0(r5)
		lwz		r3, 4(r5)
		lwz		r8, 8(r5)
		lwz		r7, 0xC(r5)
		stw		r4, 0x40(r11)
		stw		r3, 0x44(r11)
		stw		r8, 0x48(r11)
		stw		r7, 0x4C(r11)

loc_82D8EB88:				// CODE XREF: Compress+2B4j
		addic.	r9, r9, -1
		addi	r11, r11, 0x50
		bne		loc_82D8E90C
		cmplwi	cr6, r10, 0
		bne		cr6, loc_82D8E900
		cmplwi	cr6, r30, 0
		beq		cr6, loc_82D8EBD8
		addi	r11, r1, 0x7C
		addi	r10, r1, 0x78

loc_82D8EBAC:				// CODE XREF: Compress+374j
		lbzx	r9, r31, r29
		addi	r3, r1, 0x50
		rotlwi	r8, r9, 4
		lwzx	r5, r8, r11
		lwzx	r4, r8, r10
		bl		sub_82D8E3C8
		addi	r31, r31, 1
		addi	r11, r1, 0x7C
		cmplw	cr6, r31, r30
		addi	r10, r1, 0x78
		blt		cr6, loc_82D8EBAC

loc_82D8EBD8:				// CODE XREF: Compress+340j
		lwz		r11, 0x50(r1)
		lwz		r10, 0x54(r1)
		subf	r3, r28, r11
		cmplwi	cr6, r10, 0
		beq		cr6, loc_82D8EBF0
		addi	r3, r3, 1

loc_82D8EBF0:				// CODE XREF: Compress+388j
		addi	  r1, r1, 0x10B0
		ld		r26, -0x38(r1)
		ld		r27, -0x30(r1)
		ld		r28, -0x28(r1)
		ld		r29, -0x20(r1)
		ld		r30, -0x18(r1)
		ld		r31, -0x10(r1)
		lwz		r12, -8(r1)
		mtspr	LR, r12
		blr
	}
}

int __declspec(naked) sub_82D8E768()
{
	__asm
	{
		mfspr	r12, LR
		std		r28, -0x28(r1)
		std		r29, -0x20(r1)
		std		r30, -0x18(r1)
		std		r31, -0x10(r1)
		stw		r12, -8(r1)
		stwu	r1, -0x80(r1)

		lwz		r11, 0(r5)
		li		r9, 0
		li		r8, -1
		slwi	r10, r11, 1
		addi	r7, r11, 1
		add		r6, r11, r10
		stw		r7, 0(r5)
		mr		r30, r4
		slwi	r11, r6, 2
		mr		r29, r5
		add		r31, r11, r3
		li		r5, 1
		mr		r28, r3
		stwx	r9, r11, r3
		stw		r9, 4(r31)
		stw		r8, 8(r31)
		lwz		r11, 0(r4)
		lbz		r9, 0(r11)
		lwz		r10, 4(r4)
		subfic	r4, r10, 7
		slw		r3, r5, r4
		and		r8, r3, r9
		addi	r7, r10, 1
		addic	r6, r8, -1
		clrlwi	r10, r7, 29	// r10 =	r7 & 7
		subfe	r9, r6, r8
		cmplwi	cr6, r10, 0
		bne		cr6, loc_82D8E7E8
		addi	r11, r11, 1

loc_82D8E7E8:				// CODE XREF: sub_82D8E768+78j
		stw		r10, 4(r30)
		cmplwi	cr6, r9, 0
		stw		r11, 0(r30)
		beq		cr6, loc_82D8E82C
		subfic	r9, r10, 8
		lbz		r8, 1(r11)
		lbz		r7, 0(r11)
		addi	r11, r11, 1
		clrlwi	r6, r9, 24
		slw		r5, r7, r10
		stw		r11, 0(r30)
		srw		r4, r8, r6
		or		r11, r4, r5
		mr		r3, r31
		stw		r11, 8(r31)

		addi	r1, r1, 0x80
		ld		r28, -0x28(r1)
		ld		r29, -0x20(r1)
		ld		r30, -0x18(r1)
		ld		r31, -0x10(r1)
		lwz		r12, -8(r1)
		mtspr	LR, r12
		blr

// ---------------------------------------------------------------------------

loc_82D8E82C:				// CODE XREF: sub_82D8E768+8Cj
		mr		r5, r29
		mr		r4, r30
		mr		r3, r28
		bl		sub_82D8E768
		stw		r3, 0(r31)
		mr		r5, r29
		mr		r4, r30
		mr		r3, r28
		bl		sub_82D8E768
		stw		r3, 4(r31)
		mr		r3, r31

		addi	r1, r1, 0x80
		ld		r28, -0x28(r1)
		ld		r29, -0x20(r1)
		ld		r30, -0x18(r1)
		ld		r31, -0x10(r1)
		lwz		r12, -8(r1)
		mtspr	LR, r12
		blr
	}
}

int __declspec(naked) Decompress(void *in, void  *out, unsigned int length)
{
	__asm
	{
		mfspr	r12, LR
		stw		r12, -8(r1)
		std		r30, -0x18(r1)
		std		r31, -0x10(r1)
		ld		r12, -0x1000(r1)
		stwu	r1, -0x1870(r1)
		li		r11, 0
		stw		r3, 0x50(r1)
		mr		r30, r4
		stw		r11, 0x54(r1)
		mr		r31, r5
		stw		r11, 0x58(r1)
		addi	r5, r1, 0x58
		addi	r4, r1, 0x50
		addi	r3, r1, 0x60
		bl		sub_82D8E768
		cmplwi	cr6, r31, 0
		beq		cr6, loc_82D8ECC8
		lwz		r11, 0x54(r1)
		mtspr	CTR, r31
		lwz		r10, 0x50(r1)
		addi	r6, r30, -1
		li		r7, 1

loc_82D8EC54:				// CODE XREF: Decompress+CCj
		lwz		r9, 8(r3)
		mr		r8, r3
		cmpwi	cr6, r9, 0
		bge		cr6, loc_82D8ECB8

loc_82D8EC64:				// CODE XREF: Decompress+BCj
		subfic	r9, r11, 7
		lbz		r5, 0(r10)
		addi	r4, r11, 1
		slw		r11, r7, r9
		and		r9, r11, r5
		clrlwi	r11, r4, 29
		addic	r5, r9, -1
		cmplwi	cr6, r11, 0
		subfe	r9, r5, r9
		bne		cr6, loc_82D8EC90
		addi	r10, r10, 1

loc_82D8EC90:				// CODE XREF: Decompress+90j
		stw		r11, 0x54(r1)
		cmplwi	cr6, r9, 0
		stw		r10, 0x50(r1)
		beq		cr6, loc_82D8ECA8
		lwz		r8, 4(r8)
		b		loc_82D8ECAC
// ---------------------------------------------------------------------------

loc_82D8ECA8:				// CODE XREF: Decompress+A4j
		lwz		r8, 0(r8)

loc_82D8ECAC:				// CODE XREF: Decompress+ACj
		lwz		r9, 8(r8)
		cmpwi	cr6, r9, 0
		blt		cr6, loc_82D8EC64

loc_82D8ECB8:				// CODE XREF: Decompress+68j
		lwz		r9, 8(r8)
		clrlwi	r8, r9, 24
		stbu	r8, 1(r6)
		bdnz	loc_82D8EC54

loc_82D8ECC8:				// CODE XREF: Decompress+44j
		addi	r1, r1, 0x1870
		lwz		r12, -8(r1)
		mtspr	LR, r12
		ld		r30, -0x18(r1)
		ld		r31, -0x10(r1)
		blr
	}
}

void DecompressSavegame(const char *pstrPath)
{
	// For some strange reason pstrPath was getting corrupted on sprintf, so had to do this -_-
	CHAR *FileName = strdup(pstrPath);

	CHAR fPath[MAX_PATH];
	sprintf_s(fPath, MAX_PATH, "GAME:\\compressed\\%s", FileName);

	DWORD dwDataLength = 0;
	PBYTE pbData = GetFile(fPath, &dwDataLength);

	if (!pbData)
	{
		printf("Failed to open savegame file '%s'!\n", pstrPath);
		return;
	}

	DWORD UncompressedLength = *(DWORD*)(pbData + 0x14);
	PBYTE CompressedData = pbData + 0x18;

	PBYTE pbUncompressedBuffer = new BYTE[UncompressedLength];

	lzo_uint DecompressedLen = 0;
	int result = lzo1x_decompress(CompressedData, dwDataLength - 0x18, pbUncompressedBuffer, &DecompressedLen, 0);

	if (result == LZO_E_OK)
	{
		DWORD TotalSize = *(DWORD*)(pbUncompressedBuffer);

		if (memcmp(pbUncompressedBuffer + 4, "WSG", 3) != 0)
		{
			printf("Decompression failed horribly!\n");
			delete pbUncompressedBuffer;
			return;
		}

		DWORD VersionNum = *(DWORD*)(pbUncompressedBuffer + 7);
		DWORD UncompressedCRC32 = *(DWORD*)(pbUncompressedBuffer + 0xB);
		DWORD UncompressedSize = *(DWORD*)(pbUncompressedBuffer + 0xF);
		PBYTE CompressedData = pbUncompressedBuffer + 0x13;

		PBYTE UncompressedData = new BYTE[UncompressedSize];
		Decompress(CompressedData, UncompressedData, UncompressedSize);

		char finalpath[MAX_PATH];
		sprintf(finalpath, "GAME:\\uncompressed\\%s.bin", FileName);

		DumpFile(finalpath, UncompressedData, UncompressedSize);
	}
	else
	{
		printf("Failed to decompress data!\n");
	}

	delete pbUncompressedBuffer;
}

void DecompressFiles()
{
	WIN32_FIND_DATA lpFindFileData;

	HANDLE hFind = FindFirstFile("GAME:\\compressed\\*", &lpFindFileData);
	do
	{
		if (lpFindFileData.dwFileAttributes & FILE_ATTRIBUTE_NORMAL)
		{
			DecompressSavegame(lpFindFileData.cFileName);
		}

	} while (FindNextFile(hFind, &lpFindFileData) != 0);
}

//-------------------------------------------------------------------------------------
// Name: main()
// Desc: The application's entry point
//-------------------------------------------------------------------------------------
int __cdecl main(int argc, char **argv)
{
	DecompressFiles();
	return 0;
}

