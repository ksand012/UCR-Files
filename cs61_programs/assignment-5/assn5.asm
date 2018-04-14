;=================================================
; Name: <REMOVED>
; Email: <REMOVED>
; 
; Assignment name: Assignment 5
; Lab section: <REMOVED>
; 
; I hereby certify that I have not received assistance on this assignment,
; or used code, from ANY outside source other than the instruction team.
;
;=================================================
.ORIG x3000   ; Program begins here
;-------------
;Instructions
;-------------
;-------------------------------
;INSERT CODE STARTING FROM HERE
;--------------------------------
STARTING_BRANCH
 LD R1,menu_sr_addr
 JSRR R1
 ADD R2,R1,#0
 ADD R2,R2,#-1
 BRz SR_NUM_1
 ADD R2,R2,#-1
 BRz SR_NUM_2
 ADD R2,R2,#-1
 BRz SR_NUM_3
 ADD R2,R2,#-1
 BRz SR_NUM_4
 ADD R2,R2,#-1
 BRz SR_NUM_5
 ADD R2,R2,#-1
 BRz SR_NUM_6
 ADD R2,R2,#-1
 BRz SR_NUM_7
 SR_NUM_1
 LD R0,busy_sr_addr
 JSRR R0
 ADD R2,R2,#0
 BRz SR_NUM_1_NOPE
 LEA R0,ALLBUSY
 TRAP x22
 BRnzp STARTING_BRANCH
SR_NUM_1_NOPE
 LEA R0,ALLNOTBUSY
 TRAP x22
 BRnzp STARTING_BRANCH
SR_NUM_2
 LD R0,free_sr_addr
 JSRR R0
 ADD R2,R2,#0
 BRz SR_NUM_2_NOPE
 LEA R0,FREE
 TRAP x22
 BRnzp STARTING_BRANCH
SR_NUM_2_NOPE
 LEA R0,NOTFREE
 TRAP x22
 BRnzp STARTING_BRANCH
SR_NUM_3 
 LD R0,busy_sr_addr_amt
 JSRR R0
 LEA R0,BUSYMACHINE1
 TRAP x22
 LD R0,print_sr_addr
 JSRR R0
 LEA R0,BUSYMACHINE2
 TRAP x22
 BRnzp STARTING_BRANCH
SR_NUM_4
 LD R0,free_sr_addr_amt
 JSRR R0
 LEA R0,FREEMACHINE1
 TRAP x22
 LD R0,print_sr_addr
 JSRR R0
 LEA R0,FREEMACHINE2
 TRAP x22
 BRnzp STARTING_BRANCH
SR_NUM_5
 LD R0,input_sr_addr
 JSRR  R0
 LD R0,status_sr_addr 
 JSRR R0
 LEA R0,STATUS1
 TRAP x22
 ST R2,hex_65535
 ADD R2,R1,#0
 LD R0,print_sr_addr
 JSRR R0
 LD R2,hex_65535
 BRp SR_NUM_5_YEP
 LEA R0,STATUS2
 TRAP x22
 BRnzp STARTING_BRANCH
SR_NUM_5_YEP
 LEA R0,STATUS3
 TRAP x22
 BRnzp STARTING_BRANCH
SR_NUM_6
 LD R0,first_free_sr_addr
 JSRR R0
 ADD R0,R2,#-16
 BRz SR_NUM_5_NOPE
 LEA R0,FIRSTFREE
 TRAP x22
 LD R0,print_sr_addr
 JSRR R0
 LEA R0,FIRSTFREE2
 TRAP x22
 BRnzp STARTING_BRANCH
SR_NUM_5_NOPE
 LEA R0,FIRSTFREE3
 TRAP x22
 BRnzp STARTING_BRANCH
SR_NUM_7
 LEA R0,Goodbye
 TRAP x22
HALT
;--------------- 
;Data
;---------------
;Add address for subroutines
menu_sr_addr .FILL x3200
busy_sr_addr .FILL x3400
free_sr_addr .FILL x3600
busy_sr_addr_amt .FILL x3800
free_sr_addr_amt .FILL x4000
status_sr_addr .FILL x4200
first_free_sr_addr .FILL x4400
input_sr_addr .FILL x4600
print_sr_addr .FILL x4800
;Other data 
hex_65535 .FILL xFFFF
;Strings for options
Goodbye .Stringz "Goodbye!\n"
ALLNOTBUSY .Stringz "Not all machines are busy\n"
ALLBUSY .Stringz "All machines are busy\n"
FREE .STRINGZ "All machines are free\n"
NOTFREE .STRINGZ "Not all machines are free\n"
BUSYMACHINE1 .STRINGZ "There are "
BUSYMACHINE2 .STRINGZ " busy machines\n"
FREEMACHINE1 .STRINGZ "There are "
FREEMACHINE2 .STRINGZ " free machines\n"
STATUS1 .STRINGZ "Machine "
STATUS2  .STRINGZ " is busy\n"
STATUS3 .STRINGZ " is free\n"
FIRSTFREE .STRINGZ "The first available machine is number "
FIRSTFREE2 .STRINGZ "\n"
FIRSTFREE3 .STRINGZ "No machines are free\n"
;-----------------------------------------------------------------------------------------------------------------
; Subroutine: MENU
; Inputs: None
; Postcondition: The subroutine has printed out a menu with numerical options, allowed the
;                          user to select an option, and returned the selected option.
; Return Value (R1): The option selected:  #1, #2, #3, #4, #5, #6 or #7
; no other return value is possible
;-----------------------------------------------------------------------------------------------------------------
;-------------------------------
;INSERT CODE For Subroutine MENU
;--------------------------------
.ORIG x3200
;HINT back up 
 ST R7,ret_addr_1
DO_WHILE_LOOP_1
 LD R0,Menu_string_addr
 TRAP x22
 TRAP x20
 TRAP x21
 ADD R1,R0,#0
 AND R0,R0,#0
 ADD R0,R0,#10
 TRAP x21
 ADD R0,R1,#0
 LD R2,num_dec_48  
 ADD R1,R1,R2
 ADD R1,R1,#-1   
 BRn ERROR_BRANCH_1
 ADD R1,R0,#0
 LD R2,num_dec_55
 ADD R1,R1,R2
 BRp ERROR_BRANCH_1
 ADD R1,R0,#0
 LD R2,num_dec_48
 ADD R1,R1,R2
 BRnzp END_DO_WHILE_LOOP_1
ERROR_BRANCH_1
 LEA R0,Error_message_1
 TRAP x22
 BRnzp DO_WHILE_LOOP_1
END_DO_WHILE_LOOP_1
;HINT Restore
 AND R0,R0,#0
 AND R2,R2,#0
 LD R7,ret_addr_1
 RET
;--------------------------------
;Data for subroutine MENU
;--------------------------------
num_dec_48 .FILL#-48
num_dec_55 .FILL#-55
ret_addr_1 .FILL x0
Error_message_1 .STRINGZ "INVALID INPUT\n"
Menu_string_addr .FILL x6000
;-----------------------------------------------------------------------------------------------------------------
; Subroutine: ALL_MACHINES_BUSY
; Inputs: None
; Postcondition: The subroutine has returned a value indicating whether all machines are busy
; Return value (R2): 1 if all machines are busy,    0 otherwise
;-----------------------------------------------------------------------------------------------------------------
;-------------------------------
;INSERT CODE For Subroutine ALL_MACHINES_BUSY
;--------------------------------
.ORIG x3400
;HINT back up 
ST R7,ret_addr_2
 LD R6,BUSYNESS_ADDR_ALL_MACHINES_BUSY
 LDR R1,R6,#0
 LD R3,num_dec_16_1
 AND R2,R2,#0
DO_WHILE_LOOP_2
 ADD R1,R1,#0
 BRn END_DO_WHILE_LOOP_2
 ADD R1,R1,R1
 ADD R3,R3,#-1
 BRp DO_WHILE_LOOP_2
 ADD R2,R2,#1  
END_DO_WHILE_LOOP_2
;HINT Restore
 AND  R0,R0,#0
 AND R1,R1,#0
 AND R3,R3,#0
 AND R6,R6,#0
 LD R7,ret_addr_2
 RET
;--------------------------------
;Data for subroutine ALL_MACHINES_BUSY
;--------------------------------
ret_addr_2 .FILL x0
BUSYNESS_ADDR_ALL_MACHINES_BUSY .Fill xD000
num_dec_16_1 .FILL #16
;-----------------------------------------------------------------------------------------------------------------
; Subroutine: ALL_MACHINES_FREE
; Inputs: None
; Postcondition: The subroutine has returned a value indicating whether all machines are free
; Return value (R2): 1 if all machines are free,    0 otherwise
;-----------------------------------------------------------------------------------------------------------------
;-------------------------------
;INSERT CODE For Subroutine ALL_MACHINES_FREE
;--------------------------------
.ORIG x3600
;HINT back up
ST R7,ret_addr_3
 LD R6,BUSYNESS_ADDR_ALL_MACHINES_FREE
 LDR R1,R6,#0
 LD R3,num_dec_16_2
 AND R2,R2,#0
DO_WHILE_LOOP_3
 ADD R1,R1,#0
 BRzp END_DO_WHILE_LOOP_3
 ADD R1,R1,R1
 ADD R3,R3,#-1
 BRp DO_WHILE_LOOP_3
 ADD R2,R2,#1 
END_DO_WHILE_LOOP_3
;HINT Restore
 AND R0,R0,#0
 AND R1,R1,#0
 AND R3,R3,#0
 AND R6,R6,#0
 LD R7,ret_addr_3
 RET
;--------------------------------
;Data for subroutine ALL_MACHINES_FREE
;--------------------------------
ret_addr_3 .FILL x0
BUSYNESS_ADDR_ALL_MACHINES_FREE .Fill xD000
num_dec_16_2 .FILL #16
;-----------------------------------------------------------------------------------------------------------------
; Subroutine: NUM_BUSY_MACHINES
; Inputs: None
; Postcondition: The subroutine has returned the number of busy machines.
; Return Value (R2): The number of machines that are busy
;-----------------------------------------------------------------------------------------------------------------
;-------------------------------
;INSERT CODE For Subroutine NUM_BUSY_MACHINES
;--------------------------------
.ORIG x3800
;HINT back up
ST R7,ret_addr_4
 LD R6,BUSYNESS_ADDR_NUM_BUSY_MACHINES
 LDR R1,R6,#0
 LD R3,num_dec_16_3
 AND R2,R2,#0
DO_WHILE_LOOP_4
 ADD R1,R1,#0
 BRzp END_DO_WHILE_LOOP_5
DO_WHILE_LOOP_5
 ADD R1,R1,R1
 ADD R3,R3,#-1
 BRp DO_WHILE_LOOP_4
 BRnzp END_DO_WHILE_LOOP_4
END_DO_WHILE_LOOP_5
 ADD R2,R2,#1
 BRnzp DO_WHILE_LOOP_5
END_DO_WHILE_LOOP_4
;HINT Restore
 LD R7, ret_addr_4
 RET
;--------------------------------
;Data for subroutine NUM_BUSY_MACHINES
;--------------------------------
ret_addr_4 .FILL x0
BUSYNESS_ADDR_NUM_BUSY_MACHINES .Fill xD000
num_dec_16_3 .FILL #16
;-----------------------------------------------------------------------------------------------------------------
; Subroutine: NUM_FREE_MACHINES
; Inputs: None
; Postcondition: The subroutine has returned the number of free machines
; Return Value (R2): The number of machines that are free 
;-----------------------------------------------------------------------------------------------------------------
;-------------------------------
;INSERT CODE For Subroutine NUM_FREE_MACHINES
;--------------------------------
.ORIG x4000
;HINT back up
 ST R7,return_address5
 LD R6,BUSYNESS_ADDR_NUM_FREE_MACHINES
 LDR R1,R6,#0
 LD R3,num_dec_16_4
 AND R2,R2,#0
DO_WHILE_LOOP_6
 ADD R1,R1,#0
 BRn END_DO_WHILE_LOOP_7
DO_WHILE_LOOP_7
 ADD R1,R1,R1
 ADD R3,R3,#-1
 BRp DO_WHILE_LOOP_6
 BRnzp END_DO_WHILE_LOOP_6
END_DO_WHILE_LOOP_7
 ADD R2,R2,#1
 BRnzp DO_WHILE_LOOP_7
END_DO_WHILE_LOOP_6
;HINT Restore
 LD R7, return_address5
 RET
