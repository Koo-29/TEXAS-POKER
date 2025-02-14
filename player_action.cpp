#include "include/player_action.h"
#include "include/gameRules.h"

bool err = false;
bool checkRaise = false;

void fold(player &currentPlayer)
{
    currentPlayer.folded = true;
    err = false;
    cout << currentPlayer.name << " has folded.\n\n";
}

void check(player &currentPlayer)
{
    if (checkRaise)
    {
        cout << "You cannot check, you can only call, raise or fold.\n\n";
        err = true;
    }
    else
    {
        cout << currentPlayer.name << " has checked.\n\n";
        err = false;
    }
}

void raise(player &currentPlayer, int raiseAmount, int &currentBet, int &currentPlayerIndex, vector<player> players)
{
    int totalBet = raiseAmount + currentBet;
    int requireAmount = totalBet - currentPlayer.currentBet;
    if (currentPlayer.pot >= requireAmount)
    {
        currentPlayer.currentBet += requireAmount;
        currentPlayer.pot -= requireAmount;
        currentBet = currentPlayer.currentBet;
        pool_pot += requireAmount;
        checkRaise = true;
        err = false;

        cout << currentPlayer.name << " raised to " << currentBet << ".\n\n";
    }
    else
    {
        err = true;
        cout << currentPlayer.name << "does not have enough chips to raise.\n\n";
    }
}

void call(player &currentPlayer, int &currentBet, int &currentPlayerIndex)
{
    int requireAmount = currentBet - currentPlayer.currentBet;
    if (currentPlayer.pot >= requireAmount)
    {
        currentPlayer.currentBet += requireAmount;
        currentPlayer.pot -= requireAmount;
        pool_pot += requireAmount;
        checkRaise = true;
        err = false;

        cout << currentPlayer.name << " calls " << currentBet << ".\n\n";
    }
    else
    {
        pool_pot += currentPlayer.pot;
        currentPlayer.currentBet += currentPlayer.pot;
        currentPlayer.pot = 0;

        cout << currentPlayer.name << " goes all-in!\n\n";
    }
}