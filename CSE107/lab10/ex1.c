#include <stdio.h>

void swapByValue(int a, int b) {

	int tmp = a;
	a = b;
	b = a;

}

void swapByReference(int *a, int *b) {

	int tmp = *a;
	*a = *b;
	*b = tmp;

}

int main() {

	int num1 = 200;
	int num2 = 300;


	printf("num1: %d num2: %d\n", num1, num2);

	swapByValue(num1, num2);  //wont work
	swapByReference(&num1, &num2); //works

	printf("num1: %d num2: %d\n", num1, num2);

}