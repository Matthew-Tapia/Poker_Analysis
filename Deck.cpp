//
// Created by Matthew Tapia on 10/29/22.
//

#include "Deck.h"

Deck::Deck() : cardIndex(0){
    init();
}

Card Deck::dealCard() {
    return deck[cardIndex++];
}

Card Deck::getCardAt(int index) const{
    return deck[index];
}

bool Deck::empty() {
    return cardIndex == 52;
}

void Deck::shuffle() {

    for(int i = DECK_SIZE - 1; i > 0; i--){
        int j = rand() % (i + 1);

        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void Deck::init() {
    int counter = 0;

    for(SuitEnum i = SuitEnum(0); i != END_SUIT; i = (SuitEnum)(i+1)){
        for(RankEnum j = RankEnum(0); j != END_RANK; j = (RankEnum)(j+1)){
            deck[counter] = Card(i, j);
            counter ++;
        }
    }

    shuffle();
}

std::ostream& operator<<(std::ostream &os, const Deck &deck) {
    for(int i = 0; i < deck.DECK_SIZE; i++){
        os << (i+1) << ": " << deck.getCardAt(i) << std::endl;
    }

    return os;
}
