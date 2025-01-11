#include "include/player.h"

// constructor
player::player(string inputName, int inputPot)
{
    name = inputName;
    pot = inputPot;
    folded = false;
}

// setter
void player::set_hand(string getHand[])
{
    hand[0] = getHand[0];
    hand[1] = getHand[1];
}

// getter
string player::get_name()
{
    return name;
}

string player::get_hand(int card)
{
    return hand[card];
}

int player::get_pot()
{
    return pot;
}