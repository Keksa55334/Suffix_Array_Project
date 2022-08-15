test_basic:
	leaq	-4(%rsp), %rax
	movl	$101, -4(%rsp)
	ret

test_redundant_store:
	movl	$3, ExternInt(%rip)
	movl	$51, ExternInt(%rip)
	ret

test_redundant_read:
	leaq	-4(%rsp), %rax
	movl	ExternInt(%rip), %eax
	movl	%eax, -4(%rsp)
	ret

test_redundant_read2:
	leaq	-4(%rsp), %rax
	movl	ExternInt(%rip), %eax
	movl	%eax, -4(%rsp)
	movl	ExternInt2(%rip), %eax
	movl	%eax, -4(%rsp)
	ret

GLOBAL__sub_I_test_basic:
	jmp	_ZN9benchmark8internal17InitializeStreamsEv@PLT
