.model small
.stack 100h 

.data
    str db "helloworld", 0
    cnt dw ?
    
.code
    main proc
        mov ax, @data
        mov ds, ax
    
        mov si, offset str
        mov cx, 0
            
    repeat:
        mov bl, [si]
        and bl, bl
        jz terminate
        cmp bl, 'a'
        jz increment
        cmp bl, 'e'
        jz increment
        cmp bl, 'i'
        jz increment
        cmp bl, 'o'
        jz increment
        cmp bl, 'u'
        jz increment
    skip:        
        inc si
        jmp repeat
    
    increment:
        inc cx
        jmp skip
    
    terminate:
        mov cnt, cx
        mov ah, 4ch
        int 21h
    
    main endp
    end main