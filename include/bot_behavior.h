#ifndef bot_behavior_H
#define bot_behavior_H

#include "player.h"
#include "player_action.h"
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

int evaluateHand(string hand[]);
void decideAction(player &currentPlayer, int &currentBet, string hand[], int currentPlayerIndex, vector<player> players, int &);

#endif