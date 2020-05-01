; ----------------------------------------------------------------------------------------
; To assemble and run:
;	nasm -felf64 ft_strcpy.s && gcc main_strcpy.c ft_strcpy.o && ./a.out
; Prototype:
;	char	*strcpy(char *dest, const char *src);
; ----------------------------------------------------------------------------------------

	global		ft_strcpy
	extern		printf

          section	.text
ft_strcpy:

count:	
		mov	BYTE [rsi + 1], 122
		

exit:
		ret
