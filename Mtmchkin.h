#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <queue>
#include <stack>
#include "Players/Player.h"
#include "Cards/Card.h"

class Mtmchkin{
    private:
    std::queue<std::unique_ptr<Player>> players;
    std::queue<std::unique_ptr<Card>> deck;
    std::queue<std::unique_ptr<Player>> winners;
    std::stack<std::unique_ptr<Player>> losers;
    int m_rounds;
public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string fileName); // Harel
    
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
