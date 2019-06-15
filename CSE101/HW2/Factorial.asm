LOAD R1, 4					;Number to calculate factorial
LOAD RE, -1					;Logic negative one
LOAD RD, 1					;Logic one
LOAD RC, 0					;Logic zero
addi R2,R1,RE					;Second operand for factorial

LOAD RB, 0					;Temp value
LOAD R6, 10					;For division
LOAD R7, 100					;For division
LOAD R9, 48d					;For display

LOAD R0, 0					;Set R0 for input checking

start:						;Input checking
jmpLE R1<=R0, error				;If input less than 0 display error
LOAD R0, 5					;Set R0 for input checking
jmpLE R1<=R0, factorial				;If input less than 5 start the factorial operation
jmp error					;Else display error

error:						;Error displaying
load R1,errText
load R2,1
load R0,0

NextCharacter:					;Error message writing
load RF,[R1]
addi R1,R1,R2
jmpEQ RF=R0, EndProgram
jmp NextCharacter

EndProgram:					;After error end program
halt

org 60h
errText: db 10					;Error text
	db "Please enter between 0 and 6" ,10
	db 0	


factorial:					;Start of factorial operation
MOVE R0,R2					;Move second operand for comparison
MOVE R3,R1					;Duplicate input for adding same each time
jmpEQ RC = R0, display   			;End condition is 2nd operand = 0
jmp multiply					;Loop

multiply:					;Basic multiplication
jmpEQ RD = R0, middle				;End condition 2nd operand(R0) = 1
addi R1,R1,R3					;Adding for multiplication operation
addi R0,R0,RE					;Decrease 2nd operand by 1
jmp multiply					;Loop

middle: 					;Used to seperate multiplication's 2nd operand from factorial's 2nd operand
addi R2,R2,RE 					;Decrease 2nd operand of factorial by 1 				
jmp factorial					;Pass it to factorial

display:					;Validate the results digits
LOAD R0, 10
jmpLE R1<=R0, oneDigit				;If one digit
LOAD R0, 100
jmpLE R1<=R0, twoDigit				;If two digit
MOVE R0, R1
jmp threeDigit					;If three digit

oneDigit:
addi RF,R1,R9					;Only convert to ASCII and display
halt						;END PROGRAM 

twoDigit: 					;This section displays the first digit of a 2 digit number
addi RB,RB,R6					;Count 10 by 10
addi R8,R8,RD					;Result of division
MOVE R0,R1					;Put limit number to R0
jmpLE RB<=R0, twoDigit  			;Loop condition
addi R8,R8,RE					;0 is counted too so we substract 1
LOAD R6, -10					;Temporary -10
addi RB,RB,R6					;Counting exceeded by 10 so we substract 10
addi RF,R8,R9					;Convert to ASCII and display
LOAD R6, 10					;Reset the R6
LOAD R8, 0					;Reset the result R8
jmp twoDigitContd				;Continue to write last digit

twoDigitContd: 					;This section displays the second digit of a 2 digit number
addi RB,RB,RD					;Count 1 by 1 
addi R8,R8,RD					;Result of mod operation
jmpLE RB <= R0, twoDigitContd			;Loop condition
addi R8,R8,RE					;1 exceeded so we substract 1
addi RA,R8,R9					;Convert to ASCII
MOVE RF,RA					;Displyar the last digit
halt						;END PROGRAM

threeDigit:					;This section displays the first digit of a 3 digit number
addi RB,RB,R7					;Count 100 by 100
addi R8,R8,R6					;Result of division
jmpLE RB <= R0, threeDigit			;Loop condition
addi R8,R8,RD					;1 exceeded so we substract 1
addi RA,R8,R9					;Convert to ASCII
addi RF,RD,R9					;Display the first digit
LOAD RB, 100					;Reset RB
LOAD R8, 0					;Reset the result R8
jmp threeDigitContd				;Proceed to displaying other digits

threeDigitContd:				;This section displays the second and third digit of a 3 digit number
addi RB,RB,RD					;Count 1 by 1 from 100 to the number
addi R8,R8,R6					;Result of mod operation
jmpLE RB <= R0, threeDigitContd			;Loop condition
addi R8,R8,RD					;1 exceeded so we substract 1
addi RA,R8,R9					;Convert to ASCII
addi RD,RD,RD					;Display the second digit of number
addi RF,RD,R9					;Convert to ASCII
addi RF,RC,R9					;Display the third digit of number
halt						;END PROGRAM


