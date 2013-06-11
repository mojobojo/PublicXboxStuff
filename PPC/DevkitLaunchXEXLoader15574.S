.set XexLoadImage, 0x81CEB6BC
.set Loader, 0x817CDE18
.set strlocation, 0x816145F8
.set dwordlocation, 0x81D26934
.set test, 0x817CDE78
.set CTR, 9
 
	.globl begin
begin:

.long strlocation
.long (9f - 0f) / 4
0:
.string "\\SystemRoot\\launch.xex"
.byte 0
9:

.long Loader - 0x8000
.long (9f - 0f) / 4
0:
	nop
	nop
	addi	%r31, %r1, 0x50
	lis		%r11, strlocation@h
	ori		%r11, %r11, strlocation@l
	lis		%r4, 0x4000 # 0x40000008
	mr		%r5, %r3
	mr		%r6, %r31
	ori		%r4, %r4, 8 # 0x40000008
	mr		%r3, %r11
1:	bl		XexLoadImage-((1b-0b)+Loader)

5:	b		0x34

9:

.long 0xFFFFFFFF
