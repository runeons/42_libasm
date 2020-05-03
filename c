     1                                  ; ----------------------------------------------------------------------------------------
     2                                  ; To assemble and run:
     3                                  ;	nasm -felf64 ft_write.s && gcc main_write.c ft_write.o && ./a.out
     4                                  ; Prototype:
     5                                  ;	ssize_t write(int fd, const void *buf, size_t count)
     6                                  ; ----------------------------------------------------------------------------------------
     7                                  
     8                                  	global		ft_write
     9                                  	extern		___error
    10                                  
    11                                  	section		.text
    12                                  ft_write:
    13 00000000 B801000000              		mov	rax, 1
    14 00000005 0F05                    		syscall
    15                                  					; now, rax = -14
    16                                  					; shouldn't it be -1 ? because ret value of write
    17                                  					; or, it means that ret value of write au niveau
    18                                  					; de l'assembleur is errno * -1
    19 00000007 4883F800                		cmp	rax, 0		; if rax < 0
    20 0000000B 7C02                    		jl	error
    21 0000000D EB16                    		jmp	exit
    22                                  
    23                                  error:
    24 0000000F 4889C7                  		mov	rdi, rax
    25 00000012 48F7DF                  		neg	rdi		; rdi holds errno (rax * -1)
    26 00000015 48C7C0FFFFFFFF          		mov	rax, -1		; set rax at -1
    27 0000001C 55                      		push	rbp
    28 0000001D E8(00000000)            		call	___error
    29 00000022 5D                      		pop	rbp
    30                                  		
    31                                  		
    32                                  					; put rdi in ERRNO
    33 00000023 EB00                    		jmp	exit		; exit
    34                                  	
    35                                  exit:
    36 00000025 C3                      		ret
