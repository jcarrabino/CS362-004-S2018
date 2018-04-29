/******************************************************************
*  Name: John Carrabino
*  Class: CS362
*  Card Tested: Adventurer
******************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
  int passed = 0;
  int failed = 0;
  int player1 = 0;
  int position = 0;
  int choice1 = 0;
  int choice2 = 0;
  int choice3 = 0;
  int bonus = 0;
  int k[10] = {smithy, adventurer, village, mine, minion, steward, treasure_map, council_room, feast, gardens};
  char x1[32];
  char x2[32];
  struct gameState game, test;
  initializeGame(2, k, 100, &game);
  memcpy(&test, &game, sizeof(struct gameState));

  printf("\nADVENTURER card test:\n");
  
  printf("\nTEST 1: Initial hand/deck counts match BEFORE playing Adventurer\n");
  printf("Test hand count: %d\n", test.handCount[player1]);
  printf("Control hand count: %d\n", game.handCount[player1]);
  printf("Test deck count: %d\n", test.deckCount[player1]);
  printf("Control deck count: %d\n", game.deckCount[player1]);
  if (test.handCount[player1] == game.handCount[player1] && test.deckCount[player1] == game.deckCount[player1])
    printf("TEST 1 PASSED\n");
  else {
    printf("TEST 1 FAILED\n");
    passed = 1;
    failed++;
  }
  
  
  printf("\nTEST 2: hand/deck counts AFTER playing Adventurer\n");
  cardEffect(adventurer, choice1, choice2, choice3, &test, position, &bonus);
  printf("\nPlay adventurer card.\n");
  printf("Check hand/deck count.\n");
  int addedCards = 2;
  printf("Hand count: %d\n", test.handCount[player1]);
  printf("Expected: %d\n", game.handCount[player1] + addedCards - 1);
  printf("Deck count: %d\n", test.deckCount[player1]);
  printf("Expected: %d\n", game.deckCount[player1] - (game.discardCount[player1] + addedCards));
  if (test.handCount[player1] == game.handCount[player1] + addedCards - 1 && test.deckCount[player1] == game.deckCount[player1] - (game.discardCount[player1] + addedCards)){
    printf("Player successfully added two cards to hand after playing Adventurer card\n");
    printf("TEST 2 PASSED\n");
  } else {
    printf("TEST 2 FAILED\n");
    passed = 1;
    failed++;
  }
  
  
  printf("\nTEST 3: player gained 2 treasure cards AFTER playing Adventurer\n");
  int first = game.hand[player1][game.handCount[player1]-1];
  int second = game.hand[player1][game.handCount[player1]-2];
  cardNumToName(first, x1);
  cardNumToName(second, x2);
  printf("First new card is %s\n", x1);
  printf("Second new card is %s\n", x2);
  if ((first != copper || first != silver || first != gold) && (second != copper || second != silver || second != gold)){
    printf("The player drew 2 treasure cards\n");
    printf("TEST 3 PASSED\n");
  } else {
    printf("TEST 3 FAILED\n");
    passed = 1;
    failed++;
  }
  
  
  if (passed == 0)
    printf("\n3 of 3 tests passed.\n\n");
  else
    printf("\n%d of 3 tests failed.\n\n", failed);
  return 0;
}