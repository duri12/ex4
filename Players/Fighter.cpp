#include "Fighter.h"

Fighter::Fighter(const std::string &name, int maxHP, int force ):Player(name,"Fighter",maxHP,force) {}

int Fighter::getAttackStrength() const {
    return Player::getAttackStrength()*2 - Player::getLevel();
}

