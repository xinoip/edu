#include <stdio.h>
#include <math.h>

double calc_quadratic_eq_roots(int a, int b, int c, int choice);

int main() {

	int a,b,c,choice;

	printf("a = ");
	scanf("%d",&a);

	printf("b = ");
	scanf("%d",&b);

	printf("c = ");
	scanf("%d",&c);

	printf("choice = ");
	scanf("%d",&choice);

	printf("%d(x^2)+%d(x)+%d\n", a, b, c);

	printf("%lf\n", calc_quadratic_eq_roots(a,b,c,choice));

}

double calc_quadratic_eq_roots(int a, int b, int c, int choice) {

	double res = 0.0;

	switch(choice) {

		case 0:
			res = (sqrt((b*b)-(4*a*c))) - b;
			res /= 2*a;
		break;

		case 1:
			res = (-sqrt((b*b)-(4*a*c))) - b;
			res /= 2*a;
		break;

		default:
			printf("ERROR\n");
		break;

	}

	return res;
		
}