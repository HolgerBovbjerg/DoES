	.file	"lesson-1.c"
	.text
	.section .rdata,"dr"
.LC0:
	.ascii "Is Little Endian \0"
.LC1:
	.ascii "Is Not Little Endian \0"
	.text
	.globl	IsLittleEndian
	.def	IsLittleEndian;	.scl	2;	.type	32;	.endef
	.seh_proc	IsLittleEndian
IsLittleEndian:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movl	$1, -12(%rbp)
	leaq	-12(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$1, %al
	jne	.L2
	leaq	.LC0(%rip), %rcx
	call	puts
	jmp	.L3
.L2:
	leaq	.LC1(%rip), %rcx
	call	puts
.L3:
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC2:
	.ascii "%d\12\0"
	.text
	.globl	TwosComplement
	.def	TwosComplement;	.scl	2;	.type	32;	.endef
	.seh_proc	TwosComplement
TwosComplement:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movw	$0, -4(%rbp)
	movzbl	-4(%rbp), %eax
	orl	$1, %eax
	movb	%al, -4(%rbp)
	movzbl	-4(%rbp), %eax
	andl	$-3, %eax
	movb	%al, -4(%rbp)
	movzbl	-4(%rbp), %eax
	andl	$-5, %eax
	movb	%al, -4(%rbp)
	movzbl	-4(%rbp), %eax
	orl	$8, %eax
	movb	%al, -4(%rbp)
	movzbl	-4(%rbp), %eax
	orl	$16, %eax
	movb	%al, -4(%rbp)
	movzbl	-4(%rbp), %eax
	andl	$-33, %eax
	movb	%al, -4(%rbp)
	movzbl	-4(%rbp), %eax
	andl	$-65, %eax
	movb	%al, -4(%rbp)
	movzbl	-4(%rbp), %eax
	orl	$-128, %eax
	movb	%al, -4(%rbp)
	movzbl	-3(%rbp), %eax
	orl	$1, %eax
	movb	%al, -3(%rbp)
	movzbl	-3(%rbp), %eax
	andl	$-3, %eax
	movb	%al, -3(%rbp)
	movzbl	-3(%rbp), %eax
	orl	$4, %eax
	movb	%al, -3(%rbp)
	movzbl	-3(%rbp), %eax
	orl	$8, %eax
	movb	%al, -3(%rbp)
	movzbl	-3(%rbp), %eax
	andl	$-17, %eax
	movb	%al, -3(%rbp)
	movzbl	-3(%rbp), %eax
	orl	$32, %eax
	movb	%al, -3(%rbp)
	movzbl	-3(%rbp), %eax
	orl	$64, %eax
	movb	%al, -3(%rbp)
	movzbl	-3(%rbp), %eax
	orl	$-128, %eax
	movb	%al, -3(%rbp)
	movzwl	-4(%rbp), %eax
	cwtl
	movl	%eax, %edx
	leaq	.LC2(%rip), %rcx
	call	printf
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC3:
	.ascii "Skriv et tal i base 10: \0"
.LC4:
	.ascii "%ld\0"
.LC5:
	.ascii "Du indtastede: %ld\12\0"
.LC6:
	.ascii "Dette er i hexadecimal:\0"
	.text
	.globl	ToHexaDecimal
	.def	ToHexaDecimal;	.scl	2;	.type	32;	.endef
	.seh_proc	ToHexaDecimal
ToHexaDecimal:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$160, %rsp
	.seh_stackalloc	160
	.seh_endprologue
	movl	$0, -12(%rbp)
	leaq	.LC3(%rip), %rcx
	call	printf
	leaq	-20(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC4(%rip), %rcx
	call	scanf
	movl	-20(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC5(%rip), %rcx
	call	printf
	movl	-20(%rbp), %eax
	movl	%eax, -4(%rbp)
	jmp	.L8
.L11:
	movl	-4(%rbp), %edx
	movl	%edx, %eax
	sarl	$31, %eax
	shrl	$28, %eax
	addl	%eax, %edx
	andl	$15, %edx
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -16(%rbp)
	cmpl	$9, -16(%rbp)
	jg	.L9
	movl	-16(%rbp), %eax
	leal	48(%rax), %ecx
	movl	-12(%rbp), %eax
	leal	1(%rax), %edx
	movl	%edx, -12(%rbp)
	movl	%ecx, %edx
	cltq
	movb	%dl, -128(%rbp,%rax)
	jmp	.L10
.L9:
	movl	-16(%rbp), %eax
	leal	55(%rax), %ecx
	movl	-12(%rbp), %eax
	leal	1(%rax), %edx
	movl	%edx, -12(%rbp)
	movl	%ecx, %edx
	cltq
	movb	%dl, -128(%rbp,%rax)
.L10:
	movl	-4(%rbp), %eax
	leal	15(%rax), %edx
	testl	%eax, %eax
	cmovs	%edx, %eax
	sarl	$4, %eax
	movl	%eax, -4(%rbp)
.L8:
	cmpl	$0, -4(%rbp)
	jne	.L11
	leaq	.LC6(%rip), %rcx
	call	printf
	movl	-12(%rbp), %eax
	movl	%eax, -8(%rbp)
	jmp	.L12
.L13:
	movl	-8(%rbp), %eax
	cltq
	movzbl	-128(%rbp,%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %ecx
	call	putchar
	subl	$1, -8(%rbp)
.L12:
	cmpl	$0, -8(%rbp)
	jns	.L13
	movl	$10, %ecx
	call	putchar
	movl	$0, %eax
	addq	$160, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	call	__main
	call	IsLittleEndian
	call	TwosComplement
	call	ToHexaDecimal
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	scanf;	.scl	2;	.type	32;	.endef
	.def	putchar;	.scl	2;	.type	32;	.endef
