.MODEL SMALL
.STACK 200H
.DATA

NUM1 DB 4
NUM2 DB 3
VAL  DB ?
MSG1 DB "The sum is : $"

.CODE
MAIN PROC
     mov bl,2
     mov cl,3
     add bl,cl
     add bl,48
     mov dl,bl
     mov ah,2
     int 21h
     
     mov ah, 4ch
     int 21h
      
MAIN ENDP
END MAIN