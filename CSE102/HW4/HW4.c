#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POKEMON_QUANTITY 10
#define MAX_POCKET_SIZE 4

typedef enum {
	Charmander, Pikachu, Squirtle, Bulbasaur, Pidgeotto, Ratata, Mug, Caterpie, Zubat, Krabby
} pokemon;

typedef enum {
	linear, quadratic
} attack_type;

/* For the battle part, area 2d array i came up with a concept: 
    pokemon_id is just 2 digit integer, lets say it's XY
    X holds the information about owner of pokemon which is 1-user or 2-ai
    Y holds the information about pokemon specie which can be 0 to 9 from pokemon database
    In 2d area array i just stored the pokemons with this concept of abstraction
    MADE FOR UNDERSTANDING THE FURTHER COMMENTS MORE CLEAR	
*/

int strcmp_me(char str_one[], char str_two[]);
int strlen_me(char str[]);
void pokedex(char Pokemon_name[10][11], int range[], attack_type type[], int attack_power[], int stamina[]);
void oaks_laboratory(char Pokemon_name[10][11], pokemon Pokemons[], pokemon *my_Pokemons);
void show_Pokemons(char Pokemon_name[10][11], pokemon Pokemons[], int pokemon_count);
void catch_a_pokemon(char Pokemon_name[10][11], pokemon Pokemons[], pokemon *my_pocket);
void release_a_pokemon(char Pokemon_name[10][11], pokemon Pokemons[], pokemon *my_pocket);
void battle(char Pokemon_name[10][11], int range[], attack_type type[], int attack_power[], int stamina[], pokemon user_Pokemons[]);
void show_area (char Pokemon_name[10][11], int area[8][8], int pokemon_staminas_view[8][8]);
int checkWin(pokemon user_Pokemons[4], int ai_pokemon_positions[4]);
int checkCoord(int row, int col);
int id_duplicate(int id, int area[8][8]);
void do_attacks(char Pokemon_name[10][11], int area[8][8], int pokemon_staminas_view[8][8], attack_type type, int row, int col, int range, int attack_power, int owner);
void remove_dead(int area[8][8], int pokemon_staminas_view[8][8], int ai_pokemon_positions[4], pokemon user_Pokemons[4], char Pokemon_name[10][11]);
void attack_target(int pokemon_staminas_view[8][8], int attack_power, int area[8][8], int target_row, int target_col, int row, int col, char Pokemon_name[10][11]);

int main() {

	/* Data initilizations */
	char Pokemon_name[10][11] = {"Charmander", "Pikachu", "Squirtle", "Bulbasaur", "Pidgeotto", "Ratata", "Mug", "Caterpie", "Zubat", "Krabby"};
	int range[10] = {1, 3, 4, 3, 2, 2, 1, 2, 3, 2};
	attack_type type[10] = {quadratic, linear, linear, linear, quadratic, linear, quadratic, quadratic, linear, linear};
	int attack_power[10] = {500, 350, 300, 400, 250, 250, 350, 200, 350, 300};
	int stamina[10] = {2200, 1500, 1700, 2500, 1900, 2500, 3000, 1200, 1250, 2600};
	pokemon Pokemons[10] = {Charmander, Pikachu, Squirtle, Bulbasaur, Pidgeotto, Ratata, Mug, Caterpie, Zubat, Krabby};

	/* At start player does not have any pokemons*/
	pokemon my_Pokemons[4] = {-1, -1, -1, -1};

	/* battle_flag for checking my pocket an letting player to enter arena, running for main menu loop, input for getting input from user */
	int input, battle_flag = 1, i, running = 1;

	/* Main menu loop */
	while(running) {
		battle_flag = 1;

		printf("\nMain Menu\n");
		printf("1) Open Pokedex\n");
		printf("2) Go to Oak’s Laboratory\n");
		printf("3) Enter the tournament\n");
		printf("4) Exit\n");
		printf("Enter selection:");
		scanf("%d", &input);

		switch(input) {
			case 1:
				pokedex(Pokemon_name, range, type, attack_power, stamina);
			break;
			case 2:
				oaks_laboratory(Pokemon_name, Pokemons, my_Pokemons);
			break;
			case 3:
				for(i = 0; i < 4; i++) {
					if(my_Pokemons[i] == -1) {
						battle_flag = 0;
					}
				}
				if(battle_flag) {
					battle(Pokemon_name, range, type, attack_power, stamina, my_Pokemons);	
				} else {
					printf("\nYou don't have required amount of pokemons!\n");
					printf("Go back and catch 'em!\n");
				}
			break;
			case 4:
				printf("\nExiting...\n");
				running = 0;
			break;
			default:
				printf("\nThere is no such option!\n");
			break;
		}
	}

}

