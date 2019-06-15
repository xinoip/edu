#include <stdio.h>
#include <stdlib.h>

struct complex {
	float real;
	float imag;
};

struct complex add(struct complex *n1, struct complex *n2) {

	struct complex r = malloc(sizeof(struct complex));
	struct complex *rptr = &r;

	rptr->real = n1->real + n2->real;
	rptr->imag = n1->imag + n2->imag;

	return r;

}

void printComplex(struct complex *n) {

	printf("%.3f+%.3fi", n->real, n->imag);

}

struct complex createComplex(float real, float imag) {

	struct complex r = malloc(sizeof(struct complex));
	struct complex *rptr = &r;

	rptr->real = real;
	rptr->imag = imag;

	return r;

}

int main() {

	float f1, f2;
	
	int i = 1;
	printf("Enter num%d real: ", i);
	scanf("%f", &f1);
	printf("Enter num%d imag: ", i);
	scanf("%f", &f2);

	struct complex num1 = createComplex(f1,f2);

	i++;
	printf("Enter num%d real: ", i);
	scanf("%f", &f1);
	printf("Enter num%d imag: ", i);
	scanf("%f", &f2);

	struct complex num2 = createComplex(f1,f2);
	
	
	struct complex result = add(&num1, &num2);

	printComplex(&num1);
	printf(" + ");
	printComplex(&num2);
	printf(" = ");
	printComplex(&result);
	printf("\n");

}