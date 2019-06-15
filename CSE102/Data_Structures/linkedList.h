typedef struct Linkedlist {
	void *data;
	struct Linkedlist *next;
} list_t;

list_t * create_list();
list_t * push(void data);
list_t * pop();