#include <stdio.h>

//36,24 = 12
//36,12 = 12

//a > b sağlamalı
int gcdRec(int a, int b) {

	if(a % b == 0) {
		return b;
	} else {
		return gcdRec(a, a % b);
	}

}

int gcdLoop(int a, int b) {

	int max, gcd;

	if(a > b) {
		max = a;
	} else {
		max = b;
	}

	for(int i = 1; i < max; i++) {

		if(b % i == 0 && a % i == 0) {
			gcd = i;
		}
		
	}

	return gcd;

}

int main() {

	int num1, num2;

	printf("Enter first num: ");
	scanf("%d", &num1);
	printf("Enter second num: ");
	scanf("%d", &num2);

	int tmp;

	if(num2 > num1) {
		tmp = num2;
		num2 = num1;
		num1 = tmp;
	}

	printf("Gcd with loop: %d\n", gcdLoop(num1,num2));
	printf("Gcd with recursive: %d\n", gcdRec(num1,num2));

}