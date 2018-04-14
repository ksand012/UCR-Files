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
LD R5, DATA_PTR

LDR R3, R5, #0
ADD R3, R3, #1
STR R3, R5, #0

ADD R5, R5, #1
LDR R4, R5, #0
ADD R4, R4, #1
STR R4, R5, #0

HALT
;--------
;Data
;--------

DATA_PTR .FILL ARRAY
.orig x4000
	.FILL #65
	.FILL x41
