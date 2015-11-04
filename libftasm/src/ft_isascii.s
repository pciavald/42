section .text
	global _ft_isascii

_ft_isascii:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov rax, 1
	cmp rdi, 0		; \0
	jl false
	cmp rdi, 127	; del
	jg false
	call done

false:
	mov rax, 0
	call done

done:
	leave
	ret
