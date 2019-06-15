#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define LUCKYNUMBER_MENU 1
#define HOURGLASS_MENU 2
#define MOUNTAINROAD_MENU 3
#define EXIT_MENU 4

#define TRIAL 10

void menu();
void start_ln_game(int *score_human, int *score_program);
int make_a_guess (int trial, int min, int max);
void show_scores(int score_human, int score_program);
void draw_hourglass(int height);
void draw_mountain_road(int length, int max_radius);

int main() {

	menu();

}

/**
 * @brief Prints and contains menu info to user.
 *		  Stores the scores for lucky number game.
 *		  When launching the features of program,
 *			Gets the necessary inputs for related feature.
 *			Does the input checks for related feature.
 */
void menu() {

	int menu_input, input_1, input_2, score_human = 0, score_program = 0;

	srand(time(NULL));

	do {

		printf("***** MENU *****\n");
		printf("1. Play Lucky Number\n");
		printf("2. Draw Hourglass\n");
		printf("3. Draw Mountain Road\n");
		printf("4. Exit\n");

		printf("Choice: ");
		scanf("%d", &menu_input);
		printf("\n");

		switch(menu_input) {

			case LUCKYNUMBER_MENU:
				start_ln_game(&score_human, &score_program);
			break;

			case HOURGLASS_MENU:
				do {
					printf("Height can only be odd positive numbers.\n");
					printf("Enter Height = ");
					scanf("%d", &input_1);
					printf("\n");
				} while(input_1 % 2 == 0 || input_1 < 0);

				draw_hourglass(input_1);
			break;

			case MOUNTAINROAD_MENU:
				do {
					printf("Length and max radius can be 0 or a positive number\n");
					printf("Enter Length and max radius = ");
					scanf("%d %d", &input_1, &input_2);
					printf("\n");
				} while(input_1 < 0 || input_2 < 0);

				draw_mountain_road(input_1, input_2);
			break;

			default:
				printf("Please enter a valid selection!\n");
			break;

		}

		printf("\n");

	} while(menu_input != EXIT_MENU);

}

/**
 * @brief Starts the lucky number game.
 *		  Function runs until the player loses or wins.
 * @param Both of them are pointer to integer variables.
 */
void start_ln_game(int *score_human, int *score_program) {

	int tries = 0, min = 1, max = 1024, gn ,distance;
	int	ln = (rand() % 1024) + 1;

	while(tries < TRIAL && gn != ln) {

		gn = make_a_guess(tries, min, max);

		if(gn > ln && gn < max) {
			max = gn;

		} else if(gn < ln && gn > min) {
			min = gn;

		}

		distance = (log(abs(ln - gn)) / log(2)) + 1;
		if(distance < 0) {
			distance = 0;
		}
		printf("Distance: %d \n\n", distance);

		tries++;

	}

	if(tries <= TRIAL && gn == ln) {
		printf("You win!\n");
		(*score_human)++;

	} else {
		printf("You lose!\n");
		(*score_program)++;

	}

	printf("Lucky number %d\n", ln);

	show_scores(*score_human, *score_program);

}

/**
 * @brief Gets a integer from user.
 *		  Prints an information message to user.
 *		   Catches user faults for case like:
 *		   If input is not in range, don't take the users try.
 * @param "min" specifies lower bound of interval.
 *		  "max" specifies upper bound of interval.
 *		  "trial" is used for information message.
 * @return The desired user input between specified range.			
 */
int make_a_guess (int trial, int min, int max) {

	int gn, firstTry = 1;

	do {
		if(!firstTry) {
			printf("\nI don't wanna take your limited tries for silly inputs...\n");
			printf("Please enter a num between the specified range!\n\n");

		} 

		printf("(Trial: %d) Make a guess between %d and %d: ", trial+1, min, max);
		scanf("%d", &gn);
		firstTry = 0;	

	} while(gn >= max || gn <= min);
	
	return gn;

}

/**
 * @brief Shows the score information to user.
 * @param Users score as integer and computers score as integer.
 */
void show_scores(int score_human, int score_program) {

	printf("Your Score: %d Program Score: %d\n", score_human, score_program);

}

/**
 * @brief Prints hourglass pattern.
 * @param Is an positive integer argument.
 */
void draw_hourglass(int height) {

	int i, j, blanks = 0, stars = height;

	for(i = 0; i < height; i++) {		/* Rows */

		for(j = 0; j < blanks; j++) { 	/* Print blanks */
			printf(" ");
		}

		for(j = 0; j < stars; j++) {	/* Print stars */
			printf("*");
		}

		if(i < height / 2) {			/* Upper half */
			blanks++;					/* Increase blanks for next row */
			stars -= 2;					/* Decrease stars for next row */
		} else {						/* Lower half - vice versa */
			blanks--;					
			stars += 2;
		}

		printf("\n");					/* End current row */

	}

}

/**
 * @brief Prints mountain road pattern.
 *		   There will be length times half circles in total.
 *		   Half circles will go zig-zag pattern.
 *		   Half circles radius will be determined randomly.
 * @param Length determines the length of road is an integer.
 *		  Max_Radius specifies the maximum radius that a circle can have.
 *		   Max_Radius can be zero, in that case just draw a line.
 */
void draw_mountain_road(int length, int max_radius) {

	int i, j, k, blanks, rows, radius;

	for(i = 0; i < length; i++) { /* Half Circles Loop */

		if(max_radius != 0) {   /* Random radius 1,2,3,...,max_radius */
			radius = (rand() % max_radius) + 1;	
		} else { 				/* If max R is zero then just print a line */
			radius = 0;
			blanks = 0;
		}

		/* Initialize rows using current random radius */
		rows = (2 * radius) + 1;

		/* Initialize blanks */
		if(i == 0) {							
			blanks = max_radius;
		}

		/* Half Circles individual rows loop */
		for(j = 0; j < rows; j++) {				

			for(k = 0; k < blanks; k++) { /* Spacing from start */
				printf(" ");
			}

			if(i % 2 == 0) { /* Even indexed half circles goes left */

				if(j < rows / 2) { /* upper */
					printf("/");
					blanks--;
				} else if((float)j == rows / 2) { /* middle */
					printf("|");
					blanks++;
				} else { /* lower */
					printf("\\");
					blanks++;
				}

			} else { /* Odd indexed half circles goes right */

				if(j < rows / 2) { /* upper */
					printf("\\");
					blanks++;
				} else if((float)j == rows / 2) { /* middle */
					printf("|");
					blanks--;
				} else { /* lower */
					printf("/");
					blanks--;
				}

			}

			/* go to next row */
			printf("\n");
		}				/* End of j loop (rows for each circles loop)*/

	} /* End of i loop (half circles loop) */

}
