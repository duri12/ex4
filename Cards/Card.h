//
// Created by Daniel_Meents on 07/04/2022.
//
#ifndef EX2_Card_H
#define EX2_Card_H

#include "../Players/Player.h"
#include "../utilities.h"

class Card {
protected:
    Card(const std::string& name);
    friend std::ostream& operator<<(std::ostream&,const Card&);
    std::string m_name;

public:
    std::string getName();
    virtual void print(std::ostream&) const;
    virtual bool applyEncounterGang(Player& player , bool isDefeated);
    virtual void applyEncounter(Player& player) const =0;
    Card(const Card&) = default;
    virtual ~Card() = default;
    Card& operator=(const Card& other) = default;

};


#endif //EX2_Card_H
