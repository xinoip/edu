#include <stdio.h>

#define PI 3.14

double areaOfSphere(int r);

int main() {

	float r;

	printf("Enter r:");
	scanf("%f", &r);

	printf("Area of sphere: %f\n", areaOfSphere(r));

}

double areaOfSphere(int r) {
	return PI*r*r*4;
}