#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Length of the data array to used for benchmark */
/* You can use any length of data (odd or even does not matters) */
#define DATA_LEN 20

/* Time results are initialy seconds. This macro will multiply every result */
#define TIME_UNIT 1000

typedef struct Stack {
  int data;
  struct Stack *next;
} stack;

typedef struct Queue_Node {
  int data;
  struct Queue_Node *next;
} queue_node;

typedef struct Queue {
  queue_node *rear, *front;
} queue;

typedef struct Bst {
  int data;
  struct Bst *right, *left;
} bst;

/***********************************/
//QUEUE OPERATORS start
/***********************************/

queue_node * create_queue_node(int data) {
  queue_node * rtr = (queue_node *)malloc(sizeof(queue_node));
  rtr->data = data;
  rtr->next = NULL;
  return rtr;
}

queue * create_queue() {
  queue * rtr = (queue *)malloc(sizeof(queue));
  rtr->rear = rtr->front = NULL;
  return rtr;
}

void enqueue(queue * q, int data) {
  if(q->front == NULL) {
    q->front = q->rear = create_queue_node(data);

  } else {
    q->rear->next = create_queue_node(data);
    q->rear = q->rear->next;

  }
}

queue * copy_queue(queue *q) {
	queue *rtr = create_queue();
	queue_node *curr = q->front;
	while(curr != NULL) {
		enqueue(rtr, curr->data);
		curr = curr->next;
	}
	return rtr;
}

int search_queue(queue *q, int data, int *steps) {
	queue_node *curr = q->front;
	*steps = 0;
	while(curr != NULL) {
		if(curr->data == data) {
			return 1;
		}

		(*steps)++;
		curr = curr->next;
	}
	return 0;
}

int max_queue(queue *q) {
	queue_node *curr = q->front;
	int max = curr->data;
	while(curr != NULL) {
		if(curr->data > max) {
			max = curr->data;

		}

		curr = curr->next;
	}
	return max;
}

int min_queue(queue *q) {
	queue_node *curr = q->front;
	int min = curr->data;
	while(curr != NULL) {
		if(curr->data < min) {
			min = curr->data;

		}

		curr = curr->next;
	}
	return min;
}

void delete_queue_node(queue *q, int val) {
	queue_node *curr = q->front, *prev = NULL;
	queue_node *tmp = NULL;
	while(curr != NULL) {
		if(curr->data == val) {
			tmp = curr;
			if(prev != NULL) {
				prev->next = curr->next;
				if(curr->next = NULL) {
					q->rear = prev;
				}
			} else {
				q->front = curr->next;

			}
			
			free(tmp);

			return;
		}

		prev = curr;
		curr = curr->next;	
	}
}

/***********************************/
//QUEUE OPERATORS end
/***********************************/

/***********************************/
//STACK OPERATORS start
/***********************************/

stack * create_stack(int data) {
  stack *rtr = (stack *)malloc(sizeof(stack));
  rtr->data = data;
  rtr->next = NULL;
  return rtr;
}

void push(stack ** top, int data) {
  stack *tmp = create_stack(data);
  tmp->next = *top;
  *top = tmp;
}

int max_stack(stack *s) {
	int max = s->data;
	while(s != NULL) {
		if(s->data > max) {
			max = s->data;
		}

		s = s->next; 
	}
	return max;
}

int min_stack(stack *s) {
	int min = s->data;
	while(s != NULL) {
		if(s->data < min) {
			min = s->data;
		}

		s = s->next; 
	}
	return min;
}

void delete_stack_node(stack **s, int val) {
	stack *prev = NULL, *curr = *s;
	while(curr != NULL) {
		if(curr->data == val) {
			if(prev != NULL) {
				prev->next = curr->next;

			} else {
				*s = curr->next;

			}
			
			free(curr);
			return;

		}

		prev = curr;
		curr = curr->next; 
	}
}

int search_stack(stack *s, int data, int *steps) {
	*steps = 0;
	while(s != NULL) {
		if(s->data == data) {
			return 1;
		}

		(*steps)++;
		s = s->next;
	}
	return 0;
}

