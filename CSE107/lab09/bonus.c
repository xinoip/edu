/* Question: what will break the function foo? */

#include <stdio.h>

/* NEGATIVE NUMBERS WILL BREAK THIS */
int foo(int n) {

	if(n == 0) {
		return 0;
	} else if(n == 1) {
		return 1;
	} else {
		return n + foo(n-1);
	}

}

int main() {

	printf("Negative numbers will be a problem for function foo.\n");

}