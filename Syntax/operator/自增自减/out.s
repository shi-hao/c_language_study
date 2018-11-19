	.file	"main.c"
	.section	.rodata
.LC0:
	.string	"a=%d\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp
	movl	$1, 28(%esp)
	addl	$1, 28(%esp)
	movl	28(%esp), %eax
	addl	%eax, %eax
	movl	%eax, 28(%esp)
	addl	$1, 28(%esp)
	movl	$.LC0, %eax
	movl	28(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$1, 28(%esp)
	addl	$1, 28(%esp)
	addl	$1, 28(%esp)
	movl	28(%esp), %eax
	addl	%eax, %eax
	movl	%eax, 28(%esp)
	movl	$.LC0, %eax
	movl	28(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.4.3-4ubuntu5.1) 4.4.3"
	.section	.note.GNU-stack,"",@progbits
