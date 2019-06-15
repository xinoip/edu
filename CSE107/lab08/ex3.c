#include <stdio.h>

void buildStair(int n) {

	for(int i = 0; i < n; i++) {

		for(int j = 0;j <= i; j++) {

			printf("x");

		}

		printf("\n");

	}

}

int main() {

	int input;

	printf("Enter your input: ");
	scanf("%d", &input);

	buildStair(input);

}