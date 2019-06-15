#include <stdio.h>

void drawHome(int row) {

	int empty = 3;
	int star = 1;

	for(int i = 0; i < 3; i++) {

		for(int j = 1; j <= empty; j++) {
			printf("  ");
		}
		for(int t = 1; t <= star; t++) {
			printf("* ");
		}

		printf("\n");

		empty = empty - 1;
		star = star + 2;

	}

	empty = 5;

	for(int i = 0; i < row; i++) {

		if(i == 0 || i == row - 1) {
			for(int j = 0; j < 7; j++) {
				printf("* ");
			}
		} else {
			printf("* ");
			for(int j = 0; j < empty; j++) {
				printf("  ");
			}
			printf("* ");
		}

		printf("\n");

	}
}

int main() {

	int input;

	printf("Enter input: ");
	scanf("%d", &input);

	drawHome(input);

}
