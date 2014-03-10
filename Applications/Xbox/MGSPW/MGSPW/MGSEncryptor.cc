#include "stdafx.h"
#include "MGSEncryptor.h"
#include "MGSCryptShared.h"

extern unsigned char obf_table[];
extern unsigned int dword_837FD224[];
extern unsigned int dword_834A73A4[];
extern unsigned int off_832F5EB8[];
extern unsigned int dword_832E05C8[];

void __declspec(naked) sub_82B8BBF8() {
	__asm {
		//lis	  r11, ((dword_837FD224+0x10000)@h)
		lau   r11, dword_837FD224
		cmpwi	  cr6, r4, 0
		//addi	  r6, r11, -0x2DDC # dword_837FD224
		lal   r6, r11, dword_837FD224
		//lwz	  r10, dword_837FD224@l(r11)
		lwz   r10, 0(r6)
		ble	  cr6, loc_82B8BC60
		addi	  r9, r4, -1
		//lwz	  r7, ((dword_837FD228+0x2DDC)@l)(r6)
		lwz   r7, 4(r6)
		addi	  r11, r3, -4
		srwi	  r9, r9, 2
		addi	  r9, r9, 1
		mtspr	CTR, r9
		lis	  r9, 0x2E9 // 0x2E90EDD
		ori	  r8, r9, 0xEDD	// 0x2E90EDD

loc_82B8BC2C:				// CODE XREF: sub_82B8BBF8+64j
		lwz	  r5, 4(r11)
		mullw	  r9, r10, r8
		mr	  r4, r5
		mr	  r3, r5
		inslwi	  r4, r5, 16,16
		insrwi	  r3, r5, 16,0
		extrwi	  r5, r4, 16,8
		extlwi	  r4, r3, 16,8
		or	  r3, r5, r4
		xor	  r5, r3, r10
		add	  r10, r9, r7
		stwu	  r5, 4(r11)
		bdnz	  loc_82B8BC2C

loc_82B8BC60:				// CODE XREF: sub_82B8BBF8+10j
		//stw	  r10, ((dword_837FD224+0x2DDC)@l)(r6)
		stw    r10, 0(r6)
		blr
	}
}

