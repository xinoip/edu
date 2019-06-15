#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
	unsigned int capacity;	 	//Capacity, duh
	int top_index;				//Top elements index in data array
	int *data;					//Data array, duh
	//OPTIONAL instead of putting your data directly in,
	//data_t data;
} stack_t;

/* Optionally, you can seperate your data, then include it in main struct */
typedef struct Data {
	//Put your data here
} data_t;

//Initial top index is -1 because,
//	Max index can only be "capacity-1"
stack_t * create_stack(int capacity) {
	stack_t *rtr 	= (stack_t *)malloc(sizeof(stack_t));

	rtr->capacity 	= capacity;		
	rtr->top_index 	= -1;
	rtr->data 		= (int *)malloc(sizeof(int) * capacity);

	return rtr;
}

//If last index is "capacity-1" then it's full, else it's not
int is_full(stack_t *root) {
	return (root->top_index == root->capacity - 1);
}

//If last index is "-1" then it's empty, else it's not
int is_empty(stack_t *root) {
	return (root->top_index == -1);
}

//Returns current length (not the capacity)
int get_len(stack_t *root) {
	return (root->top_index + 1);
}

//Returns top element from stack
int peek(stack_t *root) {

	int rtr;

	if(is_empty(root)) {
		printf("Underflow while peeking!\n");
		exit(-1);

	} else {
		rtr = root->data[root->top_index];

	}

	return rtr;

}

//Add an element to top
void push(stack_t *root, int data) {

	int new_index = root->top_index + 1;

	if(is_full(root)) {
		printf("Overflow while pushing!\n");
		exit(-1);

	} else {
		printf("Pushing %d to stack...\n", data);
		root->data[new_index] = data;
		root->top_index = new_index;

	}

}

//Remove an element from top
void pop(stack_t *root) {

	if(is_empty(root)) {
		printf("Underflow while popping!\n");
		exit(-1);

	} else {
		printf("Popping top element, %d, from stack...\n", peek(root));
		root->top_index -= 1;
		
	}

}

int main() {

	stack_t *myStack = create_stack(5);

	push(myStack, 5);
	push(myStack, 6);
	push(myStack, 7);
	push(myStack, 8);

	printf("Current top element: %d\n", peek(myStack));

	printf("Current lenght: %d\n", get_len(myStack));

	pop(myStack);
	pop(myStack);
	pop(myStack);
	pop(myStack);

	printf("Current lenght: %d\n", get_len(myStack));

}





