; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_write.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2019/12/07 00:00:01 by lmartin           #+#    #+#              ;
;    Updated: 2019/12/07 15:38:30 by lmartin          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section.text:
	global ft_write

ft_write:
	push r8
	push r9
	cmp rsi, byte 0x0 ; NULL pointer
	jz error
	mov r8, rsi ; save parameters before fstat
	mov r9, rdx
	mov rsi, 0x0 ; fstat getting buf as second parameter
	mov rax, 5 ; 0x2000000 (MacOS ?)+ 0xBD (fstat syscall)
	syscall ; 64 bits version of int 0x80
	cmp rax, -9 ; if fstat return 9 it's errno 9 so badfd
	jz error
	mov rsi, r8 ; reuse saved parameters
	mov rdx, r9
	mov rax, 1 ; 0x2000000 (MacOS ?)+ 0x4 (write syscall)
	syscall ; 64 bits version of int 0x80
	pop r8
	pop r9
	ret

error:
	mov rax, -1 ; return -1 because error
	pop r8
	pop r9
	ret
