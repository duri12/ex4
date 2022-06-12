#include "Dragon.h"

Dragon::Dragon():Card("Dragon"){}

void Dragon::applyEncounter(Player &player) const
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

std::ostream &operator<<(std::ostream & os, const Dragon & p1) {
    printMonsterDetails(os,p1.force ,p1.damage ,p1.coins , true );
    printEndOfCardDetails(os);
    return os;
}
