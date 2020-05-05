; ----------------------------------------------------------------------------------------
; To assemble and run:
;	nasm -felf64 ft_read.s && gcc main_read.c ft_read.o && ./a.out
; Prototype:
;	ssize_t read(int fd, const void *buf, size_t count)
; ----------------------------------------------------------------------------------------

	global		ft_read
	extern		__errno_location

	section		.text
ft_read:
		push	rbx
		jmp	read

read:
		mov	rax, 0
		syscall			
		cmp	rax, 0			; if rax < 0
		jl	exit_err
		jmp	exit

exit_err:
		neg	rax
		mov	rbx, rax
		call	__errno_location
		mov	QWORD [rax], rbx	; write over in errno location
		mov	rax, -1
		pop	rbx
		ret

exit:
		pop	rbx
		ret
