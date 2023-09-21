section .data
    hello db 'Hello, Holberton',10,0

section .text
    global main
    extern printf

main:
    ; Prepare the arguments for printf
    mov rdi, hello     ; The format, null-terminated string
    xor rax, rax       ; Because printf is a variadic function,
                       ; RAX should hold the number of vector registers used.
                        ; In this case it's 0.

    ; Call printf
    call printf

    ; Return 0
    mov eax, 0x60      ; The syscall number for sys_exit
    xor edi, edi       ; Exit code 0
    syscall            ; Call the kernel
