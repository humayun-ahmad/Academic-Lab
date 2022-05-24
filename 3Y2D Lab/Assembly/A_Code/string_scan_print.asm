.MODEL SMALL

.STACK 100H

.DATA
MSG DB 50 DUP (?)

.CODE

MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    MOV DI, 0
    
    MOV AH, 1
    SCAN:
        INT 21H
        CMP AL, 0DH
        JE EXIT
        
        MOV DS[DI], AL
        INC DI
        JMP SCAN
        
    EXIT:
        MOV DS[DI], '$'
        
        MOV AH, 2
        MOV DL, 0DH ; line feed after press enter button() 
        INT 21H
                
        MOV DL, 0AH
        INT 21H               
                
        MOV AH, 9
        LEA DX, MSG
        INT 21H
        
        MOV AH, 4CH
        INT 21H
    
    MAIN ENDP
END MAIN