#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <queue>
#include <vector>
#include <string>
#include "ctype.h"
#include <fstream>
#include <iostream>
#include <memory>
#include "utilities.h"
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
#include "Cards/Gang.h"

class Mtmchkin{
    private:
    std::queue<std::unique_ptr<Card>> m_deck;
    std::vector<std::unique_ptr<Player>> m_leaderBoard;
    int m_rounds;
    int m_start;
    int m_end;
    void initializeLeaderboard();
    static std::unique_ptr<Card> createCard(const std::string &type , int line );
    static std::unique_ptr<Player> createPlayer(const std::string &type, const std::string &name);
public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

    std::unique_ptr<Player> createPlayer2();

    bool checkAlpta(std::string name);
};



#endif /* MTMCHKIN_H_ */