/* Simulates one battle at pokemon area */
void battle(char Pokemon_name[10][11], int range[], attack_type type[], int attack_power[], int stamina[], pokemon user_Pokemons[]) {

	/* ai_pokemon_positions array has integers that has format of XY, X-row, Y-col for i'th pokemon */
	/* area array has integers that has format of XY, X-owner (1-user, 2-ai), Y-pokemon specie (0-9), XY is a 2 digit integer */
	/* in area array -1 means the cell is empty */
	int area[8][8], pokemon_staminas_view[8][8], ai_pokemon_positions[4];

	/* Control variables (input1 is direction, input2 is length of move but sometimes they are just used as input holders) */
	int i, j, success, rng, input1, input2;

	/* Variables for selected pokemon */
	pokemon sel_pokemon;
	int sel_type, sel_range, sel_power, sel_id, sel_row, sel_col, new_row, new_col, sel_ai_index;

	/* Initialize area, -1 means empty */
	for(i = 0; i < 8; i++) {
		for(j = 0; j < 8; j++) {
			area[i][j] = -1;
		}
	}

	/* For the start, show the arena */
	show_area(Pokemon_name, area, pokemon_staminas_view);

	/* Player places pokemons to areana at start */
	for(i = 0; i < 4; i++) {

		sel_pokemon = user_Pokemons[i];		
		sel_id = 10 + sel_pokemon; 			/* sel_id = 1X where X specifies the pokemon specie (assume 1X is a 2 digit integer)*/

		success = 0;
		do {
			printf("Place %s to arena (row col):", Pokemon_name[sel_pokemon]);
			scanf("%d %d", &sel_row, &sel_col);

			if(sel_row < 2 && checkCoord(sel_row, sel_col) && area[sel_row][sel_col] == -1) { /* Is it valid cell? */
				area[sel_row][sel_col] = sel_id;
				pokemon_staminas_view[sel_row][sel_col] = stamina[sel_pokemon]; 
				success = 1;
				show_area(Pokemon_name, area, pokemon_staminas_view);

			} else {
				printf("\nYou can only place in empty cells at first 2 rows!\n\n");

			}


		} while(!success);

	}

	/* AI picks and places pokemons, randomly */
	srand(time(NULL));
	for(i = 0; i < 4; i++) {
		success = 0;
		do {
			rng = rand() % 2; /* Pick row */

			sel_id = 20;	  /* Initialize id, these pokemons will be owned by AI so first digit should be 2, id is XY where X is owner, Y is pokemon */
			switch(rng) {
				case 0: sel_row = 6; break;
				case 1: sel_row = 7; break;
			}

			rng = rand() % 8; /* Pick col */
			sel_col = rng;

			if(area[sel_row][sel_col] == -1) { /* if it's an empty cell */
				rng = rand() % 10;	/* Pick pokemon */
				sel_id += rng;		/* Create id for that pokemon, id is 2X where X will keep the pokemon specie, 2X is 2 digit integer */

				if(!id_duplicate(sel_id, area)) { /* Check if ai has that pokemon, if yes then pick again */
					area[sel_row][sel_col] = sel_id;
					pokemon_staminas_view[sel_row][sel_col] = stamina[rng];
					ai_pokemon_positions[i] = sel_row * 10 + sel_col;
					success = 1;

				} else {
					success = 0;

				}	

			} else {
				success = 0;

			}

		} while(!success);

	}

	/* Show the area after placements are done */
	show_area(Pokemon_name, area, pokemon_staminas_view);

	/* Game loop, until someone wins */
	while(checkWin(user_Pokemons, ai_pokemon_positions) == 0) {

		/* Print area every loop */
		show_area(Pokemon_name, area, pokemon_staminas_view);

		/* Player selects pokemon (check if pokemon is stuck or not) */
		success = 0;
		do {
			printf("Select a pokemon to move (row col):");
			scanf("%d %d", &sel_row, &sel_col);

			if(checkCoord(sel_row, sel_col) && area[sel_row][sel_col] / 10 == 1) { /* if valid assign selected variables */
				sel_id = area[sel_row][sel_col];
				sel_pokemon = sel_id % 10;
				sel_range = range[sel_pokemon];
				sel_type = type[sel_pokemon];
				sel_power = attack_power[sel_pokemon];
				success = 1;

			} else {
				printf("You can only select a cell, in area, that has your pokemon!\n");
				success = 0;

			}
		} while(!success);

		/* Player moves pokemon 1 or 2 block, up-down-left-right directions*/
		success = 0;
		do {
			printf("\nDirection can be 2-up, 4-left, 6-right, 8-down and length can be 1 or 2 blocks!\n");
			printf("Moving pokemon %s (dir length): ", Pokemon_name[sel_pokemon]);
			scanf("%d %d", &input1, &input2);

			if((input1 == 2 || input1 == 4 || input1 == 6 || input1 == 8) && (input2 == 1 || input2 == 2)) {

				/* Create new_row and new_col for according to direction */
				switch(input1) {
					case 2: /* UP */
						new_row = sel_row - input2;
						new_col = sel_col;
					break;
					case 4: /* LEFT */
						new_row = sel_row;
						new_col = sel_col - input2;
					break;
					case 6: /* RIGHT */
						new_row = sel_row;
						new_col = sel_col + input2;
					break;
					case 8: /* DOWN */
						new_row = sel_row + input2;
						new_col = sel_col;
					break;
				}

				/* Validations for that new coordinate, if valid move the pokemon */
				if(checkCoord(new_row, new_col) && area[new_row][new_col] == -1) {
					area[sel_row][sel_col] = -1;
					area[new_row][new_col] = sel_id;
					pokemon_staminas_view[new_row][new_col] = pokemon_staminas_view[sel_row][sel_col];
					success = 1;

				} else {
					printf("\nYou can not move there!\n");
					success = 0;

				}

			} else {
				printf("\nWrong direction or move length!\n");
				success = 0;

			}

		} while(!success);

		/* Do attacks for player and print information message */
		do_attacks(Pokemon_name, area, pokemon_staminas_view, sel_type, new_row, new_col, sel_range, sel_power, 1);
		/* Remove dead pokemons and print information message */
		remove_dead(area, pokemon_staminas_view, ai_pokemon_positions, user_Pokemons, Pokemon_name);

		/* Game may end here */
		if(checkWin(user_Pokemons, ai_pokemon_positions) != 0) break;

		/* AI picks pokemon randomly (check if pokemon is stuck or not) */
		success = 0;
		do {
			rng = rand() % 4;
			if(ai_pokemon_positions[rng] != -1) {
				success = 1;
			}
		} while(!success);
		/* Assign selected pokemons properties to the sel_variables */
		sel_row = ai_pokemon_positions[rng] / 10;
		sel_col = ai_pokemon_positions[rng] % 10;
		sel_id = area[sel_row][sel_col];
		sel_pokemon = sel_id % 10;
		sel_range = range[sel_pokemon];
		sel_type = type[sel_pokemon];
		sel_power = attack_power[sel_pokemon];
		sel_ai_index = rng;
		printf("\nAI Selected %s pokemon at (%d,%d)\n", Pokemon_name[sel_pokemon], sel_row, sel_col);

		/* AI moves pokemon 1 or 2 block randomly direction randomly */
		success = 0;
		do {
			rng = rand() % 2 + 1; /* 1, 2 */
			input2 = rng;

			rng = rand() % 4; /* 0 up, 1 left, 2 right, 3 down */
			input1 = rng;

			switch(input1) {
				case 0: /* UP */
					new_row = sel_row - input2;
					new_col = sel_col;
				break;
				case 1: /* LEFT */
					new_row = sel_row;
					new_col = sel_col - input2;
				break;
				case 2: /* RIGHT */
					new_row = sel_row;
					new_col = sel_col + input2;
				break;
				case 3: /* DOWN */
					new_row = sel_row + input2;
					new_col = sel_col;
				break;
			}

			/* Cell validations for new coordinate */
			if(checkCoord(new_row,new_col) && area[new_row][new_col] == -1) {
				printf("\nAI Moving %s from (%d,%d) to (%d,%d)...\n", Pokemon_name[sel_pokemon], sel_row, sel_col, new_row, new_col);
				pokemon_staminas_view[new_row][new_col] = pokemon_staminas_view[sel_row][sel_col];
				area[new_row][new_col] = sel_id;
				area[sel_row][sel_col] = -1;
				ai_pokemon_positions[sel_ai_index] = new_row * 10 + new_col;
				success = 1;

			} else {
				success = 0;

			}

		} while(!success);

		/* Do attacks for AI and print information message */
		do_attacks(Pokemon_name, area, pokemon_staminas_view, sel_type, new_row, new_col, sel_range, sel_power, 2);
		/* Remove dead pokemons and print information message */
		remove_dead(area, pokemon_staminas_view, ai_pokemon_positions, user_Pokemons, Pokemon_name);

	} /* End of game loop scope */

	/* After ending game show area */
	show_area(Pokemon_name, area, pokemon_staminas_view);

	/* Print winning message according to ending case */
	switch(checkWin(user_Pokemons, ai_pokemon_positions)) {
		case 1:	printf("\nYOU WON!\n");	break;
		case 2:	printf("\nYOU LOST!\n");	break;
	}

}

