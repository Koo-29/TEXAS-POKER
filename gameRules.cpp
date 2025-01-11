#include "include/gameRules.h"
using namespace std;


void allCards(const string hand[],const string board[],string all[]){
    int i = 0;
    for (int i = 0; i < 2; i++ ){
        all[i++] = hand[i];
    }

    for (int j = 0 ; j < 5; j++){
        all[i++] = board[j];
    }
}

int hand_score(string all[]){
    ;
    int score = 0;

    if (royalFlush(all)){
        score = 200;
    }
    else if (straightFlush(all)){
        score = 180 + charToInt(all[4]);
    }
   
    else if (flush(all)){

         score = 160 + charToInt(high_card(all));
    }
    else if (straight(all)){
         score = 140 + charToInt(all[4]);
    }
    else if (fourkind(all)){

         score = 120 + charToInt(high_card(all)) ;
    }
    else if (fullhouse(all)){
         score = 100 + charToInt(high_card(all)) ;
    }
   
    else if (threekind(all)){
         score = 80 + charToInt(high_card(all));
    }
    else if(two_pair(all)){
         score = 60 + charToInt(high_card(all));
    }
    else if(a_pair(all)){
         score = 40 + charToInt(high_card(all));

    }
    else{
        score =  charToInt(high_card(all));
        
    }
    return score;
}

void check_winner(vector<player> players, string board[]){
    int winner = -1;
    int highest_score = 0;
    int playerNO = players.size();
    for (int i = 0; i< playerNO ;i++){
        if (players[i].folded){
            continue;
        }
        string all[7];
        allCards(players[i].hand, board, all);
        int score = hand_score(all);
        if (score > highest_score){
            highest_score = score;
            winner = i;
            players[i].pot += pool_pot;

        }
    }

    if (winner != -1) {
        cout << "The winner is player " << winner << " with a pot of " << players[winner].pot << endl;
    } else {
        cout << "No winner could be determined." << endl;
    }
}