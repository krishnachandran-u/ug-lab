.model small
.stack 100h

.data
    dvd dd 12345678h 
    dvs dw 9ABCh
    rem dw ?
    quo dw ?

.code
    main proc
        mov ax, @data
        mov ds, ax
        mov dx, word ptr dvd+2
        mov ax, word ptr dvd
        mov bx, dvs
        div bx
        mov rem, dx
        mov quo, ax
        mov ah, 4ch
        int 21h
    main endp
    end main
