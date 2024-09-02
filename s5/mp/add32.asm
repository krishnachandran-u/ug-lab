.model small
.stack 100h

.data
num1 dd 012345678h
num2 dd 09ABCDEF0h
carry db 0 
result dd ?

.code
main proc
    mov ax, @data
    mov ds, ax
     
add_lower_half:        
    mov ax, word ptr num1
    add ax, word ptr num2
    mov word ptr result, ax
    mov ax, word ptr num1+2
    adc ax, word ptr num2+2
    mov word ptr result+2, ax
    jc handle_carry 
    jmp done
    
handle_carry:
    mov carry, 1
 
done:
    mov result, ax
    mov ah, 4ch
    int 21h

main endp
end main
    
    


    
    