;=================================================
; Name: <REMOVED>
; Email:  <REMOVED>
; 
; Lab: lab 2
; Lab section: <REMOVED>
; TA: <REMOVED>
; 
; Hello world
; Illustrates how to use PUTS
;=================================================

.ORIG x3000
;-----------
; Instructions
;-----------
      LEA R0, MSG_TO_PRINT	;R0 <-- the location of the label: MSG_TO_PRINT
      PUTS			;Prints string defined at MSG_TO_PRINT

      HALT			;terminate program
;-----------
;Local Data
;-----------
    MSG_TO_PRINT	.STRINGZ "Hello world!!!\n"	;store 'H' in an address
							;labelled MSG_TO_PRINT and then each
							;character ('e', 'l', 'l', 'o', '', 'w', ...) in
							;it's own (consecutive) memory
							;address, followed by #0 at the end
							;of the string to mark the end of the string
.END