.model small
.stack 100h

.data
    arr dw 51E2h, 10A3h, 3034h, 2022h, 8888h
    n dw 000Ah
    i dw ?
    smallest dw 0FFFFh
    smallest_index dw 0FFFFh ?
    second_smallest dw 0FFFFh ?
    
.code 
    main proc
        mov ax, @data
        mov ds, ax
        
        mov si, offset arr
        
        mov ax, 0000h
        mov i, ax
        
    find_smallest_number:
        jmp check_i
        
    loop_i:
        jmp is_smaller
        
    after_check:
        mov ax, i
        add ax, 0002h
        mov i, ax
        jmp find_smallest_number
        
    out_find_smallest_number:
        mov ax, 0000h
        mov i, ax
        
    find_second_smallest_number:
        jmp check_i_2
    
    loop_i_2:
        jmp is_greater_than_or_equal_to_smallest
        
    after_check_second_smallest:
        mov ax, i
        add ax, 0002h
        mov i, ax
        jmp find_second_smallest_number
        
    out_find_second_smallest_number:
        mov ah, 4ch
        int 21h
        
    check_i:
        mov ax, i
        mov bx, n
        cmp ax, bx
        jae out_find_smallest_number
        jmp loop_i
    
    is_smaller:
        mov bx, i
        mov ax, [si + bx]
        mov cx, smallest
        cmp ax, cx
        jb set_smallest
        jmp after_check
    
    set_smallest:
        mov bx, i
        mov ax, [si + bx]
        mov smallest, ax 
        mov smallest_index, bx
        jmp after_check
        
    check_i_2:
        mov ax, i
        mov bx, n
        cmp ax, bx
        jae out_find_second_smallest_number
        jmp loop_i_2
        
    is_greater_than_or_equal_to_smallest:
        mov ax, i
        mov bx, smallest_index
        cmp ax, bx
        je after_check_second_smallest
    
        mov ax, smallest
        mov bx, i
        mov cx, [si + bx]
        cmp cx, ax
        jae is_smaller_than_current_second_smallest
        jmp after_check_second_smallest
        
    is_smaller_than_current_second_smallest:
        mov ax, second_smallest
        mov bx, i
        mov cx, [si + bx]
        cmp cx, ax
        jb set_second_smallest
        jmp after_check_second_smallest
        
    set_second_smallest:
        mov bx, i
        mov ax, [si + bx]
        mov second_smallest, ax
        jmp after_check_second_smallest        
        
    main endp
    end main