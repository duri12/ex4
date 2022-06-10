#include "Dragon.h"

Dragon::Dragon():Card("Dragon"){}

void Dragon::applyEncounter(Player &player) const
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
