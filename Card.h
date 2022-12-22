//
// Created by Matthew Tapia on 10/29/22.
//

#ifndef POKER_ANALYSIS_CARD_H
#define POKER_ANALYSIS_CARD_H

#include <iostream>
#include "SuitEnum.h"
#include "RankEnum.h"

class Card {
public:
    Card();
    Card(SuitEnum suitEnum, RankEnum rank);

    std::string getSuit() const;
    std::string getRank() const;
    SuitEnum getSuitEnum() const;
    RankEnum getRankEnum() const;
    int getRankValue() const;

    void setSuit(SuitEnum suit);
    void setRank(RankEnum rank);

    friend std::ostream& operator<<(std::ostream& os, const Card& card);
    friend bool operator <(const Card& lhs, const Card& rhs);
private:
    SuitEnum suit;
    RankEnum rank;
};


#endif //POKER_ANALYSIS_CARD_H
