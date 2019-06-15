#include <stdio.h>

void fillArrInput(int *array, int size) {

	int *const arrayEnd = array + size;

	for(int a = 0;array < arrayEnd; array++, a++) {

		printf("Enter %d. element: ", a);
		scanf("%d", array);

	}

}

void displayArray(int *array, int size) {

	int *const arrayEnd = array + size;

	for(int a = 0;array < arrayEnd; array++, a++) {

		printf("array[%d]: %d\n", a, *array);

	}

}

int main() {

	int size;

	printf("Enter size: ");
	scanf("%d", &size);

	int nums[size];

	fillArrInput(nums, size);
	displayArray(nums, size);

}