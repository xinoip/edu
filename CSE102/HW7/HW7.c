#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define STARTING_CASH 100000

typedef enum player_type {
	noone, cap, car
} player_type;

typedef enum block_type {
	start, property, tax, punish
} block_type;

typedef struct player {
	player_type type;
	int current_block_id, account, turn_to_wait, owned_block_ids[11];
	char *name;
} player_t;

typedef struct block {
	int block_id, price, rent, rent_1, rent_2, rent_3, house_price, house_count;
	char *name;
	struct player owner;
	block_type type;
} block_t;

block_t create_block(int block_id, char *name, int price, int rent, int rent_1,
	int rent_2, int rent_3, int house_price, block_type type, player_t bank) {
	block_t rtr;
	rtr.block_id = block_id;
	rtr.name = malloc(12*sizeof(char));
	strcpy(rtr.name, name);
	rtr.price = price;
	rtr.rent = rent;
	rtr.rent_1 = rent_1;
	rtr.rent_2 = rent_2;
	rtr.rent_3 = rent_3;
	rtr.house_price = house_price;
	rtr.type = type;
	rtr.owner = bank;
	return rtr;
}

void print_nstr(char *str, int n) {
	int i;
	for(i = 0; i < n; i++) printf("%s", str);
}

void init_the_board(struct block board[20]) {
	player_t bank;
	bank.type = noone;
	board[0] = create_block(0, "Start", 0, 0, 0, 0, 0, 0, start, bank);
	board[1] = create_block(1, "Esenyurt", 16000, 800, 4000, 9000, 25000, 10000, property, bank);
	board[2] = create_block(2, "Car Park", 1500, 0, 0, 0, 0, 0, tax, bank);
	board[3] = create_block(3, "Tuzla", 16500, 850, 4250, 9500, 26000, 12000, property, bank);
	board[4] = create_block(4, "Arnavutkoy", 17000, 875, 4500, 10000, 28000, 12000, property, bank);
	board[5] = create_block(5, "Wait 2 Turn", 0, 2, 0, 0, 0, 0, punish, bank);
	board[6] = create_block(6, "Catalca", 20000, 1000, 5000, 12000, 30000, 13000, property, bank);
	board[7] = create_block(7, "Beykoz", 23000, 1100, 5500, 12500, 33000, 13000, property, bank);
	board[8] = create_block(8, "Car Fix", 1750, 0, 0, 0, 0, 0, tax, bank);
	board[9] = create_block(9, "Maltepe", 30000, 1350, 7000, 15000, 40000, 15000, property, bank);
	board[10] = create_block(10, "Bills", 2000, 0, 0, 0, 0, 0, tax, bank);
	board[11] = create_block(11, "Sisli", 33000, 1500, 8000, 16000, 42000, 16000, property, bank);
	board[12] = create_block(12, "Oil", 2250, 0, 0, 0, 0, 0, tax, bank);
	board[13] = create_block(13, "Atasehir", 35000, 1600, 8500, 17000, 45000, 17000, property, bank);
	board[14] = create_block(14, "Sariyer", 40000, 1750, 9500, 19000, 48000, 19000,	property, bank);
	board[15] = create_block(15, "Wait 1 Turn", 0, 1, 0, 0, 0, 0, punish, bank);
	board[16] = create_block(16, "Kadikoy", 43000, 1900, 11000, 21500, 55000, 23000, property, bank);
	board[17] = create_block(17, "Besiktas", 60000, 2500, 15000, 28000, 60000, 30000, property, bank);
	board[18] = create_block(18, "Vocation", 5000, 0, 0, 0, 0, 0, tax, bank);
	board[19] = create_block(19, "Bebek", 70000, 3500, 20000, 35500, 65000, 35000, property, bank);
	for(int i = 0; i < 20; i++) {
		board[i].house_count = 0;
	}
}

