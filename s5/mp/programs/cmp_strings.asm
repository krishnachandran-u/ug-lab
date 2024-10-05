.model small
.stack 100h 

.data
    str1 db 'hello', 0
    str2 db 'hello', 0
    result db ?

.code
    main proc
        mov ax, @data
        mov ds, ax
        
        mov si, offset str1
        mov di, offset str2
        
    repeat:
        mov al, [si]
        mov bl, [di]
        cmp al, bl
        jne not_equal ;not equal if characters are not equal
        inc si
        inc di
        mov cl, al
        mov dl, bl
        and cl, cl
        and dl, dl
        xor cl, dl
        jnz not_equal ;not equal if one string ended but the other string didn't
        mov cl, al
        mov dl, bl
        and cl, cl
        and dl, dl
        and cl, dl
        jnz repeat ;if both strings ended then they are equal. otherwise repeat
        
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
        
        
        
        