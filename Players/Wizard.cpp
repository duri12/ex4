//
// Created by eyal on 09/06/2022.
//

#include "Wizard.h"

Wizard::Wizard(const std::string &name, int maxHP, int force) : Player(name, maxHP, force) {}

void Wizard::heal(int health) {
    Player::heal(health*2);
}

void Wizard::printInfo(std::ostream& os) const {
    Player::printInfo("Wizard" , os);
}
