		
		.set wtf, 0x8000
		.globl _start

_start:

##################### Vars ##############################

		.long 0x82B01838 - wtf
		.long (9f - 8f) / 4
		
8:
	.float 0
	.float 99999.0		# Camera Height Limit; default = 4.0
	.float 99999.0		# Camera Range; default = 10.0
9:

#################### Camera Height ##########################

		.long 0x82A7FC4C - wtf
		.long (9f - 8f) / 4
		
8:
	b		0x82C14
9:
		.long 0x82B02860 - wtf
		.long (9f - 8f) / 4
		
8:
	lis		%r8, 0x82B0
	ori		%r8, %r8, 0x183C
	.long	0xC0280000 # lfs	%fp1, 0(%r8)
	lis		%r7, 0x8200
	ori		%r4, %r7, 0x2678
	lis		%r6, 0x82C6
	ori		%r3, %r6, 0x0788
	addi	%r7, %sp, 0x50
	b		0xFFFFFFFFFFF7D3E8
9:

################# Camera Range ##############################

		.long 0x82A7FF84 - wtf
		.long (9f - 8f) / 4
		
8:
	b		0x82904
9:
		.long 0x82B02888 - wtf
		.long (9f - 8f) / 4
		
8:
	lis		%r8, 0x82B0
	ori		%r8, %r8, 0x1840
	.long	0xC0280000 # lfs	%fp1, 0(%r8)
	lis		%r7, 0x8200
	ori		%r4, %r7, 0x2768
	lis		%r6, 0x82C6
	ori		%r3, %r6, 0x0900
	addi	%r7, %sp, 0x50
	b		0xFFFFFFFFFFF7D6F8
9:
		.long 0xFFFFFFFF
		.end
