#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
	head, proper_noun, regular
} word_type;

typedef struct Word{
	int no_vowels, length;
	word_type type;
	char word[300];
} word_t;

typedef struct node {
	int data;
	struct node *next;
} node_t;

typedef struct Stack {
	int data;
	struct Stack *next;
} stack_t;

/* PART 1 START */

int is_upper(char c) {
	return (c <= 'Z' && c >= 'A');
}

void reset_str(char *str, int len) {
	for(int i = 0; i < len; i++) {
		str[i] = '\0';
	}
}

int count_vowels(char *word) {
	int rtr = 0;
	for(int i = 0; word[i] != '\0'; i++) {
		if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' ||
			word[i] == 'u' || word[i] == 'A' || word[i] == 'E' || word[i] == 'I' ||
			word[i] == 'O' || word[i] == 'U') {
			rtr++;
		}

	}

	return rtr;
}

int get_len_str(char *str) {
	int rtr = 0;
	for(int i = 0; str[i] != '\0'; i++) {
		rtr++;

	}
	return rtr;
}

word_t create_word(char *word, int is_head) {

	word_t rtr;

	strcpy(rtr.word, word);

	if(is_head == 1) {
		rtr.type = head;

	} else {
		if(is_upper(word[0])) {
			rtr.type = proper_noun;

		} else {
			rtr.type = regular;

		}

	}
	
	rtr.no_vowels = count_vowels(word);
	rtr.length = get_len_str(word);

	return rtr;

}

void print_word_arr(word_t *word_arr, int size_arr) {
	for(int i = 0; i < size_arr; i++) {
		printf("------------------------------\n");
		printf("Word: %s\n", word_arr[i].word);
		printf("Type: ");
		switch(word_arr[i].type) {
			case 0: printf("head"); break;
			case 1: printf("proper noun"); break;
			case 2: printf("regular"); break;
		}
		printf("\n# of vowels: %d\n", word_arr[i].no_vowels);
		printf("Length: %d\n", word_arr[i].length);
		printf("------------------------------\n");
	}
}

void part_1(word_t *word_arr, int *size) {

	char sentence[300];
	char buffer[300];
	char c;
	int i = 0, j = 0, firstRun = 1, is_head = 1;
	word_t tmp;
	int word_arr_i = 0, size_arr = 1;

	printf("Enter string: ");
	scanf("%[^\n]", sentence);

	c = sentence[i];
	while(1) {
		if(c == '\0') {
			buffer[j] = '\0';
			j = 0;
			printf("%s\n", buffer);
			tmp = create_word(buffer, is_head);

			if(is_head == 1) is_head = 0;

			size_arr++;
			//word_arr = realloc(word_arr, sizeof(word_t) * size_arr);

			word_arr[word_arr_i++] = tmp;

			reset_str(buffer, 300);
			break;

		}
		if(c != ' ') {
			buffer[j] = c;
			j++;

		} else {
			buffer[j] = '\0';
			j = 0;
			printf("%s\n", buffer);
			tmp = create_word(buffer, is_head);

			if(is_head == 1) is_head = 0;

			size_arr++;
			//word_arr = realloc(word_arr, sizeof(word_t) * size_arr);

			word_arr[word_arr_i++] = tmp;

			reset_str(buffer, 300);

		}

		i++;
		c = sentence[i];
	}

	*size = size_arr-1;

}

/* PART 1 END */

/* PART 2 START */

node_t *create_node(int data) {
	node_t *rtr = malloc(sizeof(node_t));
	rtr->data = data;
	rtr->next = NULL;
	return rtr;
}

int delete_node(node_t **head, int data) {
	node_t *curr = (*head), *prev = NULL;
	int rtr = 0;
	while(curr->data != data) {
		prev = curr;
		curr = curr->next;

	}
	if(curr == (*head)) {
		(*head) = curr->next;

	} else {
		prev->next = curr->next;
		rtr = curr->data;	
	}
	
	free(curr);
	return rtr;

}

void print_linked(node_t *head) {
	printf("list->");
	while(head != NULL) {
		printf("%d ", head->data);

		head = head->next;
	}
	printf("\n");
}

void create(struct node **head) {

	int input = 0, is_init = 0;

	node_t *curr = (*head);

	printf("Enter 10 numbers: ");
	for(int i = 0; i < 10; i++) {
		scanf("%d", &input);
		if(is_init == 0) {
			(*head) = create_node(input);
			curr = (*head);
			is_init = 1;

		} else {
			curr->next = create_node(input);
			curr = curr->next;

		}

	}

	print_linked((*head));

}

int winner(struct node **head, int delete) {

	delete_node(head, delete);

	if((*head)->next == NULL) {
		return (*head)->data;

	} else {
		return 0;

	}
	
}

void part_2(struct node **head) {

	int input = 0;

	print_linked((*head));
	while((*head)->next != NULL) {
		printf("Delete number: ");
		scanf("%d", &input);
		winner(head, input);
		printf("%d is eliminated\t\t\t", input);
		print_linked((*head));
	}

	printf("%d is winner\n", (*head)->data);

}

/* PART 2 END */

/* PART 3 START */

stack_t *create_stack(int data) {
	stack_t *rtr = malloc(sizeof(stack_t));
	rtr->data = data;
	rtr->next = NULL;
	return rtr;
}

void print_stack(stack_t *top) {
	printf("Top-> ");
	while(top != NULL) {
		printf("%d ", top->data);
		top = top->next;
	}
	printf("\n");
}

void push(stack_t **top, int data) {

	stack_t *tmp = create_stack(data);

	if((*top) == NULL) {
		(*top) = create_stack(data);

	} else {
		tmp->next = (*top);
		(*top) = tmp;

	}

}

int pop(stack_t **top) {

	stack_t *tmp = NULL;
	int rtr = 0;

	if((*top) == NULL) {
		//return NULL;

	} else {
		tmp = (*top);
		rtr = tmp->data;
		(*top) = (*top)->next;
		free(tmp);

	}

	return rtr;

}

void reverse_stack(stack_t * top, stack_t **reversed) {

	int curr_data;

	if(top != NULL) {
		curr_data = pop(&top);
		push(reversed, curr_data);
		reverse_stack(top, reversed);
	}

}

void part_3() {

	stack_t *mys = NULL;
	stack_t *mys_reversed = NULL;

	int len = 0, data = 0;
	printf("Enter len for stack: ");
	scanf("%d", &len);

	for(int i = 0; i < len; i++) {
		printf("Enter data: ");
		scanf("%d", &data);
		push(&mys, data);

	}

	printf("Printing stack..\n");
	print_stack(mys);
	printf("Printing reversed stack..\n");
	reverse_stack(mys, &mys_reversed);
	print_stack(mys_reversed);

}

/* PART 3 END */

int main() {

	word_t *word_arr = malloc(sizeof(word_t) * 300);
	int size_arr;

	node_t *head;

	part_1(word_arr, &size_arr);
	print_word_arr(word_arr, size_arr);

	create(&head);
	part_2(&head);

	part_3();

}






