#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TILES 24
#define STARTING_CASH 100000
#define START_BONUS 10000
#define CARDS 5

typedef enum player_type {
	noone, cap, car
} player_type;

typedef enum block_type {
	start, property, tax, punish, fortune
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
	struct block *next;
} block_t;

typedef struct fortune_card {
	int card_no;
	char name[300];
	char explanation[1000];
} fortune_t;

block_t *go_to_index(int i, block_t *board_head) {
	block_t *rtr = board_head;
	for(int j = 0; j < i; j++) {
		rtr = rtr->next;
	}
	return rtr;
} 

void print_nstr(char *str, int n) {
	int i;
	for(i = 0; i < n; i++) printf("%s", str);
}

block_t *create_block(int block_id, char *name, int price, int rent, int rent_1, int rent_2, int rent_3, int house_price, block_type type, player_t bank) {
	block_t *rtr = (block_t *)malloc(sizeof(block_t));
	rtr->block_id = block_id;
	rtr->name = malloc(12*sizeof(char));
	strcpy(rtr->name, name);
	rtr->price = price;
	rtr->rent = rent;
	rtr->rent_1 = rent_1;
	rtr->rent_2 = rent_2;
	rtr->rent_3 = rent_3;
	rtr->house_price = house_price;
	rtr->type = type;
	rtr->owner = bank;
	rtr->house_count = 0;
	rtr->next = NULL;
	return rtr;
}

void init_the_board(block_t **curr, block_t **board_head) {
	player_t bank;
	bank.type = noone;
	(*curr) = create_block(0, "Start", 0, 0, 0, 0, 0, 0, start, bank);
	*board_head = *curr;
	(*curr)->next = create_block(1, "Esenyurt", 16000, 800, 4000, 9000, 25000, 10000, property, bank);
	(*curr) = (*curr)->next;
	(*curr)->next = create_block(2, "Car Park", 1500, 0, 0, 0, 0, 0, tax, bank);
	(*curr) = (*curr)->next;
	(*curr)->next = create_block(3, "Fortune", 0, 0, 0, 0, 0, 0, fortune, bank);
	(*curr) = (*curr)->next;
	(*curr)->next = create_block(4, "Tuzla", 16500, 850, 4250, 9500, 26000, 12000, property, bank);
	(*curr) = (*curr)->next;
	(*curr)->next = create_block(5, "Arnavutkoy", 17000, 875, 4500, 10000, 28000, 12000, property, bank);
	(*curr) = (*curr)->next;
	(*curr)->next = create_block(6, "Wait 2 Turn", 0, 2, 0, 0, 0, 0, punish, bank);
	(*curr) = (*curr)->next;
	(*curr)->next = create_block(7, "Catalca", 20000, 1000, 5000, 12000, 30000, 13000, property, bank);
	(*curr) = (*curr)->next;
	(*curr)->next = create_block(8, "Beykoz", 23000, 1100, 5500, 12500, 33000, 13000, property, bank);
	(*curr) = (*curr)->next;
	(*curr)->next = create_block(9, "Fortune", 0, 0, 0, 0, 0, 0, fortune, bank);
	(*curr) = (*curr)->next;
	(*curr)->next = create_block(10, "Car Fix", 1750, 0, 0, 0, 0, 0, tax, bank);
	(*curr) = (*curr)->next;
	(*curr)->next = create_block(11, "Maltepe", 30000, 1350, 7000, 15000, 40000, 15000, property, bank);
	(*curr) = (*curr)->next;
	(*curr)->next = create_block(12, "Bills", 2000, 0, 0, 0, 0, 0, tax, bank);
	(*curr) = (*curr)->next;
	(*curr)->next = create_block(13, "Sisli", 33000, 1500, 8000, 16000, 42000, 16000, property, bank);
	(*curr) = (*curr)->next;
	(*curr)->next = create_block(14, "Oil", 2250, 0, 0, 0, 0, 0, tax, bank);
	(*curr) = (*curr)->next;
	(*curr)->next = create_block(15, "Fortune", 0, 0, 0, 0, 0, 0, fortune, bank);
	(*curr) = (*curr)->next;
	(*curr)->next = create_block(16, "Atasehir", 35000, 1600, 8500, 17000, 45000, 17000, property, bank);
	(*curr) = (*curr)->next;
	(*curr)->next = create_block(17, "Sariyer", 40000, 1750, 9500, 19000, 48000, 19000,	property, bank);
	(*curr) = (*curr)->next;
	(*curr)->next = create_block(18, "Wait 1 Turn", 0, 1, 0, 0, 0, 0, punish, bank);
	(*curr) = (*curr)->next;
	(*curr)->next = create_block(19, "Kadikoy", 43000, 1900, 11000, 21500, 55000, 23000, property, bank);
	(*curr) = (*curr)->next;
	(*curr)->next = create_block(20, "Besiktas", 60000, 2500, 15000, 28000, 60000, 30000, property, bank);
	(*curr) = (*curr)->next;
	(*curr)->next = create_block(21, "Fortune", 0, 0, 0, 0, 0, 0, fortune, bank);
	(*curr) = (*curr)->next;
	(*curr)->next = create_block(22, "Vocation", 5000, 0, 0, 0, 0, 0, tax, bank);
	(*curr) = (*curr)->next;
	(*curr)->next = create_block(23, "Bebek", 70000, 3500, 20000, 35500, 65000, 35000, property, bank);
	(*curr) = (*curr)->next;
}

