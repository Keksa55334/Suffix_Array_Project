test_with_rvalue:
	movl	$42, %eax
	ret

test_with_large_rvalue:
	movl	ExternInt(%rip), %eax
	movd	%eax, %xmm1
	movl	%eax, -8(%rsp)
	pshufd	$0xe0, %xmm1, %xmm0
	movq	%xmm0, -16(%rsp)
	ret

test_with_non_trivial_rvalue:
	movl	ExternInt(%rip), %eax
	movl	%eax, -4(%rsp)
	ret

test_with_lvalue:
	movl	$101, %eax
	ret

test_with_large_lvalue:
	movl	ExternInt(%rip), %eax
	movd	%eax, %xmm1
	movl	%eax, -8(%rsp)
	pshufd	$0xe0, %xmm1, %xmm0
	movq	%xmm0, -16(%rsp)
	ret

test_with_extra_large_lvalue_with_op:
	movl	$42, 64+ExtraLargeObj(%rip)
	ret

test_with_big_array_with_op:
	movl	$42, 64+BigArray(%rip)
	ret

test_with_non_trivial_lvalue:
	movl	ExternInt(%rip), %eax
	movl	%eax, -4(%rsp)
	ret

test_with_const_lvalue:
	movl	$123, %eax
	ret

test_with_large_const_lvalue:
	movl	ExternInt(%rip), %eax
	movd	%eax, %xmm1
	movl	%eax, -8(%rsp)
	pshufd	$0xe0, %xmm1, %xmm0
	movq	%xmm0, -16(%rsp)
	ret

test_with_const_extra_large_obj:
	ret

test_with_const_big_array:
	ret

test_with_non_trivial_const_lvalue:
	movl	ExternInt(%rip), %eax
	movl	%eax, -4(%rsp)
	ret

test_div_by_two:
	movl	%edi, %eax
	movl	$2, %ecx
	cltd
	idivl	%ecx
	ret

test_inc_integer:
	movl	$1, %eax
	addl	$1, %eax
	addl	$1, %eax
	addl	$1, %eax
	addl	$1, %eax
	ret

test_pointer_rvalue:
	movl	$42, -4(%rsp)
	leaq	-4(%rsp), %rax
	ret

test_pointer_const_lvalue:
	movl	$42, -4(%rsp)
	leaq	-4(%rsp), %rax
	ret

test_pointer_lvalue:
	movl	$42, -4(%rsp)
	leaq	-4(%rsp), %rax
	ret

GLOBAL__sub_I_test_with_rvalue:
	jmp	_ZN9benchmark8internal17InitializeStreamsEv@PLT

_ZL18ConstExtraLargeObj:

_ZL13ConstBigArray:
