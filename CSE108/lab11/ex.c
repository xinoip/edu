#include <stdio.h>
#include <stdlib.h>

typedef struct Dynarr {
	int *nums;
	int limit, end_index;
} dynarr_t;

void init(dynarr_t *arr);
void insert(dynarr_t *arr, int insertion_index, int input_value);
void print_arr(dynarr_t *arr);
void insert_int(int *nums, int index, int i, int len);
void delete(dynarr_t *arr, int deletion_index);

int main() {

	dynarr_t *myarr = (dynarr_t *)malloc(sizeof(dynarr_t));

	init(myarr);

	print_arr(myarr);

	/* Case 1 */
	printf("Case 1  ");
	insert(myarr, 0, 12);
	insert(myarr, 1, 13);
	insert(myarr, 2, 14);
	insert(myarr, 3, 15);
	print_arr(myarr);

	insert(myarr, 2, 30);
	printf("Res     ");
	print_arr(myarr);


	return 0;

	/* Case 2 */
	printf("Case 2  ");
	insert(myarr, 4, 16); //arr is filled now
	print_arr(myarr);

	insert(myarr, 5, 21); //insertion index = limit
	printf("Case 2  ");
	print_arr(myarr);

	/* Case 3 */
	printf("Case 3  ");
	insert(myarr, 2, 34); //arr has empty but insertion index is filled already
	print_arr(myarr);

	/* Case 4 */ 
	printf("Case 4  ");
	//insert(myarr, 2, 41);
	insert(myarr, 6, 41);
	insert(myarr, 7, 42);
	print_arr(myarr);

	/* Last part */
	printf("Case delete   ");
	delete(myarr, 3);
	delete(myarr, 7);
	print_arr(myarr);

}

void print_arr(dynarr_t *arr) {

	printf("| ");
	for(int i = 0; i < arr->limit; i++) {
		printf("%d | ", arr->nums[i]);
	}
	printf("\n");

}

/* Insert int after the index to arr */
void insert_int(int *nums, int index, int i, int len) {

	int counter = len;

	while(counter >= index) {
		nums[counter+1] = nums[counter];
		counter--;
	}

	nums[index] = i;

}

void init(dynarr_t *arr) {
	arr->limit = 5;
	arr->end_index = 0;
	arr->nums = calloc(arr->limit, sizeof(int));
	for(int i = 0; i < arr->limit; i++) {
		arr->nums[i] = 0;
	}
}

void delete_int(int *nums, int index, int len) {

	int counter = index;

	while(counter != len+1) {
		nums[counter] = nums[counter+1];
		counter++;
	}

}

void delete(dynarr_t *arr, int deletion_index) {
	delete_int(arr->nums, deletion_index, arr->end_index);
}

void insert(dynarr_t *arr, int insertion_index, int input_value) {

	int tmp, tmp2;

	if(arr->end_index == (arr->limit)-1) { //arr full

		if(insertion_index > (arr->end_index) + 1) {
			printf("Can't skip empty spaces!\n");
			return;
		} else {
			arr->limit += 5;
			arr->nums = realloc(arr->nums, (arr->limit) * sizeof(int));
		}

		if(insertion_index == (arr->end_index)) { //add before end, shift end
			tmp = arr->nums[insertion_index];
			arr->nums[insertion_index+1] = tmp;
			arr->nums[insertion_index] = input_value;
			arr->end_index += 1;

		} else if(insertion_index == (arr->end_index)+1) { //add after end
			arr->nums[insertion_index] = input_value;
			arr->end_index = insertion_index;

		} else if(insertion_index < arr->end_index) { //add middle and shift
			/*tmp = arr->nums[insertion_index];
			arr->nums[insertion_index] = input_value;
			arr->end_index++;

			for(int i = insertion_index+1; i <= arr->end_index; i++) {
				tmp2 = arr->nums[i];
				if(i == insertion_index+1) {
					arr->nums[i] = tmp;	
				} else {
					arr->nums[i] = tmp2;
				}
				
			}*/

			arr->end_index++;
			insert_int(arr->nums, insertion_index, input_value, arr->end_index);


		}

	} else { //arr has empty spaces

		if(insertion_index == arr->end_index) { //add before end, shift end
			tmp = arr->nums[insertion_index];
			arr->nums[insertion_index] = input_value;
			arr->nums[insertion_index+1] = tmp;
			arr->end_index++;

		} else if(insertion_index < arr->end_index) { //add middle and shift
		
			arr->end_index++;
			insert_int(arr->nums, insertion_index, input_value, arr->end_index);

		} else {
			printf("Cant\n");
			return;
		}		

	}

	if(arr->end_index > insertion_index) { //ortaya ekleme

	} else if(arr->end_index == insertion_index) { //sona ekleme

	} else if(arr->end_index < insertion_index) { //sondan 1 sonraya ekleme

	}

	

}