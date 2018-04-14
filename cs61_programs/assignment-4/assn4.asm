;=================================================
; Name: <REMOVED>
; Email: <REMOVED>
;
; Assignment name: Assignment 4
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

;-------------------------------
;INSERT CODE STARTING FROM HERE 
;--------------------------------
;Example of how to Output Intro Message
;LD R0, introMessage  ;Output Intro Message
;PUTS

;Example of how to Output Error Message
;LD R0, errorMessage  ;Output Error Message
;PUTS

STARTING_LOOP_1
LD R0, introMessage	;Output Intro Message 
TRAP x22 

LD R6, counter
AND R5, R5, #0 			;AND the registers w/ 0
AND R4, R4, #0 			
AND R3, R3, #0
 
WHILE_LOOP_1 
TRAP x20		 	;read in a single char
	
ADD R1, R0, #0 		
LD R7, newline 		;load newline into register 7
ADD R1, R1, R7 		;add register 1 value and register 7 value to register 1

BRnp OUTPUT_LOOP_1 		;outputting character loop

OUTPUT_LOOP_2 
ADD R1, R0, #0 	 	;add register 0's value to register 1
LD R7, NEGATIVE_48 	 	;put -48 into r7
ADD R1, R1, R7

BRn LESS_THAN_48_CHECK 	 		;check if it's less than 48

ADD R1, R0, #0
LD R7,NEGATIVE_57
ADD R1, R1, R7
BRp GREATER_THAN_57_CHECK		;check if it's greater than 57
ADD R1, R6, #0
ADD R1, R1, #-6

BRz FIRST_CHAR		

ADD R5, R5, R5
ADD R7, R5, R5
ADD R7, R7, R7
ADD R5, R5, R7
LD R7, NEGATIVE_48 	 	;check to see if it's around -48
ADD R0, R0, R7
ADD R5, R5, R0
ADD R6, R6, #-1
	
BRp WHILE_LOOP_1
BRz END_BRANCH_1

OUTPUT_LOOP_1 			;loop that prints the char
TRAP x21 				;output it my dude
BRnzp OUTPUT_LOOP_2 			;if it doesn't work out, let's try again

ERROR_CHECK_1 		;check for errors
LD R0, NEWLINE_char 		;add newline if it ends up being an issue
TRAP x21 				;output it

BRnzp GREATER

IS_NEG_2
NOT R5, R5 	 	 	;find the inverse of register 5
ADD R5, R5, #1 	 	;gotta add 1 to itself for 2's compliment, my dude
BRnzp END_BRANCH_2 	
FIRST_CHAR 
LD R7, NEGATIVE_48 		;put -48 into register 7.i'll admit it took me a while until i got this.  been working on this for 3 sleepless nights, dude.  cut me some slack lol	 
  ADD R0, R0, R7
ADD R5, R0, R5
ADD R6, R6, #-2
BRnzp WHILE_LOOP_1

IS_NEWLINE 			;loop that checks if it's a newline char

ADD R1, R6, #0 			;put register 6 value into r1 
ADD R1, R1, #-6 	 	;now take that value and subtract 6 from it
BRz GREATER_THAN_57_CHECK		;if it reaches 0, it's greater than 57.  go to this branch then
ADD R1, R6, #0 	 		;put register 6's value back into register 1
ADD R1, R1, #-5 	 	;now subtract 5 from register 6's value in register 1
BRnp END_BRANCH_1
ADD R1, R3, #0 	 		;now put register 3 into register 1
ADD R1, R1, #-1 	 	;take away 1 and let's check if there's an error.  if so, go to error check.  if not, go to the end branch :)
BRz ERROR_CHECK_1
BRnp END_BRANCH_1 	 	 

IS_POSITIVE 			;check to see if the value is positive?
ADD R1, R6, #0 	 		;similar to is_newline.add register 6's value to register 1
ADD R1, R1, #-6 	 	;take 6 a`way
BRnp GREATER_THAN_57_CHECK		;now check to see if we need to go into greater 57
ADD R4, R4, #0 	 		;add register 4's value to itself.
ADD R3, R3, #1 			;add 1 to register 4.
ADD R6, R6, #-1 	 	;take 1 away from register 6
BRnzp WHILE_LOOP_1	 		;now check if we have to go back into the loop.

IS_NEG 					;check to see if value is neg?
ADD R1, R6, #0 	 	;nearly identical to is_positive except now adding some things instead of subtracting
ADD R1, R1, #-6
BRnp GREATER_THAN_57_CHECK
ADD R4, R4, #1
ADD R3, R3, #1
ADD R6, R6, #-1
BRnzp WHILE_LOOP_1	 		;if you dont meet our standards, back to while loop for you!

LESS_THAN_48_CHECK 			;checking if around -48
LD R7, POSITIVE_SIGN
ADD R1, R0, #0
ADD R1, R1, R7
BRz IS_POSITIVE
LD R7, NEGATIVE_SIGN	;bring out... the negative sign! dun dun dun!
ADD R1, R0, #0
ADD R1, R1, R7
BRz IS_NEG 	 

LD R7, newline	 
ADD R1, R0, #0
ADD R1, R1, R7
BRz IS_NEWLINE
	
GREATER_THAN_57_CHECK 	 
ADD R1, R0, #0
ADD R1, R1, #-10
BRnp ERROR_CHECK_1 
GREATER 	 
LD R0, errorMessage	;oh man.. you messed up.  time to output the error message
TRAP x22 			;outputted.  you're in trouble, mister!

BRnzp STARTING_LOOP_1			;start over.  you really messed up!
 
END_BRANCH_1 				;first end branch check
ADD R1, R4, #0 	 		;put register 4's value into register 1
ADD R1, R1, #-1 	 		;take away 1
BRz IS_NEG_2 	 	;if it's negative, go to is negative branch.  otherwise, you're good.
END_BRANCH_2 			;second end branch check.  this should be the last one
LD R0, NEWLINE_char
TRAP x21	 			;outputs it
HALT
;---------------	
;Data
;---------------
introMessage .FILL x6000
errorMessage .FILL x6100

counter	.FILL #6 
newline	.FILL #-10
NEGATIVE_57	.FILL #-57 
NEGATIVE_48 	.FILL #-48 
POSITIVE_SIGN	.FILL #-43 
NEGATIVE_SIGN	.FILL #-45 
NEWLINE_char	.FILL #10
;------------
;Remote data
;------------
.ORIG x6000
;---------------
;messages
;---------------
intro .STRINGZ	"Input a positive or negative decimal number (max 5 digits), followed by ENTER\n"
;---------------
;error_messages
;---------------
.ORIG x6100	
error_mes .STRINGZ	"ERROR INVALID INPUT\n"
;---------------
;END of PROGRAM
;---------------
.END
;-------------------
;PURPOSE of PROGRAM
;-------------------