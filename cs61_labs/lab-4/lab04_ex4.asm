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
	LD R1, ARRAY			;LOADING MEMORY LOCATION OF ARRAY INTO R1
	LD R5, ITERATOR
	NOT R5, R5
	ADD R5, R5, #1
	
	DO_WHILE_LOOP			
		TRAP x20			; getting input
		STR R0, R1, #0			;LOADING DATA
		ADD R1, R1, #1			;adding 1 to r1, move elements in array
		ADD R6, R0, R5
	BRnp DO_WHILE_LOOP
	
	LD R2, ARRAY
	DO_WHILE_LOOP_2
		LDR R0, R2, #0
		TRAP x21
		ADD R2, R2, #1
		ADD R3, R0, #0
		
		LD R0, ITERATOR
		TRAP x21
		ADD R6, R3, R5
	BRnp DO_WHILE_LOOP_2

HALT
;--------
;Data
;--------

ARRAY .FILL x4000
ITERATOR .FILL #10
INTRO .STRINGZ "Enter 10 CHARS (0...9):\n"

.end
