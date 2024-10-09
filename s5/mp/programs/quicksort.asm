.model large
.stack 100h

.data
    a dw 51E2h, 10A3h, 3034h, 2022h, 8888h
    n dw 000Ah
    pivot dw ?
    head dw ?
    tail dw ?
    i dw ?
    j dw ? 
    cnt dw ?
    ret_addr dw ?

.code
    main proc
        mov ax, @data
        mov ds, ax
        mov si, offset a
        
        mov ax, 0000h
        push ax
        
        mov ax, n
        push ax
        
        call quicksort
        
        mov ah, 4ch
        int 21h
    
    main endp
    
    quicksort proc
        pop ax
        mov ret_addr, ax
        pop dx ;dx -> end
        mov tail, dx
        pop bx ;bx -> begin
        mov head, bx
        
        jmp check_base_case: ;head >= tail - 1
        
        base_case:
            jmp return
                    
        recursive_case:
            mov bx, head
            mov ax, [si + bx]
            mov pivot, ax  
            
            mov ax, 0000h
            mov cnt, ax
            
            mov ax, 0000h
            mov i, ax
            
            while_i_lt_tail:
                jmp check_i_lt_tail: ;!NOT DEFINED
                
                loop_i_lt_tail:
                    mov ax, pivot
                    mov bx, head
                    add bx, i
                    mov cx, [si + bx]
                    cmp ax, cx
                    jae after_increment_cnt:
                    
                    mov ax, cnt
                    add ax, 0002h
                    mov cnt, ax
                                                                                     
                    after_increment_cnt:
                    mov ax, i
                    add ax, 0002h
                    mov i, ax
                    jmp while_i_lt_tail
                    
            out_while_i_lt_tail:
            
            swap:     
            mov ax, pivot
            mov bx, head
            add bx, cnt
            mov cx, [si + bx]
            
            mov bx, ax
            mov ax, cx
            mov cx, ax
            
            mov bx, head
            mov [si + bx], ax
            
            mov bx, head
            add bx, cnt
            mov [si + bx], cx
            
            sort:
            mov bx, head
            mov i, bx
            mov dx, tail
            sub dx, 0002h
            mov j, dx 
            
            while_i_lt_cnt_and_cnt_lt_j:
                jmp check_i_lt_cnt_and_cnt_lt_j
                                                                       
                loop_i_lt_cnt_and_cnt_lt_j:
                
                    while_i_lt_cnt_and_ai_lt_pivot:
                        jmp check_i_lt_cnt_and_ai_lt_pivot
                    
                        loop_i_lt_cnt_and_ai_lt_pivot:
                            mov ax, i
                            add ax, 0002h
                            mov i, ax
                            jmp while_i_lt_cnt_and_ai_lt_pivot
                            
                    out_while_i_lt_cnt_and_ai_lt_pivot:                            
                    
                    while_cnt_lt_j_and_aj_ge_pivot:
                        jmp check_cnt_lt_j_and_aj_ge_pivot
                        
                        loop_cnt_lt_j_and_aj_ge_pivot:
                            mov ax, j
                            sub ax, 0002h
                            mov j, ax
                            jmp while_cnt_lt_j_and_aj_ge_pivot
                    
                    out_while_cnt_lt_j_and_aj_ge_pivot:
                            
                    if_i_lt_cnt_and_cnt_lt_j:
                        jmp check_if_i_lt_cnt_and_cnt_lt_j
                        
                        in_if_i_lt_cnt_and_cnt_lt_j:
                            mov bx, head
                            add bx, i
                            mov ax, [si + bx]
                            
                            mov bx, head
                            add bx, j
                            mov cx, [si + bx]
                            
                            mov bx, ax
                            mov ax, cx
                            mov cx, bx
                            
                            mov bx, head
                            add bx, i
                            mov [si + bx], ax
                            
                            mov bx, head
                            add bx, j
                            mov [si + bx], cx 
                            
                    out_if_i_lt_cnt_and_cnt_lt_j:                        
                
                jmp while_i_lt_cnt_and_cnt_lt_j
                                
            out_while_i_lt_cnt_and_cnt_lt_j:
                    
            push_parameters:
            mov bx, head
            push bx
            add bx, cnt
            push bx
            add bx, 0002h
            push bx
            mov bx, tail
            push bx
            
            call quicksort
            call quicksort    
            
        return:
            mov ax, ret_addr
            push ax
            ret
            
        check_base_case:
            mov bx, head
            mov dx, tail
            sub dx, 0002h
            cmp bx, dx
            jae return   
            jmp recursive_case:
        
        check_i_lt_tail:
            mov bx, head
            add bx, i
            mov dx, tail
            cmp bx, dx
            jae loop_i_lt_tail
            jmp out_while_i_lt_tail
            
        check_i_lt_cnt_and_cnt_lt_j:
            check_i_lt_cnt_1:
                mov ax, i
                cmp ax, cnt
                jae out_while_i_lt_cnt_and_cnt_lt_j
                
            check_cnt_lt_j_1:
                mov ax, cnt
                cmp ax, j 
                jae out_while_i_lt_cnt_and_cnt_lt_j
                
            jmp loop_i_lt_cnt_and_cnt_lt_j  
         
        check_i_lt_cnt_and_ai_lt_pivot:
            check_i_lt_cnt_2:
                mov ax, i
                cmp ax, cnt
                jae out_while_i_lt_cnt_and_ai_lt_pivot
                
            check_ai_lt_pivot:
                mov bx, head
                add bx, i
                mov ax, [si + bx]
                cmp ax, pivot
                jae out_while_i_lt_cnt_and_ai_lt_pivot
                
            jmp loop_i_lt_cnt_and_ai_lt_pivot
            
        check_cnt_lt_j_and_aj_ge_pivot:
            check_cnt_lt_j:
                mov ax, cnt
                cmp ax, j
                jae out_while_cnt_lt_j_and_aj_ge_pivot
                
            check_aj_ge_pivot:
                mov bx, head
                add bx, j
                mov ax, [si + bx]
                cmp ax, pivot
                jb out_while_cnt_lt_j_and_aj_ge_pivot
                
            jmp loop_cnt_lt_j_and_aj_ge_pivot
            
        check_if_i_lt_cnt_and_cnt_lt_j:
            check_i_lt_cnt_3:
                mov ax, i
                cmp ax, cnt
                jae out_if_i_lt_cnt_and_cnt_lt_j
                
            check_cnt_lt_j_2:
                mov ax, cnt
                cmp ax, j
                jae out_if_i_lt_cnt_and_cnt_lt_j
                
            jmp in_if_i_lt_cnt_and_cnt_lt_j
                                             
    quicksort endp
    
    end main
        