#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H


#include <iostream>


class Player {
    std::string m_name;
    int m_level; //the level of the player
    int m_maxHP;//max HP of the player
    int m_HP; // the current HP of the player
    int m_coins;//the current coins of the player
    int m_force; // the force of the player
    std::string m_job;

protected:
    std::ostream& printBase(std::ostream&) const;
    Player(const std::string &name , const std::string &, int maxHP =100, int force =5);
    friend std::ostream& operator<<(std::ostream&,const Player&);


public:
    Player(const Player& );
    Player & operator=(const Player& p2 );
    virtual ~Player() = default;
    void levelUp();
    int getLevel() const;
    void weaker(int num);
    void buff(int amount);
    virtual void heal(int health);
    void damage(int damage);
    bool isKnockedOut() const;
    virtual void addCoins(int amount);
    bool pay(int amount);
    virtual int getAttackStrength() const;
    bool wonGame() const;
    int getCoins() const ;
    int getHP() const ;
    std::string getName() const;
};



#endif //EX2_PLAYER_H