stack * copy_stack(stack *s) {
	stack *rtr = NULL;
	stack *curr = s;
	while(curr != NULL) {
		push(&rtr, curr->data);
		curr = curr->next;

	}
	return rtr;
}

/***********************************/
//STACK OPERATORS end
/***********************************/

/***********************************/
//BST OPERATORS start
/***********************************/

bst * create_bst(int data) {
  bst *rtr = (bst *)malloc(sizeof(bst));
  rtr->data = data;
  rtr->right = rtr->left = NULL;
  return rtr;
}

bst * insert_bst(bst *root, int data) {
  if(root == NULL) return create_bst(data);
  else if(data > root->data) root->right = insert_bst(root->right, data);
  else root->left = insert_bst(root->left, data);
}

int search_bst(bst *root, int data, int *steps) {
  (*steps)++;
  if(root == NULL) return 0;
  if(root->data == data) return 1;
  if(data > root->data) return search_bst(root->right, data, steps); 
  if(data < root->data) return search_bst(root->left, data, steps);
}

void delete_max_bst(bst **myb) {
	bst *curr = *myb, *prev = NULL;
	while(curr->right != NULL) {
		prev = curr;
		curr = curr->right;
	}
	if(prev == NULL) {
		*myb = curr->left;

	} else {
		if(curr->right != NULL) prev->right = curr->right;
		else prev->right = curr->left;
		
	}
	free(curr);
}

void delete_min_bst(bst **myb) {
	bst *curr = *myb, *prev = NULL;
	while(curr->left != NULL) {
		prev = curr;
		curr = curr->left;
	}
	if(prev == NULL) {
		*myb = curr->right;

	} else {
		if(curr->right != NULL) prev->left = curr->right;
		else prev->left = curr->left;
	}
	free(curr);
}

int max_bst(bst *root) {
	while(root->right != NULL) {
		root = root->right;
	}
	return root->data;
}

int min_bst(bst *root) {
	while(root->left != NULL) {
		root = root->left;
	}
	return root->data;
}

void print_bst(bst *root) {
  if(root != NULL) {
    print_bst(root->right);
    printf("%d ", root->data);
    print_bst(root->left);
  }
}

/***********************************/
//BST OPERATORS end
/***********************************/

/***********************************/
//HW10 OPERATORS start
/***********************************/

/**********************/
/* Filling benchmarks */
/**********************/

double fill_stack(stack ** stack_, int data[DATA_LEN]) {
  clock_t begin = clock(), end;
  double rtr;

  for (int i = 0; i < DATA_LEN; i++) {
    push(stack_, data[i]);
  }

  end = clock();
  rtr = ((double)(end - begin)) / CLOCKS_PER_SEC;
  return rtr;
}

double fill_queue(queue ** queue_, int data[DATA_LEN]) {
  clock_t begin = clock(), end;
  double rtr;

  *queue_ = create_queue();
  for (int i = 0; i < DATA_LEN; i++) {
    enqueue(*queue_, data[i]);
  }

  end = clock();
  rtr = ((double)(end - begin)) / CLOCKS_PER_SEC;
  return rtr;
}

double fill_bst(bst ** bst_, int data[DATA_LEN]) {
  clock_t begin = clock(), end;
  double rtr;

  *bst_ = create_bst(data[0]);
  for (int i = 1; i < DATA_LEN; i++) {
    insert_bst(*bst_, data[i]);
  }

  end = clock();
  rtr = ((double)(end - begin)) / CLOCKS_PER_SEC;
  return rtr;
}

void fill_structures(stack ** stack_, queue ** queue_, bst ** bst_, int data[20]) {

  double stack_time, queue_time, bst_time;

  *stack_ = NULL;
  *queue_ = NULL;
  *bst_ = NULL;

  stack_time = fill_stack(stack_, data);
  queue_time = fill_queue(queue_, data);
  bst_time = fill_bst(bst_, data);
  stack_time *= TIME_UNIT;
  queue_time *= TIME_UNIT;
  bst_time *= TIME_UNIT;
  printf("S filled in: %.3fms\nQ filled in: %.3fms\nBST filled in: %.3fms\n\n", stack_time, queue_time, bst_time);

}

