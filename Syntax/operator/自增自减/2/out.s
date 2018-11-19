	.file	"main2.c"
	.section	.rodata
.LC0:
	.string	"a=%d\n"
.LC1:
	.string	"for 1!"
.LC2:
	.string	"for 2!"
.LC3:
	.string	"while 1!"
.LC4:
	.string	"while 2!"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp
	movl	$2, 28(%esp)
	movl	$0, 24(%esp)
	addl	$1, 28(%esp)
	movl	28(%esp), %eax
	subl	$2, %eax
	movl	%eax, 24(%esp)
	movl	$.LC0, %eax
	movl	28(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	subl	$2, 28(%esp)
	subl	$1, 28(%esp)
	movl	$.LC0, %eax
	movl	28(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$.LC1, (%esp)
	call	puts
	movl	$0, 28(%esp)
	jmp	.L2
.L3:
	movl	$.LC0, %eax
	movl	28(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	addl	$1, 28(%esp)
.L2:
	cmpl	$1, 28(%esp)
	jle	.L3
	movl	$.LC2, (%esp)
	call	puts
	movl	$0, 28(%esp)
	jmp	.L4
.L5:
	movl	$.LC0, %eax
	movl	28(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	addl	$1, 28(%esp)
.L4:
	cmpl	$1, 28(%esp)
	jle	.L5
	movl	$.LC3, (%esp)
	call	puts
	movl	$0, 28(%esp)
	jmp	.L6
.L7:
	movl	$.LC0, %eax
	movl	28(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
.L6:
	addl	$1, 28(%esp)
	cmpl	$1, 28(%esp)
	jle	.L7
	movl	$.LC4, (%esp)
	call	puts
	movl	$0, 28(%esp)
	jmp	.L8
.L9:
	movl	$.LC0, %eax
	movl	28(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
.L8:
	cmpl	$1, 28(%esp)
	setle	%al
	addl	$1, 28(%esp)
	testb	%al, %al
	jne	.L9
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.4.3-4ubuntu5.1) 4.4.3"
	.section	.note.GNU-stack,"",@progbits
