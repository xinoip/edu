#include <stdio.h>

int findMax(int x, int y) {
	if(x >= y) {
		return x;
	} else {
		return y;
	}
}

int find_max_of_five(int a1, int a2, int a3, int a4, int a5) {

	int max = a1;;

	if(findMax(a1,a2) > max) {
		max = findMax(a1,a2);		
	}
	if(findMax(a1,a3) > max) {
		max = findMax(a1,a3);		
	}
	if(findMax(a1,a4) > max) {
		max = findMax(a1,a4);		
	}
	if(findMax(a1,a5) > max) {
		max = findMax(a1,a5);		
	}
	if(findMax(a2,a3) > max) {
		max = findMax(a2,a3);		
	}
	if(findMax(a2,a4) > max) {
		max = findMax(a2,a4);		
	}
	if(findMax(a2,a5) > max) {
		max = findMax(a2,a5);		
	}
	if(findMax(a3,a4) > max) {
		max = findMax(a3,a4);		
	}
	if(findMax(a3,a5) > max) {
		max = findMax(a3,a5);		
	}
	if(findMax(a4,a5) > max) {
		max = findMax(a4,a5);		
	}

	return max;

}

int main() {

	printf("%d\n", find_max_of_five(5,25,12,3,-12));

}