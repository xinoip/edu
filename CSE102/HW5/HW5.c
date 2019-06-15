#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define DICT_SIZE 15
#define WORD_LEN 10
#define LINE_LEN 18
#define MAP_ROWS 15	//Added 
#define MAP_COLS 15	//Added

/* You can change map size, add new words, new coords, increase dict size and it will work 
	Of course if provided with a correct word_hunter.dat
	Needs word_hunter.dat file in it's directory!
	Also provided word_hunter.dat file only consists horizontal, vertical, an down-right diagonal words,
	However my algorithm can place and found words in every direction.
*/

typedef enum {
	up, down, left, right, up_right, up_left, down_right, down_left
} direction_t;

typedef struct {
	char word[300];
	int st_row, st_col, end_row, end_col;
	direction_t dir;
	int found;
} word_t;

int strcmp_me(char *str1, char *str2);
int strlen_me(char *str);
void to_upper_string(char *str);
char to_upper(char c);
int is_upper(char c);
char random_char();

/* MODIFIED remove_newline(char *line) function */
word_t create_word(char word[300], int st_row, int st_col, int end_row, int end_col);
direction_t get_direction(int st_row, int st_col, int end_row, int end_col);
void fill_word_array(word_t words[DICT_SIZE], char *dict[DICT_SIZE], int coord[DICT_SIZE][4]);

void get_input(char arr[MAP_ROWS][MAP_COLS], word_t words[DICT_SIZE], int *found);
int do_input(char arr[MAP_ROWS][MAP_COLS], int row, int col, char *word, word_t words[DICT_SIZE]);
int check_coord(char map[MAP_ROWS][MAP_COLS], int row, int col);
void print_puzzle(char arr[MAP_ROWS][MAP_COLS]);
void fill_puzzle(char arr[MAP_ROWS][MAP_COLS], word_t words[DICT_SIZE], int rng_mode);
void get_diff_dir(int dir, int *diff_row, int *diff_col);

int get_line_size(char *line) {
	char *ch_iter = line; // so as not to lose beginning of line
	int counter = 0;
	// go until you see new line or null char
	while(*ch_iter != '\n' && *ch_iter != '\0') {
		ch_iter++; // next char
		counter++; // increment counter
	}
	
	return counter;
}

void copy_string(char *source, char *destination) {
	// get iterators over original pointers
	char *src_iter = source;
	char *dst_iter = destination;
	// until null char
	while (*src_iter != '\0') {
		// copy pointers
		*dst_iter = *src_iter;
		// advance to next char
		src_iter++;
		dst_iter++;
   }
   // terminate string
   *dst_iter = '\0';
}

/* MODIFIED */
void remove_newline(char *line) {
	char *ch_iter = line;
	// go until you see new line
	while(*ch_iter != '\n') {
		/* ADDED BY 1801042669 FOR COMPATIBILITY PURPOSES */
		if(*ch_iter == '\r') {
			*ch_iter = '\0'; 
		}
		ch_iter++; // next char
	}
	*ch_iter = '\0'; // overwrite new line
}

void print_dictionary(char *dict[]) {
	int i;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		printf("%s\n", dict[i]);
	}
}

void print_coord(int coord[DICT_SIZE][4]) {
	int i, j;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		for(j = 0 ; j < 4 ; j++) {
			printf("%d ", coord[i][j]);
		}
		printf("\n");
	}
}

