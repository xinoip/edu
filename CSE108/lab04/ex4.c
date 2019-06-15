#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define x_limit 10
#define y_limit 10

void printErr() {
	//printf("Error\n");
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

int find_min_path(int posX, int posY, int nestX, int nestY) {

	int distance = 0, playing = 1;

	while(playing) {
		//diagonal right
		if(posX + 1 < 10 && posY + 1 < 10) {
			posX++;
			posY++;
			distance += 5;
		} else {
			printErr();
		}

		if(posX == nestX || posY == nestY) {
			playing = 0;
		}
	}

	playing = 1;

	if(nestX == posX) {
		while(nestY != posY) {
			if(nestY < posY) {
				//sol
				if(posY - 1 >= 0) {
					posY--;
					distance += 3;
				} else {
					printErr();
				}
			} else if(nestY > posY) {
				//sağ
				if(posY + 1 < 10) {
					posY++;
					distance += 3;
				} else {
					printErr();
				}				
			} else {
				playing = 0;
			}
		
		}

	} else if(nestY == posY) {
		while(nestX != posX) {
			if(nestX > posX) {
				//aşağı
				if(posX + 1 < 10) {
					posX++;
					distance += 4;
				} else {
					printErr();
				}	
			} else if(nestX < posX) {
				//yukarı
				if(posX - 1 >= 0) {
					posX--;
					distance += 3;
				} else {
					printErr();
				}
			} else {
				playing = 0;
			}
		
		}		
	} else {
		printf("ME\n");
	}

	return distance;

}

int main() {

	srand(time(NULL));

	int nestX = rand() % x_limit + 1;
	int nestY = rand() % y_limit + 1;

	int playing = 1;
	int posX = 0, posY = 0;
	int input, distance = 0;

	print_the_grid(0,0,nestX, nestY);

	printf("%d\n", find_min_path(posX, posY, nestX, nestY));

}
