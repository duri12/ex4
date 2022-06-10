#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H

#include "Card.h"
#include "../Players/Fighter.h"

class Barfight:public Card{
private:
    static const int damage  = 10;
public:
    Barfight();
    void applyEncounter(Player& player) const override;
    Barfight(const Barfight&) = default;
    Barfight& operator=(const Barfight& other) = default;
    ~Barfight() override = default;
};
#endif //EX4_BARFIGHT_H
