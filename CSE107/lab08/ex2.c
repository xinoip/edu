#include <stdio.h>

void buildSq(int input) {

	for(int i = 0; i < input; i++) {
		for(int j = 0; j < input; j++) {
			if(i == 0 || i == input-1) {
				printf("0");			
			} else {
				if(j == 0 || j == input-1) {
					printf("0");
				} else {
					printf("1");
				}
			}
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