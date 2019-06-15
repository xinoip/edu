#include <stdio.h>
#include <string.h>

typedef struct Pixel {
	char c;
	int row, col;
} pixel;

void fill_canvas(pixel canvas[8][14]);
pixel create_pixel(char c, int row, int col);
void show_canvas(pixel canvas[8][14]);
void find_shape(pixel canvas[8][14], char *shape);

int main() {

	pixel canvas[8][14];
	char str[8] = "(-)  (-)";


	fill_canvas(canvas);
	show_canvas(canvas);

	find_shape(canvas, str);

}

void find_shape(pixel canvas[8][14], char *shape) {
	int len = strlen(shape), flag = 0;

	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 14; j++) {

			if(canvas[i][j].c == shape[0]) {
				int index = 0;
				for(int k = j; k < j+len; k++) {
					if(canvas[i][k].c == shape[index]) {
						index++;
						if(index == len) {
							printf("Found at %d,%d\n", i, j);
							flag = 1;
							//return;
						}
					} 
					
				}
			}
		}
	}

	if(!flag) printf("Not found!\n");

}

void show_canvas(pixel canvas[8][14]) {
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 14; j++) {
			printf("%c", canvas[i][j].c);
		}
		printf("\n");
	}
}

pixel create_pixel(char c, int row, int col) {
	pixel rtr = {c, row, col};
	return rtr;
}

void fill_canvas(pixel canvas[8][14]) {

	for(int i = 0; i < 8; i++) {

		canvas[i][0] = create_pixel('.', i, 0);
		canvas[i][13] = create_pixel('.', i, 13);

		switch(i) {
			case 0:
				for(int j = 1; j < 13; j++) {
					canvas[i][j] = create_pixel('.', i, j);
				}
			break;
			case 1:
				for(int j = 1; j < 13; j++) {
					canvas[i][j] = create_pixel('S', i, j);	
				}
			break;
			case 2:
				for(int j = 1; j < 13; j++) {
					if(j == 1 || j == 12) {
						canvas[i][j] = create_pixel('|', i, j);	
					} else if(j == 3 || j == 4 || j == 5 || j == 8 || j == 9 || j == 10) {
						canvas[i][j] = create_pixel('-', i, j);	
					} else {
						canvas[i][j] = create_pixel(' ', i, j);
					}
				}
			break;
			case 3:
				for(int j = 1; j < 13; j++) {
					if(j == 1 || j == 12) {
						canvas[i][j] = create_pixel('|', i, j);	
					} else if(j == 3 || j == 4 || j == 5 || j == 8 || j == 9 || j == 10) {
						if(j == 3 || j == 8) {
							canvas[i][j] = create_pixel('(', i, j);
						} else if(j == 5 || j == 10) {
							canvas[i][j] = create_pixel(')', i, j);
						} else if(j == 4 || j == 9) {
							canvas[i][j] = create_pixel('-', i, j);
						}
					} else {
						canvas[i][j] = create_pixel(' ', i, j);
					}
				}
			break;
			case 4:
				for(int j = 1; j < 13; j++) {
					if(j == 1 || j == 12) {
						canvas[i][j] = create_pixel('|', i, j);
					} else if(j == 6) {
						canvas[i][j] = create_pixel('/', i, j);
					} else if(j == 7) {
						canvas[i][j] = create_pixel('_', i, j);
					} else {
						canvas[i][j] = create_pixel(' ', i, j);	
					}
				}
			break;
			case 5:
				for(int j = 1; j < 13; j++) {
					if(j == 1 || j == 12) {
						canvas[i][j] = create_pixel('|', i, j);
					} else if(j == 5 || j == 6 || j == 7 || j == 8) {
						canvas[i][j] = create_pixel('_', i, j);
					} else {
						canvas[i][j] = create_pixel(' ', i, j);
					}
				}
			break;
			case 6:
				for(int j = 1; j < 13; j++) {
					if(j == 1 || j == 12) {
						canvas[i][j] = create_pixel('|', i, j);
					} else {
						canvas[i][j] = create_pixel('_', i, j);
					}
				}
			break;
			case 7:
				for(int j = 1; j < 13; j++) {
					canvas[i][j] = create_pixel('.', i, j);
				}
			break;
		}

	}

}