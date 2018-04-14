;=================================================
; Name: <REMOVED>
; Email: <REMOVED>
; 
; Lab: lab 9
; Lab section: <REMOVED>
; TA: <REMOVED>
; 
;=================================================
;------------------------------------------------------------------------------------------
;Subroutine: SUB_STACK_PUSH
; Parameter (R0): The value to push onto the stack
; Parameter (R4): BASE: A pointer to the base (one less than the lowest available
; address) of the stack
; Parameter (R5): MAX: The "highest" available address in the stack
; Parameter (R6): TOS (Top of Stack): A pointer to the current top of the stack
; Postcondition: The subroutine has pushed (R0) onto the stack (i.e to address TOS+1).
;If the stack was already full (TOS = MAX), the subroutine has printed an
;overflow error message and terminated.
; Return Value: R6updated TOS
;------------------------------------------------------------------------------------------

;------------------------------------------------------------------------------------------
;Subroutine: SUB_STACK_POP
;Parameter (R4): BASE: A pointer to the base (one less than the lowest available
;address) of the stack
;Parameter (R5): MAX: The "highest" available address in the stack
;Parameter (R6): TOS (Top of Stack): A pointer to the current top of the stack
;Postcondition: The subroutine has popped MEM[top] off of the stack.
;If the stack was already empty (TOS = BASE), the subroutine has printed
;an underflow error message and terminated.
;Return Value: R0value popped off of the stack
;R6 updated TOS
;------------------------------------------------------------------------------------------

.orig x3000

LD R2, newLine
NOT R2, R2
ADD R2, R2, #1
LD R4, BASE
LD R5, MAX
LD R6, TOS

DO_WHILE_LOOP_1
LEA R0, msg1
TRAP x22
TRAP x20
TRAP x21

LD R1, num_offset
ADD R3, R0, R1

BRz POP_BRANCH

LEA R0, msg2
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

POP_BRANCH
LD R0, newLine
TRAP x21

AND R0, R0, #0 
LD R1, SUB_STACK_POP

JSRR R1
LD R1, num_offset

NOT R1, R1
ADD R1, R1, #1
ADD R0, R0, R1

BRn DO_WHILE_LOOP_1

NOT R1, R0
ADD R1, R1, #1
LD R2, max_num
ADD R2, R2, R1

BRn DO_WHILE_LOOP_1

TRAP x21

LEA R0, msg3
TRAP x22

BRnzp DO_WHILE_LOOP_1

END_BRANCH_1
HALT

;Local Data
SUB_STACK_PUSH .FILL x3200
SUB_STACK_POP .FILL x3400
num_offset .FILL #-48
max_num .FILL x39
newLine .FILL x0A
BASE .FILL xA000
MAX .FILL xA005
TOS .FILL xA000
msg1 .STRINGZ "Pop = 0 || Push = 1\n"
msg2 .STRINGZ "\nWhat would you like to push, my dude?\n"
msg3 .STRINGZ " was the value popped out, my dude.\n"
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
ST R0, reg0_error
LEA R0, OF_MSG
TRAP x22

LD R0, reg0_error
LD R2, BACKUP_R2
LD R7, BACKUP_R7

RET

;SR Data
OF_MSG .STRINGZ "Overflow.. be careful!!\n"
reg0_error .BLKW 1
BACKUP_R2 .BLKW 1
BACKUP_R7 .BLKW 1

.orig x3400
;SR Instrucs

ST R2, BACKUP_R2_2
ST R7, BACKUP_R7_2
NOT R2, R4
ADD R2, R2, #1
ADD R2, R6, R2

BRnz UF_MGMT

LDR R0, R6, #0
ADD R6, R6, #-1
LD R2, BACKUP_R2_2
LD R7, BACKUP_R7_2

RET

UF_MGMT
LEA R0, UF_MSG
TRAP x22

LD R2, BACKUP_R2_2
LD R7, BACKUP_R7_2

RET

;SR Data
UF_MSG .STRINGZ "Underflow.. be careful!\n"
BACKUP_R2_2.BLKW 1
BACKUP_R7_2.BLKW 1
