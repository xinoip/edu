#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} node_t;

typedef struct Queue {
	node_t *front, *rear;
} queue_t;

void pqueue(queue_t *q) {
	printf("Printing queue front to end..\n");
	while(q->front != NULL) {
		printf("%d ", q->front->data);
		q->front = q->front->next;

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

int isEmpty(queue_t *queue) { 
	return (queue->front == NULL); 
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

void dequeue(queue_t *queue) {

	node_t *temp;

	if(queue->front == NULL) {
		printf("Underflow at heap, while dequeue!\n");
		exit(-1);

	} else {
		printf("Dequeueing %d from queue...\n", queue->front->data);

		temp = queue->front;
		queue->front = queue->front->next;

		if(queue->front == NULL) {
			queue->rear = NULL;

		}

		free(temp);

	}

}


int get_front(queue_t *queue) {

	int rtr;

	if(isEmpty(queue)) {
		printf("Queue underflowed at heap, while get_front!\n");
		exit(-1);

	} else {
		rtr = queue->front->data;

	}

	return rtr;

}

int get_rear(queue_t *queue) {

	int rtr;

	if(isEmpty(queue)) {
		printf("Queue underflowed at heap, while get_rear!\n");
		exit(-1);

	} else {
		rtr = queue->rear->data;

	}

	return rtr;

}

int main() {

	queue_t *myq = create_queue(5);

	enqueue(myq, 5);
	enqueue(myq, 6);
	enqueue(myq, 7);
	enqueue(myq, 8);

	pqueue(myq);

	printf("Current front element: %d\n", get_front(myq));
	printf("Current rear element: %d\n", get_rear(myq));		

	dequeue(myq);
	dequeue(myq);
	dequeue(myq);
	dequeue(myq);

	pqueue(myq);

}