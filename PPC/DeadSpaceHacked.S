# ============================================================================
#   Dead Space Patch by Mojobojo - I think this for for modified savegame files
# ============================================================================
		.globl _start
		.set wtf, 0x8000

_start:

#--------------------------------------------------------- File Writing 

		.long 0x82611C40 - wtf
		.long (9f - 8f) / 4
8:
.set var_18, -0x18
.set var_10, -0x10
.set var_8, -8

	mflr    %r12
	stw     %r12, var_8(%sp)
	std     %r30, var_18(%sp)
	std     %r31, var_10(%sp)
	stwu    %sp, -0x70(%sp)
	mr      %r31, %r3
	mr      %r5, %r4
	
	# Fake Checksum, always will be 0xFFFFFFFF
	lis		%r3, 0xFFFF
	ori		%r3, %r3, 0xFFFF
	
	# MOJO Magic as a watermark
	lis     %r9, 0x4D4F
	ori     %r9, %r9, 0x4A4F

	stw     %r9, 0(%r5)			# Write the magic
	stw     %r3, 0x10(%r5)		# Write the first checksum
	stw     %r3, 0x14(%r5)		# Write the second checksum
	stw     %r3, 0x18(%r5)		# Write the third checksum
	
	lwz     %r4, 0x2C(%r31)		# Load the first file size
	lwz     %r11, 0x34(%r31)	# Load the second file size
	clrlwi  %r10, %r4, 0		# Make sure the first file is not too big
	add     %r9, %r10, %r11		# Add the two file sizes
	addi    %r9, %r9, 0x1C		# Then add 0x1C (size of header) to get the final file size
	
	stw     %r9, 4(%r5) 		# Write the whole file size
	stw     %r10, 8(%r5)		# Write the first file size
	stw     %r11, 0xC(%r5)		# Write the second file size

	addi    %sp, %sp, 0x70
	lwz     %r12, var_8(%sp)
	mtlr    %r12
	ld      %r30, var_18(%sp)
	ld      %r31, var_10(%sp)
	blr
9:

#---------------------------------------------------------



#--------------------------------------------------------- Checksum Calculation

		.long 0x826138F4 - wtf
		.long (9f - 8f) / 4
8:
	# Save file header checksum removal
	li		%r3, 0
9:

		.long 0x82613B74 - wtf
		.long (9f - 8f) / 4
8:
	# File checksums removal
	li		%r3, 0
9:


		.long 0x82612524 - wtf
		.long (9f - 8f) / 4
8:
	# Unsure, but I dont need any checksums being made here
	li		%r3, 0
9:

		.long 0x8261B980  - wtf
		.long (9f - 8f) / 4
8:
	# I dont see anything pointing to this sub but better be safe than sorry
	lwz     %r4, 4(%r3)
	lwz     %r3, 0(%r3)
	li		%r3, 0
	.long 0
	li      %r4, 0x18
	li		%r3, 0
9:

		.long 0x8261B9F0 - wtf
		.long (9f - 8f) / 4
8:
	# Unsure, but I dont need any checksums being made here
	li		%r3, 0
9:

# ============================================================================
		.long 0xffffffff
		.end
# ============================================================================