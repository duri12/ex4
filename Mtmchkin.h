#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <queue>
#include <vector>
#include <string>
#include "ctype.h"
#include <fstream>
#include <iostream>
#include <memory>
#include "Players/Player.h"
#include "Cards/Card.h"
#include "Exception.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Fairy.h"
#include "Cards/Goblin.h"
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Cards/Vampire.h"

class Mtmchkin{
    private:
    std::queue<std::unique_ptr<Card>> m_deck;
    std::vector<std::unique_ptr<Player>> m_leaderBoard;
    int m_rounds;
    int m_start;
    int m_end;

    void initializeLeaderboard();
    static std::unique_ptr<Card> createCard(const std::string &type , int line );
public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string fileName); // Harel
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound(); // harel
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const; // eyal
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const; // harel
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const; //eyal
};



#endif /* MTMCHKIN_H_ */
