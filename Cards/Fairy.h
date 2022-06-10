#ifndef EX4_FAIRY_H
#define EX4_FAIRY_H

#include "Card.h"
#include "../Players/Wizard.h"

class Fairy:public Card{
private:
    static const int heal  = 10;
public:
    Fairy();
    void applyEncounter(Player& player) const override;
    Fairy(const Fairy&) = default;
    Fairy& operator=(const Fairy& other) = default;
    ~Fairy() override = default;
};
#endif //EX4_BARFIGHT_H



