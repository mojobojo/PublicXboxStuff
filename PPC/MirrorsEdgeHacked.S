# ============================================================================
#   Mirrors Edge Patch by Mojobojo - use for modifying ini files
# ============================================================================
		.set wtf, 0x8000
		.globl _start

_start:

		.long 0x823AABD8 - wtf
		.long (9f - 8f) / 4
8:
	#Uncomment if you dont like the splash screen.
	#li		%r3, 0
9:

		.long 0x822B6D04 - wtf
		.long (9f - 8f) / 4
8:
	b	LoadWM

MOJOBOJO:
	.byte 'O', 'P', 'E', 'N', 'E', 'D', 'G', 'E', 0x00, 0x00, 0x00, 0x00

LoadWM:							# Loads the watermark by its address in memory
	lis		%r11, 0x822B
	ori		%r11, %r11, 0x6D08
	li		%r5, 0				# Loop Index
	li		%r4, 0				# Calculated Checksum holder
	
loopz:							# Just a basic adding checksum.
	lbz		%r3, 0(%r11)
	add		%r4, %r4, %r3
	addi	%r5, %r5, 1
	addi	%r11, %r11, 1
	cmpwi	%r5, 8
	bne		loopz

CheckIfValid:
	cmpwi	%r4, 0x0247
	beq		0x60		# Finish up if the check is valid.
9:

# ============================================================================
		.long 0xffffffff
		.end
# ============================================================================