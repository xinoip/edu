#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getLen(char *str) {

	int i = 0;
	int count = 0;

	while(str[i] != '\0') {
		count++;
		i++;
	}

	return count;

}

void add_binary(char *b1, char *b2, char *result) {

	int b1Num = 0;
	int b1Len = getLen(b1);
	int b2Num = 0;
	int b2Len = getLen(b2);
	int resultNum = 0;
	int resultLen = 0;

	int count = 0;

	for(int i = b1Len - 1; i >= 0; i--) {
		if(b1[i] == '1') {
			b1Num += pow(2,count);
		} 
		count++;
	}

	//printf("%d\n", b1Num);

	count = 0;

	for(int i = b2Len - 1; i >= 0; i--) {
		if(b2[i] == '1') {
			b2Num += pow(2,count);
		} 
		count++;
	}

	//printf("%d\n", b2Num);

	resultNum = b1Num + b2Num;

	count = 0;

	while(resultNum > 0) {
		resultNum = resultNum - pow(2,count);
		resultLen++;
		count++;
	}

	//printf("%d\n", resultLen);

	resultNum = b1Num + b2Num;

	count = resultLen - 1;

	for(int i = 0; i < resultLen; i++) {
		if(resultNum >= pow(2,count)) {
			result[i] = '1';
			resultNum = resultNum - pow(2,count);
		} else {
			result[i] = '0';
		}
		count--;
	} 

	printf("%s + %s = %s\n", b1, b2,result);

}

int main() {

	printf("%d\n", getLen("asd"));

	char* x = malloc(100*sizeof(char));

	add_binary("10","11", x);

}