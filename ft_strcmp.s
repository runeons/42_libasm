; ----------------------------------------------------------------------------------------
;	char	*strcmp(char *dest, const char *src);
; ----------------------------------------------------------------------------------------

		global	ft_strcmp

		section	.text
ft_strcmp:
		push	rbx			; holds counter
		mov	rbx, 0
		cmp	rdi, 0
		je	exit_err
		cmp	rsi, 0
		je	exit_err
	
compare:
		mov	rcx, 0
		mov	rdx, 0
		mov	cl, BYTE [rdi + rbx]	; s1[rbx] in cl
		mov	dl, BYTE [rsi + rbx]	; s2[rbx] in dl
		cmp	cl, dl
		jne	exit			; if not equal
		cmp	cl, 0
		je	exit			; if end of s1
		cmp	dl, 0
		je	exit			; if end of s2
		inc	rbx
		jmp	compare

exit:
		sub	rcx, rdx
		mov	rax, 0
		mov	rax, rcx		; fill rax with (cl - dl)
		cmp	rax, 0
		jl	exit_less
		jg	exit_greater
		pop	rbx
		ret

exit_less:
		mov	rax, -1
		pop	rbx
		ret

exit_greater:
		mov	rax, 1
		pop	rbx
		ret

exit_err:
		mov	rax, 0
		pop	rbx
		ret
