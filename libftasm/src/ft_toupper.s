section .text
	global _ft_toupper

_ft_toupper:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov rax, rdi
	cmp rdi, 97		; a
	jl done
	cmp rdi, 122	; z
	jg done
	sub rax, 32
	call done

done:
	leave
	ret
