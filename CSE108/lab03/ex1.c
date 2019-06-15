#include <stdio.h>
#include <math.h>

int findInverse(int n);
int getLen(int n);

int main() {

	//printf("%d\n", getLen(10));

	int input;
	scanf("%d", &input);
	printf("%d\n", findInverse(input));

}

//1234
//4321
int findInverse(int n) {

	int rtr = 0;
	int tens = getLen(n) - 1;

	for(int tens = getLen(n) - 1; tens >= 0; tens--) {

		rtr += (n % 10) * pow(10,tens);
		n /= 10;

	}

	return rtr;

}

int getLen(int n) {

	int len = 1;

	for(;n >= 10; n/=10) {
		len++;
	}

	return len;

}