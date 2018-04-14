;=================================================
; Name: <REMOVED>
; Email: <REMOVED>
; Lab: lab 6
; Lab section: <REMOVED>
; TA: <REMOVED>
;=================================================
.ORIG x3000
;instructions
	LEA R0, intro
	PUTS
	GETC
	OUT

	LD R6, DEC_16

	LD R5, SUB_GV_3400		;call subroutine
	JSRR R5

	LEA R0, NEWLINE
	PUTS

	LD R7, SUB_PV_3200		;call subroutine
	JSRR R7

HALT
;data
	DEC_16 .FILL #16
	intro .STRINGZ "ENTER BINARY VALUE\n"
	NEWLINE .STRINGZ "\n"

	SUB_GV_3400 .FILL x3400
	SUB_PV_3200 .FILL x3200

;--------------------------------------------------------
;subroutine: sub_pv_3200
;parameter (r2): contains binary value
;postcondition: prints out user input
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
	
	DO_LOOP
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
		BRnp DO_LOOP

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
	LEA R0, NEWLINE_SUB
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
	NEWLINE_SUB .STRINGZ "\n"
	b .FILL #98

;--------------------------------------------------------
;subroutine: sub_gv_3200
;parameter (r2): contains value of the user input
;postcondition: get binary value from user input
;return value: R2
;--------------------------------------------------------
.ORIG x3400
	ST R6, BU_R6_3400
	ST R7, BU_R7_3400
	
	DO_WHILE
		GETC
		OUT

	;ASCII TO DECVAL
		ADD R0, R0, -15
		ADD R0, R0, -15
		ADD R0, R0, -15
		ADD R0, R0, -3

		ADD R2, R2, R2
		ADD R2, R2, R0

		ADD R6, R6, #-1
		BRp DO_WHILE

	ST R6, BU_R6_3400
	LD R7, BU_R7_3400
RET
	BU_R6_3400 .BLKW #1
	BU_R7_3400 .BLKW #1

.END


