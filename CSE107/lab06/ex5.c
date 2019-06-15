#include <stdio.h>

int fib(int n) {

	if(n == 0) {
		return 0;
	} if(n == 1) {
		return 1;
	} else {
		return (fib(n-1) + fib(n-2));
	}

}

int main() {

	for(int k = 0; k < 20; k++) {
		printf("%i ", fib(k));
	}

}
