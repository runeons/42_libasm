; ----------------------------------------------------------------------------------------
; To assemble and run:
;	nasm -felf64 ft_write.s && gcc main_write.c ft_write.o && ./a.out
; Prototype:
;	ssize_t write(int fd, const void *buf, size_t count)
; ----------------------------------------------------------------------------------------

	global		ft_error
	extern		error

	section		.text
ft_error:
		push	rbx
		mov	rdi, 9
		call	error
		pop	rbx
		ret
