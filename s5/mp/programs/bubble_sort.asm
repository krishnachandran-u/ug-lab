.model small
.stack 100h 

.data
    arr dw 51E2h, 10A3h, 3034h, 2022h, 8888h
    n dw 000Ah
    i dw 0000h
    j dw 0000h
    temp db ?
.code 
    main proc
        mov ax, @data
        mov ds, ax
        mov si, offset arr
        
    while:
        mov ax, 0000h
        mov j, ax
        jmp check_i
        
    loop_i:
        jmp check_j
        
    loop_j:
        jmp is_greater
        
    after_swap:    
        mov ax, j
        add ax, 0002h
        mov j, ax
        
        jmp loop_i
        
    out_j:
        mov ax, i
        add ax, 0002h
        mov i, ax
        
        jmp while
        
    out_i:
        mov ah, 4ch
        int 21h
    
    check_i:
        mov ax, n
        sub ax, 0002h
        mov bx, i
        cmp bx, ax
        jae out_i
        jmp loop_i
    
    check_j:
        mov ax, n
        sub ax, 0002h
        mov bx, i
        sub ax, bx
        mov cx, j
        cmp cx, ax
        jae out_j
        jmp loop_j
        
    is_greater:
        mov bx, j
        mov cx, [si + bx]
        add bx, 0002h
        mov dx, [si + bx]
        cmp cx, dx
        ja swap
        jmp after_swap
        
    swap:
        mov bx, j
        mov cx, [si + bx]
        add bx, 0002h
        mov dx, [si + bx]
        
        mov bx, cx
        mov cx, dx
        mov dx, bx
        
        mov bx, j
        mov [si + bx], cx
        add bx, 0002h
        mov [si + bx], dx
        jmp after_swap

    main endp
    end main
        
        
        
        
        