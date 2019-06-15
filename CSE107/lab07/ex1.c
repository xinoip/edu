#include <stdio.h>

int main() {

	int myArr[333];
	int j = 0;

	for(int i = 1; i < 1000; i++) {
		if(i % 3 == 0) {
			myArr[j] = i;
			j++;
		}
	}

	for(int i = 0; i < 333; i++) {
		printf("%d\n ", myArr[i]);
	}

}