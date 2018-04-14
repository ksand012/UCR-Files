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
LD R5, DEC_65_PTR
LD R6, HEX_41_PTR

LDR R3, R5, #0
LDR R4, R6, #0

ADD R3, R3, #1
ADD R4, R4, #1

STR R3, R4, #0
STR R3, R6, #0

HALT
;--------
;Data
;--------
DEC_65_PTR .FILL x4000
HEX_41_PTR .FILL x4001
;--------
;Remote Data
;--------
.orig x4000
.FILL #65
.FILL x41

.end
