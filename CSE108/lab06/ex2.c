#include <stdio.h>
#include <math.h>

#define PI 3.14

double mysine(double x);
double convert_degree_to_rad(double x);
double exponent(double num, int n);
int factorial_me(int n);

int main() {

	double degree, rad, sign;

	printf("Enter degree:");
	scanf("%lf", &degree);

	if(degree > 90) {
		sign = 0;
		while(degree > 90) {
			degree-=90;
			if(sign) {
				sign = 0;
			} else {
				sign = 1;
			}
		}
	}

	rad = convert_degree_to_rad(degree);

	if(sign) {
		printf("%lf\n", mysine(rad));	
	} else {
		printf("-%lf\n", mysine(rad));
	}
	
	//printf("%lf\n", exponent(-1,5));
	//printf("%d\n", factorial_me(10));

}

double mysine(double x) {

	double rtr = 0;

	for(int n = 0; n < 10; n++) {
		if(n == 0) {
			rtr = exponent(-1,n) * ((exponent(x, 2*n+1)) / factorial_me(2*n+1));
		} else {
			rtr += exponent(-1,n) * ((exponent(x, 2*n+1)) / factorial_me(2*n+1));
		}
	}

	return rtr;

}

double convert_degree_to_rad(double x) {
	return x * PI / 180;
}

double exponent(double num, int n) {
	if(n == 0) return 1;
	double rtr = 1.0;
	for(int i = 0; i < n; i++) {
		rtr *= num;
	}
	return rtr;
}

int factorial_me(int n) {
	int rtr = 1;
	if(n == 0) return 1;
	if(n == 1) return 1;
	for(int i = n; i > 0; i--) {
		rtr *= i;
	}
	return rtr;
}