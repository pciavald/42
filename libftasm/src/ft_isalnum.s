section .text
	global _ft_isalnum

digit:
	cmp rdi, 48		; 0
	jl false
	cmp rdi, 57		; 9
	jg upper
	ret

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

_ft_isalnum:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov rax, 1		; true by default
	call digit
	call done

false:
	mov rax, 0
	call done

done:
	leave
	ret
