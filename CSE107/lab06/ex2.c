#include <stdio.h>

int main() {

	int x, y;
       	int tmp;

	printf("Enter x,y: ");
	scanf("%i", &x);
	//printf("Enter y: ");
	scanf("%i", &y);

	printf("Entered values are: \n");
	printf("x = %i\n", x);
	printf("y = %i\n", y);

	tmp = x;
	x = y;
	y = tmp;

	printf("Swapped values are: \n");
	printf("x = %i\n", x);
	printf("y = %i\n", y);

	x *= 2;
	y *= 2;

	printf("Multiplied values are: \n");
	printf("x = %i\n", x);
	printf("y = %i\n", y);

}
