.set XLoadImage, 0x823C2440
.set XGetProcAddress, 0x823C2400
.set PatchBase, 0x823C1F48
.set Loader, 0x82D08000
.set CTR, 9

.long PatchBase
.long (9f - 0f) / 4
0:
1:	bl		Loader-((1b-0b)+PatchBase)
9:

.long Loader
.long (9f - 0f) / 4
0:
	mfspr	%r12, %lr
	stw		%r12, -8(%sp)
	std		%r3, -16(%sp)
	std		%r4, -24(%sp)
	stwu	%sp, -0x20(%sp)
	
	lis		%r3, Dll@h
	ori		%r3, %r3, Dll@l
	bl		XLoadImage-((1b-0b)+Loader)
	mr.		%r4, %r3
	beq		end
	li		%r4, 2
	mr		%r4, %r3
	bl		XGetProcAddress-((1b-0b)+Loader)
	mr.		%r11, %r3
	beq		end
	mtspr	CTR, %r11
	bctrl
	
end:
	addi	%sp, %sp, 0x20
	lwz		%r12, -8(%sp)
	mtspr	%lr, %r12
	blr
	
Dll:
.string "GAME:\\SCIVTrainer.xex"
.align 4
9:

.long 0xFFFFFFFF