void __declspec(naked) Encrypt_NA_00000000(void *ptr) {
	__asm {
		mfspr	r12, LR
		//bl	  __savegprlr_18
		std       r18, -0x78(r1)
		std       r19, -0x70(r1)
		std       r20, -0x68(r1)
		std       r21, -0x60(r1)
		std       r22, -0x58(r1)
		std       r23, -0x50(r1)
		std       r24, -0x48(r1)
		std       r25, -0x40(r1)
		std       r26, -0x38(r1)
		std       r27, -0x30(r1)
		std       r28, -0x28(r1)
		std       r29, -0x20(r1)
		std       r30, -0x18(r1)
		std       r31, -0x10(r1)
		stw       r12, -0x8(r1)

		stwu	  r1, -0xD0(r1)
		//lis	  r10, dword_834A73A4@h
		lau   r10, dword_834A73A4
		lal   r10, r10, dword_834A73A4
		//lwz	  r31, 0x6C(r3)
		mr    r31, r3
		addi	  r11, r31, 0x40
		mr	  r19, r11
		//lwz	  r10, dword_834A73A4@l(r10)
		lwz   r10, 0(r10)
		addi	  r30, r11, 4
		clrlwi	  r8, r10, 0
		mr	  r7, r8
		rlwinm	  r6, r8, 24,16,23
		stw	  r10, 0x40(r31)
		insrwi	  r7, r8, 16,0
		lbz	  r9, 0x40(r31)
		extlwi	  r5, r7, 16,8
		or	  r4, r5, r6
		or	  r3, r4, r9
		stw	  r3, 0x40(r31)
		bl	  sub_825D2050
		lis	  r11, 1 // 0x1AF24
		mr	  r4, r3
		ori	  r29, r11, 0xAF24 // 0x1AF24
		mr	  r3, r30
		mr	  r5, r29
		bl	  memcpy
		//lis	  r27, off_832F5EB8@h
		lau   r27, off_832F5EB8
		lal   r27, r27, off_832F5EB8
		mr	  r4, r30
		mr	  r5, r29
		mr	  r28, r30
		//lwz	  r3, off_832F5EB8@l(r27)
		lwz   r3, 0(r27)
		bl	  memcpy
		li	  r4, 1
		//lwz	  r3, off_832F5EB8@l(r27)
		lwz   r3, 0(r27)
		bl	  sub_82568170
		mr	  r3, r30
		mr	  r5, r29
		//lwz	  r4, off_832F5EB8@l(r27)
		lwz   r4, 0(r27)
		bl	  memcpy
		add	  r30, r30, r29
		bl	  sub_825D2060
		mr	  r4, r3
		mr	  r3, r30
		li	  r5, 0x1C00
		bl	  memcpy
		mr	  r3, r30
		li	  r4, 1
		mr	  r27, r30
		//bl	  DebugOut
		addi	  r30, r30, 0x1C00
		bl	  sub_827D2630
		lis	  r10, 1 // 0x18E70
		mr	  r4, r3
		ori	  r29, r10, 0x8E70 // 0x18E70
		mr	  r3, r30
		mr	  r5, r29
		bl	  memcpy
		mr	  r3, r30
		li	  r4, 1
		bl	  sub_8256C3B0
		add	  r11, r30, r29
		mr	  r20, r11
		addi	  r18, r11, 0x40
		bl	  sub_825D20A0
		lis	  r5, 0	// 0xF0D0
		mr	  r4, r3
		mr	  r3, r18
		ori	  r5, r5, 0xF0D0 // 0xF0D0
		bl	  memcpy
		li	  r11, 0x6BC9
		li	  r6, -1
		//lis	  r10, unk_823630B0@h
		lau r10, obf_table
		addi	  r9, r28, -1
		mr	  r8, r6
		mtspr	CTR, r11
		lis	  r11, 0x50B8 //	0x50B85761
		//addi	  r10, r10, unk_823630B0@l
		lal   r10, r10, obf_table
		ori	  r11, r11, 0x5761 // 0x50B85761

loc_827E9CF0:				// CODE XREF: Encrypt_NA_00000000.000+1A8j
		lbz	  r3, 1(r9)
		srwi	  r5, r8, 8
		lbz	  r4, 2(r9)
		xor	  r3, r3, r8
		lbz	  r29, 3(r9)
		lbzu	  r7, 4(r9)
		clrlslwi  r3, r3, 24,2
		lwzx	  r3, r3, r10
		xor	  r5, r3, r5
		xor	  r3, r5, r11
		xor	  r5, r4, r3
		srwi	  r4, r3, 8
		clrlslwi  r3, r5, 24,2
		lwzx	  r5, r3, r10
		xor	  r4, r5, r4
		xor	  r3, r4, r11
		xor	  r8, r29, r3
		srwi	  r5, r3, 8
		clrlslwi  r4, r8, 24,2
		lwzx	  r3, r4, r10
		xor	  r8, r3, r5
		xor	  r5, r8, r11
		xor	  r4, r7, r5
		srwi	  r3, r5, 8
		clrlslwi  r8, r4, 24,2
		lwzx	  r7, r8, r10
		xor	  r5, r7, r3
		xor	  r8, r5, r11
		bdnz	  loc_827E9CF0
		li	  r7, 0x700
		not	  r5, r8
		mr	  r8, r6
		addi	  r9, r27, -1
		stw	  r5, 0x38(r31)
		mtspr	CTR, r7

loc_827E9D7C:				// CODE XREF: Encrypt_NA_00000000.000+234j
		lbz	  r3, 1(r9)
		srwi	  r5, r8, 8
		lbz	  r4, 2(r9)
		xor	  r3, r3, r8
		lbz	  r29, 3(r9)
		lbzu	  r7, 4(r9)
		clrlslwi  r3, r3, 24,2
		lwzx	  r3, r3, r10
		xor	  r5, r3, r5
		xor	  r3, r5, r11
		xor	  r5, r4, r3
		srwi	  r4, r3, 8
		clrlslwi  r3, r5, 24,2
		lwzx	  r5, r3, r10
		xor	  r4, r5, r4
		xor	  r3, r4, r11
		xor	  r8, r29, r3
		srwi	  r5, r3, 8
		clrlslwi  r4, r8, 24,2
		lwzx	  r3, r4, r10
		xor	  r8, r3, r5
		xor	  r5, r8, r11
		xor	  r4, r7, r5
		srwi	  r3, r5, 8
		clrlslwi  r8, r4, 24,2
		lwzx	  r7, r8, r10
		xor	  r5, r7, r3
		xor	  r8, r5, r11
		bdnz	  loc_827E9D7C
		li	  r7, 0x639A
		not	  r5, r8
		mr	  r8, r6
		addi	  r9, r30, -1
		stw	  r5, 0x3C(r31)
		mtspr	CTR, r7

loc_827E9E08:				// CODE XREF: Encrypt_NA_00000000.000+2C0j
		lbz	  r3, 1(r9)
		srwi	  r5, r8, 8
		lbz	  r4, 2(r9)
		xor	  r3, r3, r8
		lbz	  r30, 3(r9)
		lbzu	  r7, 4(r9)
		clrlslwi  r3, r3, 24,2
		lwzx	  r3, r3, r10
		xor	  r5, r3, r5
		xor	  r3, r5, r11
		xor	  r5, r4, r3
		srwi	  r4, r3, 8
		clrlslwi  r3, r5, 24,2
		lwzx	  r5, r3, r10
		xor	  r4, r5, r4
		xor	  r3, r4, r11
		xor	  r8, r30, r3
		srwi	  r5, r3, 8
		clrlslwi  r4, r8, 24,2
		lwzx	  r3, r4, r10
		xor	  r8, r3, r5
		xor	  r5, r8, r11
		xor	  r4, r7, r5
		srwi	  r3, r5, 8
		clrlslwi  r8, r4, 24,2
		lwzx	  r7, r8, r10
		xor	  r5, r7, r3
		xor	  r8, r5, r11
		bdnz	  loc_827E9E08
		li	  r7, 0x3C34
		not	  r5, r8
		mr	  r9, r6
		addi	  r8, r18, -1
		stw	  r5, 0x30(r31)
		mtspr	CTR, r7

loc_827E9E94:				// CODE XREF: Encrypt_NA_00000000.000+34Cj
		lbz	  r4, 1(r8)
		srwi	  r6, r9, 8
		lbz	  r5, 2(r8)
		xor	  r4, r4, r9
		lbz	  r3, 3(r8)
		lbzu	  r7, 4(r8)
		clrlslwi  r9, r4, 24,2
		lwzx	  r4, r9, r10
		xor	  r9, r4, r6
		xor	  r6, r9, r11
		xor	  r5, r5, r6
		srwi	  r4, r6, 8
		clrlslwi  r9, r5, 24,2
		lwzx	  r6, r9, r10
		xor	  r5, r6, r4
		xor	  r4, r5, r11
		xor	  r3, r3, r4
		srwi	  r9, r4, 8
		clrlslwi  r6, r3, 24,2
		lwzx	  r5, r6, r10
		xor	  r4, r5, r9
		xor	  r3, r4, r11
		xor	  r9, r7, r3
		srwi	  r7, r3, 8
		clrlslwi  r6, r9, 24,2
		lwzx	  r5, r6, r10
		xor	  r4, r5, r7
		xor	  r9, r4, r11
		bdnz	  loc_827E9E94
		not	  r10, r9
		li	  r11, 0xC
		stw	  r10, 0x34(r20)
		lis	  r4, 0x5D58 // 0x5D588B65
		lbz	  r7, 0x38(r31)
		lis	  r10, -0x3334 // 0xCCCCCCCD
		lwz	  r9, 0x38(r31)
		mr	  r8, r9
		insrwi	  r8, r9, 16,0
		mtspr	CTR, r11
		rlwinm	  r6, r9, 24,16,23
		extlwi	  r5, r8, 16,8
		ori	  r30, r4, 0x8B65 // 0x5D588B65
		or	  r3, r5, r6
		ori	  r25, r10, 0xCCCD // 0xCCCCCCCD
		or	  r11, r3, r7
		//lis	  r26, dword_832E05C8@h
		lau   r26, dword_832E05C8
		lal   r26, r26, dword_832E05C8
		stw	  r11, 0x38(r31)
		addi	  r8, r31, -4
		lbz	  r9, 0x3C(r31)
		lwz	  r7, 0x3C(r31)
		mr	  r6, r7
		insrwi	  r6, r7, 16,0
		rlwinm	  r5, r7, 24,16,23
		extlwi	  r4, r6, 16,8
		or	  r3, r4, r5
		or	  r11, r3, r9
		stw	  r11, 0x3C(r31)
		lbz	  r10, 0x30(r31)
		lwz	  r9, 0x30(r31)
		mr	  r7, r9
		insrwi	  r7, r9, 16,0
		rlwinm	  r6, r9, 24,16,23
		extlwi	  r5, r7, 16,8
		or	  r4, r5, r6
		or	  r3, r4, r10
		stw	  r3, 0x30(r31)
		//lwz	  r11, dword_832E05C8@l(r26)
		lwz       r11, 0(r26)
		mullw	  r11, r11, r30
		addi	  r11, r11, 1
		mullw	  r10, r11, r30
		srwi	  r3, r11, 8
		addi	  r11, r10, 1
		mullw	  r10, r11, r30
		srwi	  r4, r11, 8
		addi	  r11, r10, 1
		mullw	  r10, r11, r30
		addi	  r10, r10, 1
		srwi	  r5, r11, 8
		srwi	  r7, r10, 8
		mulhwu	  r6, r7, r25
		srwi	  r11, r6, 2
		slwi	  r9, r11, 2
		add	  r11, r11, r9
		subf	  r11, r11, r7
		b	  loc_827E9FEC
// ---------------------------------------------------------------------------

loc_827E9FE8:				// CODE XREF: Encrypt_NA_00000000.000+444j
		//lwz	  r10, dword_832E05C8@l(r26)
		lwz       r10, 0(r26)

loc_827E9FEC:				// CODE XREF: Encrypt_NA_00000000.000+42Cj
		mullw	  r10, r10, r30
		addi	  r10, r10, 1
		//stw	  r10, dword_832E05C8@l(r26)
		stw       r10, 0(r26)
		stwu	  r10, 4(r8)
		bdnz	  loc_827E9FE8
		lis	  r10, -0x52B9 // 0xAD47DE8F
		lwz	  r9, 4(r31)
		lis	  r29, 0x2D71 //	0x2D71D26C
		ori	  r21, r10, 0xDE8F // 0xAD47DE8F
		lis	  r28, -0x43B3 // 0xBC4DEFA2
		addi	  r8, r11, 2
		addi	  r7, r11, 3
		addi	  r6, r11, 7
		lis	  r10, 0x1327 //	0x1327DE73
		or	  r9, r9, r21
		ori	  r23, r29, 0xD26C // 0x2D71D26C
		ori	  r24, r28, 0xEFA2 // 0xBC4DEFA2
		slwi	  r29, r8, 2
		slwi	  r28, r7, 2
		slwi	  r27, r6, 2
		ori	  r22, r10, 0xDE73 // 0x1327DE73
		xor	  r8, r9, r11
		xor	  r7, r3, r22
		xor	  r6, r4, r23
		stw	  r8, 0(r31)
		xor	  r11, r5, r24
		stwx	  r7, r29, r31
		stwx	  r6, r28, r31
		stwx	  r11, r27, r31
		bl	  sub_82B8BB78
		lwz	  r10, 0(r31)
		lbz	  r9, 0(r31)
		lis	  r4, 3	// 0x35998
		mr	  r8, r10
		rlwinm	  r7, r10, 24,16,23
		insrwi	  r8, r10, 16,0
		mr	  r3, r19
		extlwi	  r6, r8, 16,8
		ori	  r4, r4, 0x5998 // 0x35998
		or	  r5, r6, r7
		or	  r11, r5, r9
		stw	  r11, 0(r31)
		lbz	  r10, 4(r31)
		lwz	  r9, 4(r31)
		mr	  r8, r9
		insrwi	  r8, r9, 16,0
		rlwinm	  r7, r9, 24,16,23
		extlwi	  r6, r8, 16,8
		or	  r5, r6, r7
		or	  r11, r5, r10
		stw	  r11, 4(r31)
		lbzx	  r10, r29, r31
		lwzx	  r9, r29, r31
		mr	  r8, r9
		insrwi	  r8, r9, 16,0
		rlwinm	  r7, r9, 24,16,23
		extlwi	  r6, r8, 16,8
		or	  r5, r6, r7
		or	  r11, r5, r10
		stwx	  r11, r29, r31
		lbzx	  r10, r28, r31
		lwzx	  r9, r28, r31
		mr	  r8, r9
		insrwi	  r8, r9, 16,0
		rlwinm	  r7, r9, 24,16,23
		extlwi	  r6, r8, 16,8
		or	  r5, r6, r7
		or	  r11, r5, r10
		stwx	  r11, r28, r31
		lbzx	  r10, r27, r31
		lwzx	  r9, r27, r31
		mr	  r8, r9
		insrwi	  r8, r9, 16,0
		rlwinm	  r7, r9, 24,16,23
		extlwi	  r6, r8, 16,8
		or	  r5, r6, r7
		or	  r11, r5, r10
		stwx	  r11, r27, r31
		bl	  sub_82B8BBF8
		lis	  r4, 3	// 0x35998
		mr	  r3, r19
		ori	  r4, r4, 0x5998 // 0x35998
		bl	  sub_82576588
		li	  r11, 0xC
		addi	  r8, r20, -4
		mtspr	CTR, r11
		//lwz	  r11, dword_832E05C8@l(r26)
		lwz   r11, 0(r26)
		mullw	  r11, r11, r30
		addi	  r11, r11, 1
		mullw	  r10, r11, r30
		srwi	  r3, r11, 8
		addi	  r11, r10, 1
		mullw	  r10, r11, r30
		srwi	  r4, r11, 8
		addi	  r11, r10, 1
		mullw	  r10, r11, r30
		addi	  r10, r10, 1
		srwi	  r5, r11, 8
		srwi	  r7, r10, 8
		mulhwu	  r6, r7, r25
		srwi	  r11, r6, 2
		slwi	  r9, r11, 2
		add	  r11, r11, r9
		subf	  r11, r11, r7
		b	  loc_827EA194
// ---------------------------------------------------------------------------

loc_827EA190:				// CODE XREF: Encrypt_NA_00000000.000+5ECj
		//lwz	  r10, dword_832E05C8@l(r26)
		lwz   r10, 0(r26)

loc_827EA194:				// CODE XREF: Encrypt_NA_00000000.000+5D4j
		mullw	  r10, r10, r30
		addi	  r10, r10, 1
		//stw	  r10, dword_832E05C8@l(r26)
		stw   r10, 0(r26)
		stwu	  r10, 4(r8)
		bdnz	  loc_827EA190
		lwz	  r10, 4(r20)
		addi	  r9, r11, 2
		addi	  r8, r11, 3
		addi	  r7, r11, 7
		or	  r6, r10, r21
		slwi	  r10, r9, 2
		slwi	  r9, r8, 2
		slwi	  r8, r7, 2
		xor	  r7, r6, r11
		xor	  r6, r3, r22
		stw	  r7, 0(r20)
		xor	  r11, r4, r23
		xor	  r7, r5, r24
		stwx	  r6, r10, r20
		stwx	  r11, r9, r20
		stwx	  r7, r8, r20
		bl	  sub_82B8BB78
		lis	  r4, 0	// 0xF0D0
		mr	  r3, r18
		ori	  r4, r4, 0xF0D0 // 0xF0D0
		bl	  sub_82B8BBA0
		addi	  r1, r1, 0xD0
		//b	  __restgprlr_18
		ld       r18, -0x78(r1)
		ld       r19, -0x70(r1)
		ld       r20, -0x68(r1)
		ld       r21, -0x60(r1)
		ld       r22, -0x58(r1)
		ld       r23, -0x50(r1)
		ld       r24, -0x48(r1)
		ld       r25, -0x40(r1)
		ld       r26, -0x38(r1)
		ld       r27, -0x30(r1)
		ld       r28, -0x28(r1)
		ld       r29, -0x20(r1)
		ld       r30, -0x18(r1)
		ld       r31, -0x10(r1)
		lwz       r12, -0x8(r1)
		mtspr   lr, r12
		blr
	}
}
