section .text
	global _ft_bzero

iter:
	cmp rsi, rcx			; size == counter
	je end
	mov byte [rdi + rcx], 0	; *(str + counter) = 0
	inc rcx					; counter++
	jmp iter

_ft_bzero:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov rcx, 0				; init counter
	mov rdx, 0				; init value
	call iter

end:
	leave
	ret
