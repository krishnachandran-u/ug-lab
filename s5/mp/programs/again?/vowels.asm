.model small 
.stack 100h

.data
    str db "helloworld", 0
    len dw 000Ah
    cnt dw 0000h
    i dw ?

.code
    main proc
        mov ax, @data 
        mov ds, ax
        mov ax, 0000h
        mov i, ax
        while_str:
            jmp check_str
            loop_str:
                mov bx, i
                mov al, [si + bx]
                cmp al, 'a'  
                je incr
                cmp al, 'e'
                je incr
                cmp al, 'i' 
                je incr
                cmp al, 'o'
                je incr
                cmp al, 'u'
                je incr
                aft_incr:
                mov ax, i
                inc ax
                mov i, ax
                jmp while_str
        out_while_str:
        mov ah, 4ch
        int 21h

        check_str:
            mov ax, i
            cmp ax, len
            jb loop_str
            jmp out_while_str

        incr:
            mov ax, cnt
            inc ax
            mov cnt, ax
            jmp aft_incr



