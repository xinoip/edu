#include <stdio.h>

int addition(int value1, int value2) {
	return value1 + value2;
}

int substraction(int value1, int value2) {
	return value1 - value2;
}

int multiplication(int value1, int value2) {
	return value1 * value2;
}

double division(int value1, int value2) {
	if(value2 == 0) {
		printf("Cant divide by zero\n");
		exit(0);
	} else {
		return value1 / value2;
	}
}

int power_of_two(int exponential) {
	int res = 1;

	for(int i = 0; i < exponential; i++) {
		res *= 2;
	}
	return res;
}

int get_integer_from_user() {
	int i;

	printf("Enter int: ");
	scanf("%d", &i);

	return i;
}

char get_operation_type_from_user() {
	char c;

	printf("Enter opr: ");
	scanf("%c", &c);

	return c;
}

int main() {

	int val1, val2;

	switch(get_operation_type_from_user()) {
		case '+':
			scanf("%d", &val1);
			scanf("%d", &val2);
			printf("%d\n", addition(val1,val2));
		break;
		case '-':
			scanf("%d", &val1);
			scanf("%d", &val2);
			printf("%d\n", substraction(val1,val2));
		break;
		case '/':
			scanf("%d", &val1);
			scanf("%d", &val2);
			printf("%lf\n", division(val1,val2));
		break;
		case '*':
			scanf("%d", &val1);
			scanf("%d", &val2);
			printf("%d\n", multiplication(val1,val2));
		break;
		case '^':
			scanf("%d", &val1);
			printf("%d\n", power_of_two(val1));
		break;
	}

}