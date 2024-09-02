.MODEL small         ; Define the memory model as small
.STACK 100h          ; Set the stack size to 256 bytes

.data
num1 dw 0ffffh
num2 dw 0ffffh
result dw 0
carry_flag db 0
        
.code 
main proc
    mov ax, @data
    mov ds, ax
    mov ax, num1
    add ax, num2
    mov result, ax
    jc carry_occurred:
    mov carry_flag, 0
    jmp done:
    
carry_occurred:
    mov carry_flag, 1

done:
    mov result, ax
    mov ah, 4ch
    int 21h

main endp
end main