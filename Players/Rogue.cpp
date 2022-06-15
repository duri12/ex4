#include "Rogue.h"

Rogue::Rogue(const std::string &name, int maxHP, int force) : Player(name,"Rogue", maxHP, force) {}

void Rogue::addCoins(int amount) {
    Player::addCoins(amount*2);
}

