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

void Goblin::print(std::ostream & os) const {
    printCardDetails(os,"Goblin");
    printMonsterDetails(os,Goblin::force ,Goblin::damage ,Goblin::coins );
    printEndOfCardDetails(os);
}
