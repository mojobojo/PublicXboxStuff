.set NtAllocateEncryptedMemory, 0x80082170
.set NtFreeEncryptedMemory, 0x800823E0
.set MmAllocatePhysicalMemory, 0x8007FD30
.set MmFreePhysicalMemory, 0x8007FA38
.set STATUS_NO_MEMORY, 0xC0000017 # NT Status
.set PAGE_FLAGS, 0x20000004 # MEM_LARGE_PAGES | PAGE_READWRITE

.long NtAllocateEncryptedMemory
.long (9f - 0f) / 4
0:
	mfspr	%r12, %lr # Setup stack frame
	stw		%r12, -8(%sp)
	stwu	%sp, -0x20(%sp) # This may be a little more than we need
	
	# r3 = process (IDLE_PROC = 0, USER_PROC = 1, SYSTEM_PROC = 2)
	# r4 = amount to allocate
	# r5 = output buffer ptr
	
	stw		%r5, 0x10(%sp) # preserve the outbut buffer ptr
	
	lis		%r5, PAGE_FLAGS@h # Load the page flags
	ori		%r5, %r5, PAGE_FLAGS@l
	
	# allocate non encrypted physical memory
1:	bl		MmAllocatePhysicalMemory-((1b-0b)+NtAllocateEncryptedMemory)

	cmpwi	%r3, 0
	beq		allocfail # failed allocation
	lwz		%r4, 0x10(%sp)  # restore the outbut buffer ptr
	stw		%r3, 0(%r4) # store the allocated data ptr
	b		allocend
	
allocfail:
	lis		%r3, STATUS_NO_MEMORY@h
	ori		%r3, %r3, STATUS_NO_MEMORY@l

allocend:
	addi	%sp, %sp, 0x20 # Tear down stack frame
	lwz		%r12, -8(%sp)
	mtspr	%lr, %r12
	blr
9:

.long NtFreeEncryptedMemory
.long (9f - 0f) / 4
0:
1:	b		MmFreePhysicalMemory-((1b-0b)+NtFreeEncryptedMemory)
9:

.long 0xFFFFFFFF
