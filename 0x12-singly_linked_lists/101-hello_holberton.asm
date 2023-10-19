section .data
hello_message db "Hello, Holberton", 10, 0

section .text
extern printf
global main

main:
    push rbp
    mov rbp, rsp

    mov rdi, hello_message
    call printf

    xor rax, rax
    leave
    ret
