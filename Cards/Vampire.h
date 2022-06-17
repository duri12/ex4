//
// Created by eyal on 09/06/2022.
//

#ifndef EX4_VAMPIRE_H
#define EX4_VAMPIRE_H

#include "Card.h"

class Vampire:public Card{
private:
    static const int force  = 10;
    static const int coins  = 2;
    static const int damage  = 10;
    //friend std::ostream& operator<<(std::ostream&,const Vampire&);

public:
    void print(std::ostream& ) const override;
    Vampire();
    void applyEncounter(Player& player) const override;
    Vampire(const Vampire&) = default;
    Vampire& operator=(const Vampire& other) = default;
    ~Vampire() override = default;
};
#endif //EX4_VAMPIRE_H