/* Prints current state of area */
/* Every cell has area of 2x16, holds coordinates, stamina-name-owner of the pokemon, if cell is not empty */
void show_area (char Pokemon_name[10][11], int area[8][8], int pokemon_staminas_view[8][8]) {

	int i, j, poke_owner, poke_id;
	pokemon poke_specie;

	printf("\n");
	for(i = 0; i < 137; i++) printf("-"); 
	printf("\n");

	for(i = 0; i < 8; i++) {

		for(j = 0; j < 8; j++) {

			poke_id = area[i][j];
			poke_specie = poke_id % 10;

			if(j == 0) printf("|");

			if(poke_id != -1) {
				printf("[%d,%d] %10s|", i, j, Pokemon_name[poke_specie]);

			} else {
				printf("[%d,%d]           |", i, j);

			}

		}

		printf("\n");

		for(j = 0; j < 8; j++) {

			poke_id = area[i][j];
			poke_owner = poke_id / 10;
			poke_specie = poke_id % 10;

			if(j == 0) printf("|");

			if(poke_id != -1) {
				printf("(%4d)        ", pokemon_staminas_view[i][j]);

				switch(poke_owner) {
					case 1: printf("US|"); break;
					case 2: printf("AI|"); break;
				}

			} else {
				printf("                |");

			}

		}

		printf("\n");
		for(j = 0; j < 137; j++) printf("-");
		printf("\n");

	}
	printf("\n");

}