void show_board(block_t *board_head, struct player player_one, struct player player_two) {
    
	int i, end = 23, front = 7;

	print_nstr("-", 155);
	printf("\n|");

	for(i = 0; i < 7; i++) {
		print_nstr(" ", 5);
		printf("%-11s", go_to_index(i, board_head)->name);
		print_nstr(" ", 5);
		printf("|");
	}
	printf("\n|");
	for(i = 0; i < 7; i++) {
		print_nstr(" ", 5);
		if(go_to_index(i, board_head)->price != 0) printf("%5d%-11s", go_to_index(i, board_head)->price, "$"); //
		else print_nstr(" ", 16);
		printf("|");
	}
	printf("\n|");
	for(i = 0; i < 7; i++) {
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
	print_nstr("-", 155);

	for(i = 0; i < 5; i++) {
		printf("\n|");
		print_nstr(" ", 5);
		printf("%-11s", go_to_index(end, board_head)->name);
		print_nstr(" ", 5);
		printf("|");
		print_nstr(" ", 109);
		printf("|");
		print_nstr(" ", 5);
		printf("%-11s", go_to_index(front, board_head)->name);
		print_nstr(" ", 5);
		printf("|\n|");
		print_nstr(" ", 5);
		if(go_to_index(end, board_head)->price != 0) printf("%5d%-11s", go_to_index(end, board_head)->price, "$"); //
		else print_nstr(" ", 16);
		printf("|");
		print_nstr(" ", 109);
		printf("|");
		print_nstr(" ", 5);
		if(go_to_index(front, board_head)->price != 0) printf("%5d%-11s", go_to_index(front, board_head)->price, "$"); //
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
		print_nstr(" ", 109);
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
		if(i != 4) {
			print_nstr("-", 23);
			print_nstr(" ", 109);
			print_nstr("-", 24);	
		}
		front++;
		end--;
	}

	print_nstr("-", 155);
	printf("\n|");
	for(i = 18; i >= 12; i--) {
		print_nstr(" ", 5);
		printf("%-11s", go_to_index(i, board_head)->name);
		print_nstr(" ", 5);
		printf("|");
	}
	printf("\n|");
	for(i = 18; i >= 12; i--) {
		print_nstr(" ", 5);
		if(go_to_index(i, board_head)->price != 0) printf("%5d%-11s", go_to_index(i, board_head)->price, "$"); //
		else print_nstr(" ", 16);
		printf("|");
	}
	printf("\n|");
	for(i = 18; i >= 12; i--) {
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
	print_nstr("-", 155);

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

void show_properties(block_t *board_head) {
	
	int i, input;

	block_t *curr = board_head;

	do {
		printf("Please select a property to see details:\n");
		for(i = 0; i < TILES; i++) {
			if(curr->type == property) {
				printf("%d -      %5s\n", i, curr->name);
			}
			curr = curr->next;
		}
		printf("0 - Exit\n");

		scanf("%d", &input);

		if(input != 0) {
			if(input < TILES && input > 0 && go_to_index(input, board_head)->type == property) {				
				print_nstr("-", 33);
				printf("\n|");
				print_nstr(" ", 10);
				printf("%-11s", go_to_index(input, board_head)->name);				
				print_nstr(" ", 10);
				printf("|\n");
				print_nstr("-", 33);
				printf("\n|");
				print_nstr(" ", 5);
				printf("Rent");
				print_nstr(" ", 4);
				print_nstr(" ", 12);
				printf("%-5d", go_to_index(input, board_head)->rent);
				print_nstr(" ", 1);
				printf("|\n|");
				print_nstr(" ", 5);
				printf("Rent 1 H");
				print_nstr(" ", 12);
				printf("%-5d", go_to_index(input, board_head)->rent_1);
				print_nstr(" ", 1);
				printf("|\n|");
				print_nstr(" ", 5);
				printf("Rent 2 H");
				print_nstr(" ", 12);
				printf("%-5d", go_to_index(input, board_head)->rent_2);
				print_nstr(" ", 1);
				printf("|\n|");
				print_nstr(" ", 5);
				printf("Rent 3 H");
				print_nstr(" ", 12);
				printf("%-5d", go_to_index(input, board_head)->rent_3);
				print_nstr(" ", 1);
				printf("|\n");
				print_nstr("-", 33);
				printf("\n|");
				print_nstr(" ", 5);
				printf("House Price");
				print_nstr(" ", 9);
				printf("%-5d", go_to_index(input, board_head)->house_price);
				printf(" |\n");
				print_nstr("-", 33);
				printf("\n");

			} else {
				printf("No such block!\n\n");
			}
		} 
	} while(input != 0);

}

void sell_property(block_t *board_head, player_t *current_player) {

	int input;
	block_t *curr = board_head;
	player_t bank;
	bank.type = noone;

	do {
		for(int i = 0; i < TILES; i++) {
			if(go_to_index(i, board_head)->owner.type == current_player->type) {
				printf("%d - %s\n", i, go_to_index(i, board_head)->name);
			}
		}
		printf("0 - Exit\n");
		printf("Enter property that you want to sell: ");
		scanf("%d", &input);

		if(input != 0) {
			if(input > 0 && input < TILES && go_to_index(input, board_head)->owner.type == current_player->type) {
				current_player->account += go_to_index(input, board_head)->price/2;
				current_player->account += go_to_index(input, board_head)->house_count * ((go_to_index(input, board_head)->house_price)/2);	
				printf("%s sold %s with %d houses on it!\n", current_player->name, go_to_index(input, board_head)->name, go_to_index(input, board_head)->house_count);

				go_to_index(input, board_head)->house_count = 0;
				go_to_index(input, board_head)->owner = bank;

			} else {
				printf("You can only sell your own properties!\n");

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
				printf("%s don't have enough money to buy!\n", current_player->name);

			}
		} else {
			printf("You can only buy unowned properties!\n");

		}
	} else {
		printf("You can only buy properties that you land!\n");

	}

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
				printf("%s don't have enough money to build!\n", current_player->name);

			}
		} else {
			printf("Block has maximum amount of houses!\n");

		}
	} else {
		printf("You can only build houses to your own properties!\n");

	}

}

