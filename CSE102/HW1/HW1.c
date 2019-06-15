#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3

#define SQUARE 11
#define RECTANGULAR 12
#define CIRCULAR 13

#define RED 0
#define YELLOW 1
#define BLUE 2
#define BLACK 3
#define WHITE 4

double CreateBody(int shape);
int SetColor(int color);
double LoadMoves(int shape, double body_size);
int SetAttackPower(int lower_bound, int upper_bound);
void ShowPokemon(int shape, double body_size, int color, double move_length, int attack_power);

int main() {
	
	int shape, color, attack_power;
	double size_of_body, move_length;

	/*Seed the random number generator with current time*/
	srand(time(NULL));

	/*CIRCULAR/RECTANGULAR/SQUARE*/
	shape = CIRCULAR; 

	size_of_body = CreateBody (shape);

	color = 798;
	color = SetColor(color);

	move_length = LoadMoves(shape, size_of_body);	

	attack_power = SetAttackPower (0, 150);
	
	ShowPokemon(shape, size_of_body, color, move_length, attack_power);
	
}

/*Get the shapes properties from user, calculate area and return it*/
double CreateBody(int shape) {

	double input1, input2, area;

	if(shape == SQUARE) { 			
		printf("Enter the length of one border:");
		scanf("%lf", &input1);
		area = input1 * input1;

	} else if(shape == RECTANGULAR) {		
		printf("Enter the length of long and short border:");
		scanf("%lf %lf", &input1, &input2);
		area = input1 * input2;

	} else if(shape == CIRCULAR) {		
		printf("Enter the radius:");
		scanf("%lf", &input1);
		area = PI * input1 * input1;

	} else {
		printf("Shape parameter can only be SQUARE, RECTANGULAR, CIRCULAR!\n");

	}

	return area;

}

/*Gets color, if it's in range of 0-1000 return mod 5, else return 1*/
int SetColor(int color) {

	int rtrColor;

	if(color > 0 && color < 1000) {
		rtrColor = color % 5;

	} else {
		rtrColor = 1;

	}

	return rtrColor;

}

/*Calculate and return perimeter of shape according to it's body size*/
/*If rectangle assume shorter edge is 5*/
double LoadMoves(int shape, double body_size) {
	
	/*edge is corresponding length according to shape*/
	double moves, edge;

	if(shape == SQUARE) { 			
		edge = sqrt(body_size);
		moves = 4 * edge;

	} else if(shape == RECTANGULAR) {		
		edge = body_size / 5;
		moves = (edge + 5) * 2;

	} else if(shape == CIRCULAR) {		
		edge = sqrt(body_size / PI);
		moves = 2 * PI * edge; 

	} else {
		printf("Shape parameter can only be SQUARE, RECTANGULAR, CIRCULAR!\n");

	}	

	return moves;

}

/*Return a random integer between specified range*/
int SetAttackPower(int lower_bound, int upper_bound) {

	int tmp, attackPower, difference;

	if(lower_bound > upper_bound) {			/*Error check, if lower is not really the lower, swap*/
		printf("In function SetAttackPower(), lower_bound > upper_bound, swapping...\n");
		tmp = lower_bound;
		lower_bound = upper_bound;
		upper_bound = tmp;

	} else if(lower_bound == upper_bound) {		/*Error check*/
		printf("In SetAttackPower() function, parameters shouldn't be same!\n");

	} 

	/*Used RAND_MAX from time.h, rand() function returns a value in between 0-RAND_MAX*/
	difference = upper_bound - lower_bound;
	attackPower = (int)(((float) rand() / RAND_MAX) * difference) + lower_bound;

	return attackPower;
	
}

