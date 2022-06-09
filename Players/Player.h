#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include "../utilities.h"
#include <iostream>


class Player {
    std::string m_name;
    int m_level; //the level of the player
    int m_maxHP;//max HP of the player
    int m_HP; // the current HP of the player
    int m_coins;//the current coins of the player
protected:
    int m_force; // the force of the player
    void printInfo(const std::string &job) const;

public:
    Player(const std::string &name, int maxHP =100, int force =5);
    Player(const Player& );
    Player & operator=(const Player& p2 );
    virtual ~Player() = default;
    virtual void printInfo() const;
    void levelUp();
    int getLevel() const;
    void buff(int amount);
    virtual void heal(int health);
    void damage(int damage);
    bool isKnockedOut() const;
    virtual void addCoins(int amount);
    bool pay(int amount);
    virtual int getAttackStrength() const;

};


#endif //EX2_PLAYER_H
