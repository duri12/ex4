#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H

#include "Card.h"

class Treasure:public Card{
private:
    static const int coins  = 10;
public:
    Treasure();
    void applyEncounter(Player& player) const override;
    Treasure(const Treasure&) = default;
    Treasure& operator=(const Treasure& other) = default;
    ~Treasure() override = default;
};

#endif //EX4_TREASURE_H