;--------------------------------
;Data for subroutine NUM_FREE_MACHINES
;--------------------------------
return_address5 .FILL x0
BUSYNESS_ADDR_NUM_FREE_MACHINES .Fill xD000
num_dec_16_4 .FILL #16
;-----------------------------------------------------------------------------------------------------------------
; Subroutine: MACHINE_STATUS
; Input (R1): Which machine to check
; Postcondition: The subroutine has returned a value indicating whether the machine indicated
;by (R1) is busy or not.
; Return Value (R2): 0 if machine (R1) is busy, 1 if it is free
;-----------------------------------------------------------------------------------------------------------------
;-------------------------------
;INSERT CODE For Subroutine MACHINE_STATUS
;--------------------------------
.ORIG x4200
;HINT back up
ST R7,return_address6
 ADD R6,R1,#0
 LD R4,num_dec_15_1
 NOT R6,R6
 ADD R6,R6,#1
 ADD R4,R4,R6
 LD R6,BUSYNESS_ADDR_MACHINE_STATUS
 LDR R2,R6,#0
 ADD R4,R4,#0
 BRz DO_WHILE_LOOP_9
DO_WHILE_LOOP_8
 ADD R2,R2,R2 
 ADD R4,R4,#-1
 BRp DO_WHILE_LOOP_8
DO_WHILE_LOOP_9
 ADD R2,R2,#0
 BRzp END_DO_WHILE_LOOP_9
 AND R2,R2,#0
 ADD R2,R2,#1
 BRnzp END_DO_WHILE_LOOP_8
END_DO_WHILE_LOOP_9
 AND R2,R2,#0
END_DO_WHILE_LOOP_8
;HINT Restore
 AND R3,R3,#0
 AND R4,R4,#0
 AND R6,R6,#0
 LD R7,return_address6
 RET
;--------------------------------
;Data for subroutine MACHINE_STATUS
;--------------------------------
return_address6 .FILL x0
BUSYNESS_ADDR_MACHINE_STATUS.Fill xD000
num_dec_15_1 .FILL #15
;-----------------------------------------------------------------------------------------------------------------
; Subroutine: FIRST_FREE
; Inputs: None
; Postcondition: 
; The subroutine has returned a value indicating the lowest numbered free machine
; Return Value (R2): the number of the free machine
;-----------------------------------------------------------------------------------------------------------------
;-------------------------------
;INSERT CODE For Subroutine FIRST_FREE
;--------------------------------
.ORIG x4400
;HINT back up 
 ST R7,return_address7
 LD R6,BUSYNESS_ADDR_FIRST_FREE
 LDR R1,R6,#0
 AND R2,R2,#0
 AND R3,R3,#0 
 ADD R3,R3,#15
DO_WHILE_LOOP_10
 ADD R3,R3,#0  
 BRz DO_WHILE_LOOP_11
 ADD R1,R1,R1
 ADD R3,R3,#-1
 BRp DO_WHILE_LOOP_10
DO_WHILE_LOOP_11 
 ADD R1,R1,#0
 BRn END_DO_WHILE_LOOP_10
 ADD R2,R2,#1
 AND R3,R3,#0
 ADD R3,R3,#15
 NOT R7,R2
 ADD R7,R7,#1
 ADD R3,R3,R7
 ADD R7,R2,#-16
 BRz END_DO_WHILE_LOOP_10
 LDR R1,R6,#0
 BRnzp DO_WHILE_LOOP_10
END_DO_WHILE_LOOP_10
;HINT Restore
 LD R7,return_address7
 RET
;--------------------------------
;Data for subroutine FIRST_FREE
;--------------------------------
return_address7 .FILL x0
BUSYNESS_ADDR_FIRST_FREE .Fill xD000
;-----------------------------------------------------------------------------------------------------------------
; Subroutine: Get input
; Inputs: None
; Postcondition: 
; The subroutine get up to a 5 digit input from the user within the range [-32768,32767]
; Return Value (R1): The value of the contructed input
; NOTE: This subroutine should be the same as the one that you did in assignment 5
; to get input from the user, except the prompt is different.
;-----------------------------------------------------------------------------------------------------------------
;-------------------------------
;INSERT CODE For Subroutine 
;--------------------------------
.ORIG x4600
ST R7,return_address8
DO_WHILE_LOOP_12
 LEA R0,prompt  
 TRAP x22
 LD R6,num_dec_6_1
 AND R5,R5,#0
 AND R4,R4,#0
 AND R3,R3,#0
DO_WHILE_LOOP_13
 TRAP x20
 ADD R1,R0,#0
 LD R7,num_dec_newline
 NOT R7, R7
 ADD R1,R1,R7
 BRnp DO_WHILE_LOOP_14
