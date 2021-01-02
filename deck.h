#ifndef DECK_H
#define DECK_H

#include <stdlib.h>
#include <stdio.h> // library for "printf"
#include <string.h> // library for "strcat"
#include <time.h>
#include "player.h"
#include "card.h"


/*
 * Structure: deck
 * ---------------
 *  An array of 52 cards.
 */
struct deck {
  struct card list[52];
  int top_card;
};

/*
 * Variable: deck_instance
 * -----------------------
 *
 * Go Fish uses a single deck
 */
struct deck deck_instance;

/*
 * Function: shuffle
 * --------------------
 *  Initializes deck_instance and shuffles it.
 *  Resets the deck if a prior game has been played.
 *
 *  returns: 0 if no error, and non-zero on error
 */

int shuffle() {

char* suit_list[4] = {"C","D","H","S"};
char* rank_list[13] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

int x=0;
for (int i=0; i<4; i++){ // keeping track of suit_list
    	for (int j=0; j<13; j++){ // keeping track of rank_list
    	//strcat(suit_list[i], rank_list[j]);
    	char* card = (char*) malloc(1 + strlen(suit_list[i])+ strlen(rank_list[j]));
    	strcpy(card, suit_list[i]);
    	strcat(card, rank_list[j]);

    	char copy[1];
    	strcpy(copy, suit_list[i]);

    	deck_instance.list[x].suit = copy[0];
    
	char copyz[2];
	strcpy(copyz, rank_list[j]);
	deck_instance.list[x].rank[0]=copyz[0];
	deck_instance.list[x].rank[1]=copyz[1];

	//printf("%c %c \n", copyz[0], copyz[1]);
    	//strcpy(deck_instance.list[x].rank, rank_list[j]);
    	//printf("%s\n", deck_instance.list[x].rank);
    	//printf("%c\n", deck_instance.list[x].suit);

    	//printf("%c\n", deck_instance.list[x]);

    	x+=1;
            	//printf("%s\n", card);

    	}
}

//printf("%s\n", deck_instance.list[8].rank);


srand(time(0));

const int SIZE = 52;
int randomint[SIZE];
for (int i = 0; i < SIZE; i++) {
    	randomint[i] = i;
    	//printf("%d\n", randomint[i]);
}

size_t length = 52;
if (length > 1)
{
    	size_t i;
    	for (int i = 0; i < length - 1; i++)
    	{
    	size_t z = i + rand() / (RAND_MAX / (length - i) + 1);
    	int temp = randomint[z];
    	randomint[z] = randomint[i];
    	randomint[i] = temp;
    	}
}



struct card shuffled[52];
for (int i = 0; i < SIZE; i++) {

    	shuffled[i].suit = deck_instance.list[randomint[i]].suit;
    	strcpy(shuffled[i].rank, deck_instance.list[randomint[i]].rank);
  	 
}

for (int i = 0; i < SIZE; i++) {
    	deck_instance.list[i].suit = shuffled[i].suit;
    	strcpy(deck_instance.list[i].rank, shuffled[i].rank);
}

deck_instance.top_card = 0;

return 0;
}


/*
 * Function: deal_player_cards
 * ---------------------------
 *  Deal 7 random cards to the player specified in the function.
 *  Remove the dealt cards from the deck.
 *
 *  target: pointer to the player to be dealt cards
 *
 *  returns: 0 if no error, and non-zero on error
 */

int deal_player_cards(struct player* target){

    
//deck_instance.top_card = index of the top card on deck

int top_card_index = deck_instance.top_card;
for (int i=0; i<7; i++){
//printf("%s%d\n","deck loop: ",i);

struct card* new_card1 = (struct card*) malloc(sizeof(struct card));
new_card1->rank[0] = deck_instance.list[top_card_index].rank[0];
new_card1->rank[1] = deck_instance.list[top_card_index].rank[1];
new_card1->suit = deck_instance.list[top_card_index].suit;
//printf("%s", "print something");
int var = add_card(target, new_card1);

//printf ("%d", var);
//printf("%c%s \n",new_card1.suit,new_card1.rank);
//printf("Prints something");

top_card_index +=1;
 
    }
deck_instance.top_card +=7;

//printf("%s", "return statement for deal cards:");
return 0;
}


/*
 * Function: next_card
 * -------------------
 *  Return a pointer to the top card on the deck.
 *  Removes that card from the deck.
 *
 *  returns: pointer to the top card on the deck.
 */
struct card* next_card()
{
struct card* hopefully = (struct card*) malloc(sizeof(struct card));
//struct card blank;
int tc = deck_instance.top_card;
hopefully->rank[0] = deck_instance.list[tc].rank[0];
hopefully->rank[1] = deck_instance.list[tc].rank[1];
hopefully->suit = deck_instance.list[tc].suit;


//deck_instance.list[tc] = blank;
deck_instance.top_card+=1;
//printf("%s\n", "output for next-card");
//printf("%c%c\n", hopefully->rank[0], hopefully->rank[1]);
return hopefully;
}


/*
 * Function: size
 * --------------
 *  Return the number of cards left in the current deck.
 *
 *  returns: number of cards left in the deck.
 */
size_t deck_size()
{
size_t size = sizeof(deck_instance.list) / sizeof(deck_instance.list[0]);
size -= deck_instance.top_card;
return size;
}

#endif




