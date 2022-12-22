//
// Created by Matthew Tapia on 10/29/22.
//

#ifndef POKER_ANALYSIS_DECK_H
#define POKER_ANALYSIS_DECK_H

#include <iostream>
#include "Card.h"
#include "RankEnum.h"
#include "SuitEnum.h"
#include <stdlib.h>
#include <time.h>

class Deck {
public:
    const int DECK_SIZE = 52;

    Deck();

    bool empty();
    Card dealCard();
    Card getCardAt(int index) const;
    void shuffle();

    friend std::ostream& operator<<(std::ostream& os, const Deck& deck);

private:
    int cardIndex;
    Card deck[52];

    void init();
};


#endif //POKER_ANALYSIS_DECK_H
