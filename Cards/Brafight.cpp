#include "Barfight.h"


Barfight::Barfight():Card("Barfight"){}


void Barfight::applyEncounter(Player &player) const
{
    try
    {
        Fighter& checker = dynamic_cast<Fighter&>(player);
        printBarfightMessage(true);
    }
    catch(std::bad_cast& e)
    {
        player.damage(damage);
        printBarfightMessage(false);
    }
}