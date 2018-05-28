/******************************************************************
*  Name: John Carrabino
*  Class: CS362
*  Function Tested: updateCoins()
******************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "rngs.h"

int main () {
    int i;
    struct gameState game;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
    int failed = 0;
    int hand1[5] = {smithy, minion, smithy, tribute, mine};
    int hand2[5] = {copper, copper, copper, copper, copper};
    int hand3[5] = {smithy, gold, gold, gold, copper};
    int hand4[5] = {gold, minion, embargo, village, silver};
    int hand5[5] = {silver, copper, copper, village, embargo};
    initializeGame(2, k, 100, &game);
    game.handCount[0] = 5;
    printf("\nUNIT TEST 4: updateCoins()\n");

    // Testing no coins
    for(i = 0; i < 5; i++)
      game.hand[0][i] = hand1[i];
    updateCoins(0, &game, 0);
    printf("\nupdateCoins() TEST 1: Hand with no coins\n");
    if (game.coins != 0){
      printf("TEST 1 FAILED\n");
      failed++;
    } else
      printf("TEST 1 PASSED: Hand has no coins\n");

    // All copper
    for(i = 0; i < 5; i++)
      game.hand[0][i] = hand2[i];
    updateCoins(0, &game, 0);
    printf("\nupdateCoins() TEST 2: Hand with 5 coins\n");
    if (game.coins != 5){
      printf("TEST 2 FAILED\n");
      failed++;
    } else
      printf("TEST 2 PASSED: Hand has 5 coins\n");

    // 3 Gold & 1 Copper
    for(i = 0; i < 5; i++)
      game.hand[0][i] = hand3[i];
    updateCoins(0, &game, 0);
    printf("\nupdateCoins() TEST 3: Hand with 10 coins\n");
    if (game.coins != 10){
      printf("TEST 3 FAILED\n");
      failed++;
    } else
      printf("TEST 3 PASSED: Hand has 10 coins\n");

    // 1 Gold & 1 Silver
    for(i = 0; i < 5; i++)
      game.hand[0][i] = hand4[i];
    updateCoins(0, &game, 0);
    printf("\nupdateCoins() TEST 4: Hand with 5 coins\n");
    if (game.coins != 5){
      printf("TEST 4 FAILED\n");
      failed++;
    } else
      printf("TEST 4 PASSED: Hand has 5 coins\n");

    // 1 Gold & 2 Copper
    for(i = 0; i < 5; i++)
      game.hand[0][i] = hand5[i];
    updateCoins(0, &game, 0);
    printf("\nupdateCoins() TEST 5: Hand with 4 coins\n");
    if (game.coins != 4){
      printf("TEST 5 FAILED\n");
      failed++;
    } else
      printf("TEST 5 PASSED: Hand has 4 coins\n");


    printf("\n%d OF 5 TESTS PASSED\n\n", 5-failed);
    return 0;
}