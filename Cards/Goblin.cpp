#include "Goblin.h"

Goblin::Goblin():Card("Goblin"){}


void Goblin::applyEncounter(Player &player) const
{
    if (player.getAttackStrength() >= force)
    {
        printWinBattle(player.getName(),this->m_name);
        player.levelUp();
        player.addCoins(coins);
    }
    else
    {
        printLossBattle(player.getName(),this->m_name);
        player.damage(damage);
    }
}

std::ostream &operator<<(std::ostream & os, const Goblin & p1 ) {
    printMonsterDetails(os,p1.force ,p1.damage ,p1.coins );
    printEndOfCardDetails(os);
    return os;
}
