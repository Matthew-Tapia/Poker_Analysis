//
// Created by Matthew Tapia on 10/29/22.
//

#include "CardHandScorer.h"

PokerScore CardHandScorer::scoreHandPoker(const CardHand &cardHand) {
    PokerScore pokerScore;

    if(hasRoyalFlush(cardHand)){
        pokerScore += PokerScore::ScoresEnum::ROYAL_FLUSH;
        pokerScore += PokerScore::ScoresEnum::STRAIGHT_FLUSH;
        pokerScore += PokerScore::ScoresEnum::FLUSH;
        pokerScore += PokerScore::ScoresEnum::HIGH_CARD;
        return pokerScore;
    }

    if(hasStraightFlush(cardHand)){
        pokerScore += PokerScore::ScoresEnum::STRAIGHT_FLUSH;
        pokerScore += PokerScore::ScoresEnum::FLUSH;
        pokerScore  += PokerScore::ScoresEnum::STRAIGHT;
        pokerScore += PokerScore::ScoresEnum::HIGH_CARD;
        return pokerScore;
    }

    if(hasFourOfAKind(cardHand)){
        pokerScore += PokerScore::ScoresEnum::FOUR_OF_A_KIND;
        pokerScore += PokerScore::ScoresEnum::THREE_OF_A_KIND;
        pokerScore += PokerScore::ScoresEnum::TWO_PAIR;
        pokerScore += PokerScore::ScoresEnum::ONE_PAIR;
        pokerScore += PokerScore::ScoresEnum::HIGH_CARD;
        return pokerScore;
    }

    if(hasFullHouse(cardHand)){
        pokerScore += PokerScore::ScoresEnum::FULL_HOUSE;
        pokerScore += PokerScore::ScoresEnum::THREE_OF_A_KIND;
        pokerScore += PokerScore::ScoresEnum::ONE_PAIR;
        pokerScore += PokerScore::ScoresEnum::HIGH_CARD;
        return pokerScore;
    }

    if(hasFlush(cardHand)){
        pokerScore += PokerScore::ScoresEnum::FLUSH;
        pokerScore += PokerScore::ScoresEnum::HIGH_CARD;
        return pokerScore;
    }

    if(hasStraight(cardHand)){
        pokerScore  += PokerScore::ScoresEnum::STRAIGHT;
        pokerScore += PokerScore::ScoresEnum::HIGH_CARD;
        return pokerScore;
    }

    if(hasThreeOfAKind(cardHand)){
        pokerScore += PokerScore::ScoresEnum::THREE_OF_A_KIND;
        pokerScore += PokerScore::ScoresEnum::ONE_PAIR;
        pokerScore += PokerScore::ScoresEnum::HIGH_CARD;
        return pokerScore;
    }

    if(hasTwoPairs(cardHand)){
        pokerScore += PokerScore::ScoresEnum::TWO_PAIR;
        pokerScore += PokerScore::ScoresEnum::ONE_PAIR;
        pokerScore += PokerScore::ScoresEnum::HIGH_CARD;
        return pokerScore;
    }

    if(hasPair(cardHand)){
        pokerScore += PokerScore::ScoresEnum::ONE_PAIR;
        pokerScore += PokerScore::ScoresEnum::HIGH_CARD;
        return pokerScore;
    }

    if(hasHighCard(cardHand)){
        pokerScore += PokerScore::ScoresEnum::HIGH_CARD;
        return pokerScore;
    }

}

bool CardHandScorer::hasHighCard(const CardHand &cardHand) {
    return cardHand.size() > 0;
}

bool CardHandScorer::hasPair(const CardHand &cardHand) {
    if(cardHand.size() < 2){
        return false;
    }

    for(int i = 0; i < cardHand.size() - 1; i++){
        if(cardHand.cardAt(i).getRankValue() == cardHand.cardAt(i+1).getRankValue()){
            return true;
        }
    }

    return false;
}

bool CardHandScorer::hasTwoPairs(const CardHand &cardHand) {
    if(cardHand.size() < 4){
        return false;
    }

    int counter = 0;

    for(int i = 0; i < cardHand.size() - 1; i++){
        if(cardHand.cardAt(i).getRankValue() == cardHand.cardAt(i+1).getRankValue()){
            counter++;
            i++;
        }
    }

    return counter == 2;
}

bool CardHandScorer::hasThreeOfAKind(const CardHand &cardHand) {
    if(cardHand.size() < 3){
        return false;
    }

    for(int i = 0; i < cardHand.size() - 2; i++){
        if(cardHand.cardAt(i).getRankValue() == cardHand.cardAt(i+1).getRankValue() && cardHand.cardAt(i+1).getRankValue() == cardHand.cardAt(i+2).getRankValue()){
            return true;
        }
    }

    return false;
}

bool CardHandScorer::hasStraight(const CardHand &cardHand) {
    if(cardHand.size() == 0){
        return false;
    }

    for(int i = 0; i < cardHand.size() - 1; i++){
        if(cardHand.cardAt(i+1).getRankValue() != cardHand.cardAt(i).getRankValue() + 1){
            return false;
        }
    }

    return true;
}

bool CardHandScorer::hasFlush(const CardHand &cardHand) {
    if(cardHand.size() == 0){
        return false;
    }

    std::string startingSuit = cardHand.cardAt(0).getSuit();

    for(int i = 0; i < cardHand.size(); i++){
        if(cardHand.cardAt(i).getSuit() != startingSuit){
            return false;
        }
    }

    return true;
}

bool CardHandScorer::hasFullHouse(const CardHand &cardHand) {
    if(cardHand.size() < 5){
        return false;
    }

    bool firstTwoMatch = cardHand.cardAt(0).getRankValue() == cardHand.cardAt(1).getRankValue();
    bool lastThreeMatch = cardHand.cardAt(2).getRankValue() == cardHand.cardAt(3).getRankValue() && cardHand.cardAt(3).getRankValue() == cardHand.cardAt(4).getRankValue();

    bool lastTwoMatch = cardHand.cardAt(3).getRank() == cardHand.cardAt(4).getRank();
    bool firstThreeMatch = cardHand.cardAt(0).getRankValue() == cardHand.cardAt(1).getRankValue() && cardHand.cardAt(1).getRankValue() == cardHand.cardAt(2).getRankValue();

    return (firstTwoMatch && lastThreeMatch)||(firstThreeMatch && lastTwoMatch);
}

bool CardHandScorer::hasFourOfAKind(const CardHand &cardHand) {
    if(cardHand.size() < 4){
        return false;
    }

    for(int i = 0; i < cardHand.size() - 3; i++){
        bool fourMatch = cardHand.cardAt(i).getRankValue() == cardHand.cardAt(i+1).getRankValue() &&
                cardHand.cardAt(i+1).getRankValue() == cardHand.cardAt(i+2).getRankValue() &&
                cardHand.cardAt(i+2).getRankValue() == cardHand.cardAt(i+3).getRankValue();

        if(fourMatch){
            return true;
        }
    }

    return false;
}

bool CardHandScorer::hasStraightFlush(const CardHand &cardHand) {
    return hasStraight(cardHand) && hasFlush(cardHand);
}

bool CardHandScorer::hasRoyalFlush(const CardHand &cardHand) {
    bool isRoyal = cardHand.cardAt(0).getRankValue() == ACE && cardHand.cardAt(1).getRankValue() == TEN;
    return isRoyal && hasFlush(cardHand);
}



