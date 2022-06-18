; ----------------------------------------------------------------------------------------
;	char	*ft_strdup(const char *s);
; ----------------------------------------------------------------------------------------

		global	ft_strdup
		extern	ft_strlen
		extern	ft_strcpy
		extern	malloc

		section	.text
ft_strdup:
		cmp	rdi, 0
		mov	rax, 0		; protect if NULL
		je	exit

store_len:
		push	rbp
		call	ft_strlen
		pop	rbp
		mov	rbx, 0
		mov	rbx, rax	; rbx holds len
		inc	rbx		; rbx holds len + 1

malloc_cpy:
		push	rdi
		mov	rdi, rbx	; rdi holds len + 1
		call	malloc
		cmp	rax, 0		; protect malloc
		je	exit
		pop	rdi		; str(src) now back in rdi

strcpy:
		mov	rsi, rdi	; src
		mov	rdi, rax	; dst
		call	ft_strcpy	
		jmp	exit

exit:
		ret
