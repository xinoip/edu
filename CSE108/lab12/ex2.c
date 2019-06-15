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

node_t *create_node(int data) {
	node_t *rtr = (node_t *)malloc(sizeof(node_t));
	rtr->n = data;
	rtr->next = NULL;
	return rtr;
}

void reverse_nodes_between_n_to_m(node_t *head, int m, int n) {

	int first_run = 1;
	node_t *last = head, *lastcpy;
	node_t *prev, *ending = head, *starting = head;

	for(int i = 0; i < m+1; i++) {
		ending = ending->next;
	}

	for(int i = 0; i < n-1; i++) {
		starting = starting->next;
	}

	while(m != n) {
		last = head;
		for(int i = 0; i < m; i++) {
			prev = last;
			last = last->next;
		}
		if(first_run) {
			lastcpy = last;
			first_run = 0;
		}
		last->next = prev;
	
		m--;	
	}
	m--;
	for(int i = 0; i < m; i++) {
		prev = last;
		last = last->next;
	}

	last->next = ending;	
	starting->next = lastcpy;

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
	reverse_nodes_between_n_to_m(head, 4, 2);
	printf("\nAfter reversing\n\n");
	plist_n(head);

}
