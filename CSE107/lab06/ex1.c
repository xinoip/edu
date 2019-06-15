#include <stdio.h>

int main() {

	int nums[3];
	int tmp;

	for(int i = 0; i < 3; i++) {
		printf("Enter num: ");
		scanf("%i", &nums[i]);
	}

	if(nums[0] > nums[1]) {
		tmp = nums[0];
		nums[0] = nums[1];
		nums[1] = tmp;
	}
	if(nums[1] > nums[2]) {
		tmp = nums[1];
		nums[1] = nums[2];
		nums[2] = tmp;
	}
	if(nums[0] > nums[1]) {
		tmp = nums[0];
		nums[0] = nums[1];
		nums[1] = tmp;
	}

	for(int i = 0; i < 3; i++) {
		printf("%i ", nums[i]);
	}

}
