section .text
	global _ft_tolower

_ft_tolower:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov rax, rdi
	cmp rdi, 65		; A
	jl done
	cmp rdi, 90		; Z
	jg done
	add rax, 32
	call done

done:
	leave
	ret
