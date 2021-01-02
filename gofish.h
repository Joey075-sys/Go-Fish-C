#ifndef GOFISH_H
#define GOFISH_H

#include "deck.h"
#include "card.h"
#include "player.h"
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "card.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int prompt_next() {
char ans[20];

printf("Do you want to play again [Y/N]: ");
scanf("%s", ans);

if(strcmp(ans, "Y") == 0) {
    	return 0;
}
else {
    	return 1;
}
}

void* player_list(struct player* target){

struct hand* cur_hand;
cur_hand = target->card_list;
printf("%s","Player 1's Hand - ");
while(cur_hand !=NULL){
	printf("%c%c%c ",cur_hand->top.suit, cur_hand->top.rank[0], cur_hand->top.rank[1]);
	cur_hand = cur_hand->next;
}
printf("\n");
}

void* player_book(struct player* target){
size_t book_length= strlen(target->book);
//printf("length of book (in print statement):%d\n",book_length);
for (int i=0; i<book_length; i++){
	printf("%c ", target->book[i]);
}
printf("\n");
}

struct card* draws(struct player* target) {

struct hand* cur_hand;
struct card* cur_card;
cur_hand = target->card_list;

while(cur_hand->next != NULL) {
    	cur_hand = cur_hand->next;
}

cur_card->rank[0] = cur_hand->top.rank[0];
cur_card->rank[1] = cur_hand->top.rank[1];
cur_card->suit = cur_hand->top.suit;

return cur_card;
}

char* books(struct player* target, int trans) {
struct hand* cur_hand;
struct card* cur_card;
cur_hand = target->card_list;
size_t loopy = 0;
size_t node = target->hand_size - trans;
char* list[100];
char *buffer=malloc((3*target->hand_size)+1);;
//char append[1000];
//char var1;
int pos=0;
while(cur_hand != NULL) {
    printf("enters the while loop");
    	if (loopy >= node) {
   	 printf("loopy condition is true");
            	//sprintf(buffer,"%c%c%c ", cur_hand->top.suit, cur_hand->top.rank[0], cur_hand->top.rank[1]);
   	 buffer[pos]=cur_hand->top.suit;
   	 printf("%s",buffer);
   	 //strcat(var1,cur_hand->top.rank[0]);
   	 //strcpy(list[pos],var1);
   	 //list[pos]=buffer;
   	 //strcat(append, buffer);
   	 pos +=1;
   	 buffer[pos]=cur_hand->top.rank[0];
   	 printf("%s",buffer);
   	 pos+=1;
    	}
    	cur_hand = cur_hand->next;
    	loopy+=1;
}
printf("return statement of books");
return buffer;
}

char* books2(struct player* target, int trans, char rank) {
struct hand* cur_hand;
struct card* cur_card;
cur_hand = target->card_list;
size_t loopy = 0;
size_t node = target->hand_size - trans;
char* list[52];
char *buffer=malloc((3*target->hand_size)+1);;
char* append[1000];
char* var1;
int pos =0;
while(cur_hand != NULL) {
    printf("enters the while loop");
    	if (loopy < node && cur_hand->top.rank[0] ==rank) {
   	 printf("loopy condition is true");
            	//sprintf(buffer,"%c%c%c ", cur_hand->top.suit, cur_hand->top.rank[0], cur_hand->top.rank[1]);
   		 //strcpy(var1, cur_hand->top.suit);
   	 //strcat(var1, cur_hand->top.rank[0]);
   	 //strcpy(list[pos], var1);
   	 //list[pos]=buffer;
   	 //strcat(append, buffer);
   	 buffer[pos]=cur_hand->top.suit;
   	 printf("%s",buffer);
   	 pos +=1;
   	 buffer[pos]=cur_hand->top.rank[0];
   	 printf("%s",buffer);
   	 pos +=1;
    }
    	cur_hand = cur_hand->next;
    	loopy+=1;
}
printf("return statement of book2");
return buffer;
}

#endif




