//
// Created by Matthew Tapia on 10/29/22.
//

#ifndef POKER_ANALYSIS_POKERSCORE_H
#define POKER_ANALYSIS_POKERSCORE_H

#include <vector>
#include <iostream>

class PokerScore {
public:
    enum ScoresEnum{

        ROYAL_FLUSH, //A, K, Q, J, 10, all the same suit.

        STRAIGHT_FLUSH, //five cards of the same suit and consecutive ranking

        FOUR_OF_A_KIND, //four cards of the same ranking

        FULL_HOUSE, //three cards of the same rank along with two cards of the same rank

        FLUSH, //five cards of the same suit

        STRAIGHT, //five cards in consecutive ranking

        THREE_OF_A_KIND, //three cards of the same rank

        TWO_PAIR, //two cards of the same rank along with another two cards of the same rank

        ONE_PAIR, //two cards of the same rank

        HIGH_CARD, //highest card in the player’s hand

        END_SCORE //End of score enumerator

    };

    PokerScore();

    static std::string scoreToString(PokerScore::ScoresEnum score);

    int size();

    void operator+=(const ScoresEnum& score);
    friend bool operator==(const PokerScore& p, ScoresEnum score);
    friend std::ostream& operator<<(std::ostream &os, const PokerScore& pokerScore);

private:
    std::vector<ScoresEnum> scores;


    ScoresEnum& operator[](unsigned int index);
};


#endif //POKER_ANALYSIS_POKERSCORE_H
