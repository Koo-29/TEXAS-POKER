#include "include/deck.h"

void initDeck()
{
    deck = {
        u8"\u2666A",
        u8"\u26660",
        u8"\u26662",
        u8"\u26663",
        u8"\u26664",
        u8"\u26665",
        u8"\u26666",
        u8"\u26667",
        u8"\u26668",
        u8"\u26669",
        u8"\u2666J",
        u8"\u2666Q",
        u8"\u2666K",
        u8"\u2663A",
        u8"\u26630",
        u8"\u26632",
        u8"\u26633",
        u8"\u26634",
        u8"\u26635",
        u8"\u26636",
        u8"\u26637",
        u8"\u26638",
        u8"\u26639",
        u8"\u2663J",
        u8"\u2663Q",
        u8"\u2663K",
        u8"\u2665A",
        u8"\u26650",
        u8"\u26652",
        u8"\u26653",
        u8"\u26654",
        u8"\u26655",
        u8"\u26656",
        u8"\u26657",
        u8"\u26658",
        u8"\u26659",
        u8"\u2665J",
        u8"\u2665Q",
        u8"\u2665K",
        u8"\u2660A",
        u8"\u26600",
        u8"\u26602",
        u8"\u26603",
        u8"\u26604",
        u8"\u26605",
        u8"\u26606",
        u8"\u26607",
        u8"\u26608",
        u8"\u26609",
        u8"\u2660J",
        u8"\u2660Q",
        u8"\u2660K",
        u8"\u2666A",
        u8"\u26660",
        u8"\u26662",
        u8"\u26663",
        u8"\u26664",
        u8"\u26665",
        u8"\u26666",
        u8"\u26667",
        u8"\u26668",
        u8"\u26669",
        u8"\u2666J",
        u8"\u2666Q",
        u8"\u2666K",
        u8"\u2663A",
        u8"\u26630",
        u8"\u26632",
        u8"\u26633",
        u8"\u26634",
        u8"\u26635",
        u8"\u26636",
        u8"\u26637",
        u8"\u26638",
        u8"\u26639",
        u8"\u2663J",
        u8"\u2663Q",
        u8"\u2663K",
        u8"\u2665A",
        u8"\u26650",
        u8"\u26652",
        u8"\u26653",
        u8"\u26654",
        u8"\u26655",
        u8"\u26656",
        u8"\u26657",
        u8"\u26658",
        u8"\u26659",
        u8"\u2665J",
        u8"\u2665Q",
        u8"\u2665K",
        u8"\u2660A",
        u8"\u26600",
        u8"\u26602",
        u8"\u26603",
        u8"\u26604",
        u8"\u26605",
        u8"\u26606",
        u8"\u26607",
        u8"\u26608",
        u8"\u26609",
        u8"\u2660J",
        u8"\u2660Q",
        u8"\u2660K",
    };
}

void shuffler()
{
    srand((unsigned)time(0));
    for (int i = 0; i < 104; i++)
        swap(deck[i], deck[rand() % 104]);
}

string getCard()
{
    string card = deck.front();
    deck.erase(deck.begin());
    return card;
}

int charToInt(string card) {
    int cardInInt;
    if (card.back() == 'J') cardInInt = 11;
    else if (card.back() == 'Q') cardInInt = 12;
    else if (card.back() == 'K') cardInInt = 13;
    else if (card.back() == 'A') cardInInt = 14;
    else if (card.back() == '0') cardInInt = 10; 
    else cardInInt = card.back() - '0'; 
    return cardInInt;
}