/* Returns: 2-AI Won, 1-Player Won, 0-Continue */
int checkWin(pokemon user_Pokemons[4], int ai_pokemon_positions[4]) {

	int counter = 0, i;

	/* Count user's death pokemons */
	for(i = 0; i < 4; i++) {
		if(user_Pokemons[i] == -1) {
			counter++;
		}
	}

	if(counter == 4) return 2;

	counter = 0;

	/* Count AI's death pokemons */
	for(i = 0; i < 4; i++) {
		if(ai_pokemon_positions[i] == -1) {
			counter++;
		}
	}

	if(counter == 4) return 1;

	return 0;

}

/* Checks the given row,col values as coordinates and finds out if they are in the area or not */
int checkCoord(int row, int col) {
	if(row < 8 && row >= 0 && col < 8 && col >= 0) {
		return 1;
	} else {
		return 0;
	}
}

/* Pokemon_id concept is explained at top of the file */
/* Checks the area and finds out if there is an pokemon_id that is equal to given id, if yes return 1, else return 0 */
int id_duplicate(int id, int area[8][8]) {

	int i, j;

	for(i = 0; i < 8; i++) {

		for(j = 0; j < 8; j++) {

			if(id == area[i][j]) return 1;

		}

	}

	return 0;

}

/* Does the attacks for pokemon at (row,col) according to it's attack type, and updates area and prints attack texts */
/* According to owner parameter it can calculate the attacks for both AI and user */
void do_attacks(char Pokemon_name[10][11], int area[8][8], int pokemon_staminas_view[8][8], attack_type type, int row, int col, int range, int attack_power, int owner) {

	/* Conrol flow variables */
	int i, j, dir_flag, attacks_done = 0;

	/* Used for lineer type to find minimum range for every direction */
	int up_range = -1, down_range = -1, left_range = -1, right_range = -1, min_range = 1000;

	/* Target's coordinates and owners */
	int target_row, target_col, target_owner;

	/* Select the target according to owner, if owner is user then target should be AI and vice-versa*/
	if(owner == 1) {
		target_owner = 2;
	} else {
		target_owner = 1;
	}

	/* I used same concept with pokemon_ids (explained at top of file), XY 2 digit integer where X is owner and Y is pokemon specie, which are stored in area 2d array */
	switch(type) {
		case linear:

			/* Calculate ranges for every direction */
			for(i = 1; i <= range; i++) {
				
				/* Look UP */
				target_row = row - i;
				target_col = col;
				if(up_range == -1 && checkCoord(target_row, target_col) && area[target_row][target_col] / 10 == target_owner) {
					up_range = i;

				}

				/* Look DOWN */
				target_row = row + i;
				target_col = col;
				if(down_range == -1 && checkCoord(target_row, target_col) && area[target_row][target_col] / 10 == target_owner) {
					down_range = i;

				}				

				/* Look LEFT */
				target_row = row;
				target_col = col - i;
				if(left_range == -1 && checkCoord(target_row, target_col) && area[target_row][target_col] / 10 == target_owner) {
					left_range = i;

				}		

				/* Look RIGHT */
				target_row = row;
				target_col = col + i;		
				if(right_range == -1 && checkCoord(target_row, target_col) && area[target_row][target_col] / 10 == target_owner) {
					right_range = i;

				}		

			}

			/* Do attacks to nearest targets, until there is no min range equal to previous min range */
			while(!attacks_done) {

				dir_flag = 0;

				if(up_range != -1 && up_range <= min_range) {
					min_range = up_range;
					dir_flag = 2;
				}
				if(down_range != -1 && down_range <= min_range) {
					min_range = down_range;
					dir_flag = 8;
				}
				if(left_range != -1 && left_range <= min_range) {
					min_range = left_range;
					dir_flag = 4;
				}
				if(right_range != -1 && right_range <= min_range) {
					min_range = right_range;
					dir_flag = 6;
				}

				switch(dir_flag) {
					case 2:	
						attack_target(pokemon_staminas_view, attack_power, area, row - up_range, col, row, col, Pokemon_name);
						up_range = -1; 
					break;
					case 4: 
						attack_target(pokemon_staminas_view, attack_power, area, row, col - left_range, row, col, Pokemon_name);
						left_range = -1;
					break;
					case 6:
						attack_target(pokemon_staminas_view, attack_power, area, row, col + left_range, row, col, Pokemon_name);
						right_range = -1;
					break;
					case 8:
						attack_target(pokemon_staminas_view, attack_power, area, row + down_range, col, row, col, Pokemon_name);
						down_range = -1; 
					break;
					case 0:
						attacks_done = 1;
						left_range = -1;
						right_range = -1;
						down_range = -1; 
						up_range = -1;
						min_range = 100;
					break;
				}

			}
		break;

		case quadratic:
		
			/* Quadratic should be a rectagular, target starts from the top left of rectangular */
			target_row = row - range; 
			target_col = col - range; 

			/* So we get a sub-array of this 2D array which can either be 5x5 or 3x3 (note that it's not hardcoded) iterate through that array */
			for(i = target_row; i < target_row + ((range * 2) + 1); i++) {
				for(j = target_col; j < target_col + ((range * 2) + 1); j++) {
					if(checkCoord(i, j) && area[i][j] / 10 == target_owner) { /* Check the coordinates validity because it may exceed the area */
						attack_target(pokemon_staminas_view, attack_power, area, i, j, row, col, Pokemon_name);
						/*pokemon_staminas_view[i][j] -= attack_power;
						printf("%s attacks to ", Pokemon_name[area[row][col] % 10]);
						printf("%s and it's very effective! ", Pokemon_name[area[i][j] % 10]);
						printf("%d damage done!\n", attack_power);*/
					}		
				}
			}
			
		break;
	}

}

