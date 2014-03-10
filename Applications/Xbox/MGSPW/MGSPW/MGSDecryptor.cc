#include "stdafx.h"
#include "MGSDecryptor.h"
#include "MGSCryptShared.h"

extern unsigned char obf_table[];
extern unsigned int off_832F5EB8[];

void __declspec(naked) sub_82B8C0D8() {
	__asm {
		mfspr	r12, LR
		//bl	  __savegprlr_28
		std       r28, -0x28(r1)
		std       r29, -0x20(r1)
		std       r30, -0x18(r1)
		std       r31, -0x10(r1)
		stw       r12, -0x8(r1)

		stwu	  r1, -0x80(r1)
		mr	  r31, r3
		mr	  r30, r4
		mr	  r29, r5
		mr	  r28, r6
		bl	  sub_825D2050
		lis	  r5, 1	// 0x1AF24
		mr	  r4, r31
		ori	  r5, r5, 0xAF24 // 0x1AF24
		bl	  memcpy
		bl	  sub_825D2060
		mr	  r4, r30
		li	  r5, 0x1C00
		bl	  memcpy
		bl	  sub_827D2630
		lis	  r5, 1	// 0x18E70
		mr	  r4, r29
		ori	  r5, r5, 0x8E70 // 0x18E70
		bl	  memcpy
		//bl	  sub_825D20A0
		lis	  r5, 0	// 0xF0D0
		mr	  r4, r28
		ori	  r5, r5, 0xF0D0 // 0xF0D0
		bl	  memcpy
		addi	  r1, r1, 0x80
		//b	  __restgprlr_28
		ld       r28, -0x28(r1)
		ld       r29, -0x20(r1)
		ld       r30, -0x18(r1)
		ld       r31, -0x10(r1)
		lwz       r12, -0x8(r1)
		mtspr   LR, r12
		blr
	}
}

