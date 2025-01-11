#include "poker_hand.h"
#include "player.h"
using namespace std;

int pool_pot = 0;


void allCards(string [], string [], string[]);//combine hand card and community card
int hand_score(const string []);
void check_winner(vector<player>&,string[]);