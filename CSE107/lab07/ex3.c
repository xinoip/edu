#include <stdio.h>

int main() {
	int myArr[5] = {4,1,2,3,4};
	int myArrTwo[5];
	int tmp;
	int n = 4;

	for(int i = 0; i < 5; i++) {
		for(int j = n; j >= 0; j--) {
			tmp += myArr[j];
		}
		myArrTwo[i] = tmp;
		tmp = 0;
		n--;
	}

	for(int i = 0; i < 5; i++) {
		printf("%d\n", myArrTwo[i]);
	}

}