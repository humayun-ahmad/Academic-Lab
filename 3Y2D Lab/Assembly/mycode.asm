.MODEL SMALL

.STACK 100H

MAIN PROC
    
    MOV DL, '?'
    MOV AH, 02H
    INT 21H
    
    MOV AH, 01H
    INT 21H
    
    
    MOV BL,AL  
    
    
    
    MOV AH, 02H
    INT 21H
    
    MOV DL,0DH
    INT 21H
    
    MOV DL, BL
    INT 21H
    
    
    
    
    
    MOV AH, 4CH
    INT 21H
    
    MAIN ENDP
END MAIN
    