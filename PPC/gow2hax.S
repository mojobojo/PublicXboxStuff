# ============================================================================
#   GOW 2 Patch by Mojobojo - use for modifying ini files
# ============================================================================
		.globl _start

_start:

		.long 0x8206DCA9
		.long (9f - 8f) / 4
8:
MOJOBOJO:
	.byte 'M', 'O', 'J', 'O', 'B', 'O', 'J', 'O', 0x00, 0x00, 0x00, 0x00
9:

		.long 0x827F9248
		.long (9f - 8f) / 4
8:

LoadWM:							# Loads the watermark by its address in memory
	lis		%r11, 0x8206
	ori		%r11, %r11, 0xDCA9
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
	cmpwi	%r4, 0x025F
	beq		0xC0	# Finish up if the check is valid.
9:

# ============================================================================
		.long 0xffffffff
		.end
# ============================================================================