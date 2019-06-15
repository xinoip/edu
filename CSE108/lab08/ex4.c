#include <stdio.h>

int max_arr(int * arr);
void swap(int *a, int *b);

int main() {

	int arr[8] = {1,5,3,4,100,7,70,2};

	//swap(&arr[0], &arr[1]);

	printf("Max of array is = %d\n", max_arr(arr));

}

int max_arr(int * arr) {

	int swapped = 0;

	for(int i = 0; i < 7; i++) {
		if(arr[i] > arr[i+1]) {
			swap(&arr[i], &arr[i+1]);
			swapped = 1;
		}
	}

	if(swapped == 0) {
		return arr[7];
	} else { //swapped == 1
		return max_arr(arr);
	}
}

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}