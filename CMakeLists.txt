cmake_minimum_required(VERSION 3.14)
project(Poker_Analysis)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Deck.cpp Deck.h Card.cpp Card.h SuitEnum.h RankEnum.h CardHand.cpp CardHand.h CardHandScorer.cpp CardHandScorer.h PokerScore.cpp PokerScore.h DrawableCard.cpp DrawableCard.h)
add_executable(Poker_Analysis ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Poker_Analysis sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
