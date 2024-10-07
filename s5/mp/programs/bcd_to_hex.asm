.model small
.stack 100h

.data
    bcd db 51h
    hex dw 0000h
    
.code 
    main proc
        mov ax, @data
        mov ds, ax
        
        mov ax, 0000h
        
        mov al, bcd
        and al, 0fh
        
        mov hex, ax
        
        mov al, bcd
        ror al, 4
        and al, 0fh
        
        mov bl, 0ah
        mul bl
        
        mov bx, hex
        add bx, ax
        mov hex, bx
        
        mov ah, 4ch
        int 21h
        
    main endp
    end main      