int main(){
	char *dict[DICT_SIZE];
    int coord[DICT_SIZE][4];    
    char line[LINE_LEN];
	FILE *fp = fopen("word_hunter.dat", "r");
	
	int line_counter = 0;
	int dict_counter = 0;
	while(fgets(line, LINE_LEN, fp) != NULL) {
		if(line_counter%5 == 0) {
			dict[dict_counter] = (char*) malloc(sizeof(char) * get_line_size(line));
			remove_newline(line);
			copy_string(line, dict[dict_counter]);
		} else if (line_counter%5 == 1){
			coord[dict_counter][0] = atoi(line);
		} else if (line_counter%5 == 2){			
			coord[dict_counter][1] = atoi(line);		
		} else if (line_counter%5 == 3){
			coord[dict_counter][2] = atoi(line);
		} else if (line_counter%5 == 4){
			coord[dict_counter][3] = atoi(line);
			dict_counter++;
		}
		line_counter++;
	}
	
	fclose(fp);
	//print_dictionary(dict);
	//print_coord(coord);
	
	// WRITE HERE...

	srand(time(NULL));

	char puzzle[MAP_ROWS][MAP_COLS];
	word_t puzzle_words[DICT_SIZE];
	int found = 0, playing = 1;
	
	fill_word_array(puzzle_words, dict, coord);
	fill_puzzle(puzzle, puzzle_words,1);
	print_puzzle(puzzle);

	while(playing) {
		if(found == -1) {
			break;
		}
		if(found >= DICT_SIZE) {
			break;
		}
		printf("Currently founded %d words!\n\n", found);
		get_input(puzzle, puzzle_words, &found);
		fill_puzzle(puzzle, puzzle_words,0);
		print_puzzle(puzzle);
		printf("\n");
	}

	if(found == DICT_SIZE) {
		printf("You won!\n");	
	} else {
		printf("Exiting...\n");
	}
	
	return 0;
}

void get_input(char arr[MAP_ROWS][MAP_COLS], word_t words[DICT_SIZE], int *found) {

	int row, col, status;
	char word[300], row_str[300], col_str[300];
	
	printf("Enter input (word row col): ");

	scanf("%s %s", word, row_str);

	if(strcmp_me(word, "exit") && strcmp_me(row_str, "game")) {
		*found = -1;
		return;
	} else {
		row = atoi(row_str);
	}

	scanf("%s", col_str);
	col = atoi(col_str);

	status = do_input(arr, row, col, word, words);

	if(status == 1) {
		*found = *found + 1;
	}

}

