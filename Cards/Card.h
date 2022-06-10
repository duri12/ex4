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

public:
    virtual void applyEncounter(Player& player) const =0;
    Card(const Card&) = default;
    virtual ~Card() = default;
    Card& operator=(const Card& other) = default;

private:
    std::string m_name;
};


#endif //EX2_Card_H
