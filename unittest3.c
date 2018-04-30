/******************************************************************
*  Name: John Carrabino
*  Class: CS362
*  Function Tested: buyCard()
******************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <assert.h>

int main() {
  int PASS = 0;
  int test1 = 0;
  int playerOne = 1;
  
  // Give player enough money to buy silver
  int treasure = 6;
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, great_hall};
  struct gameState game;
  
  initializeGame(2, k, 100, &game);

  //Start test
  printf("\nUNIT TEST 3: buyCard()\n");
  game.whoseTurn = playerOne;
  game.coins = treasure;
  test1 = buyCard(silver, &game);
  printf("buyCard() TEST 1: Buy 1 silver\n");
  if (test1 == 0){
    printf("buyCard() Returned 0, Player 1 successfully bought silver.\n");
    printf("buyCard() TEST 1 PASSED\n");
  } else {
    PASS = 1;
    printf("TEST 1 FAILED\n");
  }
  
  if (PASS == 0)
    printf("buyCard() UNIT TEST SUCCESSFULLY COMPLETED\n\n");
  else 
    printf("buyCard() UNIT TEST FAILED\n\n");
  return 0;
}