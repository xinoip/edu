#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
	char name[100];
	char surname[100];
	char musical_Work[100];
	int age;
	struct person *next;
} *top;

typedef struct person person_t;

/* Prints person at given pointer */
void print_person(person_t *ptr) {
	printf("Printing person...\n");
	printf("Name: %s\nSurname: %s\nMusical Work: %s\nAge: %d\n\n", ptr->name, ptr->surname, ptr->musical_Work, ptr->age);	
}

/* Prints stack from given pointer to bottom */
void print_stack(person_t *ptr) {
	printf("Printing stack from top to last element...\n\n");
	while(ptr != NULL) {
		print_person(ptr);
		ptr = ptr->next;

	}
	printf("\n");
}

/* Creates a person_t and returns a pointer to it */
person_t * create_person(char name[], char surname[], char musical_Work[], int age) {
	person_t *rtr 	= (person_t *)malloc(sizeof(person_t));

	strcpy(rtr->name, name);
	strcpy(rtr->surname, surname);
	strcpy(rtr->musical_Work, musical_Work);
	rtr->age = age;
	rtr->next = NULL;

	return rtr;
}

/* If top is null then stack is empty */
int is_empty() {
	return (top == NULL);
}

/* Creates a person_t with given properties and pushes it to the stack */
void addNode(char name[], char surname [], char creation [], int age) {

	person_t *new_person = create_person(name, surname, creation, age);

	if(is_empty()) {			/* If stack is empty */
		top = new_person;		/* Just initialize the top with new person */

	} else {
		new_person->next = top; /* Add the new node before top node */
		top = new_person;		/* Update the top to be new node */

	}	

}

/* Removes a person from stack (pop operator) and returns it's information as person_t */
person_t deleteNode() {

	person_t *tmp = top;	/* Temporary link to top of the stack */
	person_t rtr;			/* Return value for function */

	if(is_empty()) {		/* Empty check */
		printf("Stack is empty, nothing to delete!\n");

	} else {
		/* Set return values */
		strcpy(rtr.name, top->name);
		strcpy(rtr.surname, top->surname);
		strcpy(rtr.musical_Work, top->musical_Work);
		rtr.age = top->age;

		top = top->next;	/* The node after the top is new top */

		free(tmp);			/* Free the old node using temporary link */
		
	}

	return rtr;

}

/* Prints the menu for user */
void print_menu() {
	
	printf("****MENU****\n");
	printf("\t1- Add a Person to the Stack\n");
	printf("\t2- Pop a Person from the Stack\n");
	printf("\t3- Sort Alphabetical Order\n");
	printf("\t4- Sort Age in Increasing Order\n");
	printf("\t5- Exit menu\n");
	printf("*************\n");
	printf("Select your Choise: ");
	
}

/* Resetting stdin buffer */
void reset_stdin() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) { } /* Read remaining chars */
}

/* SORTING ALGORITHM 
	
	For sort function;
	Until stack is empty:
		1- Pop the first element and hold it somewhere
		2- Call sort function
		3- Call insert function to insert popped element to stack with respect to sorting conditions

	For insert function;
	if condition met:
		1- Push the given element to stack
	else:
		1- Pop the first element and hold it somewhere
		2- Call insert function again (We are tring to find first place to put the current element) 
		3- After inserting successfuly, push the last popped node to stack

	Condition can change but algorithm will be still same.
*/ 

/*********** SORTING BY AGE START ***********/
void Sort_Increasingly_helper(person_t element);
void Sort_Increasingly() {
	
	person_t temp;
	
	if(!is_empty()) {
		temp = deleteNode();
		Sort_Increasingly();
		Sort_Increasingly_helper(temp);
	}

}

void Sort_Increasingly_helper(person_t element) {
	
	person_t temp;
	
	if(is_empty() || element.age < top->age) {
		addNode(element.name, element.surname, element.musical_Work, element.age);
		
	} else {
		temp = deleteNode();
		Sort_Increasingly_helper(element);
		addNode(temp.name, temp.surname, temp.musical_Work, temp.age);
		
	}
	
}
/*********** SORTING BY AGE END ***********/

/*********** SORTING BY NAME START ***********/
void Sort_Alphabetically_helper(person_t element);
void Sort_Alphabetically() {
	
	person_t temp;
	
	if(!is_empty()) {
		temp = deleteNode();
		Sort_Alphabetically();
		Sort_Alphabetically_helper(temp);
	}
	
}

void Sort_Alphabetically_helper(person_t element) {
	
	person_t temp;
	
	if(is_empty() || strcmp(element.name, top->name) < 0) {
		addNode(element.name, element.surname, element.musical_Work, element.age);
		
	} else {
		temp = deleteNode();
		Sort_Alphabetically_helper(element);
		addNode(temp.name, temp.surname, temp.musical_Work, temp.age);
		
	}
	
}
/*********** SORTING BY NAME END ***********/

/* Control loop for user inputs */
void control_panel() {
	
	char name[100], surname[100], creation[100];
	int input = 0, age;							
	
	do {
		
		print_menu();
		scanf("%d", &input);
		
		switch(input) {
			case 1:
				reset_stdin();
				printf("Nameheyo: ");
				scanf("%[^\n]s", name);
				reset_stdin();
				printf("Surname: ");
				scanf("%[^\n]s", surname);
				reset_stdin();
				printf("Creation: ");			
				scanf("%[^\n]s", creation);
				reset_stdin();
				printf("Age: ");
				scanf("%d", &age);
				addNode(name, surname, creation, age);
				print_stack(top); 					
			break;
			case 2:
				printf("Deleting top element...\n\n");	 
				deleteNode();
				print_stack(top); 					
			break;	
			case 3:
				printf("Sorting by names...\n\n");	   
				Sort_Alphabetically(); 		
				print_stack(top); 	
			break;
			case 4:
				printf("Sorting by ages...\n\n");	     
				Sort_Increasingly(); 			
				print_stack(top); 	
			break;
			case 5:  printf("Exiting...\n"); 		break;
			default: printf("Enter an option from the list!\n"); break;
		}
		
	} while(input != 5);
	
}

int main() {
	
	control_panel();
	
}