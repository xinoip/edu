#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} node_t;

typedef struct Queue {
	node_t *front, *rear;
} queue_t;

int isEmpty(queue_t *queue) { 
	return (queue->front == NULL); 
}

void pqueue(queue_t *q) {
	//printf("Printing queue front to end..\n");
	queue_t *curr = q;
	node_t *node = curr->front;
	if(curr == NULL) {
		printf("(empty)\n");
		return;
	}
	while(node != NULL) {
		printf("%d ", node->data);
		node = node->next;

	}
	printf("\n");
}

node_t * create_node(int data) {
	node_t *rtr = (node_t *)malloc(sizeof(node_t));

	rtr->data = data;
	rtr->next = NULL;

	return rtr;
}

queue_t * create_queue() {
	queue_t *rtr = (queue_t *)malloc(sizeof(queue_t));

	rtr->front = rtr->rear = NULL;

	return rtr;
}

void enqueue(queue_t *queue, int data) {

	node_t *new_node = create_node(data);

	printf("Enqueueing %d to queue...\n", data);

	if(queue->rear == NULL) {
		queue->rear = new_node;
		queue->front = new_node;

	} else {
		queue->rear->next = new_node;
		queue->rear = new_node;

	}

}

int dequeue(queue_t *queue) {

	node_t *temp;
	int rtr;

	if(queue->front == NULL) {
		printf("Underflow while dequeue!\n");
		rtr = -1;
		exit(-1);

	} else {
		printf("Dequeueing %d from queue...\n", queue->front->data);
		rtr = queue->front->data;
		temp = queue->front;
		queue->front = queue->front->next;
		
		if(queue->front == NULL) {
			queue->rear = NULL;

		}

		free(temp);

	}

	return rtr;

}

int main() {

	queue_t *myq = (queue_t *)malloc(sizeof(queue_t));
	myq = create_queue();

	//queue_t *myq = create_queue();

	int input, foo, input_2;

	do {
		printf("Queue operations:\n");
		printf("1. Print Queue\n");
		printf("2. Enqueue\n");
		printf("3. Dequeue\n");
		printf("4. Exit\n");
		printf("Enter option: ");
		scanf("%d", &input);

		switch(input) {
			case 1:
				pqueue(myq);
			break;
			case 2:
				printf("Enter new data to be enqueued: ");
				scanf("%d", &input_2);
				enqueue(myq, input_2);
				printf("front: %d\n", myq->front->data);
				printf("rear: %d\n", myq->rear->data);
			break;
			case 3:
				foo = dequeue(myq);
				printf("%d popped!\n", foo);
			break;
			case 4:
				printf("Exiting...\n");
			break;
		}
		printf("\n");

	} while(input != 4);


}