/* Pokemon at (row,col) attacks to target at (target_row, target_col) and prints information message */
void attack_target(int pokemon_staminas_view[8][8], int attack_power, int area[8][8], int target_row, int target_col, int row, int col, char Pokemon_name[10][11]) {
	pokemon_staminas_view[target_row][target_col] -= attack_power;
	printf("%s attacks to ", Pokemon_name[area[row][col] % 10]);
	printf("%s and it's very effective! ", Pokemon_name[area[target_row][target_col] % 10]);
	printf("%d damage done!\n", attack_power);
}

/* Removes dead pokemons from area, users pocket and AI's pocket, also prints text information about death of pokemon */
void remove_dead(int area[8][8], int pokemon_staminas_view[8][8], int ai_pokemon_positions[4], pokemon user_Pokemons[4], char Pokemon_name[10][11]) {

	/* Control flow variables and current pokemon propertie holders */
	int i, j, k, id, specie, owner;

	/* Iterate through 2D array */
	for(i = 0; i < 8; i++) {

		for(j = 0; j < 8; j++) {

			/* If stamina is less than or equal to 0 and cell is not empty, kill it */
			if(pokemon_staminas_view[i][j] <= 0 && area[i][j] != -1) {
				id = area[i][j];
				specie = id % 10;
				owner = id / 10;

				/* To print correct information message, used a switch case for owner */
				switch(owner) {
					case 1:
						for(k = 0; k < 4; k++) {
							if(user_Pokemons[k] == specie) {
								printf("User's %s dies!\n", Pokemon_name[specie]);
								user_Pokemons[k] = -1;
								area[i][j] = -1;
							}
						}
					break;
					case 2:
						for(k = 0; k < 4; k++) {
							if(ai_pokemon_positions[k] / 10 == i && ai_pokemon_positions[k] % 10 == j) {
								printf("AI's %s dies!\n", Pokemon_name[specie]);
								ai_pokemon_positions[k] = -1;
								area[i][j] = -1;
							}
						}
					break;
				}

			}

		}

	}

}

