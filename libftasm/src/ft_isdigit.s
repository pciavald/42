section .text
	global _ft_isdigit

_ft_isdigit:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov rax, 1		; true by default
	cmp rdi, 48		; 0
	jl false
	cmp rdi, 57		; 9
	jg false
	call done

false:
	mov rax, 0
	call done

done:
	leave
	ret
