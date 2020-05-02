; ----------------------------------------------------------------------------------------
; To assemble and run:
;	nasm -felf64 ft_write.s && gcc main_write.c ft_write.o && ./a.out
; Prototype:
;	ssize_t write(int fd, const void *buf, size_t count)
; ----------------------------------------------------------------------------------------

	global		ft_write
	extern		___error

	section		.text
ft_write:
		mov	rax, 1
		syscall
					; now, rax = -14
					; shouldn't it be -1 ? because ret value of write
					; or, it means that ret value of write au niveau
					; de l'assembleur is errno * -1
					; if rax < 0
					; set errno at rax * -1
					; set rax at -1
					; exit
					; 
	
exit:
		ret
