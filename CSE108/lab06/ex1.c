#include <stdio.h>

void read_forecast(float wf[4][7]);
void select_city_and_day(float ave[4][3]);
void city_avt(float wf[4][7], float ave[4][3]);

int main() {

	float wf[4][7] = {
		{8,12,17,19,19,17,14},			//ankara
		{12.5,16,19.5,18,17,12,11.5},	//istanbul
		{14,21,19,20,20,19,18}, 		//izmir
		{18,21.5,21,19,20,22,21}  		//antalya
	};

	float ave[4][3];

	read_forecast(wf);
	city_avt(wf, ave);

	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 3; j++) {
			printf("%f   ", ave[i][j]);
		}
		printf("\n");
	}

	select_city_and_day(ave);

}

void read_forecast(float wf[4][7]) {

	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 7; j++) {
			printf("Enter temp for City %d, day %d:", i+1, j+1);
			scanf("%f", &wf[i][j]);
		}
		printf("\n");
	}

	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 7; j++) {
			printf("%.2f    ", wf[i][j]);
		}
		printf("\n");
	}

}

void city_avt(float wf[4][7], float ave[4][3]) {

	int rows = 0, index = 0;
	float tmp = 0;

	while(rows < 4) {

		for(int i = 0; i < 3; i++) { //0,1,2
			for(int j = i; j < i+5; j++) {
				//printf("(%d,%d) ", rows, j); 
				tmp += wf[rows][j];
			}
			//printf("\n");
			tmp /= 5;
			//printf("R(%d,%d) ", rows,index);
			ave[rows][index] = tmp;
			tmp = 0;
			if(index < 2) {
				index++;
			} else {
				index = 0;
			}
		}

		rows++;
	}

}

void select_city_and_day(float ave[4][3]) {

	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 3; j++) {
			if(ave[i][j] >= 20) {
				printf("City %d, Days %d\n", i+1, j+1);
				printf("\n");
			}
		}
	}

}