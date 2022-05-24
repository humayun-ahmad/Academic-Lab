.MODEL small

.stack 100h

.data
msg db 'ThiS iS ThE initIAL Message$'
max db '0'

.code

main proc
    mov ax, @data
    mov ds, ax
    
    
    mov di, 0
    mov dl, '0'
    
    
    iterate:
        cmp msg[di], '$'
        je exit
        
        cmp msg[di], 'a'
        jl last
        
        cmp msg[di], 'z'
        jg last
        
        inc dl
        cmp max,dl
        jl another
        jmp last 
        
        last:
            inc di
            mov dl, '0'
            jmp iterate
            
        another:
            mov max, dl
            inc di
            jmp iterate
        
    exit:
    
    mov dl, max
    mov ah, 02
    int 21h
    
    mov ah, 4ch
    int 21h
    main endp

end main
    