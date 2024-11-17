.model small
.stack 100h

.data
    arr dw 7a8bh, 3c4dh, 09c0dh, 1a2bh, 5e6fh
    len dw 0Ah
    i dw ?
    j dw ?
    
.code
    mov ax, @data
    mov ds, ax
    mov ax, 0000h
    mov i, ax
    while_i:
        jmp check_i
        loop_i:
            mov ax, 0000h
            mov j, ax
            while_j:
                jmp check_j
                loop_j:
                    mov bx, j
                    mov ax, [si + bx]
                    add bx, 0002h 
                    mov dx, [si + bx]
                    cmp ax, dx
                    ja swap
                    aft_swap:
                    mov ax, j
                    add ax, 0002h
                    mov j, ax
                    jmp while_j
            out_while_j:
            mov ax, i
            add ax, 0002h
            mov i, ax
            jmp while_i
    out_while_i:
    mov ah, 4ch
    int 21h

    swap:
        mov bx, j
        mov ax, [si + bx]
        add bx, 0002h
        mov dx, [si + bx]
        mov cx, ax
        mov ax, dx
        mov dx, cx    
        mov bx, j
        mov [si + bx], ax
        add bx, 0002h
        mov [si + bx], dx
        jmp aft_swap

    check_i:
        mov ax, i
        add ax, 0002h
        cmp ax, len
        jb loop_i
        jmp out_while_i

    check_j:
        mov ax, j
        add ax, i
        add ax, 0002h
        cmp ax, len
        jb loop_j
        jmp out_while_j
