#include <stdio.h>

void makeup_exam(int midterm, int final, int absenteeism);

int main() {

	int input;

	int data[3][3];

	for(int i = 0; i < 3; i++) {

		printf("Enter midterm for %d. student:", i+1);
		scanf("%d", &input);
		data[i][0] = input;
		printf("Enter final for %d. student:", i+1);
		scanf("%d", &input);
		data[i][1] = input;
		printf("Enter absenteeism for %d. student:", i+1);
		scanf("%d", &input);
		data[i][2] = input;

		printf(" \n");

	}

	for(int i = 0; i < 3; i++) {
		printf("Student %d\t", i+1);
	
		printf("Midterm %d\t", data[i][0]);
		printf("Final %d\t", data[i][1]);
		printf("Abs.perc %d\t", data[i][2]);
		printf("MAKEUP EX ");
		makeup_exam(data[i][0], data[i][1], data[i][2]);
		
	}

}

void makeup_exam(int midterm, int final, int absenteeism) {

	if(absenteeism >= 80) {
		printf("NO\n");
		return;
	}

	double avg = midterm * 40 / 100;
	avg += final * 60 / 100;

	if(avg >= 59.5) {
		printf("NO\n");
		return;
	} else {
		printf("YES\n");
	}

}