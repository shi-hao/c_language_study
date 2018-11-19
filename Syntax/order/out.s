	.file	"main.c"
	.data
	.align 4
	.type	global_var, @object
	.size	global_var, 4
global_var:
	.long	5
	.text
.globl mMul
	.type	mMul, @function
mMul:
	pushl	%ebp
	movl	%esp, %ebp
	movl	global_var, %eax
	addl	%eax, %eax
	movl	%eax, global_var
	movl	global_var, %eax
	popl	%ebp
	ret
	.size	mMul, .-mMul
.globl mMinus
	.type	mMinus, @function
mMinus:
	pushl	%ebp
	movl	%esp, %ebp
	movl	global_var, %eax
	movl	%eax, %edx
	subl	$1, %eax
	movl	%eax, global_var
	movl	%edx, %eax
	popl	%ebp
	ret
	.size	mMinus, .-mMinus
.globl mPlus
	.type	mPlus, @function
mPlus:
	pushl	%ebp
	movl	%esp, %ebp
	movl	global_var, %eax
	movl	%eax, %edx
	addl	$1, %eax
	movl	%eax, global_var
	movl	%edx, %eax
	popl	%ebp
	ret
	.size	mPlus, .-mPlus
	.section	.rodata
.LC0:
	.string	"mPlus + mMinus*mMul=%d\n"
.LC1:
	.string	"mPlus + (mMinus*mMul)=%d\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	pushl	%esi
	pushl	%ebx
	subl	$24, %esp
	call	mPlus
	movl	%eax, %ebx
	call	mMinus
	movl	%eax, %esi
	call	mMul
	imull	%esi, %eax
	leal	(%ebx,%eax), %edx
	movl	$.LC0, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$5, global_var
	call	mPlus
	movl	%eax, %ebx
	call	mMinus
	movl	%eax, %esi
	call	mMul
	imull	%esi, %eax
	leal	(%ebx,%eax), %edx
	movl	$.LC1, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	addl	$24, %esp
	popl	%ebx
	popl	%esi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.4.3-4ubuntu5.1) 4.4.3"
	.section	.note.GNU-stack,"",@progbits
