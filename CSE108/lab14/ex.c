#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Data to hold */
typedef struct Lesson {
	char *code, *name, *class;
	int ccity;
	double credit;
} lesson_t;

/* Queue Nodes */
typedef struct Node {
	lesson_t *data;
	struct Node *next;
} node_t;

/* Queue itself */
typedef struct Queue {
	node_t *front, *rear;
} queue_t;

/* Reverse print helper func for pqueue */
void rev_pqueue(queue_t *q) {

	node_t *curr = q->front;
	node_t *prev;

	while(curr != q->rear) {
		prev = curr;
		curr = curr->next;
	}

	printf("%s, %s, %s, %d, %lf\n", 
		curr->data->code,
		curr->data->name,
		curr->data->class,
		curr->data->ccity,
		curr->data->credit);

	q->rear = prev;

	if(q->rear == q->front) {
		return;
	} else {
		rev_pqueue(q);	
	}

}

/* Prints queue, dir = 1 prints straight, dir = 2 prints reverse */
void pqueue(queue_t *q, int dir) {
	
	switch(dir) {
		case 1:
			printf("Printing queue front to end..\n");
			while(q->front != NULL) {
				printf("%s, %s, %s, %d, %lf\n", 
					q->front->data->code,
					q->front->data->name,
					q->front->data->class,
					q->front->data->ccity,
					q->front->data->credit);

				q->front = q->front->next;

			}
			printf("\n");
		break;
		case 2:
			printf("Printing queue end to front..\n");
			rev_pqueue(q);
			printf("%s, %s, %s, %d, %lf\n", 
					q->front->data->code,
					q->front->data->name,
					q->front->data->class,
					q->front->data->ccity,
					q->front->data->credit);

				q->front = q->front->next;
		break;
	}
	
}

/* Creates lesson_t from a line string */
lesson_t * create_lesson_f(char *line) {
	lesson_t *rtr = malloc(sizeof(lesson_t));

	rtr->code = malloc(sizeof(char)*100);
	rtr->name = malloc(sizeof(char)*100);
	rtr->class = malloc(sizeof(char)*100);
	char *tmp_ccity = malloc(sizeof(char) * 100);
	char *tmp_credit = malloc(sizeof(char) * 100);

	sscanf(line, "%[^,], %[^,], %[^,], %[^,], %[^,];", 
		rtr->code, rtr->name, rtr->class, tmp_ccity, tmp_credit);

	rtr->ccity = atoi(tmp_ccity);
	rtr->credit = atof(tmp_credit);

	return rtr;
}

/* Create queue node */
node_t * create_node(lesson_t *data) {
	node_t *rtr = (node_t *)malloc(sizeof(node_t));

	rtr->data = data;
	rtr->next = NULL;

	return rtr;
}

/* Create queue itself */
queue_t * create_queue() {
	queue_t *rtr = (queue_t *)malloc(sizeof(queue_t));

	rtr->front = rtr->rear = NULL;

	return rtr;
}

/* Enqueue lesson to main queue*/
void enqueue(queue_t *queue, lesson_t *data) {

	node_t *new_node = create_node(data);

	printf("Enqueueing to queue...\n");

	if(queue->rear == NULL) {
		queue->rear = new_node;
		queue->front = new_node;

	} else {
		queue->rear->next = new_node;
		queue->rear = new_node;

	}

}

/* Fill queue from file "filename" */
void fill_queue(char filename[15], queue_t *course_queue) {

	FILE *fin = fopen(filename, "r");

	while(!feof(fin)) {
		char buffer[300];

		fgets(buffer, 300, fin);

		enqueue(course_queue, create_lesson_f(buffer));

	}

	fclose(fin);

}

int main() {

	queue_t *myq = create_queue();

	fill_queue("./data.txt", myq);

	printf("\n\n");

	pqueue(myq, 1);


}