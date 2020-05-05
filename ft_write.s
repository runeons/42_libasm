; ----------------------------------------------------------------------------------------
; To assemble and run:
;	nasm -felf64 ft_write.s && gcc main_write.c ft_write.o && ./a.out
; Prototype:
;	ssize_t write(int fd, const void *buf, size_t count)
; ----------------------------------------------------------------------------------------

	global		ft_write
	extern		__errno_location

	section		.text
ft_write:
		push	rbx
		jmp	write

write:
		mov	rax, 1
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
