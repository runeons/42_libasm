; ----------------------------------------------------------------------------------------
; To assemble and run:
;	 nasm -felf64 ft_strlen.s && nasm -felf64 ft_strdup.s && clang main_strdup.c ft_strlen.o ft_strdup.o && ./a.out
;
; ----------------------------------------------------------------------------------------

	global	ft_strdup
	extern	ft_strlen
;	extern	ft_strcpy
	extern	malloc

          section	.text
ft_strdup:

store_len:
		push	rbp
		call	ft_strlen
		pop	rbp
		mov	rbx, rax	; rbx holds len
		inc	rbx		; rbx holds len + 1

malloc_cpy:
		push	rdi
		mov	rdi, rbx	; rdi holds len + 1
		call	malloc
		cmp	rax, 0		; protect malloc
		je	exit
		pop	rdi		; str(src) now back in rdi
		mov	r8, 0		; counter

replace:
		cmp	r8, rbx
		je	exit
		mov	cl, BYTE [rdi + r8]	; store src[r8]
		mov	BYTE [rax + r8], cl	; replace dst[r8]
		inc	r8
		jmp	replace

;strcpy:
;		mov	rsi, rdi	; put str in rsi (src)
;		mov	rdi, rax	; put malloc ret str in rdi (dest)
;		call	ft_strcpy	; supposed to copy src dans dest and return dest
;
exit:
		ret
