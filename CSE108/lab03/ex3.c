#include <stdio.h>

char letter_grade(int midterm, int final);

int main() {

	for(int i = 0; i < 3; i++) {
		int input1, input2;
		scanf("%d %d", &input1, &input2);
		printf("%c\n",letter_grade(input1,input2));	
	}
	
}

char letter_grade(int midterm, int final) {

	double avg = midterm * 40 / 100;
	avg += final * 60 / 100;

	printf("%lf\n", avg);

	if(avg >= 90) {
		//printf("A\n");
		return 'A';
	} else if(avg < 90 && avg >= 80) {
		//printf("B\n");
		return 'B';
	} else if(avg < 80 && avg >= 70) {
		//printf("C\n");
		return 'C';
	} else if(avg < 70 && avg >= 60) {
		//printf("D\n");
		return 'D';
	} else if(avg < 60) {
		//printf("F\n");
		return 'F';
	} 

}