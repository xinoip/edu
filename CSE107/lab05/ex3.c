#include <stdio.h>

int main() {

	int x;
	int y;	

	printf("Enter X value:");
	scanf("%i", &x);

	y = (5*x*x) + (6*x) - 3;

	printf("\nY = %i\n", y);

}
