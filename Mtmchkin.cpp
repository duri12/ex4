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
std::unique_ptr<Player> Mtmchkin::createPlayer(const std::string &type, const std::string &name) {
    if(type == "Rogue") {
        return std::unique_ptr<Player>(new Rogue(name));
    }
    if(type == "Fighter") {
        return std::unique_ptr<Player>(new Fighter(name));
    }
    if(type == "Wizard") {
        return std::unique_ptr<Player>(new Wizard(name));
    }
    printInvalidClass();
    return std::unique_ptr<Player>(nullptr);
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
    std::string tempInputName;
    std::string tempInputType;

    int size;
    do{
        try{
            std::getline(std::cin, tempInputName,'\n');
            size =std::stoi(tempInputName);
        }
        catch(std::exception e){
            printInvalidTeamSize();
            continue;
        }
        if(size < 2 || size >6){
            printInvalidTeamSize();
        }
    }while(size < 2 || size >6);
    this->m_start =  0;
    this->m_end = size-1;
    printInsertPlayerMessage();
    int numOfPlayer = 0;
    while(numOfPlayer<size)
    {
        bool invalidName = false;
        bool invalidClass = false;
        std::getline(std::cin, tempInputName,' ');
        if(sizeof(tempInputName)>15) {
            invalidName = true;
            printInvalidName();
        }
        if(invalidName == false) {
            for (int j = 0; j < sizeof(tempInputName); ++j)
            {
                if(!std::isalpha(tempInputName[j])){
                    printInvalidName();
                    invalidName = true;

                }
            }
        }
        if(invalidName == false) {
            std::getline(std::cin, tempInputType,' ');
            std::unique_ptr<Player> player1 = createPlayer(tempInputType, tempInputName);
            if(player1) {
                invalidClass = true;

            } else {
                m_leaderBoard.push_back(player1);
                numOfPlayer++;

            }
        }
    }
    

}
void Mtmchkin::playRound() {
    m_rounds++;
    bool knockedOut = false;
    printRoundStartMessage(m_rounds);
    for(int i = m_start; i<=m_end; i++) {
        if(isGameOver()) {
            printGameEndMessage();
            return;
        }
      //  while(m_leaderBoard[m_start]->isKnockedOut()) {
          //  m_start++;
       // }
        m_deck.front()->applyEncounter(*m_leaderBoard[i]);
        if(m_leaderBoard[i]->wonGame()) {
            for(int k=i; k>m_start; k--) {
                swap(m_leaderBoard[k], m_leaderBoard[k-1]);
            }
            m_start++;
        }
        if(m_leaderBoard[i]->isKnockedOut()) {
            knockedOut = true;
        }
            for(int k=i; k<m_end; k++) {
                swap(m_leaderBoard[k], m_leaderBoard[k+1]);
            }
            if(knockedOut) {
                m_end--;

            }

       // std::unique_ptr<Player> tempPlayerFront = std::move(m_leaderBoard[m_start]);
       // m_leaderBoard[m_end] = std::move(tempPlayerFront);
        std::unique_ptr<Card> tempCard = std::move(m_deck.front());
        m_deck.pop();
        m_deck.push(tempCard);
    }
}
