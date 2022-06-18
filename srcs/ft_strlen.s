; ----------------------------------------------------------------------------------------
;	size_t	ft_strlen(const char *s);
; ----------------------------------------------------------------------------------------

		global	ft_strlen

  	        section	.text
ft_strlen:
		mov	rax, 0		; rax (because return value) holds the len
		cmp	rdi, 0
		je	exit

count:
		cmp	BYTE [rdi + rax], 0	; cmp current char et \0
		je	exit			; if equal
		inc	rax			; i++
		jmp	count

exit:
		ret
