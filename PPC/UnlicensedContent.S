# 9199 (I think)

.set PingLimitPatch, 0x819831A8
.set XContentGetLicenseMask, 0x81936128
.set DasboardGameLicenseCheck, 0x818DBAC0

		.globl _start
_start:

# ============================================================================
# PingLimitPatch - patches xam to allow any ping level to play games on lan
# ============================================================================
	.long PingLimitPatch
	.long (9f - 0f) / 4
0:
	nop
9:

# ============================================================================
# XContentGetLicenseMask - patches xam to think all arcade are full at runtime
# ============================================================================
	.long XContentGetLicenseMask
	.long (9f - 0f) / 4
0:
	li		%r11, -1
	stw		%r11, 0(%r3)
	li		%r3, 0
	blr
9:

# ============================================================================
# DasboardGameLicenseCheck - patches xam so all your arcade games appear as full
# ============================================================================
	.long DasboardGameLicenseCheck
	.long (9f - 0f) / 4
0:
	lis		%r11, 0xFFFF
	li		%r26, 0
	ori		%r30, %r11, 0xFFFF
9:
	.long 0xFFFFFFFF
	