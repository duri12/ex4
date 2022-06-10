#include "Fairy.h"


Fairy::Fairy():Card("Fairy"){}


void Fairy::applyEncounter(Player &player) const
{
    try
    {
        Fairy& checker = dynamic_cast<Fairy&>(player);
        player.heal(heal);
        printFairyMessage(true);
    }
    catch(std::bad_cast& e)
    {
        printFairyMessage(false);
    }
}