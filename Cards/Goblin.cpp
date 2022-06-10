#include "Goblin.h"

Goblin::Goblin():Card("Goblin"){}


void Goblin::applyEncounter(Player &player) const
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
