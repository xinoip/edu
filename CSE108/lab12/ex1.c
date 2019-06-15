#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct BinaryList {
	char bin_num[300];
	struct BinaryList *next;
} binarylist;

binarylist *create_node(char *data) {
	binarylist *rtr = (binarylist *)malloc(sizeof(binarylist));
	strcpy(rtr->bin_num, data);
	rtr->next = NULL;
	return rtr;
}

int bin2list(binarylist *bn) {

	int len = strlen(bn->bin_num), decimal = 0, current_pow = 0;

	for(int i = len-1; i >= 0; i--) {
		if(bn->bin_num[i] == '1') {
			decimal += pow(2, current_pow);
		} 
		current_pow++;
	}

	return decimal;

}

int main() {

	binarylist *head = create_node("0000111");

	printf("Decimal of %s = %d\n", head->bin_num, bin2list(head));

}
