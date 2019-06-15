#include <stdio.h>
#include <math.h>

void calc_roots(int a, int b, int c, double *root1, double *root2);

int main() {

	int a,b,c;
	double r1, r2;
	printf("Input a, b, c\n");
	scanf("%d %d %d", &a, &b, &c);

	calc_roots(a,b,c, &r1, &r2);

	printf("root1:%lf, root2:%lf\n", r1, r2);

}

void calc_roots(int a, int b, int c, double *root1, double *root2) {

	*root1 = (-b) + sqrt((b*b) - (4*a*c));
	*root1 /= 2*a;

	*root2 = (-b) - sqrt(b*b - 4*a*c);
	*root2 /= 2*a;	

}