.model small
.stack 100h

.data
    arr dw 7a8bh, 3c4dh, 09c0dh, 1a2bh, 5e6fh
    len dw 0Ah
    sm dw 0ffffh 
    scsm dw 0ffffh
    cnt dw 0000h
    i dw ?

.code
    main proc
        mov ax, @data
        mov ds, ax
        mov si, offset arr
        mov ax, 0000h
        mov i, ax
        while_fsm:
            jmp check_fsm
            loop_fsm:
                mov bx, i
                mov ax, [si + bx]
                cmp ax, sm
                jb upd_sm
                aft_upd_sm:
                mov ax, i
                add ax, 0002h
                mov i, ax
                jmp while_fsm
        out_while_fsm:
        mov ax, 0000h
        mov i, ax
        while_cnt:
            jmp check_cnt
            loop_cnt:
                mov bx, i
                mov ax, [si + bx]
                cmp ax, sm
                jz upd_cnt
                aft_upd_cnt:
                mov ax, i
                add ax, 0002h
                mov i, ax
                jmp while_cnt
        out_while_cnt:             
        mov ax, 0001
        cmp ax, cnt
        jnz end_sm
        mov ax, 0000h
        mov i, ax
        while_fscsm:
            jmp check_fscsm
            loop_fscsm:
                mov bx, i
                mov ax, [si + bx]
                cmp ax, scsm
                jae continue_fscsm
                cmp sm, ax
                jae continue_fscsm
                mov bx, i
                mov ax, [si + bx]
                mov scsm, ax
            continue_fscsm:
                mov ax, i
                add ax, 0002h
                mov i, ax
                jmp while_fscsm
        out_while_fscsm:
        mov ah, 4ch
        int 21h

        check_fsm:
            mov ax, i
            cmp ax, len
            jb loop_fsm
            jmp out_while_fsm

        upd_sm:
            mov bx, i
            mov ax, [si + bx]
            mov sm, ax
            jmp aft_upd_sm

        check_cnt:
            mov ax, i
            cmp ax, len
            jb loop_cnt
            jmp out_while_cnt

        upd_cnt:
            mov ax, cnt
            add ax, 0001h
            mov cnt, ax
            jmp aft_upd_cnt

        end_sm:
            mov ax, sm
            mov scsm, ax
            mov ah, 4ch
            int 21h

        check_fscsm:
            mov ax, i
            cmp ax, len
            jb loop_fscsm
            jmp out_while_fscsm

