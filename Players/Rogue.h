
#ifndef EX4_ROGUE_H
#define EX4_ROGUE_H
#include "Player.h"

class Rogue:public Player{
public:
    Rogue(const std::string &name, int maxHP =100, int force =5);
    Rogue & operator=(const Rogue& p2 ) = default;
    ~Rogue() override = default;
    void addCoins(int amount) override;
};


#endif //EX4_ROGUE_H