/* Does the searches. Search algorithm: (NOT BRUTE FORCE)
	1) See if the entered word (which is word parameter) exists in dictionary (which i made simpler with word_t struct type)
		-If not exists return 0 (failed)
		-If exists continue
		-If it's already found return 0 (failed)
	2) Look at the starting/ending coordinates of the word 
		-If user enters starting coordinate make (reverse = 0)
		-If user enters ending coordinate make (reverse = 1)
		-If user not enters any above then return 0 (failed)
	3) Look at the direction of word (Calculated every direction of words when creating them by create_word function (not hardcoded, see get_direction() function)
	4) According to direction, find;
		-difference needed in row for each step to iterate
		-difference needed in col for each step to iterate
	5) According to being reverse or not
		-difference needed in curr_index for each step to comparison
		-initialized value of curr_index
		-difference needed in row for each step to iterate
		-difference needed in col for each step to iterate
			is recalculated and assigned
	6) Do the iteration, for every iteration;
		row += diff_row
		col += diff_col
		curr_index += diff_curr_index

	This algorithm covers up 8 different direction reading for both ways (straight and reverse)
	Therefor it covers up 16 different searches

	Note that i never compared any coordinates to find if we found correct word or not, i actuall looked at the puzzle maps characters.
*/
int do_input(char arr[MAP_ROWS][MAP_COLS], int row, int col, char *word, word_t words[DICT_SIZE]) {

	int word_index = -1, dir, diff_row, diff_col, reverse = 0, curr_index = 0, st_row, st_col, end_row, end_col, success, ending_row, ending_col, diff_curr_index = 1;
	 
	/* Look for selected word in database of words */
	for(int i = 0; i < DICT_SIZE; i++) {
		if(strcmp_me(words[i].word, word)) {
			word_index = i;
			break;
		}
	}

	/* If selected word is not in the data then no such word */
	if(word_index == -1) {
		printf("No such word!\n");
		return 0;
	}

	if(words[word_index].found) { /* If it's found return 0 */
		printf("ALREADY FOUND!\n");
		return 0;
	}

	/* If selected word founded get the direction and coordinates of it */
	dir = words[word_index].dir;
	st_row = words[word_index].st_row;
	st_col = words[word_index].st_col;
	end_row = words[word_index].end_row;
	end_col = words[word_index].end_col;
	/* Get the differences needed according to direction */
	get_diff_dir(dir, &diff_row, &diff_col);

	/* Determine if user entered reversely or not */
	if(row == end_row && col == end_col) {
		reverse = 1;
	} else if(row == st_row && col == st_col) {
		reverse = 0;
	} else { /* Not start nor end of the word, print not found */
		printf("No word found!\n");
		return 0;
	}

	/* If dealing with reverse then change the variables accordingly */
	/* differences reversed sign vise, and also we need to start from end of the word*/
	if(reverse) {
		diff_row = -diff_row;
		diff_col = -diff_col;
		curr_index = strlen_me(word) - 1;
		diff_curr_index = -1;
		ending_row = st_row;
		ending_col = st_col;
	} else { /* Ending row and col is terminating coordinates for finding algorithm */
		ending_row = end_row;
		ending_col = end_col;
	}

	/* CAN DO 16 DIFFERENT SEARCHES 
		8 direction, 2 way (straight-reverse) 
		Please note that i'm not comparing any coordinates, i'm only comparing the characters, i just made a simple algorithm for every direction */
	success = 0;
	while(!success) {
		if(arr[row][col] == word[curr_index] || arr[row][col] == to_upper(word[curr_index])) { /* Check current cell and compare */

		} else { /* If not equals, then its not our word */
			printf("No word found!\n");
			return 0;
		}

		if(row == ending_row && col == ending_col) { /* Terminating condition */
			success = 1;
		}	

		/* Add the differences that we created before */
		row += diff_row; 
		col += diff_col;
		curr_index += diff_curr_index;			
	}

	/* If no return has occured until here than we got the correct word */
	words[word_index].found = 1;
	printf("WORD FOUND!\n");

	/* Turn that word to upper case */
	to_upper_string(words[word_index].word);

	return 1;

}

/* Converts string to uppercase */
void to_upper_string(char *str) {
	int len = strlen_me(str);
	for(int i = 0; i < len; i++) {
		str[i] = to_upper(str[i]);
	}
}

/* String comparision function */
int strcmp_me(char *str1, char *str2) {
	int len1 = strlen_me(str1), len2 = strlen_me(str2);
	if(len1 == len2) {
		for(int i = 0; i < len1; i++) {
			if(str1[i] != str2[i]) return 0;
		}
		return 1;
	} else {
		return 0;
	}
}

/* Returns string length */
int strlen_me(char *str) {
	int len = 0;
	while(str[len] != '\0') {
		len++;
	}
	return len;
}

/* Fills the given word_t array */
void fill_word_array(word_t words[DICT_SIZE], char *dict[DICT_SIZE], int coord[DICT_SIZE][4]) {
	for(int i = 0; i < DICT_SIZE; i++) {
		words[i] = create_word(dict[i], coord[i][0], coord[i][1], coord[i][2], coord[i][3]);
	}
}

/* Return new word_t with given properties */
word_t create_word(char word[300], int st_row, int st_col, int end_row, int end_col) {
	word_t rtr;
	for(int i = 0; i < 300; i++) {
		rtr.word[i] = word[i];
	}
	rtr.st_row = st_row;
	rtr.st_col = st_col;
	rtr.end_row = end_row;
	rtr.end_col = end_col;
	rtr.dir = get_direction(st_row, st_col, end_row, end_col);
	rtr.found = 0;
	return rtr;
}

/* Returns direction according to 2 coordinates of points */
direction_t get_direction(int st_row, int st_col, int end_row, int end_col) {
	direction_t dir;
	if(st_row > end_row) { 
		if(st_col > end_col) { 
			dir = up_left;
		} else if(st_col == end_col) { 
			dir = up;
		} else {
			dir = up_right;
		}
	} else if(st_row == end_row) { 
		if(st_col > end_col) { 
			dir = left;
		} else { 
			dir = right;
		}
	} else { 
		if(st_col > end_col) {
			dir = down_left;
		} else if(st_col == end_col) {
			dir = down;
		} else {
			dir = down_right;
		}
	}
	return dir;
}