void to_bankrupt(block_t *board_head, player_t *player) {

	int input, bankrupt = 1, count = 0;

	player_t bank;
	bank.type = noone;

	printf("%s is about to bankrupt...\n", player->name);

	if(player->type == cap) {
		for(int i = TILES-1; i >= 0; i--) {
			if(go_to_index(i, board_head)->owner.type == cap) {
				player->account += go_to_index(i, board_head)->price/2;
				player->account += go_to_index(i, board_head)->house_count * ((go_to_index(i, board_head)->house_price)/2);	
				printf("%s sold %s with %d houses on it!\n", player->name, go_to_index(i, board_head)->name, go_to_index(i, board_head)->house_count);

				go_to_index(i, board_head)->house_count = 0;
				go_to_index(i, board_head)->owner = bank;

				if(player->account > 0) {
					printf("%s saved himself from bankruptcy!\n", player->name);
					break;
				}
			}
		}
		if(player->account > 0) {
			printf("%s saved himself from bankruptcy!\n", player->name);

		} else {
			printf("%s loses the game!\n", player->name);
			exit(0);

		}

	} else {
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
				sell_property(board_head, player);	

			} else {
				printf("%s loses the game!\n", player->name);
				exit(0);

			}
		} while(bankrupt);

	}
	
}

