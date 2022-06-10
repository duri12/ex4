#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H

#include "Card.h"

class Merchant:public Card{
private:
    static const int healthPotion = 1;
    static const int forceBoost  = 2;
    static const int leave  = 0;
public:
    Merchant();
    void applyEncounter(Player& player) const override;
    Merchant(const Merchant&) = default;
    Merchant& operator=(const Merchant& other) = default;
    ~Merchant() override = default;
};
#endif //EX4_MERCHANT_H
