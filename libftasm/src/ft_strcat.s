section .text
	global _ft_strcat

get_start:
	cmp byte [rdi], 0
	je break
	inc rdi
	jmp get_start

copy:
	cmp byte [rsi], 0
	je break
	mov rdx, [rsi]		; rdx = s2[i]
	inc rsi
	mov [rdi], rdx		; s1[i] = rdx
	inc rdi
	jmp copy

_ft_strcat:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov rax, rdi		; save s1 for return
	call get_start
	call copy
	leave
	ret

break:
	ret
