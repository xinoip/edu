#include <stdio.h>

typedef struct {
	int hour;
	int minute;
	int second;
} TIME;

void difference_time(TIME start, TIME stop, TIME *diff);
void print_time(TIME a);

int main() {

	TIME start_time, stop_time, diff_time;

	printf("Start time (h m s): ");
	scanf("%d %d %d", &start_time.hour, &start_time.minute, &start_time.second);
	printf("Start time (h m s): ");
	scanf("%d %d %d", &stop_time.hour, &stop_time.minute, &stop_time.second);

	difference_time(start_time, stop_time, &diff_time);

	printf("Time elapsed: ");
	print_time(start_time);
	printf(" - ");
	print_time(stop_time);
	printf(" = ");
	print_time(diff_time);
	printf("\n");

}

void difference_time(TIME start, TIME stop, TIME *diff) {

	if(start.second < stop.second) {
		start.second += 60;
		start.minute -= 1;
	}
	diff->second = start.second - stop.second;

	if(start.minute < stop.minute) {
		start.minute += 60;
		start.hour -= 1;
	}
	diff->minute = start.minute - stop.minute;

	diff->hour = start.hour - stop.hour;



}

void print_time(TIME a) {
	printf("%d:%d:%d", a.hour, a.minute, a.second);
}