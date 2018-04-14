;=================================================
; Name: <REMOVED>
; Email: <REMOVED>
; Lab: lab 8
; Lab section: <REMOVED>
; TA: <REMOVED>
;=================================================
.ORIG x3000
;===========
;Instructions
;===========
LD R0, addr
LD R1, SUB_GET_STRING
JSRR R1

LD R1, SUB_IS_PALINDROME
JSRR R1

LD R2, DEC_ONE
NOT R2, R2
ADD R2, R2, #1
ADD R4, R4, R2
BRz PRINT

LEA R0, NON_PALINDROME
PUTS
HALT

PRINT
  LEA R0, PALINDROME
  PUTS
  HALT
;=========
;Local Data Block
;=========
addr .FILL x4000
SUB_GET_STRING .FILL x3200
SUB_IS_PALINDROME .FILL x3400
DEC_ONE .FILL #1
PALINDROME .STRINGZ "This is a palindrome, my dude!\n"
NON_PALINDROME .STRINGZ "This is not a palindrome, my dude!\n"
;---------------------------------------------------------------------------
; Subroutine: SUB_GET_STRING
; Parameter (R0): The address of where to start storing the string
; Postcondition: The subroutine has allowed the user to input a string,
; terminated by the [ENTER] key, and has stored it in an array
; that starts at (R0) and is NULL-terminated.
; Return Value: R5 The number of non-sentinel characters read from the user
;---------------------------------------------------------------------------
.ORIG x3200
;==========
;Subroutine Instructions
;==========

ST R0, BACKUP_R0_3200
ST R1, BACKUP_R1_3200
ST R7, BACKUP_R7_3200

LEA R0, PROMPT_3200
PUTS
LD R1, BACKUP_R0_3200
AND R5, R5, #0
LD R2, NEWLINE
NOT R2, R2
ADD R2, R2, #1
STRING_INPUT_LOOP
  GETC
  OUT
  ADD R3, R0, R2
  BRz RESET

  STR R0, R1, #0
  ADD R1, R1, #1
  ADD R5, R5, #1

  BRnzp STRING_INPUT_LOOP
END_STRING_INPUT_LOOP

  BRnzp STRING_INPUT_LOOP

RESET
  LD R0, NONE
  STR R0, R1, #0
  LD R0, BACKUP_R0_3200
  LD R1, BACKUP_R1_3200
  LD R7, BACKUP_R7_3200
  RET

;========
;Subroutine Data
;========
PROMPT_3200.STRINGZ "Enter a word, my dude. Press enter when done. \n"
NEWLINE .FILL x0A
NONE.FILL#0
BACKUP_R0_3200.BLKW x1
BACKUP_R1_3200.BLKW x1
BACKUP_R7_3200.BLKW x1

;-----------------------------------------------------------------------
;Subroutine: SUB_IS_A_PALINDROME
;Parameter (R0): The address of a string
;Parameter (R5): The number of characters in the array.
;Postcondition: The subroutine has determined whether the string at (R0) is
;a palindrome or not, and returned a flag to that effect.
;Return Value: R4 {1 if the string is a palindrome, 0 otherwise}
;----------------------------------------------------------------------
.ORIG x3400
;=========
;Subroutine Instructions
;=========
ST R1, BACKUP_R1_3400
ST R7, BACKUP_R7_3400

ADD R1, R0, R5
ADD R1, R1, #-1

SUB_LOOP
  LDR R2, R0, #0
  LDR R3, R1, #0
  NOT R4, R1
  ADD R4, R4, #1
  ADD R4, R0, R4
  BRz SUCCESS

  NOT R3, R3
  ADD R3, R3, #1
  ADD R2, R2, R3
  BRnp FAILURE

  ADD R4, R4, #-1
  BRz SUCCESS

  ADD R0, R0, #1
  ADD R1, R1, #-1
  BRnzp SUB_LOOP


SUCCESS
  LD R4, DEC_ONE_3400
  LD R1, BACKUP_R1_3400
  LD R7, BACKUP_R7_3400

  RET

FAILURE
  LD R4, DEC_ZERO_3400
  LD R1, BACKUP_R1_3400
  LD R7, BACKUP_R7_3400

  RET
;==============
;Subroutine Data
;==============
DEC_ONE_3400 .FILL #1
DEC_ZERO_3400 .FILL #0
BACKUP_R1_3400 .BLKW #1
BACKUP_R7_3400 .BLKW #1

.END
