.model small
.stack 100h 

.data
    x dd 12345678h
    y dw 9ABCh
    rem dw ?
    quo dw ?

.code
    main proc
        mov ax, @data
        mov ds, ax
        mov ax, word ptr x
        mov dx, word ptr x+2
        mov cx, y
        div cx
        mov rem, dx
        mov quo, ax
        mov ah, 4ch
        int 21h
    main endp
    end main
        
        
        
        
        