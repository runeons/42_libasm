; ----------------------------------------------------------------------------------------
;	char	*strcpy(char *dest, const char *src);
; ----------------------------------------------------------------------------------------

		global	ft_strcpy

		section	.text
ft_strcpy:
		push	rbx
		mov	rbx, 0			; holds counter
		mov	rcx, 0
		cmp	rsi, 0
		je	exit_err
	
replace:
		cmp	BYTE [rsi + rbx], 0	; check if src[rbx]
		mov	cl, BYTE [rsi + rbx]	
		mov	BYTE [rdi + rbx], cl	
		je	exit			; if end of string
		inc	rbx
		jmp	replace

exit:
		mov	rax, 0
		mov	rax, rdi
		pop	rbx
		ret

exit_err:
		mov	rax, 0
		pop	rbx
		ret
