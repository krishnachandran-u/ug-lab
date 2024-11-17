.model small
.stack 100h

.data 
    bcd db 98h
    hex dw ?
    bm db 0fh

.code
    main proc
        mov ax, @data
        mov ds, ax
        mov ax, 0000h
        mov al, bcd
        and al, bm
        mov hex, ax
        mov al, bcd
        shr al, 4
        and al, bm
        mov bl, 0Ah
        mul bl
        mov bx, hex
        add ax, bx
        mov hex, ax
    main endp
    end main
        
          


