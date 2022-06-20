#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include "Card.h"

class Dragon:public Card{
private:
    static const int force  = 25;
    static const int coins  = 1000;
    static const int damage  = 1000;

public:
    void print(std::ostream& ) const override;
    bool applyEncounterGang(Player &player, bool isDefeated) override;
    Dragon();
    void applyEncounter(Player& player) const override;
    Dragon(const Dragon&) = default;
    Dragon& operator=(const Dragon& other) = default;
    ~Dragon() override = default;
};
#endif //EX4_DRAGON_H