/****************************/
/* Ordered print benchmarks */
/****************************/

double ordered_print_stack(stack * stack_) {
  stack * copy = copy_stack(stack_);	
  clock_t begin = clock(), end;
  double rtr;
  int max;

  printf("Printing stack ordered\ntop-> ");
  while(copy != NULL) {
  	max = max_stack(copy);
  	printf("%d ", max);
  	delete_stack_node(&copy, max);
  }  
  printf("\n");

  end = clock();
  rtr = ((double)(end - begin)) / CLOCKS_PER_SEC;
  return rtr;
}

double ordered_print_queue(queue * queue_) {
  queue * copy = copy_queue(queue_);
  clock_t begin = clock(), end;
  double rtr;
  int max;

  printf("Printing queue ordered\nfront-> ");
  while(copy->front != NULL) {
  	max = max_queue(copy);
  	printf("%d ", max);
  	delete_queue_node(copy, max);
  }  
  printf("<-rear\n");

  end = clock();
  rtr = ((double)(end - begin)) / CLOCKS_PER_SEC;
  return rtr;
}

double ordered_print_bst(bst * bst_) {
  clock_t begin = clock(), end;
  double rtr;

  printf("Printing bst ordered\n");
  print_bst(bst_);
  printf("\n");

  end = clock();
  rtr = ((double)(end - begin)) / CLOCKS_PER_SEC;
  return rtr;
}

void ordered_print(stack * stack_, queue * queue_, bst * bst_) {

  double stack_time, queue_time, bst_time;

  stack_time = ordered_print_stack(stack_);
  queue_time = ordered_print_queue(queue_);
  bst_time = ordered_print_bst(bst_);
  stack_time *= TIME_UNIT;
  queue_time *= TIME_UNIT;
  bst_time *= TIME_UNIT;
  printf("S printed in ordered in: %.3fms\n", stack_time);
  printf("Q printed in ordered in: %.3fms\n", queue_time);
  printf("BST printed in ordered in: %.3fms\n\n", bst_time);

}

/************************/
/* Searching benchmarks */
/************************/

double search_test_stack(stack * stack_, int val_to_search, int *is_found, int *steps) {
  clock_t begin = clock(), end;
  double rtr;

  *is_found = search_stack(stack_, val_to_search, steps);

  end = clock();
  rtr = ((double)(end - begin)) / CLOCKS_PER_SEC;
  return rtr;
}

double search_test_queue(queue * queue_, int val_to_search, int *is_found, int *steps) {
  clock_t begin = clock(), end;
  double rtr;

  *is_found = search_queue(queue_, val_to_search, steps);

  end = clock();
  rtr = ((double)(end - begin)) / CLOCKS_PER_SEC;
  return rtr;
}

double search_test_bst(bst * bst_, int val_to_search, int *is_found, int *steps) {
  clock_t begin = clock(), end;
  double rtr;

  *steps = 0;
  *is_found = search_bst(bst_, val_to_search, steps);

  end = clock();
  rtr = ((double)(end - begin)) / CLOCKS_PER_SEC;
  return rtr;
}

void search(stack * stack_, queue * queue_, bst * bst_, int val_to_search) {

  double stack_time, queue_time, bst_time;
  int is_found_stack, is_found_queue, is_found_bst;
  int steps_stack, steps_queue, steps_bst;
  stack_time = search_test_stack(stack_, val_to_search, &is_found_stack, &steps_stack);
  queue_time = search_test_queue(queue_, val_to_search, &is_found_queue, &steps_queue);
  bst_time = search_test_bst(bst_, val_to_search, &is_found_bst, &steps_bst);
  stack_time *= TIME_UNIT;
  queue_time *= TIME_UNIT;
  bst_time *= TIME_UNIT;
  printf("%s %d in S in %d steps in: %.3fms\n", is_found_stack ? "Found":"Not Found",val_to_search, steps_stack, stack_time);
  printf("%s %d in Q in %d steps in: %.3fms\n", is_found_queue ? "Found":"Not Found",val_to_search, steps_queue, queue_time);
  printf("%s %d in BST in %d steps in: %.3fms\n\n", is_found_bst ? "Found":"Not Found",val_to_search, steps_bst, bst_time);

}

