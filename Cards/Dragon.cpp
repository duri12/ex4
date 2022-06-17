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

void Dragon::print(std::ostream & os) const {
    printCardDetails(os,"Dragon");
    printMonsterDetails(os,Dragon::force ,Dragon::damage ,Dragon::coins , true );
    printEndOfCardDetails(os);
}

