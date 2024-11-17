.model small
.stack 100h

.data
    hex db 0efh
    bcd dw 0000h
    fac db 01h

.code
    main proc
        mov ax, @data
        mov ds, ax
        while_hex_gt_0:
            jmp check_hex_gt_0:

            loop_hex_gt_0:
                mov ax, 0000h
                mov al, hex
                mov bl, 0ah
                div bl
                mov hex, al
                mov al, ah
                mov ah, 00h
                mov bl, fac 
                mul bl
                mov bx, bcd
                add ax, bcd
                mov bcd, ax
                mov ax, 0000h
                mov al, fac
                mov bl, 10h
                mul bl
                mov fac, al
                jmp while_hex_gt_0
        out_hex_gt_0:
            mov ah, 4ch
            int 21h

        check_hex_gt_0:
            mov al, hex
            and al, al
            jnz loop_hex_gt_0
            jmp out_hex_gt_0