/* Checks if c is uppercase or not */
int is_upper(char c) {
	int rtr = 0;
	if('A' <= c && c <= 'Z') {
		rtr = 1;
	} 
	return rtr;
}

/* Returns uppercase of c */
char to_upper(char c) {
	if(!is_upper(c)) {
		return c - 32;
	} else {
		return c;
	}
}

/* 1 valid and not upper-case, 2 valid and upper-case, 0 not valid */
int check_coord(char map[MAP_ROWS][MAP_COLS], int row, int col) {
	int rtr = 0;
	if(row < MAP_ROWS && row >= 0 && col < MAP_COLS && col >= 0) {
		if(is_upper(map[row][col])) {
			rtr = 2;
		} else {
			rtr = 1;
		}
	}
	return rtr;
}

/* Returns random lowercase character */
char random_char() {
	char rtr = 97 + (rand() % 25 + 1);	
	return rtr;
}

/* If rng_mode is 1 than fill randomly and add/update words else just add/update words */
void fill_puzzle(char arr[MAP_ROWS][MAP_COLS], word_t words[DICT_SIZE], int rng_mode) {

	int st_row, st_col, end_row, end_col, dir, word_index = 0, diff_row, diff_col, success = 0;

	if(rng_mode == 1) { /* Fill randomly */
		for(int i = 0; i < MAP_ROWS; i++) {
			for(int j = 0; j < MAP_COLS; j++) {
				arr[i][j] = random_char();
			}
		}	
	}
	
	/* Can place words in 8 directions (even though we only need 3 directions) */
	for(int i = 0; i < DICT_SIZE; i++) { 
		st_row = words[i].st_row;
		st_col = words[i].st_col;
		end_row = words[i].end_row;
		end_col = words[i].end_col;
		dir = words[i].dir;
		get_diff_dir(dir, &diff_row, &diff_col);

		success = 0;
		while(!success) {
			if(!is_upper(arr[st_row][st_col])) {
				arr[st_row][st_col] = words[i].word[word_index]; /* Place char by char */	
			}
			
			if(st_row == end_row && st_col == end_col) { /* Terminating condition */
				success = 1;
			}

			st_row += diff_row;
			st_col += diff_col;			
			word_index++;
		}
		word_index = 0;
	}
}

/* Gives the differences needed for iterations in puzzle area according to direction */
void get_diff_dir(int dir, int *diff_row, int *diff_col) {
	switch(dir) {
		case up:         *diff_row = -1; *diff_col = 0; 	break;
		case up_right:   *diff_row = -1; *diff_col = 1; 	break;
		case up_left:    *diff_row = -1; *diff_col = -1; 	break;
		case down:       *diff_row = 1;  *diff_col = 0; 	break;
		case down_right: *diff_row = 1;  *diff_col = 1; 	break;
		case down_left:  *diff_row = 1;  *diff_col = -1; 	break;
		case left:       *diff_col = -1; *diff_row = 0; 	break;
		case right:      *diff_col = 1;  *diff_row = 0; 	break;
	}
}

/* Prints puzzle */
void print_puzzle(char arr[MAP_ROWS][MAP_COLS]) {
	printf("  ");
	for(int i = 0; i < MAP_ROWS; i++) {
		if(i < 10) {
			printf("  %d", i);
		} else {
			printf(" %d", i);	
		}
	}
	printf("\n");
	for(int i = 0; i < MAP_ROWS; i++) {
		if(i < 10) {
			printf(" %d", i);
		} else {
			printf("%d", i);	
		}
		printf(" ");
		for(int j = 0; j < MAP_COLS; j++) {
			printf(" %c ", arr[i][j]);
		}
		printf("\n");
	}
}
