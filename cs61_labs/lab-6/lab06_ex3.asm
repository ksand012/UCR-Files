;=================================================
; Name: <REMOVED>
; Email: <REMOVED>
; Lab: lab 6
; Lab section: <REMOVED>
; TA: <REMOVED>
;=================================================

.ORIG x3000
;instructions
  LD R5, SUBSTITUTE
  JSRR R5
  LD R5, JJJR
  JSRR R5
  
  HALT


;Local Data
SUBSTITUTE .FILL x3400
JJJR .FILL x3200


;=================================================
;Subroutine: SUB_OUTPUT_NUM_IN_16BIT_BINARY_3200
;Parameter (R2): The value to be converted
;Postcondition: This subroutine prints the integer value of R2 as a two's complement binary number
;Return value: none
;=================================================

.orig x3200
;Subroutine Instructions
ST R0, BACKUP_R0_3200
ST R2, BACKUP_R2_3200
ST R3, BACKUP_R3_3200
ST R4, BACKUP_R4_3200
ST R7, BACKUP_R7_3200


  LEA R0, BBBBB
  PUTS

  LD R4, IM_A_COUNTER
  LD R3, SAME_HERE
  LD R6, MASK

  WHILE_LOOP
    AND R5, R2, R6
    BRn NEG

    LD R0, cero
    OUT
    ADD R2, R2, R2
    ADD R4, R4, #-1
    ADD R3, R3, #-1
    BRz ENDLOL
      ADD R4, R4, #0
      BRp WHILE_LOOP
LD R0, SPACE
OUT
LD R4, IM_A_COUNTER
      BRnzp WHILE_LOOP

    NEG
      LD R0, uno
      OUT
      ADD R2, R2, R2
      ADD R4, R4, #-1
      ADD R3, R3, #-1
      BRz ENDLOL
ADD R4, R4, #0
BRp WHILE_LOOP
  LD R0, SPACE
  OUT
  LD R4, IM_A_COUNTER
BRnzp WHILE_LOOP 

    ENDLOL
      LEA R0, NEWLINE
      PUTS

LD R0, BACKUP_R0_3200
LD R2, BACKUP_R2_3200
LD R3, BACKUP_R3_3200
LD R4, BACKUP_R4_3200
LD R7, BACKUP_R7_3200

RET

;Subroutine Data
BACKUP_R0_3200 .BLKW #1
BACKUP_R2_3200 .BLKW #1
BACKUP_R3_3200 .BLKW #1
BACKUP_R4_3200 .BLKW #1
BACKUP_R7_3200 .BLKW #1
BBBBB .STRINGZ "b"
IM_A_COUNTER .FILL #4
SAME_HERE .FILL #16
MASK .FILL x8000
cero .FILL x30
uno .FILL x31
SPACE .FILL x20
NEWLINE .STRINGZ "\n"

;=================================================
;Subroutine: SUB_16BIT_BINARY_INPUT_3400
;Parameter: none
;Postcondition: This subroutine converts a binary number entered by the user into a decimal number
;Return value: The decimal number, in R2
;=================================================

.orig x3400
;Subroutine Instructions
ST R0, BACKUP_R0_3400
ST R1, BACKUP_R1_3400
ST R3, BACKUP_R3_3400
ST R4, BACKUP_R4_3400
ST R5, BACKUP_R5_3400
ST R7, BACKUP_R7_3400

BEGINNING
  LEA R0, PROMPT
  PUTS
  GETC
  LD R3, BEE
  NOT R0, R0
  ADD R0, R0, #1
  ADD R0, R0, R3
  BRnp INVAL1
  LD R1, FINDCOUNT
  LD R2, TOTAL

  WHILE1
    LD R5, uno1
    GETC
    NOT R3, R0
    ADD R3, R3, #1
    ADD R4, R3, R5
    BRz ADD_TOTAL

    LD R5, GAP
    NOT R3, R0
    ADD R3, R3, #1
    ADD R4, R3, R5
    BRz INVAL2

    LD R5, cero1
    NOT R3, R0
    ADD R3, R3, #1
    ADD R4, R3, R5
    BRnp INVAL3
    ADD R1, R1, #-1
    BRp WHILE1
    BRnz END_LOOP2

    ADD_TOTAL
      LD R4, DEC1
      ADD R5, R1, #-1
      BRnz END_LOOP1
      ANOTHA_ONE
ADD R4, R4, R4
ADD R5, R5, #-1
BRp ANOTHA_ONE
      END_ANOTHA_ONE
      ADD R2, R2, R4
      ADD R1, R1, #-1
      BRp WHILE1

      END_LOOP1
ADD R2, R2, #1
LD R0, BACKUP_R0_3400
LD R1, BACKUP_R1_3400
LD R3, BACKUP_R3_3400
LD R4, BACKUP_R4_3400
LD R5, BACKUP_R5_3400
LD R7, BACKUP_R7_3400

RET

      END_LOOP2
LD R0, BACKUP_R0_3400
LD R1, BACKUP_R1_3400
LD R3, BACKUP_R3_3400
LD R4, BACKUP_R4_3400
LD R5, BACKUP_R5_3400
LD R7, BACKUP_R7_3400

RET

    INVAL1
      LEA R0, b_message
      PUTS
      BRnzp BEGINNING

    INVAL2
      LD R0, GAP
      OUT
      BRnzp WHILE1

    INVAL3
      LEA R0, b_message
      PUTS
      BRnzp WHILE1
 END

;Subroutine Data
BACKUP_R0_3400 .BLKW #1
BACKUP_R1_3400 .BLKW #1
BACKUP_R3_3400 .BLKW #1
BACKUP_R4_3400 .BLKW #1
BACKUP_R5_3400 .BLKW #1
BACKUP_R7_3400 .BLKW #1
BEE .STRINGZ "b"
GAP .FILL x20
PROMPT .STRINGZ "ENTER BINARY VALUE STARTING WITH 'b'\n"
b_message .STRINGZ "START WITH 'b'\n"
FINDCOUNT .FILL 16
TOTAL .FILL #0
DEC1 .FILL #1
cero1.FILL x30
uno1 .FILL x31


.end