DO_WHILE_LOOP_15
 ADD R1,R0,#0
 LD R7,num_dec_48_1
 ADD R1,R1,R7
 BRn DO_WHILE_LOOP_16
 ADD R1,R0,#0
 LD R7,num_dec_57_1
 ADD R1,R1,R7
 BRp DO_WHILE_LOOP_17
 ADD R1,R6,#0
 ADD R1,R1,#-6
 BRz DO_WHILE_LOOP_18
 ADD R5,R5,R5
 ADD R7,R5,R5
 ADD R7,R7,R7
 ADD R5,R5,R7
 LD R7,num_dec_48_1
 ADD R0,R0,R7
 ADD R5,R5,R0
 ADD R6,R6,#-1
 BRp DO_WHILE_LOOP_13
 BRz DO_WHILE_LOOP_19
DO_WHILE_LOOP_14
 TRAP x21
 BRnzp DO_WHILE_LOOP_15
DO_WHILE_LOOP_20
 LD R0,num_dec_newline
 TRAP x21
 BRnzp DO_WHILE_LOOP_21
DO_WHILE_LOOP_22
 NOT R5,R5
 ADD R5,R5,#1
 BRnzp DO_WHILE_LOOP_23
DO_WHILE_LOOP_18
 LD R7,num_dec_48_1
 ADD R0,R0,R7
 ADD R5,R0,R5
 ADD R6,R6,#-2
 BRnzp DO_WHILE_LOOP_13
DO_WHILE_LOOP_24
 ADD R1,R6,#0
 ADD R1,R1,#-6
 BRz DO_WHILE_LOOP_20
 ADD R1,R6,#0
 ADD R1,R1,#-5
 BRnp DO_WHILE_LOOP_19
 ADD R1,R3,#0
 ADD R1,R1,#-1
 BRz DO_WHILE_LOOP_20
 BRnp DO_WHILE_LOOP_19
DO_WHILE_LOOP_25
 ADD R1,R6,#0
 ADD R1,R1,#-6
 BRnp DO_WHILE_LOOP_17
 ADD R4,R4,#0
 ADD R3,R3,#1
 ADD R6,R6,#-1
 BRnzp DO_WHILE_LOOP_13
DO_WHILE_LOOP_26
 ADD R1,R6,#0
 ADD R1,R1,#-6
 BRnp DO_WHILE_LOOP_17
 ADD R4,R4,#1
 ADD R3,R3,#1
 ADD R6,R6,#-1
 BRnzp DO_WHILE_LOOP_13
DO_WHILE_LOOP_16
 LD R7,num_dec_plus
 ADD R1,R0,#01
 ADD R1,R1,R7
 BRz DO_WHILE_LOOP_25
 LD R7,num_dec_neg
 ADD R1,R0,#0
 ADD R1,R1,R7
 BRz DO_WHILE_LOOP_26
 LD R7,num_dec_newline
 NOT R7, R7
 ADD R1,R0,#01
 ADD R1,R1,R7
 BRz DO_WHILE_LOOP_24
DO_WHILE_LOOP_17
 ADD R1,R0,#0
 ADD R1,R1,#-10
 BRnp DO_WHILE_LOOP_20
DO_WHILE_LOOP_21 
 LEA R0,Error_message_2
 TRAP x22
 BRnzp DO_WHILE_LOOP_12
DO_WHILE_LOOP_19
 ADD R1,R4,#0
 ADD R1,R1,#-1
 BRz DO_WHILE_LOOP_22
DO_WHILE_LOOP_23
 LD R0,num_dec_newline
 TRAP x21
 ADD R1,R5,#0
 ADD R1,R1,#0
 BRn DO_WHILE_LOOP_21
 ADD R2,R1,#-15
 BRp DO_WHILE_LOOP_21
 LD R7,return_address8
 RET
;--------------------------------
;Data for subroutine Get input
;--------------------------------
return_address8 .FILL x0
num_dec_neg .FILL #-45
num_dec_plus .FILL #-43
num_dec_newline .FILL #10
num_dec_57_1 .FILL #-57
num_dec_48_1 .FILL #-48
num_dec_6_1  .FILL #6
prompt .STRINGZ "Enter which machine you want the status of (0 - 15), followed by ENTER: "
Error_message_2 .STRINGZ "ERROR INVALID INPUT\n"
;-----------------------------------------------------------------------------------------------------------------
; Subroutine: print number
; Inputs: 
; Postcondition: 
; The subroutine prints the number that is in 
; Return Value : 
; NOTE: This subroutine should print the number to the user WITHOUT 
;  leading 0's and DOES NOT output the '+' for positive numbers.
;-----------------------------------------------------------------------------------------------------------------
;-------------------------------
;INSERT CODE For Subroutine 
;--------------------------------
.ORIG x4800
ST R7,return_address9
 ADD R5,R2,#0 
 AND R2,R2,#0
 ADD R6,R5,#0
