#ifndef PLAYER_ACTION_H
#define PLAYER_ACTION_H

#include "gameRules.h"
#include "player.h"
#include <iostream>
using namespace std;

bool err = false;
bool checkRaise = false;

void fold(player &);
void check(player &);
void raise(player &, int, int &, int &, vector<player>);

#endif