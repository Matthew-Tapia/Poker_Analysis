#include <SFML/Graphics.hpp>
#include <string>
#include "CardHandScorer.h"
#include "DrawableCard.h"

int main(){
    srand(time(NULL));

    //GAME LOGIC
    const int NUM_OF_RUNS = 1000000;
    int scoreCounter[10] = {0, 0, 0, 0, 0, 0, 0, 0,0,0};

    for(int i = 0; i < NUM_OF_RUNS; i++){
        Deck deck;
        CardHand cardHand;

        for(int j = 0; j < 5; j++){
            cardHand.addCard(deck.dealCard());
        }

        cardHand.sortByRank();
        PokerScore currentPokerScore = CardHandScorer::scoreHandPoker(cardHand);

        for(PokerScore::ScoresEnum j = PokerScore::ScoresEnum(0); j != PokerScore::ScoresEnum::END_SCORE; j = (PokerScore::ScoresEnum)(j+1)){
            if(currentPokerScore == j){
                scoreCounter[j]++;
            }
        }
    }

    //SFML STUFF
    sf::RenderWindow window({2560, 1600 , 32},"Bhloe");
    window.setFramerateLimit(60);

    DrawableCard EXAMPLE_CARDS[10][5] = {{DrawableCard(CLUBS, ACE), DrawableCard(CLUBS, TEN), DrawableCard(CLUBS, JACK), DrawableCard(CLUBS, QUEEN), DrawableCard(CLUBS, KING) },
                                         {DrawableCard(HEARTS, THREE), DrawableCard(HEARTS, FOUR), DrawableCard(HEARTS, FIVE), DrawableCard(HEARTS, SIX), DrawableCard(HEARTS, SEVEN) },
                                         {DrawableCard(DIAMONDS, TWO), DrawableCard(HEARTS, NINE), DrawableCard(CLUBS, NINE), DrawableCard(DIAMONDS, NINE), DrawableCard(SPADES, NINE) },
                                         {DrawableCard(HEARTS, ACE), DrawableCard(DIAMONDS, ACE), DrawableCard(CLUBS, FIVE), DrawableCard(DIAMONDS, FIVE), DrawableCard(SPADES, FIVE) },
                                         {DrawableCard(DIAMONDS, THREE), DrawableCard(DIAMONDS, SEVEN), DrawableCard(DIAMONDS, TEN), DrawableCard(DIAMONDS, QUEEN), DrawableCard(DIAMONDS, KING) },
                                         {DrawableCard(HEARTS, THREE), DrawableCard(CLUBS, FOUR), DrawableCard(CLUBS, FIVE), DrawableCard(DIAMONDS, SIX), DrawableCard(SPADES, SEVEN) },
                                         {DrawableCard(DIAMONDS, THREE), DrawableCard(HEARTS, EIGHT), DrawableCard(CLUBS, EIGHT), DrawableCard(DIAMONDS, EIGHT), DrawableCard(SPADES, JACK) },
                                         {DrawableCard(DIAMONDS, ACE), DrawableCard(HEARTS, ACE), DrawableCard(CLUBS, NINE), DrawableCard(DIAMONDS, NINE), DrawableCard(SPADES, TEN) },
                                         {DrawableCard(DIAMONDS, ACE), DrawableCard(SPADES, THREE), DrawableCard(CLUBS, NINE), DrawableCard(DIAMONDS, NINE), DrawableCard(HEARTS, QUEEN) },
                                         {DrawableCard(CLUBS, FOUR), DrawableCard(CLUBS, SIX), DrawableCard(HEARTS, SEVEN), DrawableCard(DIAMONDS, JACK), DrawableCard(HEARTS, KING) }};

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            EXAMPLE_CARDS[i][j].setSize(window.getSize().x/32, window.getSize().y/12);
            EXAMPLE_CARDS[i][j].setPosition((window.getSize().x/32) + (3*window.getSize().x/64)*j, window.getSize().y/16 + (window.getSize().y/5)*i);
        }
    }

    for(int i = 5; i < 10; i++){
        for(int j = 0; j < 5; j++){
            EXAMPLE_CARDS[i][j].setSize(window.getSize().x/32, window.getSize().y/12);
            EXAMPLE_CARDS[i][j].setPosition((17*window.getSize().x/32) + (3*window.getSize().x/64)*j, window.getSize().y/16 + (window.getSize().y/5)*(i-5));
        }
    }

    sf::Text probabilities[10];
    sf::Font probabilityFont;

    if(!probabilityFont.loadFromFile("Fonts/OpenSans-Bold.ttf"))
        exit(20);

    for(int i = 0; i < 10; i++){
        int gcd = 1;

        for (int j = 1; j <= scoreCounter[i]; ++j) {
            if (NUM_OF_RUNS % j == 0 && scoreCounter[i] % j ==0) {
                gcd = j;
            }
        }

        probabilities[i].setFont(probabilityFont);
        probabilities[i].setString(std::to_string(scoreCounter[i]/gcd) + " : " + std::to_string(NUM_OF_RUNS/gcd));
        probabilities[i].setCharacterSize(window.getSize().x/45);
    }

    for(int i = 0; i < 5; i++){
        probabilities[i].setPosition(19*window.getSize().x/64, window.getSize().y/12 + (window.getSize().y/5)*i);
    }

    for(int i = 5; i < 10; i++){
        probabilities[i].setPosition(51*window.getSize().x/64, window.getSize().y/12 + (window.getSize().y/5)*(i-5));
    }

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(sf::Event::Closed == event.type)
                window.close();
        }

        window.clear(sf::Color(51, 86, 71));

        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 5; j++){
                window.draw(EXAMPLE_CARDS[i][j]);
            }
            window.draw(probabilities[i]);
        }

        window.display();
    }


    return 0;
}