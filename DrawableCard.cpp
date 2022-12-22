//
// Created by Matthew Tapia on 11/3/22.
//

#include "DrawableCard.h"

DrawableCard::DrawableCard() : DrawableCard(HEARTS, ACE) {

}

DrawableCard::DrawableCard(SuitEnum suit, RankEnum rank) : baseCard(Card(suit, rank)){
    init();
}

void DrawableCard::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform = getTransform();
    target.draw(background, states);
    target.draw(suitSprite, states);
    target.draw(rankText, states);
    target.draw(secondRankText, states);
}

void DrawableCard::setFillColor(const sf::Color &color) {
    background.setFillColor(color);
}

void DrawableCard::setSize(const sf::Vector2f &size) {
    background.setSize(size);
    fixSuitScale();
    fixRankScale();
}

void DrawableCard::setSize(float x, float y) {
    setSize({x, y});
}

void DrawableCard::setPosition(const sf::Vector2f &position) {
    sf::Transformable::setPosition(position);
}

void DrawableCard::setPosition(float x, float y) {
    setPosition({x, y});
}

void DrawableCard::init() {
    setupBackground();
    setupSuit();
    setupRank();
}

void DrawableCard::setupSuit() {
    if(!texture.loadFromFile(suitToFileName()))
        exit(21);
    suitSprite.setTexture(texture);
    fixSuitScale();
}

void DrawableCard::setupRank() {
    if(!font.loadFromFile("Fonts/OpenSans-Bold.ttf"))
        exit(20);
    rankText.setFont(font);
    rankText.setString(rankToCharacter());

    secondRankText.setFont(font);
    secondRankText.setString(rankToCharacter());
    secondRankText.rotate(180);

    fixRankScale();

    if(baseCard.getSuitEnum() == HEARTS || baseCard.getSuitEnum() == DIAMONDS){
        rankText.setFillColor(sf::Color(178, 0, 9));
        secondRankText.setFillColor(sf::Color(178, 0, 9));
    } else {
        rankText.setFillColor(sf::Color::Black);
        secondRankText.setFillColor(sf::Color::Black);
    }
}

void DrawableCard::setupBackground() {
    background.setSize({250,350});
    background.setPosition(0, 0);
}

void DrawableCard::fixSuitScale() {
    suitSprite.setScale({background.getSize().x/1250, background.getSize().y/1750});
    float spriteWidth = suitSprite.getTexture()->getSize().x * suitSprite.getScale().x;
    float spriteHeight = suitSprite.getTexture()->getSize().y * suitSprite.getScale().y;

    suitSprite.setPosition({(background.getSize().x/2) - (spriteWidth/2), (background.getSize().y/2) - (spriteHeight/2)});
}

void DrawableCard::fixRankScale() {
    rankText.setCharacterSize(background.getSize().x/5);
    rankText.setPosition({background.getSize().x/25, background.getSize().y/35});

    secondRankText.setCharacterSize(background.getSize().x/5);
    secondRankText.setPosition({background.getSize().x - background.getSize().x/15 , background.getSize().y - background.getSize().y/35});
}

std::string DrawableCard::suitToFileName() {
    switch (baseCard.getSuitEnum()) {
        case CLUBS:
            return "Images/Club.png";
        case DIAMONDS:
            return "Images/Diamond.png";
        case HEARTS:
            return "Images/Heart.png";
        case SPADES:
            return "Images/Spade.png";
        default:
            return std::string();
    }
}

std::string DrawableCard::rankToCharacter() {
    switch(baseCard.getRankEnum()){
        case ACE:
            return "A";
        case JACK:
            return "J";
        case QUEEN:
            return "Q";
        case KING:
            return "K";
        default:
            return std::to_string(baseCard.getRankEnum() + 1);
    }
}
