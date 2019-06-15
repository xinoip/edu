#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
	//OPTIONAL instead of putting your data directly in,
	//data_t data;
	int data;
	struct Stack *next;
} stack_t;

/* Optionally, you can seperate your data, then include it in main struct */
typedef struct Data {
	//Put your data here
} data_t;

void pstack(stack_t *s) {
	printf("Printing stack...\n");
	printf("Top-.......- last\n");
	while(s != NULL) {
		printf("%d ", s->data);
		s = s->next;

	}
	printf("\n");
}

stack_t * create_stack_node(int data) {
	stack_t *rtr 	= (stack_t *)malloc(sizeof(stack_t));

	rtr->data 		= data;
	rtr->next 		= NULL;

	return rtr;
}

//If there is no top, then it's empty
int is_empty(stack_t *top) {
	return (top == NULL);
}

//Returns current length of stack
int get_len(stack_t *top) {
	if(top != NULL) return 1 + get_len(top->next);
	else return -1;
}

//Returns top element from stack
int peek(stack_t *top) {

	int rtr;

	if(is_empty(top)) {
		printf("Underflow at heap, while peeking!\n");
		exit(-1);

	} else {
		rtr = top->data;

	}

	return rtr;

}

//Add an element to top
void push(stack_t **top, int data) {

	stack_t *new_node = create_stack_node(data);

	if(is_empty(*top)) {
		*top = new_node;

	} else {
		printf("Pushing %d to stack...\n", data);

		new_node->next = *top; //Add new node after the top

		*top = new_node;	//update top

	}	

}

//Remove an element from top
int pop(stack_t **top) {

	stack_t *tmp = *top;	//temporary link to top
	int rtr;

	if(is_empty(*top)) {
		printf("Underflow at heap, while popping!\n");
		exit(-1);

	} else {
		printf("Popping top element, %d, from stack...\n", peek(*top));
		rtr = peek(*top);
		*top = (*top)->next;	//new top is the node before the top (top->next)

		free(tmp);	//free old top using temporary link
		
	}

	return rtr;

}

void insert(stack_t *top, int data);

void sort(stack_t *top) {

	if(!is_empty(top)) {
		int curr = pop(&top);
		sort(top);
		insert(top, curr);

	}

}

void insert(stack_t *top, int data) {

	if(!is_empty(top)) {
		int curr_top = peek(top);
		if(data < curr_top) {
			pop(&top);
			insert(top, data);
			push(&top, curr_top);

		} else {
			push(&top, data);

		}

	} else {
		push(&top, data);

	}

}

int main() {

	stack_t *myStack = malloc(sizeof(stack_t));

	push(&myStack, 8);
	push(&myStack, 7);
	push(&myStack, 6);
	push(&myStack, 5);

	pstack(myStack);

	/*pstack(myStack);

	printf("Current top element: %d\n", peek(myStack));

	printf("Current lenght: %d\n", get_len(myStack));

	sort(myStack);

	printf("Current top element: %d\n", peek(myStack));
	printf("Current lenght: %d\n", get_len(myStack));

	pstack(myStack);*/

	
	pop(&myStack);
	pop(&myStack);
	pop(&myStack);
	pop(&myStack);

	pstack(myStack);

	//printf("Current lenght: %d\n", get_len(myStack));

}