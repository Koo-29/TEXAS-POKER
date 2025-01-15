#include "include/bot_behavior.h"

int evaluateHand(string hand[])
{
    // Simplified evaluation (0-100)
    int handStrength = rand() % 20 + 50;

    // Example: Better hand if community cards are suited
    if (charToInt(hand[0]) == charToInt(hand[1]))
        handStrength += 10;

    if (hand[0].substr(0, 3) == hand[1].substr(0, 3))
        handStrength += 10;

    return handStrength;
}

void decideAction(player &currentPlayer, int &currentBet, string hand[], int currentPlayerIndex, vector<player> players, int &playerCount)
{
    int handStrength = evaluateHand(hand);

    // Aggression influences decision-making
    float riskFactor = handStrength / 100.0f;
    cout << riskFactor << endl;
    int actionDecision = rand() % 100;

    if (riskFactor > 0.7 && actionDecision > 30)
    {
        int raiseAmount = currentBet + (rand() % 50);
        playerCount = 0;
        raise(currentPlayer, raiseAmount, currentBet, currentPlayerIndex, players);
    }

    else
    {
        if (checkRaise)
        {
            if (riskFactor > 0.4 || actionDecision > 60)
            {
                call(currentPlayer, currentBet, currentPlayerIndex);
            }
            else
            {
                fold(currentPlayer);
            }
        }

        else
        {
            if (riskFactor > 0.4 || actionDecision > 60)
            {
                check(currentPlayer);
            }
            else
            {
                fold(currentPlayer);
            }
        }
    }
}