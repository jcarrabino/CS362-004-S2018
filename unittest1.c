/******************************************************************
*  Name: John Carrabino
*  Class: CS362
*  Function Tested: gainCard()
******************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <assert.h>

int main() {
  int success = 0;
  int failed = 0;
  int passed = 4;
  int toFlag = 0;
  int player1 = 0;
  int k[10] = {smithy, adventurer, village, mine, minion, steward, treasure_map, baron, feast, gardens};
  struct gameState game;
  initializeGame(2, k, 100, &game);
  
  printf("\nUNIT TEST 1: isGameOver()\n");
  passed++;
  
  //int gainCard(int supplyPos, struct gameState *state, int toFlag, int player)
  // toFlag = 0 : add to discard
  // toFlag = 1 : add to deck
  // toFlag = 2 : add to hand
  
  printf("\ngainCard() TEST 1: toFlag == 0 && supplyPos == gold\n");
  printf("Discard count BEFORE gainCard(): %d\n", game.discardCount[player1]);
  int discard1 = game.discardCount[player1];
  game.hand[player1][1] = gold;
  int test1 = gainCard(gold, &game, 0, player1);
  printf("Discard count AFTER gainCard(): %d\n", game.discardCount[player1]);
  int discard2 = game.discardCount[player1];
  
  if (test1 == 0 && discard2 - discard1 == 1){
    printf("Player 1's Discard pile gained 1 card\n");
    printf("TEST 1 PASSED\n");
  } else{
    printf("Player 1's Discard pile DID NOT gain 1 card\n");
    printf("TEST 1 FAILED\n"); 
    failed++;    
  }
  
  
  printf("\ngainCard() TEST 2: toFlag == 1 && supplyPos == gold\n");
  passed++;
  printf("Deck count BEFORE gainCard(): %d\n", game.deckCount[player1]);
  int deck1 = game.deckCount[player1];  
  game.supplyCount[gold] = 1;
  int test2 = gainCard(gold, &game, 1, player1);
  printf("Deck count AFTER gainCard(): %d\n", game.deckCount[player1]);
  int deck2 = game.deckCount[player1];
  
  if (test2 == 0 && deck2 - deck1 == 1){
    printf("Player 1's Deck gained 1 card\n");
    printf("TEST 2 PASSED\n");
  } else{
    printf("Player 1's Deck DID NOT gain 1 card\n");
    printf("TEST 2 FAILED\n"); 
    failed++;        
  }
  
  
  
  printf("\ngainCard() TEST 3: toFlag == 2 && supplyPos == gold\n");
  passed++;
  printf("Hand count BEFORE gainCard(): %d\n", game.handCount[player1]);
  int hand1 = game.handCount[player1];
  game.supplyCount[gold] = 1;
  int test3 = gainCard(gold, &game, 2, player1);
  printf("Hand count AFTER gainCard(): %d\n", game.handCount[player1]);
  int hand2 = game.handCount[player1];
  
  if (test3 == 0 && hand2 - hand1 == 1){
    printf("Player 1's hand gained 1 card\n");
    printf("TEST 3 PASSED\n");
  } else{
    printf("Player 1's hand DID NOT gain 1 card\n");
    printf("TEST 3 FAILED\n"); 
    failed++;        
  }
  
  
  
  printf("\ngainCard() TEST 4: toFlag == 2 && supplyPos == gold\n");
  passed++;
  game.supplyCount[gold] = 0;
  printf("Hand count BEFORE gainCard(): %d\n", game.handCount[player1]);
  hand1 = game.handCount[player1];
  int test4 = gainCard(gold, &game, 2, player1);
  printf("Hand count AFTER gainCard(): %d\n", game.handCount[player1]);
  hand2 = game.handCount[player1];
  
  if (test4 == -1 && hand2 - hand1 == 0){
    printf("gainCard() Successfully returned -1 when card does not exist\n");
    printf("TEST 4 PASSED\n");
  } else{
    printf("gainCard() DID NOT return -1 when card does not exist\n");
    printf("TEST 4 FAILED\n"); 
    failed++;        
  }
  
  
  
  if (success == 0)
    printf("\n%d OF 4 TESTS PASSED.\n\n", passed - failed);
  else
    printf("\n%d OF 4 TESTS FAILED.\n\n", failed);
  return 0;
}