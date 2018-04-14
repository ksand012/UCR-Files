;=================================================
; Name: <REMOVED>
; Email: <REMOVED>
; 
; Lab: lab 3
; Lab section: <REMOVED>
; TA: <REMOVED>
; 
;=================================================
.orig x3000

;---------
;Instructions
;---------
LD R0, HEX_61
LD R1, HEX_1A

DO_WHILE_LOOP
	TRAP x21
	ADD R0, R0, #1
	ADD R1, R1, #-1
	BRp DO_WHILE_LOOP
END_DO_WHILE_LOOP

HALT
;---------
;Data
;---------
HEX_61 .FILL x61
HEX_1A .FILL x1A

.orig x4000
.FILL #61
.FILL x41
