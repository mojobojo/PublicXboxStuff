# mojobojo 2012 - dumps the hypervisor to address in register 4

	.globl _start
_start:
	mflr	%r12
	std	  	%r12, -8(%r1)
	std	  	%r13, -0x10(%r1)
	std	  	%r14, -0x18(%r1)
	std		%r15, -0x20(%r1)
	stdu	%r1, -0x30(%r1)
	
	# HV address 0x0000000000000000
	lis		%r14, 0x1 
	li		%r15, 0

cploop1:
	lbzx	%r13, %r0, %r15
	stbx	%r13, %r4, %r15
	addi	%r15, %r15, 1
	cmplw	%r15, %r14
	bne		cploop1
	
	# HV address 0x0000000200010000
	
	lis		%r14, 1
	add		%r4, %r4, %r14
	
	lis		%r14, 1 
	li		%r15, 0
	
	li		%r12, 2
	sldi	%r12, %r12, 32
	oris	%r12, %r12, 1
	
cploop2:
	lbzx	%r13, %r12, %r15
	stbx	%r13, %r4, %r15
	addi	%r15, %r15, 1
	cmplw	%r15, %r14
	bne		cploop2
	
	# HV address 0x0000000400020000
	
	lis		%r14, 1
	add		%r4, %r4, %r14
	
	lis		%r14, 1 
	li		%r15, 0
	
	li		%r12, 4
	sldi	%r12, %r12, 32
	oris	%r12, %r12, 2
	
cploop3:
	lbzx	%r13, %r12, %r15
	stbx	%r13, %r4, %r15
	addi	%r15, %r15, 1
	cmplw	%r15, %r14
	bne		cploop3
	

	# HV address 0x0000000600030000
	
	lis		%r14, 1
	add		%r4, %r4, %r14
	
	lis		%r14, 1 
	li		%r15, 0
	
	li		%r12, 6
	sldi	%r12, %r12, 32
	oris	%r12, %r12, 3
	
cploop4:
	lbzx	%r13, %r12, %r15
	stbx	%r13, %r4, %r15
	addi	%r15, %r15, 1
	cmplw	%r15, %r14
	bne		cploop4
	
	addi	%r1, %r1, 0x30
	ld		%r12, -8(%r1)
	mtlr	%r12
	ld		%r15, -0x20(%r1)
	ld		%r14, -0x18(%r1)
	ld		%r13, -0x10(%r1)
	lis		%r3, 0xBAD # 0xBADF00D
	ori		%r3, %r3, 0xF00D # 0xBADF00D
	blr
