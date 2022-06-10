#include "Vampire.h"

Vampire::Vampire():Card("Vampire"){}

void Vampire::applyEncounter(Player &player) const
{
    if (player.getAttackStrength() >= force)
    {
        player.levelUp();
        player.addCoins(coins);
    }
    else
    {
        player.damage(damage);
    }
}

