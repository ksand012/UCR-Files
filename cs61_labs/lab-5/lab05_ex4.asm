;=================================================
; Name: <REMOVED>
; Email: <REMOVED>
; Lab: lab 5
; Lab section: <REMOVED>
; TA: <REMOVED>
;=================================================


.ORIG x3000
;-----------------------
;INSTRUCTIONS
;-----------------------
LD R1, arr			;ld array			
AND R2, R2, #0			;and r2 to compare
ADD R2, R2, #1			;add 1 to r2
STR R2, R1, #0			;store r1 into r2
LD R3, num9			;load decimal number 9 into r3
DO_WHILE_LOOP_1
	ADD R1, R1, #1		;next element
	ADD R2, R2, R2		
	STR R2, R1, #0
	ADD R3, R3, #-1
	BRnp DO_WHILE_LOOP_1
LD R1, arr
LD R3, num9
	ADD R3, R3, #1
DO_WHILE_LOOP_2
LD R6, num15
LD R5, num4
LD R4, num0
	LDR R2, R1, #0
	LD R0, letb
	TRAP x21
	DO_WHILE_LOOP_3
		ADD R2, R2, R4
		BRzp POSITION
		BRn ENDPOSITION
	POSITION
		LD R0, asc0
		TRAP x21
	ENDPOSITION
		BRn IFNEGATIVENUM
		BRzp ENDNEGATIVENUM
	IFNEGATIVENUM
		LD R0, asc1
		OUT
	ENDNEGATIVENUM

		ADD R5, R5, #-1
		BRnp SKIPSPACE
	
		LD R0, space
		TRAP x21
		LD R5, num4
	SKIPSPACE
		ADD R4, R2, #0
		ADD R6, R6, #-1
		BRnp DO_WHILE_LOOP_3
	ADD R2, R2, R4
	BRzp POSITION_2
	BRn ENDPOSITION_2

	POSITION_2
		LD R0, asc0
		TRAP x21
	ENDPOSITION_2

	BRn NEWLINECHECK
	BRzp ENDNEWLINE
	
	NEWLINECHECK
		LD R0, asc1
		TRAP x21
	ENDNEWLINE

	LD R0, newLine
	TRAP x21

	ADD R1, R1, #1
	ADD R3, R3, #-1
	BRnp DO_WHILE_LOOP_2

HALT
;-----------------------
;DATA
;-----------------------
arr .FILL x4000
num9 .FILL #9
letb .FILL #98
num15 .FILL #15
num4 .FILL #4
num0 .FILL #0
asc0 .FILL #48
asc1 .FILL #49
space .FILL #32
newLine .FILL x0A
.ORIG x4000
	.BLKW #10
.END

