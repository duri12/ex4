#include "Card.h"

Card::Card(const std::string &name) {
    this->m_name = name;
}

std::string Card::getName(){
    return this->m_name;
}
std::ostream &operator<<(std::ostream &os, const Card & p1) {
    p1.print(os);
    return os;
}

void Card::print(std::ostream &os ) const {
    printCardDetails(os,this->m_name);
    printEndOfCardDetails(os);
}

bool Card::applyEncounterGang(Player &player, bool isDefeated) {
    return false;
}
