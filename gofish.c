#include <stdio.h>
#include <stdlib.h>
#include "gofish.h"
#include "card.h"
#include "player.h"
#include "deck.h"

int main(int args, char* argv[])
{
int transno;
int transno2;
char rank;
char book;
char book2;
char *buffer1;
char *buffer2;

    	shuffle();
    	printf("Shuffling deck...\n");
    	deal_player_cards(&user);
    	deal_player_cards(&computer);
  //  extern struct deck deck_instance;

while(1) {
int player_1 =1;
int player_2 =1;
    	while(player_1) {
	// printf("continued...\n");
   	 printf("\n");
        	player_list(&user);
        	printf("%s", "Player 1's Book -");
        	player_book(&user);
        	printf("%s", "Player 2's Book -");
   	 player_book(&computer);

            	rank = user_play(&user);

            	if (search(&computer, rank) == 1) {
   		 transno = transfer_cards(&computer, &user, rank);
   		 player_1=0;
   	  }

            	else {
   		 printf("  - Player 2 has no %c's\n",rank);
                 add_card(&user, next_card());
		 printf("adds card successfully\n");
   		 struct card* draw = (struct card*) malloc(sizeof(struct card));
		 printf("creates card draw object successfully\n");
   		 draw = draws(&user);
		 printf("completes draw\n");
   		 printf("  - Go Fish, Player 1 draws %c%c%c\n", draw->suit, draw->rank[0], draw->rank[1]);
   		 player_1=0;
   		 transno=1;
   	 }
   	 //buffer1=books(&user, transno);
   	 //buffer2=books2(&user, transno2,rank);
   	 book = check_add_book(&user);
            	if (book != 0 && game_over(&user)==0){
   	 //printf("  - Player 2 has %s",buffer1);
   	 //books(&user, transno);
   	 //printf("\n  - Player 1 has %s",buffer2);
   	 //books2(&user, transno, rank);
        		 printf("\n  - Player 1 books %c\n",book);
   	 printf("  - Player 1 gets another turn\n");
   	 player_1=1;
   		 }
   	 else if (game_over(&user)==1){
   	 player_2 =0;}
   	 else{
   	 printf("  - Player 2's turn\n");
   		 }
    } // while player_1

    while(player_2){
   	 printf("\n");
   	 player_list(&user);
        	printf("%s", "Player 1's Book -");
        	player_book(&user);
        	printf("%s", "Player 2's Book -");
        	player_book(&computer);

            	rank = computer_play(&computer);

            	if (search(&user, rank) == 1) {
                    	transno2=transfer_cards(&user, &computer, rank);
           		 player_2=0;
   	 }

            	else {
   		 printf("  - Player 1 has no %c's\n",rank);
                    	add_card(&computer, next_card());
   		 printf("  - Go Fish, Player 2 draws a card\n");   		 
   		 player_2=0;
   		 transno2=1;
            	}

   	 //buffer1=books(&user, transno);   	 
   	 //buffer2=books2(&user, transno2,rank);
   	 book2 = check_add_book(&computer);
            	if (book2!= 0 && game_over(&computer)==0){
   	 //printf("  - Player 1 has %s",buffer2);
   	 //books2(&computer, transno2,rank);
   	 //printf("\n  - Player 2 has %s",buffer1);
   	 //books(&computer, transno2);
        		 printf("\n  - Player 2 books %c\n",book2);
        		 printf("  - Player 2 gets another turn\n");
         player_2 =1;
   		 }
   	 else if(game_over(&computer)==1){
   		 }
   	 else{
   		 printf("  - Player 1's turn\n");
   		 }
    }// while player_2


            	int prompt = 0;
            	if(game_over(&user)==1) {
              			 printf("\n");
   		 player_list(&user);
        	printf("%s", "Player 1's Book -");
        	player_book(&user);
        	printf("%s", "Player 2's Book -");
   	     	player_book(&computer);
   	 fprintf(stderr, "\nCongratulations! you beat the computer player.\n");
                    	prompt = prompt_next();
   		 if (prompt ==0){
   		 reset_player(&user);
   		 reset_player(&computer);
		 //continue;
//   		 free(deck_instance);
   	     	shuffle();
   	     	printf("Shuffling deck...\n");
   	     	deal_player_cards(&user);
   	     	deal_player_cards(&computer);
   			 }
   		 else if (prompt ==1){
   		 return 0;}
            	}

            	else if(game_over(&computer)==1) {
       			 printf("\n");
   		 player_list(&user);
       		 printf("%s", "Player 1's Book -");
       		 player_book(&user);
       		 printf("%s", "Player 2's Book -");
       		 player_book(&computer);
   	     	fprintf(stderr, "\nSorry! You loose the game to the computer player. \n");
                    	prompt = prompt_next();
   		 if (prompt ==0){
   		 reset_player(&user);
   		 reset_player(&computer);
		 //continue;
//   		 free(deck_instance);
   		 shuffle();
   	     	printf("Shuffling deck...\n");
   	     	deal_player_cards(&user);
   	     	deal_player_cards(&computer);
   	 }
   		 else if (prompt ==1){
   		 return 0;}
            	}

}


}

