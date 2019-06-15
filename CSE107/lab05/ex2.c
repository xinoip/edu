#include <stdio.h>

int main() {

	int num1, num2, res;

	printf("Enter first number, please:\n");

	scanf("%i", &num1);

	printf("Enter second number, please:\n");
	
	scanf("%i", &num2);

	res = num1 + num2;

	printf("\nResult: %d\n", res);

	return 0;

}
