/******************************************************************
*  Name: John Carrabino
*  Class: CS362
*  Assignment:  4 (Adventurer Random Test File)
******************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>



int main() {
    srand(time(NULL));
	struct gameState game;
    int count = 1;
    int numTests = rand() % 80 + 21;
	int seed = rand() % 80 + 21;
	int passed = 0, failed = 0, pass = 0, beforeHand = 0, afterHand = 0;
	int draw = 0, discard = 0;
	int player = 0, randDeck, randHand, randCard, randKCard;
	int icopper, isilver, igold;
	int beforeCoins = 0, afterCoins = 0;
	int i, j, n;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,
              remodel, tribute, smithy, council_room };
	for (i = 0; i < numTests; i++) {
		initializeGame(2, k, seed, &game);
		beforeCoins = 0, afterCoins = 0;
		randDeck = rand() % (500 + 1);
		randHand = rand() % (randDeck + 1);
		game.deckCount[0] = randDeck - randHand;
		game.handCount[0] = randHand;
        
		for (j = 0; j < 2; j++) {
			for (n = 0; n < game.deckCount[j]; n++) {
				randCard = rand() % 5 + 1;
				if (randCard == 1)
					game.deck[j][n] = copper;
				else if (randCard == 2)
					game.deck[j][n] = silver;
				else if (randCard == 3)
					game.deck[j][n] = gold;
				else {
					randKCard = rand() % 10;
					game.deck[j][n] = k[randKCard];
				}
			}
		}
        player = game.whoseTurn;
		for (j = 0; j < game.handCount[player]; j++) {
			if (game.hand[player][j] == copper || game.hand[player][j] == silver || game.hand[player][j] == gold)
				beforeCoins += 1;
		}
    
        printf("|==================================================|\n");
        printf("|                 Random Test #%-3d                 |\n", count);
        printf("|--------------------------------------------------|\n");
        printf("| Initial Coins: %-4d                              |\n", beforeCoins);
        beforeHand = game.handCount[player];
        printf("| Initial Hand: %-4d                               |\n", beforeHand);
		cardEffect(adventurer, 0, 0, 0, &game, 0, 0);
		for (j = 0; j < game.handCount[player]; j++) {
			if (game.hand[player][j] == copper || game.hand[player][j] == silver || game.hand[player][j] == gold)
				afterCoins += 1;
		}
        printf("|                                                  |\n");
        printf("| Result Coins: %-4d                               |\n", afterCoins);
        afterHand = game.handCount[player];
        printf("| Result Hand: %-4d                                |\n", afterHand);
		icopper = 0, isilver = 0, igold = 0;
		for (j = 0; j < game.discardCount[player]; j++) {
			if (game.discard[player][j] == copper)
				icopper += 1;
			else if (game.discard[player][j] == silver)
				isilver += 1;
			else if (game.discard[player][j] == gold)
				igold += 1;
		}
		pass = 1;
		if (afterCoins < beforeCoins || afterCoins != beforeCoins + 1) {
			pass = 0;
		}
		if (afterHand <= beforeHand) {
			pass = 0;
		}
		if (pass == 1){
            passed++;
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
    
    failed = (count-1) - passed;
	printf("|==================================================|\n");
    printf("|         Random Test Results: ADVENTURER          |\n");
    printf("|--------------------------------------------------|\n");
	printf("| PASSED: %-4d of %4d                             |\n", passed, count-1);
	printf("| FAILED: %-4d of %4d                             |\n", failed, count-1);
    printf("|==================================================|\n\n");
	return 0;
}
