.model small
.stack 100h 

.data
    x dw 0ffffh
    y dw 0ffffh
    res dw ?
    carry dw 0000h

.code
    main proc
        mov ax, @data
        mov ds, ax
        mov ax, x
        sub ax, y 
        mov res, ax
        jnc no_carry
        mov carry, 0001h
        
   no_carry:
        mov ah, 4ch
        int 21h
       
    main endp
    end main