/* Basic string compare implementation by me */
int strcmp_me(char str_one[], char str_two[]) {

	int rtr = 1, i, len_one = strlen_me(str_one), len_two = strlen_me(str_two);

	if(len_one != len_two) {
		rtr = 0;

	} else {
		for(i = 0; i < len_one; i++) {

			if(str_one[i] != str_two[i]) {
				rtr = 0;
				break;

			}

		}

	}

	return rtr;

}

/* Basic string length finder implementation by me */
int strlen_me(char str[]) {

	int rtr;

	for(rtr = 0; str[rtr] != '\0'; rtr++);

	return rtr;

}

/* Starts pokedex, which is an interactive wiki for pokemons */
void pokedex(char Pokemon_name[10][11], int range[], attack_type type[], int attack_power[], int stamina[]) {
	
	/* Control flow variables, found_flag specifies if we found the inputted pokemon or not */
	int i, found_flag = 0;

	/* Input holder */
	char input[1000];

	do {

		found_flag = 0;

		printf("\nPlease type name of the Pokémon (type exit to close Pokedex):");
		scanf("%s", input);

		if(strcmp_me(input, "exit")) {
			printf("\nExiting pokedex...\n");

		} else {

			for(i = 0; i < 10; i++) {

				if(strcmp_me(input, Pokemon_name[i])) {
					printf("\nName: %s\n", Pokemon_name[i]);
					printf("A. Type: ");

					switch(type[i]) {
						case 0:	printf("linear\n");	   break;	
						case 1: printf("quadratic\n"); break;
					}

					printf("Range: %d block\n", range[i]);
					printf("A. Power: %d\n", attack_power[i]);
					printf("Stamina: %d\n", stamina[i]);
					found_flag = 1;

				}

			}

			if(!found_flag) {
				printf("\nNo such pokemon in pokedex!\n");

			}

		}

	} while(!strcmp_me(input, "exit"));

} 