void init_fortune_cards(fortune_t cards[CARDS]) {
	fortune_t f1 = {1, "Free House", "Build a house on one of your properties for free."};
	fortune_t f2 = {2, "Time Travel", "Roll a dice. If result is [1-3], move forward by 2 blocks. Else, move backward by 2 blocks."};
 	fortune_t f3 = {3, "Garnishment", "Pay 5.000 to the bank."};
	fortune_t f4 = {4, "Generosity", "Give 10.000 to the opponent."};
	fortune_t f5 = {5, "Treasure Hunter", "Take 20.000 from the bank."};
	cards[0] = f1;
	cards[1] = f2;
	cards[2] = f3;
	cards[3] = f4;
	cards[4] = f5;
}

void process_move(player_t *current_player, block_t *board_head, fortune_t cards[CARDS], player_t *opponent);

void pick_fortune_card(player_t *player, fortune_t cards[CARDS], block_t *board_head, player_t *opponent) {

	int rng = rand() % 5, input, count = 0, success = 0;

	rng = 1;

	printf("%s drawed the fortune card: %s\n", player->name, cards[rng].name);
	printf("\nExplanation of card: %s\n", cards[rng].explanation);

	switch(rng) {
		case 0:
			for(int i = 0; i < 11; i++) {
				if(player->owned_block_ids[i] != -1) {
					printf("%d - %s\n", i, go_to_index(player->owned_block_ids[i], board_head)->name);
					if(go_to_index(player->owned_block_ids[i], board_head)->house_count < 3) count++;
				}
			}
			printf("\n");
			if(count == 0) {
				printf("Unfortunetly you don't have any valid property to build this new free house.\n");

			} else {
				printf("Select one of your property to build your new free house on!\n");
				do {
					printf("Select one of your property to build your new free house on!\n");
					scanf("%d", &input);
					if(input < 11 && input >= 0) {	
						printf("%s built a free house on %s\n", player->name, go_to_index(player->owned_block_ids[input], board_head)->name);
						go_to_index(player->owned_block_ids[input], board_head)->house_count++;	
						success = 1;
						
					} else {
						printf("Please enter something from menu!\n");

					}
				} while(!success);
			}
		break;
		case 1:
			rng = (rand() % 6) + 1;
			printf("%s rolled %d!\n", player->name, rng);
			if(rng <= 3 && rng >= 1) {
				printf("%s moved forward for %d blocks!\n", player->name, 2);
				player->current_block_id += 2;
				if(player->current_block_id > TILES-1) player->current_block_id %= TILES;
			} else {
				printf("%s moved backwards for %d blocks!\n", player->name, 2);
				player->current_block_id -= 2;
				if(player->current_block_id < 0) player->current_block_id += TILES;
			}
			process_move(player, board_head, cards, opponent);
		break;
		case 2:
			printf("%s paid 5000$ to bank!\n", player->name);
			player->account -= 5000;
			if(player->account < 0) to_bankrupt(board_head, player);
		break;
		case 3:
			printf("%s gave 10000$ to opponent!\n", player->name);
			player->account -= 10000;
			if(player->account < 0) to_bankrupt(board_head, player);
			opponent->account += 10000;
		break;
		case 4:
			printf("%s took 20000$ from bank!\n", player->name);
			player->account += 20000;
		break;
	}

}

