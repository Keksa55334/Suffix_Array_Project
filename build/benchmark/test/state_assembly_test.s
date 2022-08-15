test_for_auto_loop:
	pushq	%rbp
	pushq	%rbx
	subq	$8, %rsp
	call	GetState@PLT
	cmpb	$0, 26(%rax)
	movq	%rax, %rbp
	je	.L2
	movq	%rax, %rdi
	call	_ZN9benchmark5State16StartKeepRunningEv@PLT
.L3:
	movq	%rbp, %rdi
	call	_ZN9benchmark5State17FinishKeepRunningEv@PLT
	addq	$8, %rsp
	movl	$101, %eax
	popq	%rbx
	popq	%rbp
	ret
.L2:
	movq	16(%rax), %rbx
	movq	%rax, %rdi
	call	_ZN9benchmark5State16StartKeepRunningEv@PLT
	testq	%rbx, %rbx
	je	.L3
	movl	$42, %edx
	testq	%rbx, %rbx
	jle	.L16
	subq	$1, %rbx
	movq	%rbx, %rcx
	je	.L3
.L5:
	subq	$1, %rcx
	jne	.L5
	jmp	.L3
.L16:
	leaq	.LC0(%rip), %rcx
	movl	$943, %edx
	leaq	.LC1(%rip), %rsi
	leaq	.LC2(%rip), %rdi
	call	__assert_fail@PLT

test_while_loop:
	pushq	%rbp
	pushq	%rbx
	movl	$42, %ebx
	subq	$8, %rsp
	call	GetState@PLT
	movq	%rax, %rbp
	jmp	.L21
.L23:
	subq	$1, %rdx
	movq	%rdx, 0(%rbp)
.L21:
	movq	0(%rbp), %rdx
	testq	%rdx, %rdx
	jg	.L23
	cmpb	$0, 24(%rbp)
	je	.L24
.L20:
	movq	%rbp, %rdi
	call	_ZN9benchmark5State17FinishKeepRunningEv@PLT
	addq	$8, %rsp
	movl	$101, %eax
	popq	%rbx
	popq	%rbp
	ret
.L24:
	movq	%rbp, %rdi
	call	_ZN9benchmark5State16StartKeepRunningEv@PLT
	cmpb	$0, 26(%rbp)
	jne	.L20
	movq	0(%rbp), %rdx
	testq	%rdx, %rdx
	jle	.L20
	jmp	.L23

GLOBAL__sub_I_test_for_auto_loop:
	jmp	_ZN9benchmark8internal17InitializeStreamsEv@PLT
