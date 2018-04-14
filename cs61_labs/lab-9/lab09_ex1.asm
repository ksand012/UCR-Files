;=================================================
; Name: <REMOVED>
; Email: <REMOVED>
; 
; Lab: lab 9
; Lab section: <REMOVED>
; TA: <REMOVED>
;=================================================
;------------------------------------------------------------------------------------------;
; Subroutine: SUB_STACK_PUSH
; Parameter (R0): The value to push onto the stack
; Parameter (R4): BASE: A pointer to the base ( one less than the lowest available
; address) of the stack
; Parameter (R5): MAX: The "highest" available address in the stack
; Parameter (R6): TOS (Top of Stack): A pointer to the current top of the stack
; Postcondition: The subroutine has pushed (R0) onto the stack (i.e to address TOS+1).
; If the stack was already full (TOS = MAX), the subroutine has printed an
; overflow error message and terminated.
; Return Value: R6 ← updated TOS
;------------------------------------------------------------------------------------------

.orig x3000

LD R2, newLine

NOT R2, R2
ADD R2, R2, #1

LD R4, BASE
LD R5, MAX
LD R6, TOS

DO_WHILE_LOOP_1
LEA R0, welcome_msg
TRAP x22
TRAP x20
TRAP x21

ADD R3, R0, R2

BRz END_BRANCH_1

ST R0, input
LD R0, newLine
TRAP x21

LD R0, input
LD R1, num_offset
ADD R0, R0, R1
LD R1, SUB_STACK_PUSH

JSRR R1

BRnzp DO_WHILE_LOOP_1

END_BRANCH_1
HALT

;Data
SUB_STACK_PUSH .FILL x3200
num_offset .FILL #-48
newLine .FILL x0A
BASE .FILL xA000
MAX .FILL xA005
TOS .FILL xA000
welcome_msg .STRINGZ "Enter value to push onto stack\n"
input .BLKW 1

.orig x3200

;SR Instrucs

ST R2, BACKUP_R2
ST R7, BACKUP_R7
NOT R2, R5
ADD R2, R2, #1
ADD R2, R6, R2

BRzp OF_MGMT

ADD R6, R6, #1
STR R0, R6, #0

LD R2, BACKUP_R2
LD R7, BACKUP_R7

RET

OF_MGMT
ST R0, R0_ERROR
LEA R0, OFMSG
TRAP x22

LD R0, R0_ERROR
LD R2, BACKUP_R2
LD R7, BACKUP_R7

RET

;SR Data
R0_ERROR .BLKW 1
BACKUP_R2 .BLKW 1
BACKUP_R7 .BLKW 1
OFMSG .STRINGZ "Overflow.. careful!\n"