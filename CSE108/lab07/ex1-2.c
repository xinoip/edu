#include <stdio.h>
#include <string.h>

void insert_text(char str[], int index, char c);
void delete_text(char str[], int index);
void to_upper(char str[], int index); 
void to_lower(char str[], int index);
void check_typos(char plain_text[300]);
void word_counter(char text[300], int counters[150], char words[150][20]);
int check_words(char words[150][20], char str[], int * index);
void reset_str(char str[]);

int main() {

	//char str[300] = "merhaba ben buğra.   bu da benim,cümlelerim";
	//char plain_text[300]="this Is a text which has some typos.   you should correct tHe text,because you will use the Text to test your check_typos function.therefore, try to correct all typos iN the test. This part of the text is correct, so no correction should be done on this part.";
	//printf("%s\n", plain_text);
	//check_typos(plain_text);
	//printf("%s\n", plain_text);

	char text[300] = "Merhaba benim adım buğra ve tekrar Buğra buğra tekrar ve Merhaba ve ";
	int counters[150];

	for(int i = 0; i < 150; i++) counters[i] = 1;

	char words[150][20];

	word_counter(text, counters, words);

}

void word_counter(char text[300], int counters[150], char words[150][20]) {

	char tmp[300];

	int words_index = 0, counter_index, words_len = 0;

	for(int i = 0, j = 0; i < 300; i++) {

		if(text[i] == ' ') {

			tmp[j] = '\0';

			if(check_words(words, tmp, &counter_index)) { //word yok ekle

				strncpy(words[words_index++], tmp, j);	
				words_len++;

			} else { //word var say

				counters[counter_index]++;

			}
			
			j = 0;
			reset_str(tmp);

		} else {

			tmp[j++] = text[i];
			
		}


	}

	int i = 0;
	while(i < words_len) {
		printf("There are %d '%s' in the text.\n", counters[i], words[i]);
		i++;
	}

}

void reset_str(char str[]) {

	for(int i = 0; i < 150; i++) {
		str[i] = '\0';
	}

}

/* Check words, if there is word return 0 else return 1,
	Also if there is the word;
		Return the index of that word.
*/
int check_words(char words[150][20], char str[], int * index) {

	for(int i = 0; i < 150; i++) {
		if(strcmp(words[i], str) == 0) {
			*index = i;
			return 0;
		}
	}

	return 1;

}

void check_typos(char plain_text[300]) {

	for(int i = 0; i < 300; i++) to_lower(plain_text, i);

	to_upper(plain_text, 0);

	int i = 0, j = 0;

	while(plain_text[i] != '\0') {

		if(plain_text[i] == '.' || plain_text[i] == ',') {

			j = i+1;
			while(plain_text[j] == ' ') {
				delete_text(plain_text, j);
			}

			insert_text(plain_text, i+1, ' ');

			if(plain_text[i] == '.') {
				to_upper(plain_text, i+2);
			}

		}

		i++;
	} 

}

/* Insert char after the index to string */
void insert_text(char str[], int index, char c) {

	int counter = index;

	while(str[counter] != '\0') {
		counter++;
	}

	while(counter >= index) {
		str[counter+1] = str[counter];
		counter--;
	}

	str[index] = c;

}

/* Delete text at the index and shift it back */
void delete_text(char str[], int index) {

	int counter = index;

	while(str[counter+1] != '\0') {
		str[counter] = str[counter+1];
		counter++;
	}

	str[counter] = '\0';

}

/* Convert the char at index to lower char */
void to_lower(char str[], int index) {

	if(str[index] <= 90 && str[index] >= 65) {
		str[index] += 32; 
	}

}

/* Convert the char at index to upper char */
void to_upper(char str[], int index) {

	if(str[index] <= 122 && str[index] >= 97) {
		str[index] -= 32; 
	}

}

































