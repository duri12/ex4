//
// Created by eyal on 09/06/2022.
//

#ifndef EX4_WIZARD_H
#define EX4_WIZARD_H
#include "Player.h"

class Wizard:public Player{
public:
    Wizard(const std::string &name, int maxHP =100, int force =5);
    Wizard & operator=(const Wizard& p2 ) = default;
    ~Wizard() override = default;
    void heal(int health) override;
    void printInfo() const override;
};
#endif //EX4_WIZARD_H
