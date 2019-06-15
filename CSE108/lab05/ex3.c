#include <stdio.h>

typedef enum day {Mon, Tue, Wed, Thu, Fri, Sat, Sun} day_t;
typedef enum month {Jan, Feb, Mar, Apr, May, June, July, Aug, Sept, Oct, Nov, Dec} month_t;
typedef enum year {y2019, y2020, y2021} year_t;

int calc_date(int n, int *dm, day_t *d, month_t *m, year_t *y);
void printDay(int n); 
void printMonth(int n);
void printYear(int n);

int main() {

	day_t d;
	month_t m;
	year_t y;
	int dm;

	calc_date(0, &dm, &d, &m, &y);
	printf("%d. day ", dm);
	printDay(d);
	printf(" ");
	printMonth(m);
	printf(" ");
	printYear(y);
	printf("\n");
	
	calc_date(360, &dm, &d, &m, &y);
	printf("%d. day ", dm);
	printDay(d);
	printf(" ");
	printMonth(m);
	printf(" ");
	printYear(y);
	printf("\n");

}

int calc_date(int n, int *dm, day_t *d, month_t *m, year_t *y) {

	if(n == 0) {
		*dm = 1;
		*d = Tue;
		*m = Jan;
		*y = y2019;
	}

	*dm = (*dm + n) % 30;
	*d = (*d + n) % 7;
	*m = (*m + (n/30)) % 12;
	*y = (*y + (n / 360) % 360);

}

void printDay(int n) {

	switch(n) {
		case 0:
			printf("Mon");
		break;
		case 1:
			printf("Tue");
		break;
		case 2:
			printf("Wed");
		break;
		case 3:
			printf("Thu");
		break;
		case 4:
			printf("Fri");
		break;
		case 5:
			printf("Sat");
		break;
		case 6:
			printf("Sun");
		break;
	}

}

void printMonth(int n) {

	switch(n) {
		case 0:
			printf("Jan");
		break;
		case 1:
			printf("Feb");
		break;
		case 2:
			printf("Mar");
		break;
		case 3:
			printf("Apr");
		break;
		case 4:
			printf("May");
		break;
		case 5:
			printf("June");
		break;
		case 6:
			printf("July");
		break;
		case 7:
			printf("Aug");
		break;
		case 8:
			printf("Sept");
		break;
		case 9:
			printf("Oct");
		break;
		case 10:
			printf("Nov");
		break;
		case 11:
			printf("Dec");
		break;
	}

}

void printYear(int n) {

	switch(n) {
		case 0:
			printf("2019");
		break;
		case 1:
			printf("2020");
		break;
		case 2:
			printf("2021");
		break;
	}

}
