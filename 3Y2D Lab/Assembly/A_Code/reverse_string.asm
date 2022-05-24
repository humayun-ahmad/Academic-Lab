.model small

.stack 100h

.data
var1 db 50 dup(?)
var2 db ?
msg db 'enter the string: ','$'
msg2 db 10,13,'reversed form: ','$'

.code

main proc
    mov ax,@data
    mov ds,ax 
    
    mov ah,9
    lea dx,msg
    int 21h
    
    mov si,offset var1
    mov cx, 0 
    
    getstring:
        mov ah, 1
        int 21h
        
        cmp al,13
        je end_getstring
        
        mov var1[si], al
        inc si
        inc cx
        jmp getstring
        
        
    end_getstring:
    
    mov ah,9
    lea dx,msg2
    int 21h
    
    
    printstring:
        dec si 
        mov ah,2
        mov dl, var1[si]
        int 21h
    loop printstring
    
    mov ah, 4ch
    int 21h 
    
    main endp
end main

    
