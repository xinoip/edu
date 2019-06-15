#include <stdio.h>

void reverse_print(char *str);

int main() {

	char input[300];

	printf("Enter string to reverse: ");
	scanf("%s", input);

	reverse_print(input);
	printf("\n");

}

void reverse_print(char *str) {

	int i = 0;
	while(str[i+1] != '\0')  {
		i++;
	}

	if(i > 0) {
		printf("%c", str[i]);
		str[i] = '\0';
		reverse_print(str);
	}

	if(i == 0) {
		printf("%c", str[i]);
		return;
	}

	

}