void process_move(player_t *current_player, block_t *board_head, fortune_t cards[CARDS], player_t *opponent) {

	int acceptance, is_ai = 0, rng, avg_price = 0, count_props;

	if(current_player->type == cap) {
		is_ai = 1;
	} else {
		is_ai = 0;
	}

	/* Player lands on tax */
	if(go_to_index(current_player->current_block_id, board_head)->type == tax) {

		printf("%s pays %d taxes!\n", current_player->name, 
			go_to_index(current_player->current_block_id, board_head)->price);

		current_player->account -= go_to_index(current_player->current_block_id, board_head)->price;

		if(current_player->account < 0) {
			to_bankrupt(board_head, current_player);
		}

	}

	/* Player lands on punishment */
	if(go_to_index(current_player->current_block_id, board_head)->type == punish) {

		printf("%s waits for %d turn!\n", current_player->name,
			go_to_index(current_player->current_block_id, board_head)->rent);

		current_player->turn_to_wait = go_to_index(current_player->current_block_id, board_head)->rent;

	}

	/* Player lands on opponents property */
	if(go_to_index(current_player->current_block_id, board_head)->owner.type != noone &&
		go_to_index(current_player->current_block_id, board_head)->owner.type != current_player->type) {

		printf("%s pays rent of %s with %d houses!\n", current_player->name, 
			go_to_index(current_player->current_block_id, board_head)->name, 
			go_to_index(current_player->current_block_id, board_head)->house_count);

		int rent = 0;
		switch(go_to_index(current_player->current_block_id, board_head)->house_count) {
			case 0: rent = go_to_index(current_player->current_block_id, board_head)->rent; break;
			case 1: rent = go_to_index(current_player->current_block_id, board_head)->rent_1; break;
			case 2: rent = go_to_index(current_player->current_block_id, board_head)->rent_2; break;
			case 3: rent = go_to_index(current_player->current_block_id, board_head)->rent_3; break;
		}

		printf("%s pays %d!\n", current_player->name, rent);

		current_player->account -= rent;
		opponent->account += rent;

		if(current_player->account < 0) {
			to_bankrupt(board_head, current_player);
		}

	}						

	/* player lands on unowned property */
	if(go_to_index(current_player->current_block_id, board_head)->type == property && go_to_index(current_player->current_block_id, board_head)->owner.type == noone) {
		if(is_ai == 1) { /* AI */
			for(int i = 0; i < TILES; i++) {
				if(go_to_index(i, board_head)->type == property) {
					avg_price += go_to_index(i, board_head)->price;
					count_props++;
				}
			}
			avg_price /= count_props;
			if(go_to_index(current_player->current_block_id, board_head)->type < avg_price) {
				buy_property(go_to_index(current_player->current_block_id, board_head), current_player);
 
			} else {
				rng = (rand() % 6) + 1;

				if(rng <= 3 && rng >= 1) {
					buy_property(go_to_index(current_player->current_block_id, board_head), current_player);

				} else {
					printf("%s decided to not buy this property!\n", current_player->name);

				}

			}

		} else { /* PLAYER */
			printf("\n%s, wanna buy this property?\n\n", current_player->name);
			printf("(1-yes, 0-no): ");
			scanf("%d", &acceptance);
			if(acceptance == 1) {
				buy_property(go_to_index(current_player->current_block_id, board_head), current_player);
			
			}	

		}
		
	}

	count_props = 0;

	/* Player lands on his property */
	if(go_to_index(current_player->current_block_id, board_head)->owner.type == current_player->type) {
		if(is_ai == 1) { /* AI */
			for(int i = 0; i < TILES; i++) {
				if(go_to_index(i, board_head)->type == property && go_to_index(i, board_head)->owner.type == cap) {
					count_props++;
				}
				if(count_props >= 4) {
					rng = (rand() % 6) + 1;
					if(rng <= 3 && rng >= 1) {
						build_house(go_to_index(current_player->current_block_id, board_head), current_player);

					} 

				} 
			}
		} else { /* PLAYER */
			printf("%s landed on his property!\n", current_player->name);
			acceptance = 1;
			while(acceptance == 1) {
				printf("\n%s, wanna build on property?\n\n", current_player->name);
				printf("(1-yes, 0-no): ");
				scanf("%d", &acceptance);
				build_house(go_to_index(current_player->current_block_id, board_head), current_player);

			}
		}
	}

	/* Player lands on fortune card */
	if(go_to_index(current_player->current_block_id, board_head)->type == fortune) {
		printf("%s draws a fortune card!\n", current_player->name);
		pick_fortune_card(current_player, cards, board_head, opponent);
	}

}

