#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void start_calculator();
int get_input(char str[], char *opr, int *num1, int *num2);
int doit(int f(), int first_number, int second_number);
int add(int num1, int num2);
int sub(int num1, int num2);
int multiply(int num1, int num2);
int divide(int num1, int num2);
int modulo(int num1, int num2);
int power(int num1, int num2);

int take_grades(int arr[]);
int take_exam_grades(int arr[]);
double calculate_homework(int arr[]);
double calculate_lab(int arr[]);
double calculate_all(double avg_hw, int exams[], double avg_lab);

void draw_pattern(int n);

int main() {

	int input, height_input, lab[10], homework[10], exams[2];
	double hw_avg, lab_avg, grade;

	do {

		printf("\n***** MENU *****\n");
		printf("1. Start calculator\n");
		printf("2. Calculate grades\n");
		printf("3. Draw pattern\n");
		printf("4. Exit\n\n");

		scanf("%d", &input);
		printf("\n");

		switch(input) {
			case 1:
				start_calculator();
			break;
			case 2:
				printf("Lab Grades\n");
				take_grades(lab);
				printf("Homework Grades\n");
				take_grades(homework);
				take_exam_grades(exams);
		
				hw_avg = calculate_homework(homework);
				printf("%f\n", hw_avg);
				lab_avg = calculate_lab(lab);
				printf("%f\n", lab_avg);
				grade = calculate_all(hw_avg, exams, lab_avg);

				printf("Weighted Grade: %f\n", grade);
			break;
			case 3:
				do {
					printf("Height can only be positive integer!\n");
					printf("Enter height = ");
					scanf("%d", &height_input);
					printf("\n");
				} while(height_input <= 0);
				draw_pattern(height_input);
			break;
			case 4:
				printf("Exiting...\n");
			break;
			default:
				printf("Error\n");
			break;
		}

	} while(input != 4);

}

/**
 * @brief Starts the calculator program.
 *  	  Takes inputs in correct format and proceeds,
 *			If not correct format, display warning and don't take input.
 *		  
 * 		  User can exit the program by enterin 'q' or 'Q'
 */
void start_calculator() {

	char input[80], opr;
	int flag, running = 1, num1, num2, res = 0, first_run = 1;

	printf("\nEnter input in formats of:\n");
	printf("(Operation)(Operand1)(Operand2) or\n(Operation)(Operand1)\n");
	printf("Enter \'q\' or \'Q\' to exit the calculator.\n\n");

	while(running) {

		fgets(input, 80, stdin);
		if(input[0] == 'Q' || input[0] == 'q') running = 0;		

		flag = get_input(input, &opr, &num1, &num2);
		while(!flag && running) {
			if(!first_run) printf("Wrong input\n");
			first_run = 0;
			fgets(input, 80, stdin);
			if(input[0] == 'Q' || input[0] == 'q') running = 0;		
			flag = get_input(input, &opr, &num1, &num2);
		}

		if(running) {
			switch(opr) {
				case '+':
					if(flag == 2) res = doit(add, num1, num2);
					else res = doit(add, res, num1);
				break;
				case '-':
					if(flag == 2) res = doit(sub, num1, num2);
					else res = doit(sub, res, num1);
				break;
				case '/':
					if(flag == 2 && num2 != 0) res = doit(divide, num1, num2);
					else if(flag == 1 && num1 != 0)res = doit(divide, res, num1);	
					else printf("Can't divide by zero!\n");
				break;
				case '*':
					if(flag == 2) res = doit(multiply, num1, num2);
					else res = doit(multiply, res, num1);
				break;
				case '^':
					if(flag == 2) res = doit(power, num1, num2);
					else res = doit(power, res, num1);
				break;
				case '%':
					if(flag == 2) res = doit(modulo, num1, num2);
					else res = doit(modulo, res, num1);
				break;
				default:
					/* There is no way that user can break the program */
				break;
			}

			printf("%d\n", res);	
		}
		
	}
}

/**
 * @brief Fills the passed array with user input.
 * @param Integer array with size of 10.
 */
int take_grades(int arr[]) {
	int i, input;

	for(i = 0; i < 10; i++) {
		printf("Enter %d. grade:", i+1);
		scanf("%d", &input);
		arr[i] = input;
	}
}

/**
 * @brief Fills the passed array with user input.
 * @param Integer array with size of 2.
 */
int take_exam_grades(int arr[]) {
	int input;

	printf("Enter midterm:");
	scanf("%d", &input);
	arr[0] = input;
	printf("Enter final:");
	scanf("%d", &input);
	arr[1] = input;
}

