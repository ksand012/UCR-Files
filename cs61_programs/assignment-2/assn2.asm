;=================================================
; Name: <REMOVED>
; Email: <REMOVED>
; 
; Assignment name: Assignment 2
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

;----------------------------------------------
;outputs prompt
;----------------------------------------------	
LEA R0, intro			; 
PUTS				; Invokes BIOS routine to output string

;-------------------------------
;Program code below
;--------------------------------
LEA R0, NEWLINE
PUTS ;outputs .STRINGZ that is passed into R0???


TRAP x20 ;Take input for int #1
TRAP x21 ;Output that input?
ADD R1, R0, #0 ;Put R0 value into R1
LEA R0, NEWLINE ;insert string into R0
PUTS ; outputs newline from R0
TRAP x20 ;Take input for int #2
TRAP x21 ;output that input
ADD R2, R0, #0 ;Put R0 value into R2
LEA R0, NEWLINE ;put new stringz into R0
PUTS ;output R0 newline
ADD R0, R1, #0 ;add the first value of R1 into R0 so we can output it
TRAP x21 ;output time!!!
LEA R0, SUBTRACT
PUTS
ADD R0, R2, #0 ;add the second input value from R2 into R0 so we can output it
TRAP x21 ;output time!!!!!
LEA R0, EQUAL
PUTS

;Simple output is done.... now time for figuring out how to manipulate #'s
;We only do two's compliment of the second #
;We should move R2 to R3 and modify R3 just in-case we screw up

ADD R3, R2, #0
NOT R3, R3 ;2's compliment negative 1, need to add 1 next
ADD R3, R3, 1 ;adding 1 now
ADD R4, R3, R1 ;Adding R4 <--- R3 + R1
;you can apparently use a branch to look at the last executed statement and base
;it off of that.  how convenient!!
BRn NEGATIVE

;so apparently looking at the 48th element allows you to get from ASCII to dec
ADD R4, R4, #12
ADD R4, R4, #12
ADD R4, R4, #12
ADD R4, R4, #12
ADD R0, R4, #0
TRAP x21
LEA R0, NEWLINE
PUTS
HALT

NEGATIVE
  NOT R4, R4 ;2's compliment
  ADD R4, R4, #1
  ADD R4, R4, #12
  ADD R4, R4, #12
  ADD R4, R4, #12
  ADD R4, R4, #12 ;cool, so we went from ASCII to dec, time to display the final answr
  LEA R0, NEGATIVE_SIGN
  PUTS ;printing negative symbol
  ADD R0, R4, #0
  TRAP x21
  LEA R0, NEWLINE
  PUTS

  HALT				; Stop execution of program
;------	
;Data
;------
; String to explain what to input 
intro .STRINGZ	"ENTER two numbers (i.e '0'....'9')\n" 
NEWLINE .STRINGZ "\n"	; String that holds the newline character
EQUAL .STRINGZ " = "
SUBTRACT .STRINGZ " - "
NEGATIVE_SIGN .STRINGZ "-"



;---------------	
;END of PROGRAM
;---------------	
.END

