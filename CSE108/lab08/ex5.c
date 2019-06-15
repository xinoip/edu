#include <stdio.h>
#include <string.h>

int isPalindrome(char *str);

int main() {

	char input[300];

	printf("Enter string to check:");
	scanf("%s", input);

	printf("Palindrom = %d\n", isPalindrome(input));

}

//01234
//12321

/* 
	0-4
	1-3
	2
*/

//bi son
//bi başş

//01234567
//12344321

/* 
	0-7
	1-6
	2-5
	3-4

*/

01234
012345
int isPalindrome(char *str) {

	int start = 0;

	int end = 0;
	while(str[end+1] != '\0') {
		end++;
	}

	if(start >= end) {
		return 1;
	}

	if(str[start] == str[end]) {
		str[end] = '\0';
		return isPalindrome(&str[1]);
	} else {
		return 0;
	}
	
}