void show_board(struct block board[20], struct player player_one, struct player player_two) {
    
	int i, end = 19, front = 6;

	print_nstr("-", 133);
	printf("\n|");

	for(i = 0; i < 6; i++) {
		print_nstr(" ", 5);
		printf("%-11s", board[i].name);
		print_nstr(" ", 5);
		printf("|");
	}
	printf("\n|");
	for(i = 0; i < 6; i++) {
		print_nstr(" ", 5);
		if(board[i].price != 0) printf("%5d%-11s", board[i].price, "$"); //
		else print_nstr(" ", 16);
		printf("|");
	}
	printf("\n|");
	for(i = 0; i < 6; i++) {
		print_nstr(" ", 5);
		if(i == player_one.current_block_id) {
			printf("%-5s", player_one.name);
		} else {
			print_nstr(" ", 5);
		}
		if(i == player_two.current_block_id) {
			printf("%-6s", player_two.name);
		} else {
			print_nstr(" ", 6);
		}
		print_nstr(" ", 5);
		printf("|");
	}
	printf("\n");
	print_nstr("-", 133);

	for(i = 0; i < 4; i++) {
		printf("\n|");
		print_nstr(" ", 5);
		printf("%-11s", board[end].name);
		print_nstr(" ", 5);
		printf("|");
		print_nstr(" ", 87);
		printf("|");
		print_nstr(" ", 5);
		printf("%-11s", board[front].name);
		print_nstr(" ", 5);
		printf("|\n|");
		print_nstr(" ", 5);
		if(board[end].price != 0) printf("%5d%-11s", board[end].price, "$"); //
		else print_nstr(" ", 16);
		printf("|");
		print_nstr(" ", 87);
		printf("|");
		print_nstr(" ", 5);
		if(board[front].price != 0) printf("%5d%-11s", board[front].price, "$"); //
		else print_nstr(" ", 16);
		printf("|\n");
		printf("|");
		print_nstr(" ", 5);
		if(end == player_one.current_block_id) {
			printf("%-5s", player_one.name);
		} else {
			print_nstr(" ", 5);
		}
		if(end == player_two.current_block_id) {
			printf("%-6s", player_two.name);
		} else {
			print_nstr(" ", 6);
		}
		print_nstr(" ", 5);
		printf("|");
		print_nstr(" ", 87);
		printf("|");
		print_nstr(" ", 5);
		if(front == player_one.current_block_id) {
			printf("%-5s", player_one.name);
		} else {
			print_nstr(" ", 5);
		}
		if(front == player_two.current_block_id) {
			printf("%-6s", player_two.name);
		} else {
			print_nstr(" ", 6);
		}
		print_nstr(" ", 5);
		printf("|\n");
		if(i != 3) {
			print_nstr("-", 23);
			print_nstr(" ", 87);
			print_nstr("-", 24);	
		}
		front++;
		end--;
	}

	print_nstr("-", 133);
	printf("\n|");
	for(i = 15; i >= 10; i--) {
		print_nstr(" ", 5);
		printf("%-11s", board[i].name);
		print_nstr(" ", 5);
		printf("|");
	}
	printf("\n|");
	for(i = 15; i >= 10; i--) {
		print_nstr(" ", 5);
		if(board[i].price != 0) printf("%5d%-11s", board[i].price, "$"); //
		else print_nstr(" ", 16);
		printf("|");
	}
	printf("\n|");
	for(i = 15; i >= 10; i--) {
		print_nstr(" ", 5);
		if(i == player_one.current_block_id) {
			printf("%-5s", player_one.name);
		} else {
			print_nstr(" ", 5);
		}
		if(i == player_two.current_block_id) {
			printf("%-6s", player_two.name);
		} else {
			print_nstr(" ", 6);
		}
		print_nstr(" ", 5);
		printf("|");
	}
	printf("\n");
	print_nstr("-", 133);

}

void show_properties(struct block board[20]) {
	
	int i, input;

	do {
		printf("Please select a property to see details:\n");
		for(i = 0; i < 20; i++) {
			if(board[i].type == property) {
				printf("%d -      %5s\n", i, board[i].name);
			}
		}
		printf("0 - Exit\n");

		scanf("%d", &input);

		if(input != 0) {
			if(input < 20 && input > 0 && board[input].type == property) {				
				print_nstr("-", 33);
				printf("\n|");
				print_nstr(" ", 10);
				printf("%-11s", board[input].name);				
				print_nstr(" ", 10);
				printf("|\n");
				print_nstr("-", 33);
				printf("\n|");
				print_nstr(" ", 5);
				printf("Rent");
				print_nstr(" ", 4);
				print_nstr(" ", 12);
				printf("%-5d", board[input].rent);
				print_nstr(" ", 1);
				printf("|\n|");
				print_nstr(" ", 5);
				printf("Rent 1 H");
				print_nstr(" ", 12);
				printf("%-5d", board[input].rent_1);
				print_nstr(" ", 1);
				printf("|\n|");
				print_nstr(" ", 5);
				printf("Rent 2 H");
				print_nstr(" ", 12);
				printf("%-5d", board[input].rent_2);
				print_nstr(" ", 1);
				printf("|\n|");
				print_nstr(" ", 5);
				printf("Rent 3 H");
				print_nstr(" ", 12);
				printf("%-5d", board[input].rent_3);
				print_nstr(" ", 1);
				printf("|\n");
				print_nstr("-", 33);
				printf("\n|");
				print_nstr(" ", 5);
				printf("House Price");
				print_nstr(" ", 9);
				printf("%-5d", board[input].house_price);
				printf(" |\n");
				print_nstr("-", 33);
				printf("\n");

			} else {
				printf("No such block!\n\n");
			}
		} 
	} while(input != 0);

}

