; ----------------------------------------------------------------------------------------
; Writes "Hello, World" to the console using only system calls. Runs on 64-bit Linux only.
; To assemble and run:
;	nasm -felf64 ft_strlen.s && gcc callstrlen.c ft_strlen.o && ./a.out
;
; ----------------------------------------------------------------------------------------

          global    start

          section   .text
start:	mov	r12, 0		; r12 holds the len
	mov	r13, rsi	; r13 holds the current char

count:	cmp	r13, 0
	je	write
	inc	r12
	inc	r13
	jmp	count

write:	mov	rax, 1		; system call for write
	mov	rdi, 1		; file handle 1 is stdout
	mov	rsi, r12	; address of string to output
	mov	rdx, 1		; number of bytes
	syscall			; invoke operating system to do the write
	mov	rax, 60		; system call for exit
	xor	rdi, rdi	; exit code 0
	syscall			; invoke operating system to exit
