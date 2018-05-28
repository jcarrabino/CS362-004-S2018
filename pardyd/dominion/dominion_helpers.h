#ifndef _DOMINION_HELPERS_H
#define _DOMINION_HELPERS_H

#include "dominion.h"

int drawCard(int player, struct gameState *state);
int updateCoins(int player, struct gameState *state, int bonus);
int discardCard(int handPos, int currentPlayer, struct gameState *state, 
		int trashFlag);
int gainCard(int supplyPos, struct gameState *state, int toFlag, int player);
int getCost(int cardNumber);
int cardEffect(int card, int choice1, int choice2, int choice3, 
	       struct gameState *state, int handPos, int *bonus);

int playMine(int *currentPlayer, struct gameState *state, int *choice1, int *choice2, int *j, int *handPos);

int playFeast(int *currentPlayer, struct gameState *state, int *temphand, int *choice1, int *x);

int playCouncilRoom(int *currentPlayer, struct gameState *state, int *handPos);

int playAventurer(int *drawntreasure, int *currentPlayer, struct gameState *state, int *temphand, int *z, int *cardDrawn);

int playSmithy(int *currentPlayer, struct gameState *state, int *handPos);

#endif
