/* THIS PROGRAM SORTS ARRAY DEMONSTRATION PURPOSES */
/* GTU RULEZ */
#include<stdio.h>
//NOTE BY 1801042669
//This header was not used by the provided program but included by the professor anyways
//#include <math.h>
#define TRUE 1
#define FALSE 0


int PrintSelection(int selection){
 printf("Selected Menu item is:");
 printf("%d\n",selection);
 return 1;
 
}

//IMPLEMENTED BY 1801042669
int Subtract(int a, int b) { 
	return a-b;
}

//IMPLEMENTED BY 1801042669
void Divide(double a, double b) {
	if(b == 0.0) {
		printf("CAN'T DIVIDE BY ZERO\n");
	} else {
		printf("The result is: %.6f", a / b);
	}
}

//IMPLEMENTED BY 1801042669
int Exponent(int a, int b) {
	int result = 1;
	if(a == 0) {					//If base is 0 
		if(b == 0) {				//And power is 0 return 1
			return 1;
		} 
		return 0;					//Other wise return 0
	} else if(b == 0) {					//If power is 0 return 1 
		return 1;
	} else if(b == 1) {				//If power is 1 return the base
		return a;
	} else {						//Do the operation loop
		for(int i = 1; i <= b; i++) {	//Multiply the num by it self
			result = result * a;		//For "power" times
		}
	}
	return result;					//Return the result
}

//IMPLEMENTED BY 1801042669
void Summarize(int n) {

	int digits[10], lengthOfN, copyOfN = n;
	//digits arrays size is 10 becaus largest integer can be 10 digit
	//lengthOfN will be the number of digits of n
	//copyOfN is needed since we will manipulate the n and need to restore it

	lengthOfN = 0; 
	while(n >= 1) { //Getting the length of n
		n = n / 10;
		lengthOfN++;
	}
	n = copyOfN;	//Restore n

	for(int i = 0; i < lengthOfN; i++) { //Fill the digits in to array
		digits[i] = n % 10;
		n = n / 10;
	}
	n = copyOfN;	//Restore n

	/* Since we filled the digits in to array starting from right
	   most digit, we should consider that while displaying the result.
	   If we input 1234, array should be 4321, so we should display
	   it reversely.
	*/

	printf("%d = ", n); //Start of result 
	for(int i = lengthOfN-1; i >= 0; i--) {	//Display result

		/* By iteration parameters we started the array from last digit
		   Let's assume input is 1234, so last digit in the array would
		   be 1, it's index would be 3, this way we can get the corres-
		   ponding "10's value" to that digit, in this case it's 10^3.	
		*/
		
		printf("%d x %d ", digits[i], Exponent(10,i));

		if(i != 0) { //Do we reach the end of result? if not insert "+ ".
			printf("+ ");
		}

	}

}

int DisplayMenu(){
 int selection;
 printf("\e[2J"); // clears screen
 
 printf("%s","\e[5;31;47mWELCOME TO ADDING PROGRAM\e[0m\n");
 printf("%s","(1) Add two numbers\n");
 printf("%s","(2) Sort an array\n");
 printf("%s","(3) Subtract two numbers\n");
 printf("%s","(4) Divide numbers\n");
 printf("%s","(5) Summarize numbers with words\n");
 printf("%s","(6) Exponent two numbers x to the y\n");
 printf("%s","(0) quit\n");
 printf("Selection:");	
 scanf("%d",&selection);
 PrintSelection(selection);
 return selection;
}

int main(){
int number1, number2, sum;
char wanttoexit = FALSE;
char c;
int choice;
int i,j;
int myArray[100];
int max;
int pivot;
int temp;

//IMPLEMENTED BY 1801042669
double dividend;
double divisor;

// main loop
while(wanttoexit == FALSE){

	// display menu and get result	
	choice = DisplayMenu();
	
	
	if(choice == 1){
		printf("%s","PLEASE  ENTER FIRST NUMBER\n");
		scanf("%d",&number1);
		printf("%s","PLEASE  ENTER SECOND NUMBER\n");
		scanf("%d",&number2);
		sum = number1 + number2;
		printf("The result is: ");
		printf("%d\n",sum);
		c=getchar();
		c=getchar();
	}
	if(choice == 2){
		printf("%s","Enter numbers for array and 0 for end\n");
		for(i=0;i<100;i++){
			scanf("%d",&choice);
			if(choice == 0) break;
			myArray[i] = choice;
			max = i ;
		}
		printf("Numbers are entered.. \n");
		printf("Now sorting.. ");
	    for(i=0;i<=max;i++){
	       for(j=0;j<max; j++){
	           if(myArray[j] > myArray[j+1]){
	           		temp = myArray[j];
	           		myArray[j]= myArray[j+1];
	           		myArray[j+1]=temp;
	           }
		    }
		    
		}
		printf("finished..\n ");
	    for(i=0;i<=max;i++){
	      printf("%d  ",myArray[i]);
	    }
	      printf("are the numbers.\n");
	        
		    
		c=getchar();
		c=getchar();
	}
	//IMPLEMENTED BY 1801042669
	if(choice == 3) {
		printf("%s","PLEASE  ENTER FIRST NUMBER\n");
		scanf("%d",&number1);
		printf("%s","PLEASE  ENTER SECOND NUMBER\n");
		scanf("%d",&number2);
		printf("The result is: %d", Subtract(number1,number2));
		c=getchar();
		c=getchar();
	}
	//IMPLEMENTED BY 1801042669
	if(choice == 4) {
		printf("%s","PLEASE  ENTER DIVIDEND NUMBER\n");
		scanf("%le",&dividend);
		printf("%s","PLEASE  ENTER DIVISOR NUMBER\n");
		scanf("%le",&divisor);
		Divide(dividend, divisor);
		c=getchar();
		c=getchar();
	}
	//IMPLEMENTED BY 1801042669
	if(choice == 5) {
		printf("%s","PLEASE  ENTER THE NUMBER\n");
		scanf("%d", &number1);
		printf("The result is: ");
		Summarize(number1);
		c=getchar();
		c=getchar();
	}
	//IMPLEMENTED BY 1801042669
	if(choice == 6) {
		printf("%s","PLEASE  ENTER BASE NUMBER\n");
		scanf("%d",&number1);
		printf("%s","PLEASE  ENTER EXPONENT NUMBER\n");
		scanf("%d",&number2);
		printf("The result is: %d", Exponent(number1,number2));
		c=getchar();
		c=getchar();
	}

	if(choice == 0){
		wanttoexit = TRUE;
		printf("exiting...");
	}
} // end of while

}