/******************************/
/* Special traverse benchmark */
/******************************/

double special_stack(stack * stack_) {
  stack *copy = copy_stack(stack_);
  clock_t begin = clock(), end;
  double rtr;
  int max, min, flip = 1;

  printf("Special printing stack\n");
  while(copy != NULL) {
  	switch(flip) {
  		case 1:
  			max = max_stack(copy);
		  	printf("%d ", max);
		  	delete_stack_node(&copy, max);		
		  	flip = 2;
  		break;
  		case 2:
  			min = min_stack(copy);
		  	printf("%d ", min);
		  	delete_stack_node(&copy, min);
		  	flip = 1;
  		break;
  	}
  }
  printf("\n");

  end = clock();
  rtr = ((double)(end - begin)) / CLOCKS_PER_SEC;
  return rtr;
}

double special_queue(queue * queue_) {
  queue *copy = copy_queue(queue_);
  clock_t begin = clock(), end;
  double rtr;
  int max, min, flip = 1;

  printf("Special printing queue\n");
  while(copy->front != NULL) {
  	switch(flip) {
  		case 1:
  			max = max_queue(copy);
		  	printf("%d ", max);
		  	delete_queue_node(copy, max);		
		  	flip = 2;
  		break;
  		case 2:
  			min = min_queue(copy);
		  	printf("%d ", min);
		  	delete_queue_node(copy, min);
		  	flip = 1;
  		break;
  	}
  }  
  printf("\n");

  end = clock();
  rtr = ((double)(end - begin)) / CLOCKS_PER_SEC;
  return rtr;
}

double special_bst(bst * bst_) {
  clock_t begin = clock(), end;
  double rtr;
  int max, min, flip = 1; //1-max, 2-min

  printf("Special printing bst\n");
  while(bst_ != NULL) {
  	switch(flip) {
  		case 1:
  			max = max_bst(bst_);
		  	printf("%d ", max);
		  	delete_max_bst(&bst_);		
		  	flip = 2;
  		break;
  		case 2:
  			min = min_bst(bst_);
		  	printf("%d ", min);
		  	delete_min_bst(&bst_);
		  	flip = 1;
  		break;
  	}
  }
  printf("\n");

  end = clock();
  rtr = ((double)(end - begin)) / CLOCKS_PER_SEC;
  return rtr;
}

void special_traverse(stack * stack_, queue * queue_, bst * bst_) {

  double stack_time, queue_time, bst_time;

  stack_time = special_stack(stack_);
  queue_time = special_queue(queue_);
  bst_time = special_bst(bst_);
  stack_time *= TIME_UNIT;
  queue_time *= TIME_UNIT;
  bst_time *= TIME_UNIT;
  printf("S special printed in: %.3fms\n", stack_time);
  printf("Q special printed in: %.3fms\n", queue_time);
  printf("BST special printed in: %.3fms\n\n", bst_time);

}

/***********************************/
//HW10 OPERATORS end
/***********************************/

int main() {

  int data[20]={5, 2, 7, 8, 11, 3, 21, 7, 6, 15, 19, 35, 24, 1, 8, 12, 17, 8, 23, 4};

  bst * bst_;
  queue * queue_;
  stack * stack_;

  fill_structures(&stack_, &queue_, &bst_, data);

  ordered_print(stack_, queue_, bst_);

  search(stack_, queue_, bst_, 5);

  special_traverse(stack_, queue_, bst_);

  return 0;

}
