LOAD R1,myString			;String to be reversed
LOAD R2,1				;Logic one
LOAD R0,0				;Logic zero
LOAD R3,0 				;Length counter
LOAD R4,-1				;Logic minus one

countChar:
LOAD R6,[R1]			;Count the given string
addi R1,R1,R2			;Start from first letter	
addi R3,R3,R2			;Length counter
jmpEQ R6=R0, fixLength		;Counting finished condition
jmp countChar			;Loop

fixLength:
LOAD R1, myString			;Reset the string
addi R1,R1,R3			;Reset the strings char pointer to the last char
LOAD R0, 10				;This time terminating condition will be 10
jmp reverseString			;Start reversing

reverseString:
LOAD RF,[R1]			;Reverse the string
addi R1,R1,R4			;Start from last letter and go backwards one by one
jmpEQ RF=R0, endProgram		;End condition 
jmp reverseString			;Loop

endProgram:	      
halt					;END PROGRAM

org 30h
myString:
db 10 
db "MERHABA DÜNYA 1 3 4@56_*/()" 
db 0	

