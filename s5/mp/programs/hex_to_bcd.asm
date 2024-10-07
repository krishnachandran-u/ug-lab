.model small
.stack 100h

.data
    hex db 0ffh
    bcd dw 0000h
    shl_cnt dw 0000h
    shl_cnt_temp dw ?
    
.code
    main proc
        mov ax, @data
        mov ds, ax
        
        mov al, hex
        while_not_zero:
            jmp check_hex
            
            loop_hex:
                mov ax, 0000h
                mov al, hex
                mov bl, 0ah
                div bl
                
                mov cx, 0
                mov cl, ah
                        
                mov dx, 0000h
                mov shl_cnt_temp, dx
                  
                jmp shl_cx
                
                after_shl_cx:
                mov bx, bcd
                add bx, cx
                mov bcd, bx
                
                mov hex, al
                
                mov ax, shl_cnt
                inc ax
                mov shl_cnt, ax
                   
                jmp while_not_zero
        
        out_while_not_zero:        
            mov ah, 4ch
            int 21h
            
        check_hex:
            mov al, hex
            test al, al
            jnz loop_hex
            jmp out_while_not_zero
            
        shl_cx:
            jmp check_shl_cnt:
                
            loop_shl_cx:
                shl cx, 4
                mov dx, shl_cnt_temp
                inc dx
                mov shl_cnt_temp, dx
                
                jmp shl_cx:
                
        check_shl_cnt:
            mov dx, shl_cnt_temp
            cmp dx, shl_cnt
            jb loop_shl_cx
            jmp after_shl_cx              
            
    main endp
    end main