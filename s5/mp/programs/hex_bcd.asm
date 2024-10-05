.model small
.stack 100h 

.data
    str1 db 'hello$', 0
    str2 db 'hello$', 0
    result db ?

.code
    main proc
        mov ax, @data
        mov ds, ax
        
        mov si, offset str1
        mov di, offset str2
        
    repeat:
        mov al, [si]
        cmpsb
        jnz not_equal
        test al, al
        jnz repeat
        
    equal:
        mov result, 00h
        jmp terminate
        
    not_equal:
        mov result, 01h
       
    terminate:
        mov ah, 4ch
        int 21h 
        
    main endp
    end main
        
        
        
        