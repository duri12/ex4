#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include "utilities.h"
#include <cstring>
#include <iostream>


class Player {
    char * m_name;
    int m_level; //the level of the player
    int m_force; // the force of the player
    int m_maxHP;//max HP of the player
    int m_HP; // the current HP of the player
    int m_coins;//the current coins of the player


public:
    explicit Player(const char *name, int maxHP =100, int force =5);
    Player(const Player& );
    Player & operator=(const Player& p2 );
    ~Player();
    void printInfo() const;
    void levelUp();
    int getLevel() const;
    void buff(int amount);
    void heal(int health);
    void damage(int damage);
    bool isKnockedOut() const;
    void addCoins(int amount);
    bool pay(int amount);
    int getAttackStrength() const;

};


#endif //EX2_PLAYER_H
