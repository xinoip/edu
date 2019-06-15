#include <stdio.h>

int common(int a, int b);
void merge(int arr[], int left, int middle, int right);
void merge_sort(int arr[], int left, int right);
int function_3(int n);
int function_4(int n, int res, int digits);
char find_first_uppercase(char * str);

int digits(int n);
void print_arr(int arr[], int len);
int my_pow(int a, int b);

int main() {

	char str[300], c;
	int input, a, b;

	do {
		printf("\n-----Menu-----\n");
		printf("1) Common function\n");
		printf("2) Merge sort\n");
		printf("3) Function 3\n");
		printf("4) Function 4\n");
		printf("5) Find first uppercase\n");
		printf("6) Exit\n\n");
		printf("Enter option: ");
		scanf("%d", &input);

		switch(input) {
			case 1:
				printf("\nEnter 2 numbers: ");
				scanf("%d %d", &a, &b);
				printf("Result: %d\n", common(a, b));
			break;
			case 2: { //Because of declaring variable inside the case, needs scope.
				printf("Enter the length of the list: ");
				scanf("%d", &a);
				int arr[a];
				printf("Enter the elements of list: \n");
				for(int i = 0; i < a; i++) {
					scanf("%d", &arr[i]);
				}
				merge_sort(arr, 0, a-1);
				printf("Sorted array is: ");
				print_arr(arr, a);
			break; }
			case 3:
				printf("\nEnter positive number: ");
				scanf("%d", &a);
				function_3(a);
			break;
			case 4:
				printf("\nEnter number: ");
				scanf("%d", &a);
				printf("%s\n", function_4(a, a, digits(a)) ? "Equal":"Not Equal");
			break;
			case 5:
				printf("\nEnter string: ");
				scanf("%s", str);
				c = find_first_uppercase(str);
				if(c != -1) printf("%c\n", c);
			break;
			case 6: printf("\nExiting...\n"); break;
			default: printf("\nNo such option!\n"); break;
		}

	} while(input != 6);

}

/* Returns greates common divisor of a and b */
int common(int a, int b) { 
	if (b != 0) {
		return common(b, a % b);
	} else { 
       return a;
    }
}

/* Merge sort, recursively dividing array in halves and sorting */
void merge_sort(int arr[], int left, int right) { 
	int middle;
    if (left < right) {  
        middle = left+(right-left)/2; 
  
        merge_sort(arr, left, middle); 
        merge_sort(arr, middle+1, right); 
  
        merge(arr, left, middle, right); 
    } 
}

/* Sorts and merges given array by given points */
void merge(int arr[], int left, int middle, int right) { 
    int left_i, right_i, result_i; 
    int len_1 = middle - left + 1; 
    int len_2 =  right - middle; 
  	
  	/* Temp holders */
    int left_arr[len_1], right_arr[len_2]; 
  
    /* Trasnfer data to temp holder arrays */
    for (left_i = 0; left_i < len_1; left_i++) {
        left_arr[left_i] = arr[left + left_i]; 
    }
    for (right_i = 0; right_i < len_2; right_i++) {
        right_arr[right_i] = arr[middle + 1 + right_i]; 
    }
  
    /* Merge the temp arrays to result array, index initializations */
    right_i = 0; 
    left_i = 0; 
    result_i = left; 
    while (left_i < len_1 && right_i < len_2) { 
        if (left_arr[left_i] <= right_arr[right_i]) { 
            arr[result_i] = left_arr[left_i]; 
            left_i++; 
        } else { 
            arr[result_i] = right_arr[right_i]; 
            right_i++; 
        } 
        result_i++; 
    } 
  
    /* Transfer remainings */
    while (left_i < len_1) { 
        arr[result_i] = left_arr[left_i]; 
        left_i++; 
        result_i++; 
    } 
  
    while (right_i < len_2) { 
        arr[result_i] = right_arr[right_i]; 
        right_i++; 
        result_i++; 
    } 

} 

/* Collatz Conjecture */
int function_3(int n) { 
	printf("%d ", n);

	if(n == 1) return n;

	if(n % 2 == 0) {
		return function_3(n/2);
	} else {
		return function_3(3*n+1);
	}
}

/* Algorithm:
For 371, pass function_4(371, 371, digits(371))
n = 371, res = 371, digits = 3

Substract 1^digits (which is (371 % 10 ^ digits)) from res
Divide n by 10 so we eliminate last digit

n = 37, res = 370, digits = 3

Substract 7^digits (which is (37 % 10 ^ digits)) from res
Divide n by 10 so we eliminate last digit

n = 3, res = 27, digits = 3

Substract 3^digits (which is (3 % 10 ^ digits)) from res
Divide n by 10 so we eliminate last digit

n = 0, res = 0, digits = 3

Base case met, return (ress == 0) (Which means if ress is 0 return 1)

If equal returns 1, else returns 0
*/
int function_4(int n, int res, int digits) {
	if(n == 0) return (res == 0);

	res -= my_pow((n % 10),digits);
	
	return function_4(n/10, res, digits);
}

/* Returns first capital letter in the string */
char find_first_uppercase(char * str) {
	if(*str == '\0') {
		printf("There is no capital letter in the given string!\n");
		return -1;
	}

	if('A' <= *str && *str <= 'Z') return *str;

	return find_first_uppercase(&str[1]);
}

/* Return number of digits of n, recursively */
int digits(int n) {
	if(n == 0) return 0;
	return (1 + digits(n/10));
}

/* Prints integer array */
void print_arr(int arr[], int len) {
	for(int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
}

/* Returns a^b, recursively */
int my_pow(int a, int b) {
	if(b == 0) return 1;
	return a * my_pow(a, b-1);
}
