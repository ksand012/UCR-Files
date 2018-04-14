;=================================================
; Name: <REMOVED>
; Email: <REMOVED>
; 
; Lab: lab 5
; Lab section: <REMOVED>
; TA: <REMOVED>
;=================================================


.orig x3000

;-----------
;Instructions
;-----------
LD R1, HARDCODED
LD R2, DATA_PTR

FOR_LOOP
	STR R1, R2, #0
	ADD R2, R2, #1
	ADD R1, R1, #1
	ADD r3, r1, #-10
BRnp FOR_LOOP

LD R4, DATA_PTR
ADD R4, R4, #6
LDR R2, R4, #0

LD R1, DATA_PTR
LD R4, CONVERT

FOR_LOOP_2
	LDR R0, R1, #0
	ADD R3, R0, #0
	ADD R0, R0, R4
	TRAP x21
	ADD R1, R1, #1
	ADD R3, R3, #-9
BRnp FOR_LOOP_2

HALT
;-----------
;Data
;-----------
HARDCODED .FILL #0
DATA_PTR .FILL ARRAY

CONVERT .FILL #48

.orig x4000
ARRAY .BLKW #10



.end
