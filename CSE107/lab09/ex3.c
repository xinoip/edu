#include <stdio.h>

int func(int n, int a) {

	return factorial(n) + exponent(n,a) + 7;

}
//5 4 3 2 1
int factorial(int n) {

	if(n == 0) {
		return 1;
	} else {
		return n * factorial(n-1);
	}

}

int exponent(int n, int a) {

	if(a == 0) {
		return 1;
	} else {
		return n * exponent(n, a-1);
	}

}

int main() {
	printf("%d\n", factorial(4));
	printf("%d\n", exponent(12,2));

	int input1, input2;

	printf("Enter input: ");
	scanf("%d", &input1);
	printf("Enter input: ");
	scanf("%d", &input2);


	printf("%d", func(input1,input2));

}