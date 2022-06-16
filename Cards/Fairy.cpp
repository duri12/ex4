#include "Fairy.h"


Fairy::Fairy():Card("Fairy"){}


void Fairy::applyEncounter(Player &player) const
{
    try
    {
        Wizard& checker = dynamic_cast<Wizard&>(player);
        player.heal(heal);
        printFairyMessage(true);
        checker.doNothing(); // to avoid the not used error
    }
    catch(std::bad_cast& e)
    {
        printFairyMessage(false);
    }
}