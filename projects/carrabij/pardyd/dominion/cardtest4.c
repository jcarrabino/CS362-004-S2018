/******************************************************************
*  Name: John Carrabino
*  Class: CS362
*  Card Tested: Steward
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
  int  failedTests = 0;
  int totalTests = 0;
  int player1 = 0;
  int position = 0;
  int choice1 = 0;
  int choice2 = 0;
  int choice3 = 0;
  int c1_after = 0;
  int c1_before = 0;
  int bonus = 0;
  int k[10] = {smithy, adventurer, village, mine, minion, steward, treasure_map, council_room, feast, gardens};
  struct gameState test1, test2, test3;
  initializeGame(2, k, 100, &test1);
  initializeGame(2, k, 100, &test2);
  initializeGame(2, k, 100, &test3);
  memcpy(&test2, &test1, sizeof(struct gameState));
  memcpy(&test3, &test1, sizeof(struct gameState));

  printf("\nSTEWARD card test:\n");
  totalTests++;
  
  //int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
  // choice1 == 1, +2 cards
  // choice1 == 2, +2 coins
  // choice1 == 3, -2 cards from hand
  
  printf("\nTEST 1: Steward Choice 1, +2 cards to hand\n");
  printf("Test hand count BEFORE Steward: %d\n", test1.handCount[player1]);
  c1_before = test1.handCount[player1];
  choice1 = 1;
  cardEffect(steward, choice1, choice2, choice3, &test1, position, &bonus);
  printf("Test hand count AFTER Steward: %d\n", test1.handCount[player1]);  
  c1_after = test1.handCount[player1];
  // Actual hand count will increase by 1 since we discard the Steward card after plying it
  if (c1_after - c1_before == 1){
    printf("Steward choice 1 added two cards to players hand\n");
    printf("TEST 1 PASSED\n");  
  }
  else {
    printf("Steward choice 1 DID NOT add two cards to players hand\n");
    printf("TEST 1 FAILED\n");  
    failedTests++;
  }
  
  
  printf("\nTEST 2: Steward Choice 2, +2 coins\n");
  totalTests++;
  printf("Test coin count BEFORE Steward: %d\n", test2.coins);
  c1_before = test2.coins;
  choice1 = 2;
  cardEffect(steward, choice1, choice2, choice3, &test2, position, &bonus);
  printf("Test coin count AFTER Steward: %d\n", test2.coins);
  c1_after = c1_before + 2;
  
  if (test2.coins == c1_after){
    printf("Steward choice 2 added 2 coins to player 1\n");
    printf("TEST 2 PASSED\n");  
  }
  else {
    printf("Steward choice 2 DID NOT add 2 coins to player 1\n");
    printf("TEST 2 FAILED\n");  
    passed = 1;
    failedTests++;
  }   
  
  printf("\nTEST 3: Steward Choice 3, -2 cards from hand\n");
  totalTests++;  
  printf("Test hand count BEFORE steward is %d\n", test3.handCount[player1]);
  c1_before = test3.handCount[player1];
  choice1 = 3;
  cardEffect(steward, choice1, choice2, choice3, &test3, position, &bonus);
  printf("Test hand count AFTER steward is %d\n", test3.handCount[player1]);
  c1_after = test3.handCount[player1];  
  // Actual hand count will decrease by 3 since we discard the Steward card after plying it
  if (c1_before - c1_after == 3){
    printf("Steward choice 3 removed 2 cards from player's hand\n");
    printf("TEST 3 PASSED\n");  
  } else {
    printf("Steward choice 3 DID NOT remove 2 cards from player's hand\n");
    printf("TEST 3 FAILED\n");  
    passed = 1;
    failedTests++;
  }
  
  if (passed == 0)
    printf("\n%d out of 3 tests passed\n\n", totalTests - failedTests);
  else
    printf("\n%d out of 3 tests passed\n\n", totalTests - failedTests);
  return 0;
}