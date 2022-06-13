#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const std::string fileName){
    std::string input;
    int line = 1 ;
    char inputBuffer[1024];
    std::ifstream file(fileName.c_str());
    if (file) {
        while(file.getline(inputBuffer,sizeof(inputBuffer))) {
            input = inputBuffer;
            this->m_deck.push(createCard(input , line));
            line++;
        }
    }
    else
    {
        throw(DeckFileNotFound());
    }
    this->m_rounds =0 ;

}


int Mtmchkin::getNumberOfRounds() const {
    return this->m_rounds;
}

std::unique_ptr<Card> Mtmchkin::createCard(const std::string &type, int line) {
    if(type == "Barfight")
    {
        return std::unique_ptr<Card>(new Barfight());
    }
    else if (type == "Dragon")
    {
        return std::unique_ptr<Card>(new Dragon());
    }
    else if (type == "Fairy")
    {
        return std::unique_ptr<Card>(new Fairy());
    }
    else if (type == "Goblin")
    {
        return std::unique_ptr<Card>(new Goblin());
    }
    else if (type == "Merchant")
    {
        return std::unique_ptr<Card>(new Merchant());
    }
    else if (type == "Pitfall")
    {
        return std::unique_ptr<Card>(new Pitfall());
    }
    else if (type == "Treasure")
    {
        return std::unique_ptr<Card>(new Treasure());
    }
    else if (type == "Vampire")
    {
        return std::unique_ptr<Card>(new Vampire());
    }
    throw(DeckFileFormatError(line));
}

bool Mtmchkin::isGameOver() const {
    for(int i = 0; i < this->m_leaderBoard.size(); ++i) {
        if(this->m_leaderBoard[i]->getLevel() != 10 && this->m_leaderBoard[i]->getHP() != 0){
            return false;
        }
    }
    return true;
}

void Mtmchkin::initializeLeaderboard() {
    printStartGameMessage();
    printEnterTeamSizeMessage();
    std::string tempInput;
    int size;
    do{
        try{
            std::getline(std::cin, tempInput,'\n');
            size =std::stoi(tempInput);
        }
        catch(std::exception e){
            printInvalidTeamSize();
            continue;
        }
        if(size < 2 || size >6){
            printInvalidTeamSize();
        }
    }while(size < 2 || size >6);
    this->m_start =  size; 
    this->m_end = 0; 
    printInsertPlayerMessage();
    for (int i = 0; i < size; ++i)
    {
        std::getline(std::cin, tempInput,' ');
        for (int j = 0; j < sizeof(tempInput); ++j)
        {
            if(!std::isalpha(tempInput[j])){
                printInvalidName();

            }
        }
    }
    

}