void __declspec(naked) Decrypt_NA_00000000(void *ptr) {
	__asm {
		mfspr	r12, lr
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
		//lwz	  r31, 0x6C(r3)
		mr    r31, r3
		lis	  r11, -0x52B9 // 0xAD47DE8F
		lwz	  r10, 0(r31)
		lbz	  r9, 0(r31)
		mr	  r8, r10
		rlwinm	  r7, r10, 24,16,23
		insrwi	  r8, r10, 16,0
		extlwi	  r6, r8, 16,8
		or	  r5, r6, r7
		or	  r4, r5, r9
		stw	  r4, 0(r31)
		lbz	  r3, 4(r31)
		lwz	  r10, 4(r31)
		mr	  r9, r10
		insrwi	  r9, r10, 16,0
		rlwinm	  r8, r10, 24,16,23
		extlwi	  r7, r9, 16,8
		or	  r6, r7, r8
		or	  r5, r6, r3
		stw	  r5, 4(r31)
		lbz	  r4, 8(r31)
		lwz	  r3, 8(r31)
		mr	  r10, r3
		insrwi	  r10, r3, 16,0
		rlwinm	  r9, r3, 24,16,23
		extlwi	  r8, r10, 16,8
		or	  r7, r8, r9
		or	  r6, r7, r4
		stw	  r6, 8(r31)
		lbz	  r5, 0xC(r31)
		lwz	  r4, 0xC(r31)
		mr	  r3, r4
		insrwi	  r3, r4, 16,0
		rlwinm	  r10, r4, 24,16,23
		extlwi	  r9, r3, 16,8
		or	  r8, r9, r10
		or	  r7, r8, r5
		stw	  r7, 0xC(r31)
		lbz	  r6, 0x10(r31)
		lwz	  r5, 0x10(r31)
		mr	  r4, r5
		insrwi	  r4, r5, 16,0
		rlwinm	  r3, r5, 24,16,23
		extlwi	  r10, r4, 16,8
		or	  r9, r10, r3
		or	  r8, r9, r6
		stw	  r8, 0x10(r31)
		lbz	  r7, 0x14(r31)
		lwz	  r6, 0x14(r31)
		mr	  r5, r6
		insrwi	  r5, r6, 16,0
		rlwinm	  r4, r6, 24,16,23
		extlwi	  r3, r5, 16,8
		or	  r10, r3, r4
		or	  r9, r10, r7
		stw	  r9, 0x14(r31)
		lbz	  r8, 0x18(r31)
		lwz	  r7, 0x18(r31)
		mr	  r6, r7
		insrwi	  r6, r7, 16,0
		rlwinm	  r5, r7, 24,16,23
		extlwi	  r4, r6, 16,8
		or	  r3, r4, r5
		or	  r10, r3, r8
		stw	  r10, 0x18(r31)
		lbz	  r9, 0x1C(r31)
		lwz	  r8, 0x1C(r31)
		mr	  r7, r8
		insrwi	  r7, r8, 16,0
		rlwinm	  r6, r8, 24,16,23
		extlwi	  r5, r7, 16,8
		or	  r4, r5, r6
		or	  r3, r4, r9
		stw	  r3, 0x1C(r31)
		lwz	  r10, 0x20(r31)
		mr	  r9, r10
		insrwi	  r9, r10, 16,0
		lbz	  r8, 0x20(r31)
		rlwinm	  r7, r10, 24,16,23
		extlwi	  r6, r9, 16,8
		or	  r5, r6, r7
		or	  r4, r5, r8
		lis	  r3, -0x43B3 //	0xBC4DEFA2
		stw	  r4, 0x20(r31)
		ori	  r26, r11, 0xDE8F // 0xAD47DE8F
		lbz	  r10, 0x24(r31)
		ori	  r27, r3, 0xEFA2 // 0xBC4DEFA2
		lwz	  r8, 0x24(r31)
		mr	  r7, r8
		insrwi	  r7, r8, 16,0
		rlwinm	  r6, r8, 24,16,23
		extlwi	  r5, r7, 16,8
		lis	  r11, 0x2D71 //	0x2D71D26C
		or	  r4, r5, r6
		ori	  r28, r11, 0xD26C // 0x2D71D26C
		or	  r3, r4, r10
		lis	  r9, 0x1327 // 0x1327DE73
		stw	  r3, 0x24(r31)
		lbz	  r11, 0x28(r31)
		ori	  r29, r9, 0xDE73 // 0x1327DE73
		lwz	  r10, 0x28(r31)
		mr	  r9, r10
		insrwi	  r9, r10, 16,0
		rlwinm	  r8, r10, 24,16,23
		extlwi	  r7, r9, 16,8
		or	  r6, r7, r8
		or	  r5, r6, r11
		stw	  r5, 0x28(r31)
		lbz	  r4, 0x2C(r31)
		lwz	  r3, 0x2C(r31)
		mr	  r11, r3
		insrwi	  r11, r3, 16,0
		rlwinm	  r10, r3, 24,16,23
		extlwi	  r9, r11, 16,8
		or	  r8, r9, r10
		or	  r7, r8, r4
		stw	  r7, 0x2C(r31)
		lbz	  r6, 0x30(r31)
		lwz	  r5, 0x30(r31)
		mr	  r4, r5
		insrwi	  r4, r5, 16,0
		rlwinm	  r3, r5, 24,16,23
		extlwi	  r11, r4, 16,8
		or	  r10, r11, r3
		or	  r9, r10, r6
		stw	  r9, 0x30(r31)
		lbz	  r6, 0x34(r31)
		lwz	  r8, 0x34(r31)
		mr	  r7, r8
		insrwi	  r7, r8, 16,0
		rlwinm	  r5, r8, 24,16,23
		extlwi	  r4, r7, 16,8
		or	  r3, r4, r5
		or	  r11, r3, r6
		stw	  r11, 0x34(r31)
		lbz	  r8, 0x38(r31)
		lwz	  r10, 0x38(r31)
		mr	  r9, r10
		insrwi	  r9, r10, 16,0
		rlwinm	  r7, r10, 24,16,23
		extlwi	  r6, r9, 16,8
		or	  r5, r6, r7
		or	  r4, r5, r8
		stw	  r4, 0x38(r31)
		lbz	  r10, 0x3C(r31)
		lwz	  r3, 0x3C(r31)
		mr	  r11, r3
		insrwi	  r11, r3, 16,0
		rlwinm	  r9, r3, 24,16,23
		extlwi	  r8, r11, 16,8
		or	  r7, r8, r9
		or	  r6, r7, r10
		stw	  r6, 0x3C(r31)
		lwz	  r4, 4(r31)
		or	  r3, r4, r26
		lwz	  r5, 0(r31)
		xor	  r11, r3, r5
		addi	  r10, r11, 7
		addi	  r9, r11, 3
		addi	  r8, r11, 2
		slwi	  r7, r10, 2
		slwi	  r6, r9, 2
		slwi	  r4, r8, 2
		lwzx	  r3, r6, r31
		lwzx	  r5, r7, r31
		xor	  r5, r5, r27
		lwzx	  r11, r4, r31
		xor	  r4, r3, r28
		xor	  r3, r11, r29
		bl	  sub_82B8BB78
		addi	  r30, r31, 0x40
		lis	  r4, 3	// 0x35998
		mr	  r3, r30
		ori	  r4, r4, 0x5998 // 0x35998
		bl	  sub_82576588
		lis	  r4, 3	// 0x35998
		mr	  r3, r30
		ori	  r4, r4, 0x5998 // 0x35998
		bl	  sub_82B8BBA0
		lis	  r10, 1 // 0x1AF24
		addi	  r11, r30, 4
		ori	  r24, r10, 0xAF24 // 0x1AF24
		mr	  r25, r11
		add	  r23, r11, r24
		addis	  r11, r11, 2
		lis	  r9, 1	// 0x18E70
		addi	  r11, r11, -0x34DC
		ori	  r21, r9, 0x8E70 // 0x18E70
		mr	  r22, r11
		add	  r30, r11, r21
		mr	  r8, r28
		mr	  r28, r30
		lwzx	  r6, r11, r21
		lwz	  r7, 4(r30)
		or	  r5, r7, r26
		xor	  r11, r5, r6
		addi	  r4, r11, 7
		addi	  r3, r11, 3
		addi	  r11, r11, 2
		slwi	  r10, r4, 2
		slwi	  r9, r3, 2
		slwi	  r7, r11, 2
		lwzx	  r6, r10, r30
		lwzx	  r4, r9, r30
		lwzx	  r3, r7, r30
		xor	  r5, r6, r27
		xor	  r4, r4, r8
		xor	  r3, r3, r29
		bl	  sub_82B8BB78
		lis	  r11, 0 // 0xF0D0
		addi	  r30, r30, 0x40
		ori	  r29, r11, 0xF0D0 // 0xF0D0
		mr	  r3, r30
		mr	  r4, r29
		bl	  sub_82B8BBA0
		lis	  r4, 3	// 0x35994
		mr	  r3, r25
		ori	  r4, r4, 0x5994 // 0x35994
		add	  r27, r30, r29
		bl	  sub_82576588
		li	  r11, 0x6BC9
		li	  r6, -1
		lwz	  r4, 0x38(r31)
		//lis	  r10, unk_823630B0@h
		lau r10, obf_table
		lwz	  r3, 0x3C(r31)
		addi	  r9, r25, -1
		mr	  r8, r6
		mtspr	CTR, r11
		lis	  r11, 0x50B8 //	0x50B85761
		//addi	  r10, r10, unk_823630B0@l
		lal r10, r10, obf_table
		ori	  r11, r11, 0x5761 // 0x50B85761

loc_827EA5B0:				// CODE XREF: Decrypt_NA_00000000.000+41Cj
		lbz	  r20, 1(r9)
		srwi	  r5, r8, 8
		lbz	  r26, 2(r9)
		xor	  r8, r20, r8
		lbz	  r19, 3(r9)
		lbzu	  r7, 4(r9)
		clrlslwi  r8, r8, 24,2
		mr	  r20, r19
		lwzx	  r8, r8, r10
		xor	  r5, r8, r5
		xor	  r8, r5, r11
		xor	  r5, r26, r8
		srwi	  r8, r8, 8
		clrlslwi  r5, r5, 24,2
		lwzx	  r5, r5, r10
		xor	  r8, r5, r8
		xor	  r5, r8, r11
		xor	  r8, r19, r5
		srwi	  r5, r5, 8
		clrlslwi  r8, r8, 24,2
		lwzx	  r8, r8, r10
		xor	  r5, r8, r5
		xor	  r8, r5, r11
		xor	  r7, r7, r8
		srwi	  r5, r8, 8
		clrlslwi  r8, r7, 24,2
		lwzx	  r7, r8, r10
		xor	  r5, r7, r5
		xor	  r8, r5, r11
		bdnz	  loc_827EA5B0
		li	  r7, 0x700
		not	  r5, r8
		mr	  r8, r6
		addi	  r9, r23, -1
		mtspr	CTR, r7

loc_827EA63C:				// CODE XREF: Decrypt_NA_00000000.000+4A8j
		lbz	  r19, 1(r9)
		srwi	  r26, r8, 8
		lbz	  r20, 2(r9)
		xor	  r8, r19, r8
		lbz	  r18, 3(r9)
		lbzu	  r7, 4(r9)
		clrlslwi  r8, r8, 24,2
		mr	  r19, r18
		lwzx	  r8, r8, r10
		xor	  r8, r8, r26
		xor	  r8, r8, r11
		xor	  r26, r20, r8
		srwi	  r8, r8, 8
		clrlslwi  r26, r26, 24,2
		lwzx	  r26, r26, r10
		xor	  r8, r26, r8
		xor	  r8, r8, r11
		xor	  r26, r18, r8
		srwi	  r8, r8, 8
		clrlslwi  r26, r26, 24,2
		lwzx	  r26, r26, r10
		xor	  r8, r26, r8
		xor	  r8, r8, r11
		xor	  r7, r7, r8
		srwi	  r8, r8, 8
		clrlslwi  r7, r7, 24,2
		lwzx	  r7, r7, r10
		xor	  r8, r7, r8
		xor	  r8, r8, r11
		bdnz	  loc_827EA63C
		cmplw	  cr6, r5, r4
		bne	  cr6, loc_827EA8C8
		not	  r9, r8
		cmplw	  cr6, r9, r3
		bne	  cr6, loc_827EA8C8
		li	  r7, 0x639A
		lwz	  r5, 0x30(r31)
		mr	  r8, r6
		addi	  r9, r22, -1
		mtspr	CTR, r7

loc_827EA6DC:				// CODE XREF: Decrypt_NA_00000000.000+548j
		lbz	  r26, 1(r9)
		srwi	  r4, r8, 8
		lbz	  r3, 2(r9)
		xor	  r8, r26, r8
		lbz	  r20, 3(r9)
		lbzu	  r7, 4(r9)
		clrlslwi  r8, r8, 24,2
		mr	  r26, r20
		lwzx	  r8, r8, r10
		xor	  r4, r8, r4
		xor	  r8, r4, r11
		xor	  r4, r3, r8
		srwi	  r3, r8, 8
		clrlslwi  r8, r4, 24,2
		lwzx	  r4, r8, r10
		xor	  r3, r4, r3
		xor	  r8, r3, r11
		xor	  r4, r20, r8
		srwi	  r3, r8, 8
		clrlslwi  r8, r4, 24,2
		lwzx	  r4, r8, r10
		xor	  r3, r4, r3
		xor	  r8, r3, r11
		xor	  r7, r7, r8
		srwi	  r4, r8, 8
		clrlslwi  r3, r7, 24,2
		lwzx	  r8, r3, r10
		xor	  r7, r8, r4
		xor	  r8, r7, r11
		bdnz	  loc_827EA6DC
		not	  r9, r8
		cmplw	  cr6, r9, r5
		bne	  cr6, loc_827EA8C8
		li	  r7, 0x3C34
		lwz	  r5, 0x34(r28)
		mr	  r8, r6
		addi	  r9, r30, -1
		mtspr	CTR, r7

loc_827EA774:				// CODE XREF: Decrypt_NA_00000000.000+5DCj
		lbz	  r3, 1(r9)
		srwi	  r6, r8, 8
		lbz	  r4, 2(r9)
		xor	  r3, r3, r8
		lbz	  r28, 3(r9)
		lbzu	  r7, 4(r9)
		clrlslwi  r3, r3, 24,2
		lwzx	  r3, r3, r10
		xor	  r6, r3, r6
		xor	  r3, r6, r11
		xor	  r6, r4, r3
		srwi	  r4, r3, 8
		clrlslwi  r3, r6, 24,2
		lwzx	  r6, r3, r10
		xor	  r4, r6, r4
		xor	  r3, r4, r11
		xor	  r8, r28, r3
		srwi	  r6, r3, 8
		clrlslwi  r4, r8, 24,2
		lwzx	  r3, r4, r10
		xor	  r8, r3, r6
		xor	  r6, r8, r11
		xor	  r4, r7, r6
		srwi	  r3, r6, 8
		clrlslwi  r8, r4, 24,2
		lwzx	  r7, r8, r10
		xor	  r6, r7, r3
		xor	  r8, r6, r11
		bdnz	  loc_827EA774
		not	  r11, r8
		cmplw	  cr6, r11, r5
		bne	  cr6, loc_827EA8C8
		//lis	  r28, off_832F5EB8@h
		lau   r28, off_832F5EB8
		lal   r28, r28, off_832F5EB8
		mr	  r5, r24
		mr	  r4, r25
		//lwz	  r3, off_832F5EB8@l(r28)
		lwz   r3, 0(r28)
		bl	  memcpy
		li	  r4, 0
		//lwz	  r3, off_832F5EB8@l(r28)
		lwz   r3, 0(r28)
		bl	  sub_82568170
		mr	  r5, r24
		mr	  r3, r25
		//lwz	  r4, off_832F5EB8@l(r28)
		lwz   r4, 0(r28)
		bl	  memcpy
		li	  r4, 0
		mr	  r3, r23
		//bl	  DebugOut
		li	  r4, 0
		mr	  r3, r22
		bl	  sub_8256C3B0
		bl	  sub_82B8BFB8
		subf	  r11, r27, r31
		lis	  r10, 0 // 0x8000
		add	  r9, r3, r11
		ori	  r8, r10, 0x8000 // 0x8000
		cmpw	  cr6, r9, r8
		blt	  cr6, loc_827EA87C
		mr	  r7, r27
		mr	  r6, r30
		mr	  r5, r22
		mr	  r4, r23
		mr	  r3, r25
		bl	  sub_82B8C0D8
		li	  r3, 0
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
// ---------------------------------------------------------------------------

loc_827EA87C:				// CODE XREF: Decrypt_NA_00000000.000+64Cj
		bl	  sub_825D2050
		mr	  r4, r25
		mr	  r5, r24
		bl	  memcpy
		bl	  sub_825D2060
		mr	  r4, r23
		li	  r5, 0x1C00
		bl	  memcpy
		bl	  sub_827D2630
		mr	  r4, r22
		mr	  r5, r21
		bl	  memcpy
		bl	  sub_825D20A0
		mr	  r4, r30
		mr	  r5, r29
		bl	  memcpy
		li	  r3, 0
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
// ---------------------------------------------------------------------------

loc_827EA8C8:				// CODE XREF: Decrypt_NA_00000000.000+4B0j
					        // Decrypt_NA_00000000.000+4BCj	...
		li	  r3, 1
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
