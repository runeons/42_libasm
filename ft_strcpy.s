; ----------------------------------------------------------------------------------------
; To assemble and run:
;	nasm -felf64 ft_strcpy.s && gcc main_strcpy.c ft_strcpy.o && ./a.out
; Prototype:
;	char	*strcpy(char *dest, const char *src);
; ----------------------------------------------------------------------------------------

	global		ft_strcpy
	extern		printf

	section		.text
ft_strcpy:
		push	rbx
		mov	rbx, 0
	
compare:
		cmp	BYTE [rdi + rbx], 0	; check if dst[rbx]
		je	exit			; if end of string
		mov	cl, BYTE [rsi + rbx]	; store src[rbx]
		mov	BYTE [rdi + rbx], cl	; replace dst[rbx]
		inc	rbx
		jmp	compare

exit:
		mov	rax, rdi
		pop	rbx
		ret
