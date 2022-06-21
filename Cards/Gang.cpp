#include "Gang.h"


Gang::Gang():Card("Gang"){
    this->m_Cards = std::vector<std::unique_ptr<Card>>();
}

void Gang::pushMonster(std::unique_ptr<Card> monster){
    if(isMonster(*monster)){
        this->m_Cards.push_back(std::move(monster));
    }
    else{
        throw(DeckFileInvalidSize());
    }
}

void Gang::applyEncounter(Player &player) const
{
    bool isDefeated = false;
    for (unsigned int i = 0; i <this->m_Cards.size(); ++i) {
        isDefeated = this->m_Cards[i]->applyEncounterGang(player,isDefeated);
    }
    if (!isDefeated){
        printWinBattle(player.getName(),this->m_name);
        player.levelUp();
    }
}

bool Gang::isMonster(Card &c) {
    std::string name = c.getName();
    if (name == "Goblin" || name == "Dragon" || name == "Vampire"){
        return true;
    }
    return false;
}
void Gang::print(std::ostream & os) const {
}

