#include "Vampire.h"

Vampire::Vampire():Card("Vampire"){}

void Vampire::applyEncounter(Player &player) const
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
        player.weaker(1);
    }
}

void Vampire::print(std::ostream & os) const {
    printCardDetails(os,"Vampire");
    printMonsterDetails(os,Vampire::force ,Vampire::damage ,Vampire::coins );
    printEndOfCardDetails(os);
}
