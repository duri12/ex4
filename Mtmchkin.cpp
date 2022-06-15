#include "Mtmchkin.h"
#include <exception>

Mtmchkin::Mtmchkin(const std::string fileName){
    this->m_start =  0 ;
    this->m_end = 0 ;
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
        this->m_rounds =0 ;
        initializeLeaderboard();
    }
    else
    {
        throw(DeckFileNotFound());
    }

}


int Mtmchkin::getNumberOfRounds() const {
    return this->m_rounds;
}
std::unique_ptr<Player> Mtmchkin::createPlayer(const std::string &type, const std::string &name) {
    if(type == "Rogue") {
        return std::move(std::unique_ptr<Player>(new Rogue(name)));
    }
    if(type == "Fighter") {
        return std::move(std::unique_ptr<Player>(new Fighter(name)));
    }
    if(type == "Wizard") {
        return std::move(std::unique_ptr<Player>(new Wizard(name)));
    }
    printInvalidClass();
    return {nullptr};
}

std::unique_ptr<Card> Mtmchkin::createCard(const std::string &type, int line) {
    if(type == "Barfight")
    {
        return std::move(std::unique_ptr<Card>(new Barfight()));
    }
    else if (type == "Dragon")
    {
        return std::move(std::unique_ptr<Card>(new Dragon()));
    }
    else if (type == "Fairy")
    {
        return std::move(std::unique_ptr<Card>(new Fairy()));
    }
    else if (type == "Goblin")
    {
        return std::move(std::unique_ptr<Card>(new Goblin()));
    }
    else if (type == "Merchant")
    {
        return std::move(std::unique_ptr<Card>(new Merchant()));
    }
    else if (type == "Pitfall")
    {
        return std::move(std::unique_ptr<Card>(new Pitfall()));
    }
    else if (type == "Treasure")
    {
        return std::move(std::unique_ptr<Card>(new Treasure()));
    }
    else if (type == "Vampire")
    {
        return std::move(std::unique_ptr<Card>(new Vampire()));
    }
    throw(DeckFileFormatError(line));
}

bool Mtmchkin::isGameOver() const {
    for(int i = 0; i < this->m_leaderBoard.size() && !this->m_leaderBoard.empty();i++) {
        if(!this->m_leaderBoard[i]->wonGame()&& !this->m_leaderBoard[i]->isKnockedOut()){
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
        if(tempInputName.size()>15) {
            invalidName = true;
            printInvalidName();
        }
        if(!invalidName) {
            for (int j = 0; j < tempInputName.size(); ++j)
            {
                if(!invalidName &&!std::isalpha(tempInputName[j])){
                    printInvalidName();
                    invalidName = true;
                }
            }
        }
        if(!invalidName) {
            std::getline(std::cin, tempInputType);
            try {
                std::unique_ptr<Player> player1 = createPlayer(tempInputType, tempInputName);
                if (player1== nullptr) {
                    invalidClass = true;
                    printInvalidClass();
                } else {
                    this->m_leaderBoard.push_back(std::move(player1));
                    numOfPlayer++;
                }
            }
            catch(std::exception &e){
                printInvalidClass();
            }
        }
    }
}



void Mtmchkin::playRound() {
    this->m_rounds++;
    printRoundStartMessage(this->m_rounds);
    for(int i = this->m_start; i<=this->m_end; i++) {
        if(isGameOver())
        {
            printGameEndMessage();
            return;
        }
        printTurnStartMessage(m_leaderBoard[m_start].get()->getName());
        m_deck.front()->applyEncounter(*m_leaderBoard[m_start]);

        if(m_leaderBoard[m_start]->wonGame()) {
            m_start++;
        }
        else{
            for(int k=m_start; k<m_end; k++) {
                m_leaderBoard[k].swap( m_leaderBoard[k+1]);
            }
            if(m_leaderBoard[m_end]->isKnockedOut()) {
                m_end--;
            }
        }

        std::unique_ptr<Card> tempCard = std::move(m_deck.front());
        m_deck.pop();
        m_deck.push(std::move(tempCard));
    }
}

void Mtmchkin::printLeaderBoard() const {
    printLeaderBoardStartMessage();
    for (int i = 0; i < this->m_leaderBoard.size(); i++){
        printPlayerLeaderBoard(i,*m_leaderBoard[i]);
    }
}
