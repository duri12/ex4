#ifndef EX4_GOBLIN_H
#define EX4_GOBLIN_H

#include "Card.h"

class Goblin:public Card{
    private:
    static const int force  = 6;
    static const int coins  = 2;
    static const int damage  = 10;
    //friend std::ostream& operator<<(std::ostream&,const Goblin&);

public:
    void print(std::ostream& ) const override;
    Goblin();
    void applyEncounter(Player& player) const override;
    Goblin(const Goblin&) = default;
    Goblin& operator=(const Goblin& other) = default;
    ~Goblin() override = default;
};
#endif //EX4_GOBLIN_H
