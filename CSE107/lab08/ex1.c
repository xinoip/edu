#include <stdio.h>

void buildSq(int n) {

	for(int i = 0; i < n; i++) {

		for(int j = 0; j < n; j++) {
			printf("x");
		}

		printf("\n");

	}

}

int main() {

	int input;

	printf("Enter your input: ");
	scanf("%d",&input);

	buildSq(input);

}