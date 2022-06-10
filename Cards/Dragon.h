#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include "Card.h"

class Dragon:public Card{
private:
    static const int force  = 25;
    static const int coins  = 10000;
    static const int damage  = 100;
public:
    Dragon();
    void applyEncounter(Player& player) const override;
    Dragon(const Dragon&) = default;
    Dragon& operator=(const Dragon& other) = default;
    ~Dragon() override = default;
};
#endif //EX4_DRAGON_H
