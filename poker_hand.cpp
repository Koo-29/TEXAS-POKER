#include "include/poker_hand.h"

int const NUM_CARDS = 7;

string high_card(const string card[])
{
    // change the type of card array to integer for comparision
    int value[NUM_CARDS];
    for (int i = 0; i < NUM_CARDS; i++)
    {
        value[i] = charToInt(card[i]);
    }
    int highest = 0;
    for (int i = 0; i < NUM_CARDS; i++)
    {
        if (value[i] > value[highest])
        {
            highest = i;
        }
    }
    return card[highest];
}

bool a_pair(const string card[])
{
    // change the type of card array to integer for comparision
    int value[NUM_CARDS];
    for (int i = 0; i < NUM_CARDS; i++)
    {
        value[i] = charToInt(card[i]);
    }
    for (int i = 0; i < NUM_CARDS - 1; i++)
    {
        for (int j = (i + 1); j < NUM_CARDS; j++)
        {
            if (value[i] == value[j])
            {
                return true;
            }
        }
    }
    return false;
}

bool two_pair(const string card[])
{
    // change the type of card array to integer for comparision
    int value[NUM_CARDS];

    for (int i = 0; i < NUM_CARDS; i++)
    {
        value[i] = charToInt(card[i]);
    }
    int matching_card = 0;
    for (int i = 0; i < NUM_CARDS; i++)
    {

        for (int j = i + 1; j < NUM_CARDS; j++)
        {
            if (value[i] == value[j])
            {
                matching_card += 1;
            }
        }
        if (matching_card == 2)
        {
            return true;
        }
    }
    return false;
}

bool threekind(const string card[])
{
    // change the type of card array to integer for comparision
    int value[NUM_CARDS];

    for (int i = 0; i < NUM_CARDS; i++)
    {
        value[i] = charToInt(card[i]);
    }
    for (int i = 0; i < NUM_CARDS; i++)
    {
        int matching_card = 0;
        for (int j = i + 1; j < NUM_CARDS; j++)
            if (value[i] == value[j])
            {
                matching_card += 1;
            }

        if (matching_card == 2)
        {
            return true;
        }
    }
    return false;
}

bool fourkind(const string card[])
{
    // change the type of card array to integer for comparision
    int value[NUM_CARDS];

    for (int i = 0; i < NUM_CARDS; i++)
    {
        value[i] = charToInt(card[i]);
    }

    for (int i = 0; i < NUM_CARDS; i++)
    {
        int matching_card = 0;
        for (int j = i + 1; j < NUM_CARDS; j++)
            if (value[i] == value[j])
            {
                matching_card += 1;
            }

        if (matching_card == 3)
        {
            return true;
        }
    }
    return false;
}

bool fullhouse(const string card[])
{
    // change the type of card array to integer for comparision
    int value[NUM_CARDS];
    for (int i = 0; i < NUM_CARDS; i++)
    {
        value[i] = charToInt(card[i]);
    }
    // check three of kind
    int threekind = 0;
    for (int i = 0; i < NUM_CARDS; i++)
    {
        int matching = 0;
        for (int j = (i + 1); j < NUM_CARDS; j++)
        {
            if (value[i] == value[j])
            {
                matching += 1;
            }
            if (matching == 2)
            {
                threekind = value[i];
                break;
            }
        }
    }
    if (threekind == 0)
    {
        return false;
    }
    // check pair

    for (int i = 0; i < NUM_CARDS; i++)
    {
        for (int j = (i + 1); j < NUM_CARDS; j++)
        {
            if (value[j] == value[i] && value[j] != threekind)
            {
                return true;
            }
        }
    }
    return false;
}
bool straight(const string card[])
{
    int value[NUM_CARDS];
    for (int i = 0; i < NUM_CARDS; i++)
    {
        value[i] = charToInt(card[i]);
    }
    sort(value, value + NUM_CARDS);
    // Handle the special case for A-2-3-4-5
    if (value[0] == 2 && value[1] == 3 && value[2] == 4 && value[3] == 5 && value[4] == 14)
        return true;
    int consequtive = 0;
    for (int i = 1; i < NUM_CARDS; i++)
    {
        if (value[i] == value[i - 1] + 1)
            consequtive += 1;
    }
    if (consequtive >= 5)
    {
        return true;
    }
    return false;
}

bool flush(const string card[])
{
    string suit = card[0].substr(0, 3);
    for (int i = 1; i < NUM_CARDS; i++)
    {
        if (card[i].substr(0, 3) != suit)
            return false;
    }
    return true;
}

bool straightFlush(const string card[])
{
    return straight(card) && flush(card);
}

bool royalFlush(const string card[])
{
    map<string, vector<int>> suits;

    for (int i = 0; i < NUM_CARDS; i++)
    {
        string suit = card[i].substr(0, 3);
        suits[suit].push_back(charToInt(card[i]));
    }

    for (const auto &group : suits)
    {
        auto rank = group.second;
        if (rank.size() >= 5)
        {
            sort(rank.begin(), rank.end());
            if (rank[2] == 10 && rank[3] == 11 && rank[4] == 12 && rank[5] == 13 && rank[6] == 14)
                return true;
        }
    }
    return false;
}