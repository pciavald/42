section .text
	global _ft_isprint

_ft_isprint:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov rax, 1
	cmp rdi, 32		; sp
	jl false
	cmp rdi, 126	; ~
	jg false
	call done

false:
	mov rax, 0
	call done

done:
	leave
	ret