void gameplay(block_t *board_head, struct player player_one, struct player player_two, fortune_t cards[CARDS]) {

	int input, turn_done, rng, rent = 0, gaming = 1, rolled = 0, acceptance;
	player_t *current_player = &player_two;

	while(gaming) {

		show_board(board_head, player_one, player_two);
		printf("\n");

		if(current_player->turn_to_wait != 0) {
			printf("%s waits for %d turns!\n", current_player->name, current_player->turn_to_wait);
			current_player->turn_to_wait -= 1;

		} else {
			turn_done = 0;
			rolled = 0;

			while(!turn_done) {
				if(current_player->type == car) {
					printf("Car: %d$\t Cap: %d$\n", player_two.account, player_one.account); //fix this
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

				} else {
					input = 1;

				}
				
				switch(input) {
					case 1:
						//roll dice and move
						rng = (rand() % 6) + 1;
						printf("%s Rolled dice: %d\n", current_player->name, rng);
						current_player->current_block_id += rng;
						if(current_player->current_block_id > TILES-1) {
							current_player->current_block_id %= TILES;
							printf("%s gets start bonus!\n", current_player->name);
							current_player->account += 10000;
							turn_done = 1;
						}
						rolled = 1;

						printf("\n");
						show_board(board_head, player_one, player_two);
						printf("\n");

						if(current_player == &player_one) {
							process_move(current_player, board_head, cards, &player_two);

						} else if(current_player == &player_two) {
							process_move(current_player, board_head, cards, &player_one);

						}

						//exit(0);

						turn_done = 1;
						
					break;
					case 2:
						printf("%s account: %d\n", current_player->name, current_player->account);	
					break;
					case 3:
						printf("Printing owned properties of %s...\n", current_player->name);
						for(int i = 0; i < 11; i++) {
							if(current_player->owned_block_ids[i] != -1) {
								printf("%d - %s\n", i, go_to_index(current_player->owned_block_ids[i], board_head)->name);
							}
						}
					break;
					case 4:
						show_properties(board_head);
					break;
					case 5:
						if(rolled) {
							buy_property(go_to_index(current_player->current_block_id, board_head), current_player);	
						} else {
							printf("First you gotta roll dice!\n");
						}
					break;
					case 6:
						if(rolled) {
							build_house(go_to_index(current_player->current_block_id, board_head), current_player);
						} else {
							printf("First you gotta roll dice!\n");
						}
					break;
					case 7:
						sell_property(board_head, current_player);
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

int main() {

	srand(time(NULL));

	block_t *curr, *board_head;
	player_t p1, p2;
	fortune_t cards[CARDS];

	init_players(&p1, &p2);
	p1.name = "AI";
	p2.name = "Car";
	init_the_board(&curr, &board_head);
	init_fortune_cards(cards);
	curr->next = board_head;

	/*
	printf("%s\n", curr->name);
	curr = curr->next;
	printf("%s\n", curr->name);
	curr = curr->next;
	printf("%s\n", curr->name);
	curr = curr->next;
	printf("%s\n", curr->name);*/

	gameplay(board_head, p1, p2, cards);
	//show_board(board_head, p1, p2);
	printf("\n");

}