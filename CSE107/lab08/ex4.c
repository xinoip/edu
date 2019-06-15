#include <stdio.h>

void selectionSort(int myArr[], int size) {
	int tmp;
	for(int i = 0; i < size; i++) {
		for(int j = i + 1; j < size; j++) {
			if(myArr[i] < myArr[j]) {
                tmp = myArr[i];
				myArr[i] = myArr[j];
				myArr[j] = tmp;
				//printf("Debug");
				//swapVar(myArr[i], myArr[j]);
			}
		}
	}
	printf("Array sorted with selection sort algorithm.\n");
}

void fillWithInput(int myArr[], int size) {
	for(int i = 0; i < size; i++) {
		printf("%i. element of array: ", i);
		scanf("%i", &myArr[i]);
		printf("\n");
	}
	printf("Array filled with user input.\n");
}

void displayArr(int myArr[], int size) {
	printf("Displaying array which sized %i\n", size);
	for(int i = 0; i < size; i++) {
		printf("%i  ", myArr[i]);
	}
	printf("\n");
}

int main() {

	int input;

	printf("Enter size: \n");
	scanf("%d", &input);

	int size = input;
	int nums[input];

	fillWithInput(nums, size);
	selectionSort(nums, size);
	displayArr(nums, size);

}