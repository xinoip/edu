#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
	unsigned int capacity;
	int front, rear, size;
	int *data;
} queue_t;

/* Optionally, you can seperate your data, then include it in main struct */
typedef struct Data {
	//Put your data here
} data_t;

queue_t * create_queue(unsigned int capacity) {
	queue_t *rtr = (queue_t *)malloc(sizeof(queue_t));

	rtr->capacity = capacity;
	rtr->front = 0;
	rtr->rear = capacity - 1;
	rtr->size = 0;

	rtr->data = malloc(sizeof(int) * capacity);

	return rtr;

}

int isFull(queue_t *queue) {
  	return (queue->size == queue->capacity);  
} 
  

int isEmpty(queue_t *queue) { 
	return (queue->size == 0); 
}

void enqueue(queue_t *queue, int data) {

	int new_rear = (queue->rear + 1) % (queue->capacity);

	if(isFull(queue)) {
		printf("Queue overflowed at stack, while enqueue!\n");
		exit(-1);

	} else {
		printf("Enqueueing %d to queue...\n", data);

		queue->rear = new_rear;
		queue->data[queue->rear] = data;
		queue->size++;

	}

}

void dequeue(queue_t *queue) {

	int new_front = (queue->front + 1) % (queue->capacity);

	if(isEmpty(queue)) {
		printf("Queue underflowed at stack, while dequeue!\n");
		exit(-1);

	} else {
		printf("Dequeueing %d from queue...\n", queue->data[queue->front]);

		queue->front = new_front;
		queue->size--;

	}

}

int get_front(queue_t *queue) {

	int rtr;

	if(isEmpty(queue)) {
		printf("Queue underflowed at stack, while get_front!\n");
		exit(-1);

	} else {
		rtr = queue->data[queue->front];

	}

	return rtr;

}

int get_rear(queue_t *queue) {

	int rtr;

	if(isEmpty(queue)) {
		printf("Queue underflowed at stack, while get_rear!\n");
		exit(-1);

	} else {
		rtr = queue->data[queue->rear];

	}

	return rtr;

}

int main() {

	queue_t *myq = create_queue(5);

	enqueue(myq, 5);
	enqueue(myq, 6);
	enqueue(myq, 7);
	enqueue(myq, 8);

	printf("Current front element: %d\n", get_front(myq));
	printf("Current rear element: %d\n", get_rear(myq));		

	dequeue(myq);
	dequeue(myq);
	dequeue(myq);
	dequeue(myq);

}











