#include <stdio.h>

void drawHearth(int rows) {

	//4 7 8 7 4

	int blanks1 = 4;
	int stars = 7;
	int secPart = rows - 4;

	for(int i = 0; i < 4; i++) { //first 4 row
		for(int j = 0; j < blanks1; j++) {
			printf(" ");
		}
		for(int j = stars; j > 0; j--) {
			printf("x");
		}
		for(int j = 0; j < blanks1; j++) {
			printf(" ");
		}
		for(int j = 0; j < blanks1; j++) {
			printf(" ");
		}
		for(int j = stars; j > 0; j--) {
			printf("x");
		}
		for(int j = 0; j < blanks1; j++) {
			printf(" ");
		}
		printf("\n");
		blanks1 = blanks1 - 1;
		stars = stars + 2;
	}

	blanks1 = 0;
	stars = 30;

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < blanks1; j++) {
			printf(" ");
		}
		for(int j = stars; j > 0; j--) {
			printf("x");
		}
		for(int j = 0; j < blanks1; j++) {
			printf(" ");
		}
		printf("\n");
		blanks1 = blanks1 + 1;
		stars = stars - 2;
	}

}

int main() {

	int input;

	printf("Enter your input: ");
	scanf("%d", &input);

	drawHearth(input);

}