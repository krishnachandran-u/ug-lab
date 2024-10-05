.model small
.stack 100h

.data
    str db "helloworld", 0
    str_n dw 000Ah
    substr db "llowo", 0
    substr_n dw 0005h 
    found db "found$", 0
    not_found db "not_found$", 0
    i dw ?
    j dw ?
    
.code
    main proc
        mov ax, @data
        mov ds, ax
        
        mov ax, 0000h
        mov i, ax
        mov j, ax
        
        mov si, offset str
        mov di, offset substr
        
        while_str:
            mov ax, i
            mov j, ax
            jmp check_str     
            
            str_loop:
                while_substr:
                    jmp check_substr
                        
                    substr_loop:
                        mov bx, j
                        mov al, [si + bx]     
                        mov bx, j
                        sub bx, i
                        mov cl, [di + bx]
                        cmp al, cl
                    
                        pushf
                        
                        mov bx, j
                        inc bx
                        mov j, bx
                        
                        popf
                    
                        jne out_while_substr
                        jmp while_substr
                        
                out_while_substr:                     
                    mov bx, i
                    inc bx
                    mov i, bx
                    jmp while_str
            
            out_while_str:                
                mov ah, 09h
                mov dx, offset not_found
                int 21h
                jmp exit    
                                        
        check_str:
            mov ax, i
            mov bx, str_n
            cmp ax, bx
            jae out_while_str
            jmp str_loop
            
        check_substr:
            mov ax, j
            sub ax, i
            cmp ax, substr_n
            jae substr_found
            
            mov ax, j
            cmp ax, str_n
            jae out_while_substr
            jmp substr_loop
                        
        substr_found:
            mov ah, 09h
            mov dx, offset found
            int 21h
            
        exit:
            mov ah, 4ch
            int 21h
            
    main endp
    end main
    