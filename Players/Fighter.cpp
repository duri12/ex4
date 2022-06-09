#include "Fighter.h"

Fighter::Fighter(const std::string &name, int maxHP, int force ):Player(name,maxHP,force) {}

int Fighter::getAttackStrength() const {
    return this->m_force+Player::getAttackStrength();
}


void Fighter::printInfo() const {
    Player::printInfo("Fighter");
}
