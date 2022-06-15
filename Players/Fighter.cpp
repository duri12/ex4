#include "Fighter.h"

Fighter::Fighter(const std::string &name, int maxHP, int force ):Player(name,maxHP,force) {}

int Fighter::getAttackStrength() const {
    return Player::getAttackStrength()*2 - Player::getLevel();
}


std::ostream & Fighter::printInfo(std::ostream& os) const {
    this->printBase("Fighter" ,os);
    return os;
}

