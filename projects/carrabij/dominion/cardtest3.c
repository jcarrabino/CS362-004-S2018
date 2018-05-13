/******************************************************************
*  Name: John Carrabino
*  Class: CS362
*  Card Tested: Village
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
  int testCount = 0; 
  int player1 = 0;
  int position = 0;
  int choice1 = 0;
  int choice2 = 0;
  int choice3 = 0;
  int bonus = 0;
  int cards = 1;
  int k[10] = {smithy, adventurer, village, mine, minion, steward, treasure_map, council_room, feast, gardens};
  struct gameState game, test;
  initializeGame(2, k, 100, &game);

  printf("\nVILLAGE Card Test:\n");
  memcpy(&test, &game, sizeof(struct gameState));
  testCount++;
  printf("\nTEST 1: Hand/Deck counts BEFORE playing Village Card\n");
  printf("Test hand count: %d\n", test.handCount[player1]);
  printf("Control hand count: %d\n", game.handCount[player1]);
  printf("Test deck count: %d\n", test.deckCount[player1]);
  printf("Control deck count: %d\n", game.deckCount[player1]);
  
  //Test 1: Initial Hand/Deck Counts
  if (test.handCount[player1] == game.handCount[player1] && test.deckCount[player1] == game.deckCount[player1]){
    printf("Test hand/deck counts match actual counts\n");
    printf("TEST 1 PASSED\n");
  }  else {
    printf("Test hand/deck counts DO NOT match actual counts\n");
    printf("TEST 1 FAILED\n");
    passed = 1;
    failed++;
  }
  testCount++;
  
  //Test 2:Initial Action count
  printf("\nTEST 2: Action count BEFORE playing Village Card\n");
  printf("Test action count: %d\n", test.numActions);
  printf("Control action count: %d\n", game.numActions);
  if (test.numActions == game.numActions){
    printf("Test action count matches Control count\n");
    printf("TEST 2 PASSED\n");
  } else {
    printf("Test action count DOES NOT match actual action count\n");
    printf("TEST 2 FAILED\n");
    passed = 1;
    failed++;
  }
  
  //Test 3: Hand/Deck counts AFTER playing Village Card
  cardEffect(village, choice1, choice2, choice3, &test, position, &bonus);
  testCount++;
  printf("\nTEST 3: Hand/Deck counts AFTER playing Village Card\n");
  printf("Test hand count: %d\n", test.handCount[player1]);
  printf("Control hand count: %d\n", game.handCount[player1] + cards - 1);
  printf("Test deck count: %d\n", test.deckCount[player1]);
  printf("Control deck count: %d\n", game.deckCount[player1] - cards);
  if (test.handCount[player1] == game.handCount[player1] + cards - 1 && test.deckCount[player1] == game.deckCount[player1] - cards){
    printf("Test hand/deck counts match actual counts\n");
    printf("TEST 3 PASSED\n");
  }  else {
    printf("Test hand/deck counts DO NOT match actual counts\n");
    printf("TEST 3 FAILED\n");
    passed = 1;
    failed++;
  }
  
  //Test 4: Action count AFTER playing village Card. 
  testCount++;
  printf("\nTEST 4: Action counts AFTER playing Village Card");
  printf("Test action count: %d\n", test.numActions);
  printf("Control action count: %d\n", game.numActions + 2);
  if (test.numActions == game.numActions + 2){
    printf("Test action count matches actual count\n");
    printf("TEST 4 PASSED\n");
  }  else {
    printf("Test action count DOES NOT match actual action count\n");
    printf("TEST 4 FAILED\n");
    passed = 1;
    failed++;
  }

  if (passed == 0)
    printf("\n%d out of %d tests passed\n\n", testCount - failed, testCount);
  else
    printf("\n%d out of %d tests passed\n\n", testCount - failed, testCount);
  return 0;
}