DO_WHILE_LOOP_27
 LD R1,num_dec_10k_1
 ADD R5,R1,R5
 BRzp DO_WHILE_LOOP_30
 LD R0,num_dec_48_2
 ADD R0,R2,R0
 ADD R2,R2,#0
 BRz DO_WHILE_LOOP_28
 TRAP x21
DO_WHILE_LOOP_28
 ADD R5,R6,#0
 AND R2,R2,#0
 BRnzp DO_WHILE_LOOP_29
DO_WHILE_LOOP_30
 ADD R6,R5,#0
 ADD R2,R2,#1
 BRnzp DO_WHILE_LOOP_31
DO_WHILE_LOOP_29
 LD R1,num_dec_1k_1
 ADD R5,R1,R5
 BRzp DO_WHILE_LOOP_32
 LD R0,num_dec_48_2
 ADD R0,R2,R0
 ADD R2,R2,#0
 BRz DO_WHILE_LOOP_33
 TRAP x21
DO_WHILE_LOOP_33
 ADD R5,R6,#0
 AND R2,R2,#0
 BRnzp DO_WHILE_LOOP_31
DO_WHILE_LOOP_32
 ADD R6,R5,#0
 ADD R2,R2,#1
 BRnzp DO_WHILE_LOOP_29
DO_WHILE_LOOP_31
 LD R1,num_dec_100_1
 ADD R5,R1,R5
 BRzp DO_WHILE_LOOP_34
 LD R0,num_dec_48_2
 ADD R0,R2,R0
 ADD R2,R2,#0
 BRz DO_WHILE_LOOP_35
 TRAP x21
DO_WHILE_LOOP_35
 ADD R5,R6,#0
 AND R2,R2,#0
 BRnzp DO_WHILE_LOOP_36
DO_WHILE_LOOP_34
 ADD R6,R5,#0
 ADD R2,R2,#1
 BRnzp DO_WHILE_LOOP_31
DO_WHILE_LOOP_36
 LD R1,num_dec_10_1
 ADD R5,R1,R5
 BRzp DO_WHILE_LOOP_37
 LD R0,num_dec_48_2
 ADD R0,R2,R0
 ADD R2,R2,#0
 BRz DO_WHILE_LOOP_38
 TRAP x21
DO_WHILE_LOOP_38
 ADD R5,R6,#0
 AND R2,R2,#0
 BRnzp DO_WHILE_LOOP_39
DO_WHILE_LOOP_37
 ADD R6,R5,#0
 ADD R2,R2,#1
 BRnzp DO_WHILE_LOOP_36
DO_WHILE_LOOP_39
 LD R1,num_dec_1_1
 ADD R5,R1,R5
 BRzp DO_WHILE_LOOP_40
 LD R0,num_dec_48_2
 ADD R0,R2,R0
 TRAP x21
 ADD R5,R6,#0
 AND R2,R2,#0
 BRnzp DO_WHILE_LOOP_41
DO_WHILE_LOOP_40
 ADD R6,R5,#0
 ADD R2,R2,#1
 BRnzp DO_WHILE_LOOP_39
DO_WHILE_LOOP_41
 LD R7,return_address9
 RET
;--------------------------------
;Data for subroutine print number
;--------------------------------
 return_address9 .FILL x0
 num_dec_48_2  .FILL #48
 num_dec_10k_1 .FILL #-10000
 num_dec_1k_1 .FILL #-1000
 num_dec_100_1  .FILL #-100
 num_dec_10_1  .FILL #-10
 num_dec_1_1  .FILL #-1
.ORIG x6000
MENUSTRING .STRINGZ "**********************\n* The Busyness Server *\n**********************\n1. Check to see whether all machines are busy\n2. Check to see whether all machines are free\n3. Report the number of busy machines\n4. Report the number of free machines\n5. Report the status of machine n\n6. Report the number of the first available machine\n7. Quit\n"
.ORIG xD000   ; Remote data
BUSYNESS .FILL xABCD  ; <----!!!VALUE FOR BUSYNESS VECTOR!!!
;--------------- 
;END of PROGRAM
;--------------- 
.END