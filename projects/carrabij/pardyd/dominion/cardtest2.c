/******************************************************************
*  Name: John Carrabino
*  Class: CS362
*  Card Tested: Smithy
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
  struct gameState game, test;
  initializeGame(2, k, 1000, &game);

  printf("\nSMITHY cart test:\n");

  memcpy(&test, &game, sizeof(struct gameState));
  printf("\nTEST 1: deck/hand counts match BEFORE playing Smithy\n");
  printf("Test hand count: %d\n", test.handCount[player1]);
  printf("Control hand count: %d\n", game.handCount[player1]);
  printf("Test deck count: %d\n", test.deckCount[player1]);
  printf("Control deck count: %d\n", game.deckCount[player1]);
  if (test.handCount[player1] == game.handCount[player1] && test.deckCount[player1] == game.deckCount[player1])
    printf("TEST 1 PASSED\n");
  else {
    printf("TEST 1 FAILEDn");
    passed = 1;
    failed++;
  }
  
  
  printf("\nTEST 2: deck/hand counts match AFTER playing Smithy\n");
  cardEffect(smithy, choice1, choice2, choice3, &test, position, &bonus);
  int cards = 3;

  printf("Test hand count: %d\n", test.handCount[player1]);
  printf("Control hand count: %d\n", game.handCount[player1] + cards - 1);
  printf("Test deck count: %d\n", test.deckCount[player1]);
  printf("Control hand count: %d\n", game.deckCount[player1] - cards);
  if (test.handCount[player1] == game.handCount[player1] + cards - 1 && test.deckCount[player1] == game.deckCount[player1] - cards)
    printf("TEST 2 PASSED\n");
  else {
    printf("TEST 2 FAILED\n");
    passed = 1;
    failed++;
  }
  if (passed == 0)
    printf("\n%d out of 2 tests passed\n\n", 2 - failed);
  else
    printf("\n%d out of 2 tests failed\n\n", failed);
  return 0;
}