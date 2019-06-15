#include <stdio.h>
#include <math.h>



float getMean(int *array, int size) {

	int *const arrayEnd = array + size;
	float sum = 0.0;

	for(;array < arrayEnd; array++) {
		sum += *array;
	}

	return sum / size;

}

float getDeviation(int *array, int size, int mean) {

    float sum = 0.0, standardDeviation = 0.0;
    int n = 0;
    int *const arrayEnd = array + size;

    for(;array < arrayEnd; array++) {
        standardDeviation += pow(*array - mean, 2);
        n++;
    }

    return sqrt(standardDeviation/n);

}

int main() {

	int nums[6] = {12,21,34,45,53,62};
	printf("Mean: %f\n", getMean(nums, 6));
	printf("standard Deviation: %f\n", getDeviation(nums, 6, getMean(nums, 6)));

}
