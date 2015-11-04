%define MACH_SYSCALL(nb)	0x2000000 | nb
%define STDOUT				1
%define WRITE				4

section .text
	global _ft_puts

write:
	mov rdi, STDOUT					; configure stream
	mov rsi, rcx
	mov rdx, 1						; configure length
	mov rax, MACH_SYSCALL(WRITE)	; configure syscall
	syscall
	ret

loop:
	cmp rcx, 0
	je break
	call write
	inc rcx
	jmp loop

_ft_puts:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov rcx, rdi					; save string pointer
	mov rdi, STDOUT					; configure stream
	mov rdx, 1						; configure length
	mov rax, MACH_SYSCALL(WRITE)	; configure syscall
	call loop
	leave
	ret

break:
	ret
