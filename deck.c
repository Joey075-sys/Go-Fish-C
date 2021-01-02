#include "deck.h"
#include "card.h"
#include "player.h"
#include <stdio.h>

/*int main() {

shuffle();

deal_player_cards();
printf("%d\n", var);
//char var2 = check_add_book(&user);
//printf("%c\n", var2);
//char search_var = {'4'};
//int var3 = search(&user,search_var);
//printf("%d",var3);

for(int n=0; n<7; n++){
struct card* test = (struct card*) malloc(sizeof(struct card));
test = next_card();
printf("%s:%d\n", "card",n+1);

printf("%c", test->suit);
printf("%c%c\n", test->rank[0], test->rank[1]);

if(n==0){
printf("%s\n", "removing card 2");
printf("card 2: %c%c%c", test->suit, test->rank[0], test->rank[1]);
int test2 = remove_card(&user,test);
printf("%d\n", test2);
printf("%s\n", "testing the not work part");
printf("card 2: %c%c%c", test->suit, test->rank[0], test->rank[1]);
int test3 = remove_card(&user,test);
printf("%d\n", test3);

}
}
printf("%s\n", "return statement end");
return 0;
}*/


int main() {
shuffle();
struct player* source_player = (struct player*) malloc(sizeof(struct player));
struct player* destination_player = (struct player*) malloc(sizeof(struct player));
struct hand* iter = (struct hand*) malloc(sizeof(struct hand));

deal_player_cards(source_player);
deal_player_cards(destination_player);

transfer_cards(source_player, destination_player, source_player->card_list->top.rank[0]);
iter = source_player->card_list;
printf("%s\n", "Source Player Card List");
int i = 0;
while(iter != NULL) {
	i += 1;
	printf("card %d: %c%s\n", i, iter->top.suit, iter->top.rank);
	iter = iter->next;
}

iter = destination_player->card_list;
printf("%s\n", "Destination Player Card List");
i = 0;
while(iter != NULL) {
        i += 1;
        printf("card %d: %c%s\n", i, iter->top.suit, iter->top.rank);
        iter = iter->next;
}


//struct card* old = (struct card*) malloc(sizeof(struct card));
//old->rank[0] = new_player->card_list->next->next->next->next->next->next->top.rank[0];
//old->rank[1] = new_player->card_list->next->next->next->next->next->next->top.rank[1];
//old->suit = new_player->card_list->next->next->next->next->next->next->top.suit;




/*for(int n=0; n<7; n++){
struct card* test = (struct card*) malloc(sizeof(struct card));
test = next_card();
printf("%s:%d\n", "card",n+1);
printf("%c%s", test->suit, test->rank);
//printf("%c%c\n", test->rank[0], test->rank[1]);

if(n==1){
printf("%s\n", "removing card 2");
printf("card 2: %c%s\n", test->suit, test->rank);
int test2 = remove_card(new_player,test);
printf("%d\n", test2);
printf("%s\n", "testing the not work part");
printf("card 2: %c%c%c", test->suit, test->rank[0], test->rank[1]);
int test3 = remove_card(new_player,test);
printf("%d\n", test3);

}
}
printf("%s\n", "return statement end");

//old->rank[1] = new_player->card_list->next->next->top.rank[1];
//old->suit = new_player->card_list->next->next->top.suit;

//struct card* randomcar = (struct card*) malloc(sizeof(struct card));
printf("removing card %c%s\n", old->suit, old->rank);
remove_card(new_player, old);

struct hand* cur_hand = (struct hand*) malloc(sizeof(struct hand));
cur_hand = new_player->card_list;
//printf("removing card %c%s\n", cur_hand->top.suit, cur_hand->top.rank);
//remove_card(new_player, cur_hand); 

int i = 0;
while(cur_hand != NULL) {
	i += 1;
	printf("card %d: %c%s\n", i,cur_hand->top.suit, cur_hand->top.rank);
	cur_hand = cur_hand->next;


//char result = computer_play(new_player);
//reset_player(new_player);


//printf("%c\n", result);
//int num = game_over(new_player);

//num = 5;
//printf("%d \n", num);
//shuffle();

//struct card* fun; 
//fun = next_card( );
return 0;*/
}

