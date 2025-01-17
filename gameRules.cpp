#include "include/gameRules.h"
using namespace std;

int pool_pot = 0;
int repetitonCardValue(const string card[])
{
    int value[NUM_CARDS];
    int repValue;
    for (int i = 0; i < NUM_CARDS; i++)
    {
        value[i] = charToInt(card[i]);
    }
    sort(value, value + NUM_CARDS);
    for (int i = 0; i < NUM_CARDS - 1; i++)
    {
        for (int j = (i + 1); j < NUM_CARDS; j++)
        {
            if (value[i] == value[j])
            {
                repValue = value[i];
            }
        }
    }
    return repValue;
}
void allCards(const string hand[], const string board[], string all[])
{
    int k = 0;
    for (int i = 0; i < 2; i++)
    {
        all[k++] = hand[i];
    }

    for (int j = 0; j < 5; j++)
    {
        all[k++] = board[j];
    }
}

int hand_score(string &highestRank, string all[])
{

    int score = 0;

    if (royalFlush(all))
    {
        highestRank = "Royal Flush";
        score = 200;
    }
    else if (straightFlush(all))
    {
        score = 180 + repetitonCardValue(all);
        highestRank = "Straight Flush";
        
    }

    else if (flush(all))
    {
        highestRank = "Flush";
        score = 160 + charToInt(high_card(all));
    }
    else if (straight(all))
    {
        highestRank = "Straight";
        score = 140 + charToInt(all[4]);
    }
    else if (fourkind(all))
    {

        score = 120 + repetitonCardValue(all);
        highestRank = "Four of the kind";
      
    }
    else if (fullhouse(all))
    {
        score = 100 + repetitonCardValue(all);
        highestRank = "Full House";
      
    }

    else if (threekind(all))
    {
        score = 80 + repetitonCardValue(all);
        highestRank = "Three of the kind";
        
    }
    else if (two_pair(all))
    {
        score = 60 + repetitonCardValue(all);
        highestRank = "Two pair";
        
    }
    else if (a_pair(all))
    {
        highestRank = "Pair";
        score = 40 + repetitonCardValue(all);
    }
    else
    {
        highestRank = "High card";
        score = charToInt(high_card(all));
    }
    return score;
}

void check_winner(vector<player> &players, string board[])
{
    // all active player show hands
    cout << "Community Cards: " << board[0] << " " << board[1] << " " << board[2] << " " << board[3] << " " << board[4] << endl;
    for (int i = 0; i < players.size(); i++)
    {
        if (players[i].folded)
            continue;
        cout << players[i].name << "'s hand: " << players[i].hand[0] << " " << players[i].hand[1] << endl;
    }
    int winner = -1;
    int highest_score = 0;
    int playerNO = players.size();
    for (int i = 0; i < playerNO; i++)
    {
        if (players[i].folded)
        {
            continue;
        }
        string all[7];
        allCards(players[i].hand, board, all);
        int score = hand_score(players[i].highestRank, all);
        if (score > highest_score)
        {
            highest_score = score;
            winner = i;
        }
    }
    for (int i = 0; i < players.size(); i++)
    {
        if (players[i].folded)
            continue;
        cout << players[i].name << "'s hand: " << players[i].hand[0] << " " << players[i].hand[1] << " -> " << players[i].highestRank << endl;
    }
    players[winner].pot += pool_pot;

    if (winner != -1)
    {
        cout << "The winner is " << players[winner].name << " with a pot of " << players[winner].pot << endl;
    }
    else
    {
        cout << "No winner could be determined." << endl;
    }
}