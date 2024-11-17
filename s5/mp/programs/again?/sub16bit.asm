.model small 
.stack 100h

.data
    n1 dw 1234h
    n2 dw 9ABCh
    res dw ?
    brw db ? 

.code
    main proc
        mov ax, @data
        mov ds, ax
        mov ax, n1
        sub ax, n2
        mov res, ax
        mov al, 00h
        mov brw, al
        jnc done
        mov al, 01h
        mov brw, al
    done:
        mov ah, 4ch
        int 21h
    main endp
    end main
    
