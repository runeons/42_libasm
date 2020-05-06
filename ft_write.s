; ----------------------------------------------------------------------------------------
;	ssize_t write(int fd, const void *buf, size_t count)
; ----------------------------------------------------------------------------------------

		global	ft_write
		extern	__errno_location

		section	.text
ft_write:
		push	rbx
		mov	rbx, 0

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
