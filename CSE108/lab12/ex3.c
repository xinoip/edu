#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int n;
	struct Node *next;
} node_t;

void plist_n(node_t *head) {
	node_t *curr = head;
	int i = 1;
	while(curr != NULL) {
		printf("%d. data: %d\n", i++, curr->n);
		curr = curr->next;
	}
}

int sum_n(node_t *head) {
	node_t *curr = head;
	int sum = 0;
	while(curr != NULL) {
		sum += curr->n;
		curr = curr->next;
	}
	return sum;
}

node_t *create_node(int data) {
	node_t *rtr = (node_t *)malloc(sizeof(node_t));
	rtr->n = data;
	rtr->next = NULL;
	return rtr;
}

int main() {

	int input_n = 0, first_run = 1;
	node_t *head = create_node(0);
	node_t *curr = head;

	printf("Input numbers: ");
	while(input_n != -1) {
		scanf("%d", &input_n);
		if(input_n == -1) {
			break;
		}
		if(first_run) {
			head->n = input_n;
			first_run = 0;
		
		} else {
			curr->next = create_node(input_n);
			curr = curr->next;		
		}
	}

	plist_n(head);
	printf("Sum = %d\n", sum_n(head));

}
