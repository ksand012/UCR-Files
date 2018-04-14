;=================================================
; Name: <REMOVED>
; Email: <REMOVED>
; Lab: lab 6
; Lab section: <REMOVED>
; TA: <REMOVED>
;=================================================
.ORIG x3000

;instructions
	LD R4, A1
	LD R0, DEC_1
	LD R3, SIZE

DO_WHILE_LOOP
	STR R0, R4, #0
	ADD R0, R0, R0
	ADD R4, R4, #1
	ADD R3, R3, #-1
	BRp DO_WHILE_LOOP

	LD R1, A1
	LD R3, SIZE
DO_LOOP
	LDR R2, R1, #0
	LD R5, SUB_PB_3200		; calls subroutine
	JSRR R5
	
	ADD R1, R1, #1
	ADD R3, R3, #-1
	BRp DO_LOOP
	
	HALT

;data
	A1 .FILL x4000
	SIZE .FILL #10
	DEC_1 .FILL #1

	SUB_PB_3200 .FILL x3200

;--------------------------------------------------------
;subroutine: sub_pb_3200
;parameter (r1): filled array of power of 2
;postcondition: prints out power of 2
;return value: none
;--------------------------------------------------------

.ORIG x3200
	ST R0, BU_R0_3200
	ST R6, BU_R6_3200
	ST R5, BU_R5_3200
	ST R4, BU_R4_3200
	ST R7, BU_R7_3200

	LD R0, b
	OUT
;START OF OUTPUT OF ARRAY

	LD R6, DEC_15
	LD R5, DEC_4
	LD R4, DEC_0
	
	DO_WHILE
		ADD R2, R2, R4
		BRzp IF_POS
		BRn END
	IF_POS
		LD R0, ASCII_0
		OUT
	END
		BRn IF_NEG
		BRzp END2
	IF_NEG
		LD R0, ASCII_1
		OUT
	END2
		ADD R4, R2, #0
		ADD R5, R5, #-1
		BRz IF_4
		BRnp END3
	IF_4
		LD R0, SPACE
		OUT
		LD R5, DEC_4
	END3
		ADD R6, R6, #-1
		BRnp DO_WHILE
	END_DO_WHILE

		ADD R2, R2, R4
		BRzp IF_POS2
		BRn END4
	IF_POS2
		LD R0, ASCII_0
		OUT
	END4
		BRn IF_NEG2
		BRzp END5
	IF_NEG2
		LD R0, ASCII_1
		OUT
	END5
	LEA R0, NEWLINE
	PUTS

	LD R0, BU_R0_3200
	LD R6, BU_R6_3200
	LD R5, BU_R5_3200
	LD R4, BU_R4_3200
	LD R7, BU_R7_3200

	RET
HALT
	BU_R0_3200 .BLKW #1
	BU_R6_3200 .BLKW #1
	BU_R5_3200 .BLKW #1
	BU_R4_3200 .BLKW #1
	BU_R7_3200 .BLKW #1

	ASCII_0 .FILL #48
	ASCII_1 .FILL #49
	DEC_15 .FILL #15
	DEC_4 .FILL #4
	DEC_0 .FILL #0
	SPACE .FILL #32
	NEWLINE .STRINGZ "\n"
	b .FILL #98

.ORIG x4000
	ARR_1 .BLKW #10
.END

