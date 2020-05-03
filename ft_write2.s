; ----------------------------------------------------------------------------------------
; To assemble and run:
;	nasm -felf64 ft_write.s && gcc main_write.c ft_write.o && ./a.out
; Prototype:
;	ssize_t write(int fd, const void *buf, size_t count)
; ----------------------------------------------------------------------------------------

	global		ft_write2
	extern		___error

	section		.text
ft_write2:
		mov	rax, 1
		syscall			; now, rax = -14
	; it means that ret value of write au niveau de l'assembleur is errno * -1
		cmp	rax, 0		; if rax < 0
		jl	error
		jmp	exit

error:
		mov	rdi, 0		; set rdi='status' to 0
		mov	rsi, rax
		neg	rsi		; set rsi='errnb' to (rax * -1)
		mov	rdx, format	; set rdx='format' to %s

;		push	rbp
;		mov	rbp, rsp
;		call	error
;		mov	rsp, rbp
;		pop	rbp
		
		
					; put rdi in ERRNO
		mov	rax, rdx	; set rax at -1
		jmp	exit		; exit
	
exit:
		ret

	section		.data
format:
		db	"%s", 10, 0