/*Display the pokemons properties*/
void ShowPokemon(int shape, double body_size, int color, double
move_length, int attack_power) {

	int i, j, outerTab, innerTab, rows, isEvenRadius = 0;	/*Variables used for circular shape drawing*/
	double edge;											/*Current subjects related length (radius, edges..)*/

	printf("\n");

	if(shape == SQUARE) {
		edge = sqrt(body_size);

		for(i = 0; i < edge; i++) {
			for(j = 0; j < edge; j++) {
				printf("X");
			}
			printf("\n");
		}

		printf("\nName: Square Pokémon\n");

	} else if(shape == RECTANGULAR) {
		edge = body_size / 5;

		for(i = 0; i < 5; i++) {
			for(j = 0; j < edge; j++) {
				printf("X");
			}
			printf("\n");
		}

		printf("\nName: Rectangular Pokémon\n");

	} else if(shape == CIRCULAR) {
		edge = sqrt(body_size / PI);	/*Get radius by solving PI*r*r for r*/
		edge += 0.000001;				/*Prepare for casting*/
		
		rows = (int)edge;				/*Get the row as integer because radius was double*/
		outerTab = (rows - 1) / 2;		
		innerTab = 0;

		if(rows % 2 == 0) {				/*Radius is even*/
			rows++;						/*Rows number should be 1 more than radius*/
			isEvenRadius = 1;			/*Flag to tell we are dealing with even circular shape*/
		}

		/*
		**	ALGORITHM
		**	
		**	(outerTabs) means outerTabs times "\t"
		**	(innerTabs) means innerTabs times "\t"
		**	
		**	(outerTabs)(X)(innerTabs)(\n)			for odd circles first and last row
		**	(outerTabs)(    X    )(innerTabs)(\n)	for even circles first and last row 
		**	(outerTabs)(X)(innerTabs)(X)(\n)		for rest of the rows
		**	
		**	After every row loop; 
		**		
		**	If it's first half of the shape
		**	(outerTabs--) and (innerTabs += 2)
		**		
		**	If it's second half of the shape
		**	(outerTabs++) and (innerTabs -= 2)
		**	
		**	For special cases;
		**
		**	If it's even circle, after first row loop	
		**	(innerTabs++)
		**
		**	If it's even circle, after second from last row loop	
		**	(innerTabs--)
		**
		*/

		for(i = 0; i < rows; i++) {	
			for(j = 0; j < outerTab; j++) {
				printf("\t");

			}

			if(isEvenRadius == 1 && (i == 0 || i == rows - 1)) {	/*Even circles first or last row*/
				printf("    X    ");

			} else {
				printf("X");	

			}

			for(j = 0; j < innerTab; j++) {
				printf("\t");

			}
			
			if(i != 0 && i != rows - 1) {							/*If it is not first or last row put the second "X"*/
				printf("X");

			}

			if(i < (rows - 1) / 2) {								/*If it's upper half*/
				if(isEvenRadius == 1 && i == 0) {					/*Even circles first row*/
					innerTab++;

				} else {											
					outerTab--;
					innerTab += 2;	

				}
				
			} else {												/*If it's lower half*/
				if(isEvenRadius == 1 && i == rows - 2) {			/*Even circles second row from last*/
					innerTab--;

				} else {
					outerTab++;
					innerTab -= 2;	

				}
				
			}

			printf("\n");											/*Row ended*/			
			
		}

		printf("\nName: Circular Pokémon\n");

	} else {
		printf("Shape can only be SQUARE, RECTANGULAR, CIRCULAR!\n");

	}

	printf("Size: %f\n", body_size);

	if(SetColor(color) == RED) {
		printf("Color: Red\n");

	} else if(SetColor(color) == YELLOW) {
		printf("Color: Yellow\n");

	} else if(SetColor(color) == BLUE) {
		printf("Color: Blue\n");

	} else if(SetColor(color) == BLACK) {
		printf("Color: Black\n");		

	} else if(SetColor(color) == WHITE) {
		printf("Color: White\n");

	} else {
		printf("No such color from SetColor() function!\n");

	}

	printf("Move: %f\n", move_length);
	printf("Attack Power: %d\n", attack_power);

}
