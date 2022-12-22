//
// Created by Matthew Tapia on 10/29/22.
//

#ifndef POKER_ANALYSIS_CARDHAND_H
#define POKER_ANALYSIS_CARDHAND_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Deck.h"

class CardHand {
public:
    CardHand();

    void addCard(const Card& c);
    void sortByRank();

    int size() const;
    Card cardAt(int index) const;

    friend std::ostream& operator<<(std::ostream& os, const CardHand& cardHand);

private:
    std::vector<Card> hand;
};


#endif //POKER_ANALYSIS_CARDHAND_H
