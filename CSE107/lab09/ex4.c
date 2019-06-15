#include <stdio.h>

int fib(int n) {

	if(n == 1 || n == 2) {
		return 1;
	} else {
		return (fib(n-2) + fib(n-1));
	}

}

int main() {

	int input;

	printf("Enter input: ");
	scanf("%d", &input);

	for(int i = 1; i <= input; i++) {
		printf("%d ", fib(i));
	}

}