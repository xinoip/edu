#include <stdio.h>

int main() {

	int max, step;

	printf("Enter max: ");
	scanf("%i", &max);

	printf("Enter step: ");
	scanf("%i", &step);

	for(int i = 0; i <= max; i += step) {
		if(i > max) {
			break;
		}
		printf("%i\n", i);
	}

}
