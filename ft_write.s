; ----------------------------------------------------------------------------------------
; To assemble and run:
;	nasm -felf64 ft_write.s && gcc main_write.c ft_write.o && ./a.out
; Prototype:
;	ssize_t write(int fd, const void *buf, size_t count)
; ----------------------------------------------------------------------------------------

	global		ft_write
	global		___error
	extern		___error

	section		.text
ft_write:
		push	rbx
		jmp	write

call_fstat:
		push	rsi		; save buf for later
		push	rdx		; and count (not sure if needed)
		mov	rax, 5		; set fstat syscall args
		mov	rsi, 0;
		syscall
		pop	rsi
		pop	rdx
		cmp	rax, -9		; error "Bad file descriptor"
		jmp	err

; ai-je vraiment besoin de check ca puisque write renvoie une erreur dans tous les cas ?
; quand j'appelle fstat, errno ne semble pas se mettre à jour une fois que j'ai quitté la fonction (contrairement à la vraie fonction write)

write:
		mov	rax, 1
		syscall			; now, rax = -14
		cmp	rax, 0		; if rax < 0
		jl	err
		jmp	exit

;error2:	; using ___error
;		mov	rdi, 0		; set rdi='status' to 0
;		mov	rsi, rax
;		neg	rsi		; set rsi='errnb' to (rax * -1)
;		mov	rdx, format	; set rdx='format' to %s
;		
;					; put rdi in ERRNO
;		mov	rax, -1	; set rax at -1
;		jmp	exit		; exit

err:
		neg	rax
		mov	rbx, rax	; store errno in rbx (to use later)
		;call	_error
		;mov	rax, rbx
		jmp	exit_err

exit_err:
		mov	rax, -1
		pop	rbx
		ret

exit:
		pop	rbx
		ret

	section		.data
format:
		db	"%s", 10, 0
cmd:
		db	"F_GETFD", 0	; db : 8 bytes (size of char *)
errno:
		dq	0		; dq : 64 bytes (quadruple w=16)

;	section		.bss
;int_size	equ	64
;errno:		resb	int_size	; reserve 64 bytes (size of int)
