.MODEL small

.stack 100h

.data
msg db 'ThiS iS ThE initIAL Message$'

.code

main proc
    mov ax, @data
    mov ds, ax
    
    mov di, 0
    mov ah, 02
    
    iterate:
        mov dl,msg[di]
        
        cmp dl,'$'
        je exit  
        
        cmp dl, 'A'
        jl last
        
        cmp dl, 'Z'
        jg lower_case
        
        add dl, 32
        jmp last
        
        lower_case:
            cmp dl, 'a'
            jl last
            
            cmp dl, 'z'
            jg last
            
            sub dl, 32
        
    last:
        int 21h
        inc di
        jmp iterate
    exit:
        mov ah, 4ch
        int 21h
        main endp

end main
    