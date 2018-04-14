;=================================================
; Name: <REMOVED>
; Email: <REMOVED>
; 
; Lab: lab 4
; Lab section: <REMOVED>
; TA: <REMOVED>
; 
;=================================================

.orig x3000

;---------
;Instructions
;---------
LEA R0, INTRO
PUTS
	LDI R3, ITERATOR
	LEA R1, ARRAY				;LOADING MEMORY LOCATION OF ARRAY INTO R1
	DO_WHILE_LOOP			
		TRAP x20			; getting input
		STR R0, R1, #0			;LOADING DATA
		ADD R1, R1, #1			;adding 1 to r1, move elements in array
		TRAP x21			;OUTPUTTING DATA
		LEA R0, SPACE			;outputting space
		PUTS
		ADD R3, R3, #-1			;REDUCE ITERATOR BY 1
	BRp DO_WHILE_LOOP
	END_DO_WHILE_LOOP

	LDI R3, ITERATOR	
	LEA R1, ARRAY
	DO_WHILE_LOOP_2
		LDR R0, R1, #0
		ADD R1, R1, #1
		TRAP x21
		LEA R0, ENDLINE
		PUTS
		ADD R3, R3, #-1
	BRp DO_WHILE_LOOP_2
	END_DO_WHILE_LOOP_2

HALT
;--------
;Data
;--------

ARRAY .BLKW #10
ITERATOR .FILL x4000
INTRO .STRINGZ "Enter 10 CHARS (0...9):"
ENDLINE .STRINGZ "\n"
SPACE .STRINGZ " "

.orig x4000
	.FILL #10

.end
