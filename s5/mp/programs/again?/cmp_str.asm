.model small
.stack 100h

.data
    s1 db "hello", 00h 0
    s2 db "hello", 00h 0
    eq_str db "equal$", 0
    neq_str db "not equal$", 0
    i dw ?

.code 
    main proc
        mov ax, @data
        mov ds, ax
        mov si, offset s1
        mov di, offset s2
        mov ax, 0000h
        mov i, ax
        while_bnend:
            jmp check_bnend
            loop_bnend:
                mov bx, i
                mov al, [si + bx]
                mov dl, [di + bx]
                cmp al, dl
                jnz not_equal
                mov ax, i 
                inc ax
                mov i, ax
                jmp while_bnend

        not_equal:
            mov ah, 09h
            mov dx, offset neq_str
            int 21h
            mov ah, 4ch
            int 21h

        equal:
            mov ah, 09h
            mov dx, offset eq_str
            int 21h
            mov ah, 4ch
            int 21h

        check_bnend:
            mov bx, i
            mov al, [si + bx]
            mov dl, [di + bx]
            or al, dl
            jz equal
            xor al, dl
            jnz not_equal
            jmp loop_bnend
