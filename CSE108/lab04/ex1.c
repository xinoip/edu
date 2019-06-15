#include <stdio.h>
#include <math.h>

int isPrime(int n) {

	if(n == 2) {
		return 1;
	} 

	if(n < 2) {
		return 0;
	}

	for(int i = 2; i <= sqrt(n); i++) {
		if(n % i == 0) {
			return 0;
		}
	}

	return 1;

}

void find_prime_numbers(int number) {

	int counter = 0;

	for(int i = 2; i < number; i++) {
		if(isPrime(i)) {
			printf("%d ", i);
			counter++;
		}
	}
	printf("\n");

	printf("There are %d prime numbers which are smaller than 100\n", counter);

}

int main() {

	find_prime_numbers(10);

}
