.MODEL SMALL
.STACK 100H

.DATA
MSG DB 'H'
BYTE DB 'Rajib$'

.CODE

MAIN PROC
    
    MOV AX, @DATA
    MOV DS,AX
    
    MOV DL, MSG
    MOV AH, 2
    INT 21H    
    
    MOV AH, 1
    INT 21H
    
    MOV DL, AL
    MOV AH, 2
    INT 21H
                
    MOV AH, 9            
    LEA DX, BYTE
    INT 21H 
     
    MOV AH, 4CH
    INT 21H
    MAIN ENDP


END MAIN