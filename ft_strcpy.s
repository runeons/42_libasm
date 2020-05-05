; ----------------------------------------------------------------------------------------
; To assemble and run:
;	nasm -felf64 ft_strcpy.s && gcc main_strcpy.c ft_strcpy.o && ./a.out
; Prototype:
;	char	*strcpy(char *dest, const char *src);
; ----------------------------------------------------------------------------------------

	global		ft_strcpy

	section		.text

ft_strcpy:
		push	rbx
		mov	rbx, 0
	
compare:
		cmp	BYTE [rsi + rbx], 0	; check if src[rbx]
		mov	cl, BYTE [rsi + rbx]	; store src[rbx]
		mov	BYTE [rdi + rbx], cl	; replace dst[rbx]
		je	exit			; if end of string
		inc	rbx
		jmp	compare

exit:
		mov	rax, 0
		mov	rax, rdi
		pop	rbx
		ret
