.model small
.stack 100h 

.data
    x dd 12345678h
    y dd 9ABCDEF0h
    res dd ?
    carry dw 0000h

.code
    main proc
        mov ax, @data
        mov ds, ax
        mov ax, word ptr x
        add ax, word ptr y
        mov word ptr res, ax
        mov ax, word ptr x+2
        adc ax, word ptr y+2
        mov word ptr res+2, ax
        jnc no_carry       
        mov carry, 0001h
        
    no_carry:
        mov ah, 4ch
        int 21h
    main endp
    end main
        
        