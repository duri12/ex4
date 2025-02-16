#include "Pitfall.h"


Pitfall::Pitfall():Card("Pitfall"){}


void Pitfall::applyEncounter(Player &player) const
{
    try
    {
        Rogue& checker = dynamic_cast<Rogue&>(player);
        printPitfallMessage(true);
        checker.doNothing(); // to avoid the not used error
    }
    catch(std::bad_cast& e)
    {
        player.damage(damage);
        printPitfallMessage(false);
    }
}