/**
 * @brief Calculates the average of passed array.
 * @param Integer array with size of 10.
 * @return Average of passed array as double.
 */
double calculate_homework(int arr[]) {
	int i;
	double rtr = 0.0;

	for(i = 0; i < 10; i++) {
		rtr += arr[i];
	}

	return rtr / 10;
}

/**
 * @brief Calculates the average of passed array.
 * @param Integer array with size of 10.
 * @return Average of passed array as double.
 */
double calculate_lab(int arr[]) {
	int i;
	double rtr = 0.0;

	for(i = 0; i < 10; i++) {
		rtr += arr[i];
	}

	return rtr / 10;
}

/**
 * @brief Calculates the weighted grades according to lab and homework grades;
 *			%10 hw, %20 lab, %30 midterm, %40 final.
 * @param Integer array with size of 2 representing midterm and final.
 *		  Double representing the average of homeworks
 *		  Double representing the average of labs
 * @return Weighted grade as double.
 */
double calculate_all(double avg_hw, int exams[], double avg_lab) {
	double rtr = 0;
	rtr += avg_hw * 10 / 100;
	rtr += avg_lab * 20 / 100;
	rtr += exams[0] * 30 / 100;
	rtr += exams[1] * 40 / 100;

	return rtr;
}

/**
 * @brief Draws a special diamond pattern.
 *			Draw 2*n times rows,
 *			Treat the pattern as middle, upper, lower while drawing
 *			Increment/Decrement the spacing or stars accordingly
 * @param Positive integer.
 */
void draw_pattern(int n) {
	int rows = n * 2, blanks = n - 1, stars = 0, i, j;
	
	for(i = 0; i < rows; i++) {

		for(j = 0; j < blanks; j++) { /* Print blanks */
			printf(" ");
		}

		if(i < rows / 2) { /* Upper part */
			printf("/");
		} else { 		   /* Lower part */
			printf("\\");
		}

		for(j = 0; j < stars; j++) { /* Print stars */
			printf("*");
		}

		if(i < rows / 2) { /* Upper part */
			printf("\\\n");
			if(i != rows / 2 - 1) { /* Middle rows */
				blanks--;
				stars += 2;	
			}
		} else { 		   /* Lower part */
			printf("/\n");
			blanks++;
			stars -= 2;
		}

	}
}

/**
 * @brief Makes analysis of the input.
 *			Finds out if input is in wanted format.
 * @param Input represented as a string.
 *		  3 output parameters:.
 *		   	Operatian sign represented as char.
 *		  	Operand 1 represented as integer.
 *	 		Operand 2 represented as integer.
 * @return Return 2 if there exists 2 operands.
 *		   Return 1 if there exists 1 operand.
 *		   Return 0 if input is in wrong format.
 */
int get_input(char str[], char *opr, int *num1, int *num2) {

	char *token = strtok(str, " ");
	int tokenCounter = 1;

	if(!strspn(str, "0123456789+-/%*")) return 0;

	if(strlen(token) == 2) {
		*opr = '^';

	} else {
		*opr = *token;

	}
	
	if(strcmp(token, "+") != 0 &&
		strcmp(token, "-") != 0 &&
		strcmp(token, "/") != 0 &&
		strcmp(token, "*") != 0 &&
		strcmp(token, "**") != 0 &&
		strcmp(token, "%") != 0) {
		return 0;

	} else {
		if(strlen(token) == 2) {
			*opr = '^';

		} else {
			*opr = *token;

		}	

	}

	token = strtok(NULL, " ");
	if(!strspn(token, "-0123456789")) {
		return 0;

	} else {
		*num1 = atoi(token);

	}

	token = strtok(NULL, " ");
	if(token == NULL || !strspn(token, "-0123456789")) {
		/* Do nothing */

	} else {
		*num2 = atoi(token);
		return 2;

	}

	token = strtok(NULL, " ");
	if(token != NULL) {
		return 0;

	}

	return 1;
}

int doit(int f(), int first_number, int second_number) {
	return f(first_number, second_number);
}

int add(int num1, int num2) {
	return num1 + num2;
}

int sub(int num1, int num2) {
	return num1 - num2;
}

int multiply(int num1, int num2) {
	return num1 * num2;
}

int divide(int num1, int num2) {
	return num1 / num2;
}

int modulo(int num1, int num2) {
	return num1 % num2;
}

int power(int num1, int num2) {
	int rtr = 1, i;
	if(num2 < 0) return 0;
	for(i = 0; i < num2; i++) {
		rtr *= num1;
	}
	return rtr;
}
