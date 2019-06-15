#include <stdio.h>

typedef struct {
	int rent;
	int bill;
	int food;
} COST;

int calc_cost(COST cost, int students);

int main() {

	COST mycost;
	int no_of_students;

	printf("Enter rent bill food: ");
	scanf("%d %d %d", &mycost.rent, &mycost.bill, &mycost.food);
	printf("Enter number of students: ");
	scanf("%d", &no_of_students);



	printf("Cost: %d\n", calc_cost(mycost, no_of_students));
	printf("Cost per student: %d\n", calc_cost(mycost, no_of_students) / no_of_students);

}

int calc_cost(COST cost, int students) {

	int rtr = 0, total_cost = 0;

	total_cost += cost.rent;
	total_cost += cost.bill;
	total_cost += cost.food;

	return total_cost;

	/*
	for(int i = 0; i < students; i++) {
		rtr += total_cost;
	}

	return rtr;*/

}