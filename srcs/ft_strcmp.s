; ----------------------------------------------------------------------------------------
;	int	ft_strcmp(const char *s1, const char *s2);
; ----------------------------------------------------------------------------------------

		global	ft_strcmp

		section	.text
ft_strcmp:
		push	rbx			; holds counter
		cmp	rdi, 0
		je	exit_err
		cmp	rsi, 0
		je	exit_err
		mov	rbx, 0
	
compare:
		mov	rcx, 0
		mov	rdx, 0
		mov	cl, BYTE [rdi + rbx]	; s1[rbx] in cl
		mov	dl, BYTE [rsi + rbx]	; s2[rbx] in dl
		cmp	cl, dl
		jne	exit
		cmp	cl, 0
		je	exit
		cmp	dl, 0
		je	exit
		inc	rbx
		jmp	compare

exit:
		sub	rcx, rdx
		mov	rax, rcx		; fill rax with (cl - dl)
		pop	rbx
		ret

exit_err:
		mov	rax, 0
		pop	rbx
		ret
