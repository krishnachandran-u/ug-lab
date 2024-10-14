.model large
.stack 100h

.data
    tree dw 50 dup(0ffffh) ;array to store the binary search tree
    ins_arr dw 51E2h, 10A3h, 3034h, 2022h, 8888h, 43A1h, 09A2Bh, 1A2Bh, 0C3A1h, 0B2A1h ;elements to be inserted in the tree
    n dw 0014h ;number of elements in the tree -> 20 (each element is 2 bytes)
    i dw 0000h
    root dw 0000h ;root of the tree -> always 0000h but made a variable for better understanding
    ptr dw ? ;pointer to the current node in the bst
    inorder dw 50 dup(0ffffh) ;array to store the inorder traversal of the tree
    curr_node dw ? ;current node in the inorder traversal
    next_node dw ? ;next node in the inorder traversal

;note: you can't insert 0ffffh in the tree as it is the default value for a node -> it is used to check if a node is empty or not
;note: left child -> 2*ptr + 0002h && right_child -> 2*ptr + 0004h
;note: parent -> floor((ptr - 0002h)/0004h)*0002h
;note: inorder traversal is used to print the tree in sorted order

.code
    main proc
        mov ax, @data
        mov ds, ax
        mov si, offset ins_arr
        mov di, offset tree

        call build_tree

        mov ax, 0000h
        mov i, ax
        mov ax, root
        mov ptr, ax
        push ax
        mov si, offset tree
        mov di, offset inorder

        call inorder_traversal

        mov ah, 4ch
        int 21h

    main endp 

    build_tree proc
        while_i_lt_n:
            jmp check_i_lt_n:

            loop_i_lt_n:
                mov ax, root
                mov ptr, ax

                call insert_node

                mov ax, i 
                add ax, 0002h
                mov i, ax
                jmp while_i_lt_n

        out_loop_i_lt_n:
            ret
        
        check_i_lt_n:
            mov ax, i
            cmp ax, n
            jl loop_i_lt_n
            jmp out_loop_i_lt_n

    build_tree endp

    insert_node proc
        mov bx, ptr
        mov ax, [di + bx]
        cmp ax, 0ffffh
        je insert_and_return 
        jmp check_next_node

        insert_and_return:
            mov bx, i
            mov ax, [si + bx]
            mov bx, ptr
            mov [di + bx], ax
            ret

        check_next_node:
            mov bx, ptr
            mov ax, [di + bx]
            mov bx, i 
            cmp [si + bx], ax
            jl go_left
            jmp go_right

            go_left:
                mov bx, ptr
                add bx, bx
                add bx, 0002h
                mov ptr, bx
                call insert_node
                ret
                
            go_right:
                mov bx, ptr
                add bx, bx
                add bx, 0004h
                mov ptr, bx
                call insert_node
                ret

    insert_node endp

    inorder_traversal proc
        call rearrange_stack

        pop bx
        mov curr_node, bx

        mov bx, curr_node
        mov ax, [si + bx]
        cmp ax, 0ffffh
        je return_from_inorder_traversal

        mov bx, curr_node
        add bx, bx
        add bx, 0002h
        push bx
        call inorder_traversal

        call rearrange_stack

        pop bx
        mov curr_node, bx
        mov ax, [si + bx]
        mov bx, i
        mov [di + bx], ax

        mov bx, i
        add bx, 0002h
        mov i, bx

        mov bx, curr_node
        add bx, bx
        add bx, 0004h
        push bx
        call inorder_traversal
        ret 

        return_from_inorder_traversal:
            mov bx, curr_node
            sub bx, 0002h
            shr bx, 2 
            shl bx, 1
            push bx
            ret

    inorder_traversal endp

    rearrange_stack proc
        pop ax
        pop bx
        pop cx

        push bx
        push cx
        push ax
        ret

    rearrange_stack endp

    end main