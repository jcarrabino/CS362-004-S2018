/******************************************************************
*  Name: John Carrabino
*  Class: CS362
*  Function Tested: fullDeckCount()
******************************************************************/

#include "interface.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

int main() {
  int passed = 0;
  int failed = 0;
  struct gameState game;
  int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
  initializeGame(2, k, 100, &game);
  int h1[0];
  int d1[0];
  int td1[0];
  memcpy(game.hand[0], h1, 0);
  memcpy(game.deck[0], d1, 0);
  memcpy(game.discard[0], td1, 0);
  game.handCount[0] = 0;
  game.deckCount[0] = 0;
  game.discardCount[0] = 0;
  
  printf("\nUNIT TEST 2: fillDeckCount()\n");
  printf("fillDeckCount() TEST 1: Empty Deck\n");
  passed++;
  int result = fullDeckCount(0, copper, &game);
  if (result == 0) {
    printf("TEST 1 PASSED\n");
  }
  else {
    printf("TEST 1 FAILED\n");
    failed++;
  }

  int h2[5] = {copper, silver, gold, silver, copper};
  memcpy(game.hand[0], h2, 5 * sizeof(int));
  game.handCount[0] = 5;
  int d2[7] = {copper, silver, copper, silver, gold, copper, gold};
  memcpy(game.deck[0], d2, 7 * sizeof(int));
  game.deckCount[0] = 7;
  int td2[3] = {copper, silver, gold};
  memcpy(game.discard[0], td2, 3 * sizeof(int));
  game.discardCount[0] = 3;

  //5 Silver test
  printf("fillDeckCount() TEST 2: 5 silver in deck\n");
  passed++;
  result = fullDeckCount(0, silver, &game);
  if (result == 5) {
    printf("TEST 2 PASSED\n");
  }
  else {
    printf("TEST 2 FAILED\n");
    failed++;
  }

  //6 Copper test
  printf("fillDeckCount() TEST 3: 6 copper in deck\n");
  passed++;
  result = fullDeckCount(0, copper, &game);
  if (result == 6) {
    printf("TEST 3 PASSED\n");
  }
  else {
    printf("TEST 4 FAILED\n");
    failed++;
  }

  //4 Gold test
  printf("fillDeckCount() TEST 4: 4 gold in deck\n");
  passed++;
  result = fullDeckCount(0, gold, &game);
  if (result == 4) {
    printf("TEST 4 PASSED\n");
  }
  else {
    printf("TEST 4 FAILED\n");
    failed++;
  }

  // Output what passed or failed.
  if (failed == 0)
    printf("4 OF 4 TESTS PASSED.\n\n");
  else
    printf("%d OF 4 TESTS PASSED.\n\n", passed - failed);
  return 0;
}