void buy_property(struct block* current_block, struct player* current_player) {

	if(current_block->type != property) {
		printf("You can only buy properties!\n");
		return;
	}

	if(current_player->current_block_id == current_block->block_id) { /* On the block? */
		if(current_block->owner.type == noone) { /* Is it owned? */
			if(current_player->account >= current_block->price) { /* Has enough money?*/
				current_player->account -= current_block->price;
				current_block->owner = *current_player;
				printf("%s bought %s!\n", current_player->name, current_block->name);

				for(int i = 0; i < 11; i++) { /* Add new property to players owned array */
					if(current_player->owned_block_ids[i] == -1) {
						current_player->owned_block_ids[i] = current_block->block_id;
						break;
					}
				}

			} else {
				printf("You don't have enough money!\n");

			}
		} else {
			printf("You can only buy unowned properties!\n");

		}
	} else {
		printf("You can only buy properties that you land!\n");

	}

}

void sell_property(struct block board[20], struct player *current_player) {

	int input;

	player_t bank;
	bank.type = noone;

	do {
		for(int i = 0; i < 20; i++) {
			if(board[i].owner.type == current_player->type) {
				printf("%d - %s\n", i, board[i].name);
			}
		}
		printf("0 - Exit\n");
		printf("Enter property that you want to sell: ");
		scanf("%d", &input);

		if(input != 0) {
			if(input > 0 && input < 20 && board[input].owner.type == current_player->type) {
				current_player->account += board[input].price/2;
				current_player->account += board[input].house_count * ((board[input].house_price)/2);	
				printf("%s sold %s with %d houses on it!\n", current_player->name, board[input].name, 
					board[input].house_count);

				board[input].house_count = 0;
				board[input].owner = bank;

			} else {
				printf("You can only sell your own properties!\n");

			}
		} 
	} while(input != 0);

}

void build_house(block_t *current_block, player_t *current_player) {

	if(current_block->owner.type == current_player->type) {
		if(current_block->house_count < 3) {
			if(current_player->account >= current_block->house_price) {
				current_player->account -= current_block->house_price;
				current_block->house_count += 1;

				printf("%s built %d house on %s!\n", current_player->name, current_block->house_count
					,current_block->name);

			} else {
				printf("You don't have enough money!\n");

			}
		} else {
			printf("Block has maximum amount of houses!\n");

		}
	} else {
		printf("You can only build houses to your own properties!\n");

	}

}

void to_bankrupt(block_t board[20], player_t *player) {

	int input, bankrupt = 1, count = 0;

	printf("%s, you are about to bankrupt...\n", player->name);

	do {
		count = 0;
		printf("Try to sell your properties to save yourself from bankruptcy!\n");
		for(int i = 0; i < 11; i++) {
			if(player->owned_block_ids[i] != -1) count++;
		}
		if(player->account > 0) {
			printf("You saved yourself from bankruptcy!\n");
			break;
		}
		if(count > 0) {
			sell_property(board, player);	

		} else {
			printf("%s loses the game!\n", player->name);
			exit(0);

		}
	} while(bankrupt);
	
}

