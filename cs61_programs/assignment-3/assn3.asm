;=================================================
; Name: <REMOVED>
; Email: <REMOVED>
; 
; Assignment name: Assignment 3
; Lab section: <REMOVED>
; 
; I hereby certify that I have not received assistance on this assignment,
; or used code, from ANY outside source other than the instruction team.
;
;=================================================

.ORIG x3000			; Program begins here
;-------------
;Instructions
;-------------
LD R6, Convert_addr		; R6 <-- Address pointer for Convert
LDR R1, R6, #0			; R1 <-- VARIABLE Convert 
;-------------------------------
;INSERT CODE STARTING FROM HERE
;--------------------------------
LD R3,  Filled		;load counter of 16 into R4
LD R2, Counter		;load 4 into R3

FOR_LOOP_1			;FIRST FOR LOOP, MAY NEED MORE THAN ONE?
	ADD R2, R2, #0
	BRp SHIFT1			;if (R1 >= R4 )
	LEA R0, Space
	TRAP x22
	LD R2, Counter
	ADD R3, R3, #0		;jumping to first shift
	BR SHIFT2
	
	SHIFT1
	ADD R1, R1, #0
	BRn NEGATIVE1
	LEA R0, Nummzero
	TRAP x22
	BR NEGATIVE2
NEGATIVE1
LEA R0, Numone
TRAP x22
BR NEGATIVE2
NEGATIVE2
	ADD R1, R1, R1
	ADD R2, R2, #-1
	ADD R3, R3, #-1
	BR SHIFT2
	SHIFT2
	BRp FOR_LOOP_1
haltForLoop				;you did it!  you can now leave the ride.  we hope you enjoyed yourselves.

	LEA R0, Newline
	PUTS
	
HALT
;---------------	
;Data
;---------------
Convert_addr .FILL xD000	; The address of where to find the data
Filled .FILL #16	;fill with the address he gave us in instructions (x7000)
Counter .FILL #4		;start counter at 15 and decrease it where appropriate
Newline .STRINGZ "\n"		;newline
Numone .STRINGZ "1"		;string 1
Nummzero .STRINGZ "0"
Numzero .FILL #0		;string 0
Space .STRINGZ " "		;string space

.ORIG xD000			; Remote data
Convert .FILL xABCD		; <----!!!NUMBER TO BE CONVERTED TO BINARY!!!
;---------------	
;END of PROGRAM
;---------------	
.END
