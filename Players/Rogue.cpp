#include "Rogue.h"

Rogue::Rogue(const std::string &name, int maxHP, int force) : Player(name, maxHP, force) {}

void Rogue::addCoins(int amount) {
    Player::addCoins(amount*2);
}

void Rogue::printInfo(std::ostream& os) const {
    Player::printInfo("Rogue" , os);
}
