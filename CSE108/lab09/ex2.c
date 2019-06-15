#include <stdio.h>

typedef struct {
	double real;
	double img;
} complex_num;

complex_num add_complex(complex_num a, complex_num b);
complex_num sub_complex(complex_num a, complex_num b);
void print_complex(complex_num num);

int main() {

	complex_num num1 = {4, -3};
	complex_num num2 = {5, 6};

	print_complex(num1);
	printf(" + ");
	print_complex(num2);
	printf(" = ");
	print_complex(add_complex(num1, num2));

	printf("\n");

	print_complex(num1);
	printf(" - ");
	print_complex(num2);
	printf(" = ");
	print_complex(sub_complex(num1, num2));

	printf("\n");


}

complex_num add_complex(complex_num a, complex_num b) {

	complex_num rtr;

	rtr.real = a.real + b.real;
	rtr.img = a.img + b.img;

	return rtr;

}

complex_num sub_complex(complex_num a, complex_num b) {

	complex_num rtr;

	rtr.real = a.real - b.real;
	rtr.img = a.img - b.img;

	return rtr;

}

void print_complex(complex_num num) {

	printf("(%.1lf + %.1lfi)", num.real, num.img);

}