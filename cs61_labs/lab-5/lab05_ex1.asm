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



HALT
;-----------
;Data
;-----------
HARDCODED .FILL #0
DATA_PTR .FILL ARRAY

.orig x4000
ARRAY .BLKW #10



.end
