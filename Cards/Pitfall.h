#ifndef EX4_PITFALL_H
#define EX4_PITFALL_H

#include "Card.h"
#include "../Players/Rogue.h"

class Pitfall:public Card{
private:
    static const int damage  = 10;
public:
    Pitfall();
    void applyEncounter(Player& player) const override;
    Pitfall(const Pitfall&) = default;
    Pitfall& operator=(const Pitfall& other) = default;
    ~Pitfall() override = default;
};
#endif //EX4_PITFALL_H
