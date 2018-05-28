/******************************************************************
*  Name: John Carrabino
*  Class: CS362 
*  Assignment: Smithy Random Test File
******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <time.h>

void initTestGame(struct gameState *game) {
  int i, player;
  game->whoseTurn = rand() % 2;
  
  // Randomly generate hands, turns, decks, and discard for gameState
  int maxRandHand = rand() % (500 + 1);
  int maxRandTurn = rand() % (16 + 1);
  int maxRandDeck = rand() % (500 + 1);
  int maxRandDiscard = rand() % (500 + 1);

  // Initialize player's hand
  game->hand[game->whoseTurn][0] = 7;
  game->handCount[game->whoseTurn] = maxRandHand;
  for(i = 1; i < game->handCount[game->whoseTurn]; i++)
    game->hand[game->whoseTurn][i] = maxRandTurn;

  game->deckCount[game->whoseTurn] = maxRandDeck;
  for(i = 0; i < game->deckCount[game->whoseTurn]; i++)
    game->deck[game->whoseTurn][i] = maxRandTurn;

  game->discardCount[game->whoseTurn] = maxRandDiscard;
  for(i = 0; i < game->discardCount[game->whoseTurn]; i++)
    game->discard[game->whoseTurn][i] = maxRandTurn;

  // Initialize opponents hand
  if(game->whoseTurn == 0)
    player = 1;
  else
    player = 0;
  game->handCount[player] = maxRandHand;
  for(i = 0; i < game->handCount[player]; i++)
    game->hand[player][i] = maxRandTurn;

  game->deckCount[player] = maxRandDeck;
  for(i = 0; i < game->deckCount[player]; i++)
    game->deck[player][i] = maxRandTurn;

  game->discardCount[player] = maxRandDiscard;
  for(i = 0; i < game->discardCount[player]; i++)
    game->discard[player][i] = maxRandTurn;
}

int main() {
	int count = 1;
	srand(time(NULL));
	int seed = rand() % 100 + 1;
    int loopCounter = rand() % 80 + 21;
	int players = 2;
    int init_hand, result_hand;
	struct gameState game;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	initializeGame(players, k, seed, &game);
	game.phase = 0;
	game.numBuys = 1;
    
	int j;
	for(j = 0; j < loopCounter; j++){
        printf("|==================================================|\n");
        printf("|                 Random Test #%-3d                 |\n", count);
        printf("|--------------------------------------------------|\n");
		initTestGame(&game);
        printf("| Before Playing Smithy:                           |\n");
        printf("|    - Hand Count: %4d                            |\n", game.handCount[game.whoseTurn]);
        init_hand = game.handCount[game.whoseTurn];
        cardEffect(smithy, 0, 0, 0, &game, 0, 0);
        printf("|                                                  |\n");
        printf("| After Playing Smithy:                            |\n");
        printf("|    - Hand Count: %4d                            |\n", game.handCount[game.whoseTurn]);
        result_hand = game.handCount[game.whoseTurn];
        if (init_hand == result_hand - 2){
          printf("|--------------------------------------------------|\n");
          printf("|                 Test #%-3d PASSED                 |\n", count);
          printf("|==================================================|\n\n\n");       
        }
        else {
          printf("|--------------------------------------------------|\n");
          printf("|                Test #%-3d FAILED                  |\n", count);
          printf("|==================================================|\n\n\n");
        }
		count++;
	}
    return 0;
}