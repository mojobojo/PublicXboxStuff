# This is for xepatcher
# currently xepatcher has a bug where memory addresses are 0x8000
# bytes off. If you want to use any other way of patching
# take off the "- 0x8000" from the memory addresses

.set XLoadImage, 0x823C2440
.set XGetProcAddress, 0x823C2400
.set PatchBase, 0x823C1F48
.set Loader, 0x823CBEC0
.set CTR, 9

	.globl begin
begin:


# nop out call from unused debug function in case it gets called
# while the game is running
.long 0x823CD40C - 0x8000
.long (9f - 0f) / 4
0:
	nop
9:

# branch to our dll loading code
.long PatchBase - 0x8000
.long (9f - 0f) / 4
0:
1:	bl		Loader-((1b-0b)+PatchBase)
9:

# copys over unused debug function. Plenty of space to add more code
.long Loader - 0x8000
.long (9f - 0f) / 4
0:
	mfspr	%r12, %lr		# Stack frame...
	stw		%r12, -8(%sp)
	std		%r3, -16(%sp)
	std		%r4, -24(%sp)
	stwu	%sp, -0x20(%sp) # ...
	
	lis		%r3, Loader@h
	ori		%r3, %r3, (Loader + Dll - 0b)@l
1:	bl		XLoadImage-((1b-0b)+Loader) # Load our xex dll
	mr.		%r11, %r3
	beq		end				# if r3 (the xex handle) was zero, get out of here
	li		%r4, 2			# get the address of the second function in the dll
	mr		%r3, %r11		# xex handle
2:	bl		XGetProcAddress-((2b-0b)+Loader) # get the procedure address
	mr.		%r11, %r3		# check if its zero
	beq		end
	mtspr	CTR, %r11
	bctrl					# branch to our dll function
	
end:
	addi	%sp, %sp, 0x20 	# Tear down...
	ld		%r4, -24(%sp)
	ld		%r3, -16(%sp)
	lwz		%r12, -8(%sp)
	mtspr	%lr, %r12
	blr						# ...
	
Dll:
.string "GAME:\\SCIVTrainer.xex"
.align 4
9:

.long 0xFFFFFFFF
