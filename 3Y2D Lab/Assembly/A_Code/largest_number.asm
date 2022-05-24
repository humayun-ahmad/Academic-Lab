.MODEL SMALL
.STACK 100H
.DATA
MSG1 DB 'ENTER THE ARRAY ELEMENTS: ','$'
MSG2 DB 10,13,'LARGEST ELEMENT: ','$'
MAX DB 0
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH,9
    LEA DX,MSG1
    INT 21H
    
  INPUT:
    
    MOV AH,1
    INT 21H
    
    CMP AL,13
    JZ DISPLAY
    
    CMP AL,'0'
    JL LAST
    
    CMP AL,'9'
    JG LAST
    
    CMP AL,MAX
    JGE MAXIMUM
    
    JMP LAST
    
  MAXIMUM:
    MOV MAX,AL
  
  LAST:
    JMP INPUT
    
  DISPLAY:
    MOV AH,9
    LEA DX,MSG2
    INT 21H
    
    MOV AH,2
    MOV DL,MAX
    INT 21H
    
    MAIN ENDP

END MAIN
    