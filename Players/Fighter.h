//
// Created by eyal on 09/06/2022.
//

#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H

#include "Player.h"

class Fighter:public Player{
    public:
    Fighter(const std::string &name, int maxHP =100, int force =5);
    Fighter & operator=(const Fighter& p2 ) = default;
    ~Fighter() override = default;
    int getAttackStrength() const override;
    std::ostream& printInfo(std::ostream&) const override;

};
#endif //EX4_FIGHTER_H
