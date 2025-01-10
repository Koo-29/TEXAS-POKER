#include "include/gameRules.h"

void allCards(const string handcard[],const string poolCard[],string all[]){
    int i = 0;
    for (int i = 0; i < 2; i++ ){
        all[i++] = handcard[i];
    }

    for (int j = 0 ; j < 5; j++){
        all[i++] = poolCard[j];
    }
}

int hand_score(string all[]){

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

