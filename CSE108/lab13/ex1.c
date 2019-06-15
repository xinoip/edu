#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
	int data;
	struct Stack *next;
} stack_t;

int is_empty(stack_t *top) {
	return (top == NULL);
}

int peek(stack_t *top) {

	int rtr;

	if(is_empty(top)) {
		printf("Underflow while peeking!\n");
		exit(-1);

	} else {
		rtr = top->data;

	}

	return rtr;

}

void pstack(stack_t *s) {
	if(s == NULL) {
		printf("(empty)\n");
		return;
	}
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

void push(stack_t **top, int data) {

	stack_t *new_node = create_stack_node(data);

	if(is_empty(*top)) {
		*top = new_node;

	} else {
		printf("Pushing %d to stack...\n", data);

		new_node->next = *top; 

		*top = new_node;	

	}	

}

int pop(stack_t **top) {

	stack_t *tmp = *top;	
	int rtr;

	if(is_empty(*top)) {
		printf("Underflow while popping!\n");
		exit(-1);

	} else {
		printf("Popping top element, %d, from stack...\n", peek(*top));
		rtr = peek(*top);
		*top = (*top)->next;	

		free(tmp);	
		
	}

	return rtr;

}

int main() {

	stack_t *mystack = malloc(sizeof(stack_t));

	int input, foo, input_2;

	do {
		printf("Stack operations:\n");
		printf("1. Print Stack\n");
		printf("2. Push\n");
		printf("3. Pop\n");
		printf("Enter option: ");
		scanf("%d", &input);

		switch(input) {
			case 1:
				pstack(mystack);
			break;
			case 2:
				printf("Enter new data to be pushed: ");
				scanf("%d", &input_2);
				push(&mystack, input_2);
			break;
			case 3:
				foo = pop(&mystack);
				printf("%d popped!\n", foo);
			break;
			case 4:
				printf("Exiting...\n");
			break;
		}

	} while(input != 4);

}