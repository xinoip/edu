#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define x_limit 10
#define y_limit 10

void printErr() {
	printf("Error\n");
}

void print_the_grid(int x_pos_ant, int y_pos_ant, int x_pos_nest, int y_pos_nest) {

	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			if(x_pos_ant == i && y_pos_ant == j) {
				printf("X");
			} else if(x_pos_nest == i && y_pos_nest == j) {
				printf("O");
			} else {
				printf(".");
			}
			printf("   ");
		}
		printf("\n");
	}

}

int main() {

	srand(time(NULL));

	int nestX = rand() % x_limit + 1;
	int nestY = rand() % y_limit + 1;

	int playing = 1;
	int posX = 0, posY = 0;
	int input, distance = 0;

	print_the_grid(0,0,nestX, nestY);

	while(playing) {

		printf("Enter in:\n");
		scanf("%d", &input);

		switch(input) {
			case 1:
				if(posY - 1 >= 0 && posX + 1 < 10) {
					posY--;
					posX++;
					distance += 5;
				} else {
					printErr();
				}
			break;
			case 2:
				if(posX + 1 < 10) {
					posX++;
					distance += 4;
				} else {
					printErr();
				}
			break;
			case 3:
				if(posX + 1 < 10 && posY + 1 < 10) {
					posX++;
					posY++;
					distance += 5;
				} else {
					printErr();
				}
			break;
			case 4:
				if(posY - 1 >= 0) {
					posY--;
					distance += 3;
				} else {
					printErr();
				}
			break;
			case 6:
				if(posY + 1 < 10) {
					posY++;
					distance += 3;
				} else {
					printErr();
				}
			break;
			case 7:
				if(posX - 1 >= 0 && posY >= 0) {
					posX--;
					posY--;
					distance += 5;
				} else {
					printErr();
				}
			break;
			case 8:
				if(posX - 1 >= 0) {
					posX--;
					distance += 3;
				} else {
					printErr();
				}
			break;
			case 9:
				if(posX - 1 >= 0 && posY + 1 < 10) {
					posX--;
					posY++;
					distance += 5;
				} else {
					printErr();
				}
			break;
			default:
			break;	
		}

		print_the_grid(posX,posY,nestX,nestY);

		if(posX == nestX && posY == nestY) {
			playing = 0;
			printf("YOU WON!\n");
			printf("Ant traveled %d\n", distance);
		}

	}

	print_the_grid(posX,posY,nestX,nestY);

}
