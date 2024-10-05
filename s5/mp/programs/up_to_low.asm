.model small
.stack 100h 

.data
    str db 'HELLOWORLD', 0
    result db ?

.code
    main proc
        mov ax, @data
        mov ds, ax
        
        mov si, offset str
              
    repeat:
        mov ah, 0eh
        mov al, [si]
        and al, al
        jz terminate
        add al, 20h
        int 10h
        inc si
        jmp repeat
         
    terminate:
        mov ah, 4ch
        int 21h
        
    
        
        
        
        
        
        
        