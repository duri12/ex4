#include "Card.h"

Card::Card(const std::string &name) {
    this->m_name = name;
}

std::ostream &operator<<(std::ostream &os, const Card & p1) {
    printCardDetails(os,p1.m_name);
    return os;
}