void gameplay(struct block board[20], struct player player_one, struct player player_two) {

	int input, turn_done, rng, rent = 0, gaming = 1, rolled = 0, acceptance;
	player_t *current_player = &player_one;

	while(gaming) {

		show_board(board, player_one, player_two);
		printf("\n");

		if(current_player->turn_to_wait != 0) {
			printf("%s waits for %d turns!\n", current_player->name, current_player->turn_to_wait);
			current_player->turn_to_wait -= 1;

		} else {
			turn_done = 0;
			rolled = 0;
			while(!turn_done) {
				printf("\nTurn of %s!\n", current_player->name);
				printf("1 - Roll the dice\n");
				printf("2 - Show my account\n");
				printf("3 - Show my properties\n");
				printf("4 - Show property deeds\n");
				printf("5 - Buy property\n");
				printf("6 - Buy house\n");
				printf("7 - Sell property\n");
				printf("Please select an option to continue: ");
				
				scanf("%d", &input);

				switch(input) {
					case 1:
						//roll dice and move
						rng = (rand() % 6) + 1;
						printf("%s Rolled dice: %d\n", current_player->name, rng);
						current_player->current_block_id += rng;
						if(current_player->current_block_id > 19) {
							current_player->current_block_id %= 20;
							printf("%s gets start bonus!\n", current_player->name);
							current_player->account += 10000;
							turn_done = 1;
						}
						rolled = 1;

						printf("\n");
						show_board(board, player_one, player_two);
						printf("\n");

						/* Player lands on tax */
						if(board[current_player->current_block_id].type == tax) {

							printf("%s pays %d taxes!\n", current_player->name, 
								board[current_player->current_block_id].price);

							current_player->account -= board[current_player->current_block_id].price;

							if(current_player->account < 0) {
								to_bankrupt(board, current_player);
							}

							turn_done = 1;

						}
						
						/* Player lands on punishment */
						if(board[current_player->current_block_id].type == punish) {

							printf("%s waits for %d turn!\n", current_player->name,
								board[current_player->current_block_id].rent);

							current_player->turn_to_wait = board[current_player->current_block_id].rent;

							turn_done = 1;

						}

						/* Player lands on opponents property */
						if(board[current_player->current_block_id].owner.type != noone &&
							board[current_player->current_block_id].owner.type != current_player->type) {

							printf("%s pays rent of %s with %d houses!\n", current_player->name, 
								board[current_player->current_block_id].name, 
								board[current_player->current_block_id].house_count);

							rent = 0;
							switch(board[current_player->current_block_id].house_count) {
								case 0: rent = board[current_player->current_block_id].rent; break;
								case 1: rent = board[current_player->current_block_id].rent_1; break;
								case 2: rent = board[current_player->current_block_id].rent_2; break;
								case 3: rent = board[current_player->current_block_id].rent_3; break;
							}

							printf("%s pays %d!\n", current_player->name, rent);

							current_player->account -= rent;
							
							if(current_player == &player_one) {
								player_two.account += rent;

							} else if(current_player == &player_two) {
								player_one.account += rent;

							}

							if(current_player->account < 0) {
								to_bankrupt(board, current_player);
							}

							turn_done = 1;

						}						

						/* player lands on unowned property */
						if(board[current_player->current_block_id].type == property) {
							printf("\n%s, wanna buy this property?\n\n", current_player->name);
							printf("(1-yes, 0-no): ");
							scanf("%d", &acceptance);
							if(acceptance == 1) {
								buy_property(&board[current_player->current_block_id], current_player);
								turn_done = 1;

							} else {
								turn_done = 1;

							}
						}

						/* Player lands on his property */
						if(board[current_player->current_block_id].owner.type == current_player->type) {
							printf("%s landed on his property!\n", current_player->name);
							acceptance = 1;
							while(acceptance == 1) {
								printf("\n%s, wanna build on property?\n\n", current_player->name);
								printf("(1-yes, 0-no): ");
								scanf("%d", &acceptance);
								build_house(&board[current_player->current_block_id], current_player);

							}
							turn_done = 1;
						}
					break;
					case 2:
						printf("%s account: %d\n", current_player->name, current_player->account);	
					break;
					case 3:
						printf("Printing owned properties of %s...\n", current_player->name);
						for(int i = 0; i < 11; i++) {
							if(current_player->owned_block_ids[i] != -1) {
								printf("%d - %s\n", i, board[current_player->owned_block_ids[i]].name);
							}
						}
					break;
					case 4:
						show_properties(board);
					break;
					case 5:
						if(rolled) {
							buy_property(&board[current_player->current_block_id], current_player);	
						} else {
							printf("First you gotta roll dice!\n");
						}
					break;
					case 6:
						if(rolled) {
							build_house(&board[current_player->current_block_id], current_player);
						} else {
							printf("First you gotta roll dice!\n");
						}
					break;
					case 7:
						sell_property(board, current_player);
					break;
					default:
						printf("No such option!\n");
					break;
				}

				printf("\n");

			} /* Turn loop */ 

		} /* Else nest */

		/* Change current player */
		if(current_player == &player_one) {
			current_player = &player_two;

		} else if(current_player == &player_two) {
			current_player = &player_one;

		}

	} /* Game loop */

}

void init_players(player_t *player_one, player_t *player_two) {
	player_one->account = STARTING_CASH;
	player_two->account = STARTING_CASH;
	player_one->current_block_id = 0;
	player_two->current_block_id = 0;
	player_one->type = cap;
	player_two->type = car;
	player_one->turn_to_wait = 0;
	player_two->turn_to_wait = 0;
	for(int i = 0; i < 11; i++) {
		player_one->owned_block_ids[i] = -1;
		player_two->owned_block_ids[i] = -1;
	}
}

int main() {

	srand(time(NULL));

	block_t board[20];
	player_t player_one, player_two;

	init_players(&player_one, &player_two);
	player_one.name = "Cap";
	player_two.name = "Car";
	
	init_the_board(board);
	
	gameplay(board, player_one, player_two);

}
