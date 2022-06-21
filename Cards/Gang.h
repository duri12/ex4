#ifndef EX4_GANG_H
#define EX4_GANG_H

#include "Card.h"
#include <vector>
#include <memory>
#include <fstream>
#include "../Mtmchkin.h"
#include <memory>
#include "Dragon.h"
#include "Vampire.h"
#include "Goblin.h"
#include "../Exception.h"


class Gang:public Card{
private:
    std::vector<std::unique_ptr<Card>> m_Cards;
    static bool isMonster(Card& c);

public:
    void print(std::ostream& ) const override;
    void pushMonster(std::unique_ptr<Card>);
    Gang();
    void applyEncounter(Player& player) const override;
    Gang(const Gang&) = default;
    Gang& operator=(const Gang& other) = default;
    ~Gang() override = default;
};

#endif //EX4_GANG_H
