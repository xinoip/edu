#include <stdio.h>

void get_min_max(int *min, int *max);

int main() {

	int min, max;
	double avg;

	get_min_max(&min, &max);
	avg = (double)(min + max) / 2;

	printf("Min:%d, Max:%d, Average:%lf\n", min, max, avg);

}

void get_min_max(int *min, int *max) {

	int num1, num2, num3;

	printf("Input: ");
	scanf("%d %d %d", &num1, &num2, &num3);

	avg = num1 + num2 + num3;
	avg /= 3;


	*max = num1;
	if(num1 > num2 && num1 > num3) {
		*max = num1;
	}
	if(num3 > num1 && num3 > num2) {
		*max = num3;
	}
	if(num2 > num1 && num2 > num3) {
		*max = num2;
	}

	*min = num1;
	if(num2 < num1 && num2 < num3) {
		*min = num2;
	}
	if(num3 < num1 && num3 < num2) {
		*min = num3;
	}

}