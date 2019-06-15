#include <stdio.h>

int main() {
	int myArr[6] = {1,3,2,5,6};
	int count = 0;
	for(int i = 0; i < 4; i++) {
		if(myArr[i] < myArr[i+1]) {
			count++;
		}
	}
	printf("%d\n", count);
}