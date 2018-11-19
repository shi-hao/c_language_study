	.file	"main.c"
.globl share_var
	.data
	.align 4
	.type	share_var, @object
	.size	share_var, 4
share_var:
	.long	1
.globl reg
	.align 4
	.type	reg, @object
	.size	reg, 4
reg:
	.long	1
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$0, -4(%ebp)
.L2:
	movl	reg, %eax
	movl	(%eax), %eax
	cmpl	$1, %eax
	je	.L2
.L3:
	movl	share_var, %eax
	cmpl	$1, %eax
	je	.L3
.L4:
	movl	-4(%ebp), %eax
	cmpl	$1, %eax
	je	.L4
	movl	$1, -4(%ebp)
	movl	$2, -4(%ebp)
	movl	$3, -4(%ebp)
	movl	$0, share_var
	movl	$1, share_var
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.4.3-4ubuntu5.1) 4.4.3"
	.section	.note.GNU-stack,"",@progbits
