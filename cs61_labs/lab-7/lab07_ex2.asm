;=================================================
; Name: <REMOVED>
; Email: <REMOVED>
; Lab: lab 7
; Lab section: <REMOVED>
; TA: <REMOVED>
;=================================================
.orig x3000
LEA R0, INPUT_PROMPT
TRAP x22

TRAP x20
ST R0, charUser

LD R5, SUB_PARITY_CHECK_3200

LEA R0, OUTPUT_PROMPT
TRAP x22

LD R0, charUser
JSRR R5

ST R1, one
LD R0, one
LD R2, offset
ADD R0, R0, R2
OUT

LEA R0, NEWLINE
TRAP x22

HALT

;Local Data
INPUT_PROMPT .STRINGZ "Enter a single character:\n"
NEWLINE .STRINGZ "\n"
OUTPUT_PROMPT .STRINGZ "The number of 1's is: "

offset .FILL #48
SUB_PARITY_CHECK_3200 .FILL x3200

charUser .BLKW 1
one .BLKW 1

.orig x3200
;Subroutine Instructions
ST R0, BACKUP_R0_3200
ST R2, BACKUP_R2_3200
ST R3, BACKUP_R3_3200
ST R4, BACKUP_R4_3200
ST R7, BACKUP_R7_3200

LD R2, addr
LD R4, count
AND R1, R1, #0

DO_WHILE_LOOP
  AND R3, R0, R2
  BRzp NEXT
  ADD R1, R1, #1
  NEXT
    ADD R0, R0, R0
    ADD R4, R4, #-1
    BRp DO_WHILE_LOOP
END_DO_WHILE_LOOP

LD R0, BACKUP_R0_3200
LD R2, BACKUP_R2_3200
LD R3, BACKUP_R3_3200
LD R4, BACKUP_R4_3200
LD R7, BACKUP_R7_3200

RET

;Subroutine Data
addr .FILL x8000
count .FILL #16
BACKUP_R0_3200
BACKUP_R2_3200
BACKUP_R3_3200
BACKUP_R4_3200
BACKUP_R7_3200

.end