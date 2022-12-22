//
// Created by Matthew Tapia on 10/29/22.
//

#ifndef POKER_ANALYSIS_CARDHANDSCORER_H
#define POKER_ANALYSIS_CARDHANDSCORER_H

#include "PokerScore.h"
#include "CardHand.h"

class CardHandScorer {
public:
    static PokerScore scoreHandPoker(const CardHand& cardHand);

private:
    static bool hasHighCard(const CardHand &cardHand);
    static bool hasPair(const CardHand &cardHand);
    static bool hasTwoPairs(const CardHand &cardHand);
    static bool hasThreeOfAKind(const CardHand &cardHand);
    static bool hasStraight(const CardHand &cardHand);
    static bool hasFlush(const CardHand &cardHand);
    static bool hasFullHouse(const CardHand &cardHand);
    static bool hasFourOfAKind(const CardHand &cardHand);
    static bool hasStraightFlush(const CardHand &cardHand);
    static bool hasRoyalFlush(const CardHand &cardHand);
};


#endif //POKER_ANALYSIS_CARDHANDSCORER_H