/* Oaks lab menu */
void oaks_laboratory(char Pokemon_name[10][11], pokemon Pokemons[], pokemon *my_Pokemons) {

	int input;

	do {
		printf("\nWelcome to Laboratory of Professor Oak. How can I help you?\n");	
		printf("\t1) Show Pokémons\n");
		printf("\t2) Catch a Pokémon\n");
		printf("\t3) Release a Pokémon\n");
		printf("\t4) Show my pocket\n");
		printf("\t5) Back\n");
		printf("Enter selection: ");
		scanf("%d", &input);
		printf("\n");

		switch(input) {
			case 1: show_Pokemons(Pokemon_name, Pokemons, POKEMON_QUANTITY);   break;
			case 2: catch_a_pokemon(Pokemon_name, Pokemons, my_Pokemons); 	   break;
			case 3: release_a_pokemon(Pokemon_name, Pokemons, my_Pokemons);    break;
			case 4: show_Pokemons(Pokemon_name, my_Pokemons, MAX_POCKET_SIZE); break;
			case 5: printf("Exiting..\n"); 									   break;
			default: printf("No such option!\n"); 							   break;
		}

	} while(input != 5);

}

/* Used for both showing all the pokemons, and specific pokemon arrays (for example my_pokemon array not hardcoded) */
void show_Pokemons(char Pokemon_name[10][11], pokemon Pokemons[], int pokemon_count) {

	int i;

	for(i = 0; i < pokemon_count; i++) {

		if(Pokemons[i] == -1) {
			printf("%d - Empty\n", i);

		} else {
			printf("%d - %s\n", i, Pokemon_name[Pokemons[i]]);	

		}
		
	}

}

/* Catchs a pokemon puts it inside my_pocket */
void catch_a_pokemon(char Pokemon_name[10][11], pokemon Pokemons[], pokemon *my_pocket) {

	/* Control flow variables */
	int success = 0, my_pocket_len = 0, input, i;

	for(i = 0; i < 4; i++) {
		if(my_pocket[i] != -1) my_pocket_len++;
	}

	if(my_pocket_len >= 4) {
		printf("Your pocket is full!\n");

	} else {
		show_Pokemons(Pokemon_name, Pokemons, POKEMON_QUANTITY);

		do {
			printf("\nEnter the index of pokemon you wish to catch: ");
			scanf("%d", &input);

			if(input < 0 || input > 9) {
				success = 0;

			} else {
				for(i = 0; i < 4; i++) {

					if(input == my_pocket[i]) {
						printf("\nYou already have that pokemon!\n");
						success = 0;
						break;

					} else if(i == 3) {
						success = 1;
						break;

					}

				}

			}

		} while(!success);

		for(i = 0; i < 4; i++) {

			if(my_pocket[i] == -1) {
				my_pocket[i] = input;
				break;

			}

		}

		printf("\nYou have caught the %s pokemon!\n", Pokemon_name[input]);

	}

}

/* Releases a pokemon from my_pocket */
void release_a_pokemon(char Pokemon_name[10][11], pokemon Pokemons[], pokemon *my_pocket) {

	/* Control flow variables */
	int success = 0, my_pocket_len = 0, input, i;

	for(i = 0; i < 4; i++) {
		if(my_pocket[i] != -1) my_pocket_len++;
	}

	if(my_pocket_len <= 0) {
		printf("Your pocket is empty!\n");

	} else {
		show_Pokemons(Pokemon_name, my_pocket, MAX_POCKET_SIZE);

		do {
			printf("\nEnter the number of pokemon you wish to release: "); 
			scanf("%d", &input);

			if(input < 0 || input > 9) {
				success = 0;

			} else {
				my_pocket[input] = -1;
				success = 1;

			}

		} while(!success);

	}

}
