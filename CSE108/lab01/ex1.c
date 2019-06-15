#include <stdio.h>

double add(double x, double y) {
	return (x + y);
}

int main() {

	double num1, num2;

	scanf("%lf", &num1);
	scanf("%lf", &num2);

	printf("%lf\n", add(num1, num2));

}