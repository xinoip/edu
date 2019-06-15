#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int myArrOne[15]; //{3,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
	int myArrTwo[15];

	srand(time(NULL));
	int r;
	

	for(int i = 0; i < 15; i++) {
		r = rand() % 10;
		myArrOne[i] = r;
		myArrTwo[i] = myArrOne[i] *myArrOne[i];
		printf("%d\n", myArrTwo[i]);
	}

}