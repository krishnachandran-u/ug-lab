.model small
.stack 100h 

.data
    str db "helloworld"
    n_str dw 0Ah
    substr db "lloww"
    n_substr dw 05h
    found dw ?
    i dw ?
    j dw ?
          
.code
    main proc
        mov ax, @data
        mov ds, ax
        mov si, offset str
        mov di, offset substr
        mov ax, 0000h
        mov i, ax
        while_str:
            jmp check_str
            loop_str:
                mov ax, i
                mov j, ax
                mov ax, 0001h
                mov found, ax
                while_substr:
                    jmp check_substr
                    loop_substr:
                        mov ax, j
                        cmp ax, n_str
                        jae not_found 
                        mov bx, j
                        mov al, [si + bx]
                        mov bx, j
                        sub bx, i
                        mov dl, [di + bx]
                        cmp al, dl
                        jne not_found
                        mov ax,j
                        inc ax
                        mov j, ax
                        jmp while_substr
                out_while_substr:
                mov ax, found
                test ax, ax
                jnz substr_found 
                mov ax, i
                inc ax
                mov i, ax
                jmp while_str
        out_while_str:
        mov ah, 4ch
        int 21h

        check_str:
            mov ax, i
            cmp ax, n_str
            jb loop_str
            jmp out_while_str

        check_substr:
            mov dx, i
            add dx, n_substr
            cmp j, dx
            jb loop_substr
            jmp out_while_substr

        not_found:
            mov ax, 0000h
            mov found, ax
            jmp out_while_substr 

        substr_found:
            mov ah, 4ch
            int 21h
