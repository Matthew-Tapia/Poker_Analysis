//
// Created by Matthew Tapia on 10/29/22.
//

#include "PokerScore.h"

PokerScore::PokerScore() {

}

void PokerScore::operator+=(const PokerScore::ScoresEnum& score) {
    scores.push_back(score);
}

bool operator==(const PokerScore &p, PokerScore::ScoresEnum score) {
    for(int i = 0; i < p.scores.size(); i++){
        if(p.scores[i] == score){
            return true;
        }
    }

    return false;
}

int PokerScore::size() {
    return scores.size();
}

PokerScore::ScoresEnum &PokerScore::operator[](unsigned int index) {
    return scores.at(index);
}

std::ostream& operator<<(std::ostream &os, const PokerScore& pokerScore) {
    for(PokerScore::ScoresEnum i = PokerScore::ScoresEnum(0); i != PokerScore::ScoresEnum::END_SCORE; i = (PokerScore::ScoresEnum)(i+1)){
        if(pokerScore == i){
            os << PokerScore::scoreToString(i) << ": 1" << std::endl;
        } else {
            os << PokerScore::scoreToString(i) << ": 0" << std::endl;
        }
    }

    return os;
}

std::string PokerScore::scoreToString(PokerScore::ScoresEnum score) {
    switch (score) {
        case ROYAL_FLUSH:
            return "ROYAL_FLUSH";
        case STRAIGHT_FLUSH:
            return "STRAIGHT_FLUSH";
        case FOUR_OF_A_KIND:
            return "FOUR_OF_A_KIND";
        case FULL_HOUSE:
            return "FULL_HOUSE";
        case FLUSH:
            return "FLUSH";
        case STRAIGHT:
            return "STRAIGHT";
        case THREE_OF_A_KIND:
            return "THREE_OF_A_KIND";
        case TWO_PAIR:
            return "TWO_PAIR";
        case ONE_PAIR:
            return "ONE_PAIR";
        case HIGH_CARD:
            return "HIGH_CARD";
        default:
            return std::string();
    }
}

