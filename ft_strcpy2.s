; ----------------------------------------------------------------------------------------
; To assemble and run:
;	nasm -felf64 ft_strcpy.s && gcc main_strcpy.c ft_strcpy.o && ./a.out
; Prototype:
;	char	*strcpy(char *dest, const char *src);
; ----------------------------------------------------------------------------------------

	global		ft_strcpy
	extern		printf

          section	.text
ft_strcpy:;	push	rbx				; rbx will hold the counter
	;	mov	rbx, 0
		jmp	count

;count:	cmp	BYTE [rdi + rbx], 0			; cmp current src char et \0
;	mov	BYTE [rsi + rbx], BYTE [rdi + rbx]
;	je	exit			; if equal
;	inc	rbx			; i++
;	jmp	count

count:	
;	sub	rdi, 1
;	mov	byte [rdi + rbx], 122
;	lea	edi, [esi]
	mov	BYTE [esi + 0], 0
;	inc	rdi
	mov	eax, esi

exit:
;	pop	rbx
	ret
