;=================================================
; Name: <REMOVED>
; Email: <REMOVED>
; 
; Lab: lab 9
; Lab section: <REMOVED>
; TA: <REMOVED>
; 
;=================================================
.orig x3000

LD R4, BASE
LD R5, MAX
LD R6, TOS
LD R1, PUSH
LEA R0, PROMPT
TRAP x22
TRAP x20
TRAP x21

LD R2, OFFSET
ADD R0, R0, R2
JSRR R1
TRAP x20
TRAP x21

ADD R0, R0, R2 
JSRR R1
TRAP x20
TRAP x21

LD R0, NEWLINE
TRAP x21

LD R1, MULT
JSRR R1
LD R1, POP
JSRR R1
LD R3, MAX_DIG
ADD R3, R3, R0
BRp MULTI

NOT R2, R2
ADD R2, R2, #1
ADD R0, R0, R2
TRAP x21

LEA R0, MESSAGE
TRAP x22

HALT

MULTI
LD R1, DECI
JSRR R1
LEA R0, MESSAGE
TRAP x22

HALT


;Local Data
PUSH .FILL x3200
POP .FILL x3400
MULT .FILL x3600
DECI .FILL x4000
OFFSET .FILL #-48
MAX_DIG .FILL #-9
NEWLINE .FILL x0A
BASE .FILL xA000
MAX .FILL xA005
TOS .FILL xA000

PROMPT .STRINGZ "My dude, please enter two numbers followed by the operation you wish to perform on them.\n"
MESSAGE .STRINGZ " is the result, my dude.  You're welcome.\n"

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
; Return Value: R6 updated TOS
;------------------------------------------------------------------------------------------
.orig x3200
;Subroutine Instructions

ST R2, BACKUP_R2
ST R7, BACKUP_R7
NOT R2, R5
ADD R2, R2, #1
ADD R2, R6, R2

BRzp ERROR

ADD R6, R6, #1
STR R0, R6, #0
LD R2, BACKUP_R2
LD R7, BACKUP_R7

RET

ERROR
ST R0, R0_ERROR
LEA R0, OVERFLOW_MESSAGE
TRAP x22
LD R0, R0_ERROR
LD R2, BACKUP_R2
LD R7, BACKUP_R7

RET

;Subroutine Data
OVERFLOW_MESSAGE .STRINGZ "Overflow.. be careful!!\n"
R0_ERROR.BLKW 1
BACKUP_R2.BLKW 1
BACKUP_R7.BLKW 1


;------------------------------------------------------------------------------------------
;Subroutine: SUB_STACK_POP
; Parameter (R4): BASE: A pointer to the base (one less than the lowest available
; address) of the stack
; Parameter (R5): MAX: The "highest" available address in the stack
; Parameter (R6): TOS (Top of Stack): A pointer to the current top of the stack
; Postcondition: The subroutine has popped MEM[top] off of the stack.
;If the stack was already empty (TOS = BASE), the subroutine has printed
;an underflow error message and terminated.
; Return Value: R0value popped off of the stack
;R6updated TOS
;------------------------------------------------------------------------------------------
.orig x3400
;Subroutine Instructions

ST R2, BACKUP_R2_2
ST R7, BACKUP_R7_2
NOT R2, R4
ADD R2, R2, #1
ADD R2, R6, R2

BRnz ERROR_x3400

LDR R0, R6, #0
ADD R6, R6, #-1
LD R2, BACKUP_R2_2
LD R7, BACKUP_R7_2

RET

ERROR_x3400
LEA R0, UNDERFLOW_MESSAGE
TRAP x22
LD R2, BACKUP_R2_2
LD R7, BACKUP_R7_2

RET

;SR Data
UNDERFLOW_MESSAGE .STRINGZ "Underflow.. be careful!!\n"

BACKUP_R2_2.BLKW 1
BACKUP_R7_2.BLKW 1


;------------------------------------------------------------------------------------------
;Subroutine: MULT
; Parameter (R4): BASE: A pointer to the base (one less than the lowest available
; address) of the stack
; Parameter (R5): MAX: The "highest" available address in the stack
; Parameter (R6): TOS (Top of Stack): A pointer to the current top of the stack
; Postcondition: The subroutine has popped off the top two values of the stack,
;multiplied them together, and pushed the resulting value back
;onto the stack.
; Return Value: R6updated top value
;------------------------------------------------------------------------------------------
.orig x3600
;Subroutine Instructions

ST R0, BACKUP_R0_3
ST R1, BACKUP_R1_3
ST R2, BACKUP_R2_3
ST R3, BACKUP_R3_3
ST R7, BACKUP_R7_3

LD R1, POP_2
JSRR R1

ST R0, ONE
JSRR R1

ADD R3, R0, #0
LD R2, ONE

LD R1, MULT_2
JSRR R1

LD R1, PUSH_2
JSRR R1

LD R0, BACKUP_R1_3
LD R1, BACKUP_R1_3
LD R2, BACKUP_R2_3
LD R3, BACKUP_R3_3
LD R7, BACKUP_R7_3

RET

;Subroutine Data
POP_2 .FILL x3400
MULT_2.FILL x3800
PUSH_2.FILL x3200

ONE.BLKW 1
BACKUP_R0_3.BLKW 1
BACKUP_R1_3.BLKW 1
BACKUP_R2_3.BLKW 1
BACKUP_R3_3.BLKW 1
BACKUP_R7_3.BLKW 1


;------------------------------------------------------------------------------------------
;Subroutine: SUB_MULTIPLY
; Parameter (R2): The first number to be multiplied
; Parameter (R3): The second number to be multiplied
; Postcondition: The subroutine multiplies the two numbers in R2 and R3 and returns their result
; Return Value: R0, multiplication result
;------------------------------------------------------------------------------------------
.orig x3800
;Subroutine Instructions

ST R7, BACKUP_R7_38

AND R0, R0, #0

LOOP
ADD R0, R0, R2
ADD R3, R3, #-1
BRp LOOP

LD R7, BACKUP_R7_38

RET

;Subroutine Data
BACKUP_R7_38 .BLKW 1


;------------------------------------------------------------------------------------------
;Subroutine: SUB_PRINT_DECIMAL
; Parameter (R0): The number to be printed
; Postcondition: The subroutine outputs a multi digit number stored in R0
; Return Value: None
;------------------------------------------------------------------------------------------
.orig x4000
;Subroutine Instructions

ST R1, BACKUP_R1_4
ST R2, BACKUP_R2_4
ST R3, BACKUP_R3_4
ST R7, BACKUP_R7_4

LD R3, OFFSET_2

AND R1, R1, #0
TENS_LOOP
ADD R0, R0, #-10
BRn PRINT_NUM

ADD R1, R1, #1
BRnzp TENS_LOOP

PRINT_NUM
ADD R2, R0, #0
ADD R0, R1, #0
ADD R0, R0, R3
OUT

ADD R0, R2, #10
ADD R0, R0, R3
OUT

LD R1, BACKUP_R1_4
LD R2, BACKUP_R2_4
LD R3, BACKUP_R3_4
LD R7, BACKUP_R7_4

RET

;Subroutine Data
OFFSET_2 .FILL #48
BACKUP_R1_4.BLKW 1
BACKUP_R2_4 .BLKW 1
BACKUP_R3_4 .BLKW 1
BACKUP_R7_4 .BLKW 1