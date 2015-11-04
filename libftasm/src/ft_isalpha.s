section .text
	global _ft_isalpha

upper:
	cmp rdi, 65		; A
	jl false
	cmp rdi, 90		; Z
	jg lower
	ret

lower:
	cmp rdi, 97		; a
	jl false
	cmp rdi, 122	; z
	jg false
	ret

_ft_isalpha:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov rax, 1		; true by default
	call upper
	call done

false:
	mov rax, 0
	call done

done:
	leave
	ret
