#include <stdio.h>
#include <math.h>

int F(int n);

int main() {

	int n;

	printf("Enter n:");
	scanf("%d", &n);

	printf("Result = %d\n", F(n));

}

int F(int n) {

	if(n == 1) {
		return 1;
	} else if(n > 1) {
		return 2 * F(ceil(n/2)) + 1;
	}

}