#include <stdio.h>
#include <string.h>

typedef struct Animal {
	char name[300], habitat[300], species[300];
	int length, weight;
} animal;

void fill_struct_array(animal table[4]); 
animal create_animal(char name[300], char habitat[300], char species[300], int length, int weight);
void length_info(animal table[4], int *max, int *min, double *average);
void filter_mammals(animal table[4], animal filtered_animals[4]);
void change_weight(animal *animal_to_change, int new_w);
void print_animals(animal table[4]);

int main() {

	animal table[4];
	int max, min;
	double avg;
	animal filtered_animals[4];

	fill_struct_array(table);
	length_info(table, &max, &min, &avg);
	
	print_animals(table);

	//printf("%d\n", table[0].weight);
	//change_weight(&table[0], 2);
	//printf("%d\n", table[0].weight);

	//print_animals(table);
	filter_mammals(table, filtered_animals);


	for(int i = 0; i < 4; i++) {
		printf("filterd animal %d: %s\n", i, filtered_animals[i].name);	
	}

	printf("max:%d min:%d avg:%f\n", max, min, avg);

}

void print_animals(animal table[4]) {
	printf("Name       | Species    | length(cm) | weight(kg) | Natural habitat\n");
	for(int i = 0; i < 4; i++) {
		printf("%10s | %10s | %10d | %10d | %10s\n", table[i].name, table[i].species, table[i].length, table[i].weight, table[i].habitat);
	}
}

void change_weight(animal *animal_to_change, int new_w) {
	animal_to_change->weight = new_w;
}

void filter_mammals(animal table[4], animal filtered_animals[4]) {
	int index = 0;
	for(int i = 0; i < 4; i++) {
		if(strcmp(table[i].species, "Mammals") == 0) {
			if(table[i].weight > 100) {
				if(strcmp(table[i].habitat, "Forest") == 0 || strcmp(table[i].habitat, "Savannah") == 0) {
					filtered_animals[index++] = create_animal(table[i].name, table[i].habitat, table[i].species, table[i].length, table[i].weight);		
				}
			}
		}
	}
}

void length_info(animal table[4], int *max, int *min, double *average) {
	*max = 0, *min = 9999;
	int sum = 0;
	for(int i = 0; i < 4; i++) {
		if(table[i].length > *max) {
			*max = table[i].length;
		}
		if(table[i].length < *min) {
			*min = table[i].length;
		}
		sum += table[i].length;
	}
	*average = sum / 4;
}

animal create_animal(char name[300], char habitat[300], char species[300], int length, int weight) {
	animal rtr;
	strcpy(rtr.name, name);
	strcpy(rtr.habitat, habitat);
	strcpy(rtr.species, species);
	rtr.length = length;
	rtr.weight = weight;
	return rtr;
}

void fill_struct_array(animal table[4]) {
	table[0] = create_animal("Lion", "Savannah", "Mammals", 200, 130);
	table[1] = create_animal("Dolphin", "Oceans", "Mammals", 300, 180);
	table[2] = create_animal("Shark", "Oceans", "Fish", 450, 250);
	table[3] = create_animal("Wolf", "Forest", "Mammals", 160, 60);
}