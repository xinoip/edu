#include <stdio.h>
#include <stdlib.h>

int main() {

	int arraySize = 0; 
	int *array = malloc(arraySize * sizeof(int));
	if (!array) {
	    printf("I can't allocate memory\n");
	    return 0;
	}

	int x;
	int numberOfElements = 0;
	for(;;) {          
	    printf("Enter value(-1 to exit): ");
	    scanf("%d",&x);

	    if(x == -1) {
	    	printf("\nDisplaying...\n\n");
	    	break;
	    }
    
        if(numberOfElements == arraySize) {
            arraySize++; 
            array = realloc(array, arraySize * sizeof(int));
            if (!array) {
                printf("I can't allocate memory\n");
                break;
            }
        }
        array[numberOfElements] = x;
    	numberOfElements++;
	}

	int *ptr = array;
	int *const arrayEnd = ptr + arraySize;

	for(int a = 0;ptr < arrayEnd; ptr++, a++) {
		printf("array[%d] = %d\n", a,*ptr);
	}
	
}


