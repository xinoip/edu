#include <stdio.h>

int recursive_pow(int base, int exponent);

int main() {

	int base, exponent;

	printf("Enter base: ");
	scanf("%d", &base);
	printf("Enter exponent: ");
	scanf("%d", &exponent);

	printf("Result = %d\n", recursive_pow(base, exponent));

}

int recursive_pow(int base, int exponent) {

	if(exponent == 1) {
		return base;
	} else if(exponent == 0) {
		return 1;
	} else {
		return base * recursive_pow(base, exponent-1);
	}

}