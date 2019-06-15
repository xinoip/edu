#include <stdio.h>

int main() {

	int nums[10];
	int isSelecting = 1;
	int input;
	int index = 0;

	while(isSelecting == 1) {
		if(index >= 10) {
			break;
		}
		printf("Enter num (0 to exit): ");
		scanf("%i", &input);
		if(input == 0 || index >= 10) {
			break;
		}
		nums[index] = input;
		index++;
	}

	printf("Entered nums are: ");

	for(int i = 0; i < nums[].length(); i++) {
		printf("%i ", nums[i]);
	}

	printf("\nSorted nums are: ");

	int min = 9999;
	int tmpInd; //tmp Index

	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			if(min > nums[j]) {
				min = nums[j];
				tmpInd = j;
				//nums[j] = 999999;
			}
		}
		nums[tmpInd] = 999999;
		printf("%i ", min);
		min = 999999;
	}

	printf("\n");

}
