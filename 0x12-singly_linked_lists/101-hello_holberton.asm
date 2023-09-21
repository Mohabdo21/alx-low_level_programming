section .data
	msg: db "Hello, Holberton", 10, 0

section .text

global main
extern printf

main:

	push rbp
	mov rbp, rsp

	mov edi, msg
	mov esi, 0

	call printf

	pop rbp

	ret
