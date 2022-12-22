//
// Created by Matthew Tapia on 10/29/22.
//

#include "CardHand.h"

CardHand::CardHand() {

}

void CardHand::addCard(const Card& c) {
    hand.push_back(c);
}

int CardHand::size() const {
    return hand.size();
}

Card CardHand::cardAt(int index) const {
    return hand.at(index);
}

void CardHand::sortByRank() {
    std::sort(hand.begin(), hand.end());
}

std::ostream& operator<<(std::ostream &os, const CardHand& cardHand) {
    for(int i = 0; i < cardHand.size(); i++){
        os << (i+1) << ": " << cardHand.hand[i] << std::endl;
    }

    return os;
}
