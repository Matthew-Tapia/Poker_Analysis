//
// Created by Matthew Tapia on 10/29/22.
//

#include "Card.h"

Card::Card() : Card(HEARTS, ACE){

}

Card::Card(SuitEnum suitEnum, RankEnum rank) : suit(suitEnum), rank(rank){

}

std::string Card::getSuit() const{
    switch (suit) {
        case CLUBS:
            return "Clubs";
        case DIAMONDS:
            return "Diamonds";
        case HEARTS:
            return "Hearts";
        case SPADES:
            return "Spades";
        default:
            return std::string();
    }
}

std::string Card::getRank() const{
    switch(rank){
        case ACE:
            return "Ace";
        case JACK:
            return "Jack";
        case QUEEN:
            return "Queen";
        case KING:
            return "King";
        default:
            return std::to_string(rank + 1);
    }
}

SuitEnum Card::getSuitEnum() const {
    return suit;
}

RankEnum Card::getRankEnum() const {
    return rank;
}


void Card::setSuit(SuitEnum suit) {
    this -> suit = suit;
}

void Card::setRank(RankEnum rank) {
    this -> rank = rank;
}

std::ostream& operator<<(std::ostream& os, const Card &card) {
    return os << card.getRank() << " of " << card.getSuit();
}

bool operator<(const Card &lhs, const Card &rhs) {
    return lhs.rank < rhs.rank;
}

int Card::getRankValue() const {
    return rank;
}

