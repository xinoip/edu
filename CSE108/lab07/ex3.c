#include <stdio.h>

int find_longest_word(char text[1000]);

int main() {

	char str[1000] = "asd asd asd asd asd av av av asdc asdcvf addsc 123456789 qwe";

	printf("%d\n", find_longest_word(str));

}

int find_longest_word(char text[1000]) {

	char tmp[1000];
	int curLen = 0, max = 0;

	for(int i = 0; i < 1000; i++) {

		if(text[i] == ' ') {

			if(curLen > max) max = curLen;

			curLen = 0;

		} else {
			curLen++;
		}


	}

	return max;

}