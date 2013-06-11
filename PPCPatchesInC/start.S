# gcc likes to use r0 so preserving it just in case

.globl _start
_start:
	mfspr	%r12, %lr
	stw		%r12, -8(%sp)
	stwu	%sp, -0x20(%sp)
	std		%r0, -0x10(%sp)
	bl		main
	ld		%r0, -0x10(%sp)
	addi	%sp, %sp, 0x20
	lwz		%r12, -8(%sp)
	mtspr	%lr, %r12
	blr
