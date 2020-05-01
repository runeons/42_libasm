; ----------------------------------------------------------------------------------------
; To assemble and run:
;	nasm -felf64 ft_strlen.s && gcc main_strlen.c ft_strlen.o && ./a.out
;
; ----------------------------------------------------------------------------------------

          global	ft_strlen

          section	.text
ft_strlen:	mov	rax, 0		; rax (because return value) holds the len

count:	cmp	BYTE [rdi + rax], 0	; cmp current char et \0
	je	exit			; if equal
	inc	rax			; i++
	jmp	count

exit:	ret
