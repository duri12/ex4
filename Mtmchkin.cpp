#include "Mtmchkin.h"
#include <exception>


Mtmchkin::Mtmchkin(const std::string fileName)
{
    printStartGameMessage();
    this->m_start =  0 ;
    this->m_end = 0 ;
    std::string input;
    int line = 1 ;
    char inputBuffer[2048];
    std::ifstream file(fileName.c_str());
    if (file)
    {
        while(file.getline(inputBuffer,sizeof(inputBuffer)))
        {
            input = inputBuffer;
            if(input == "Gang"){
                std::unique_ptr<Gang> myGang = std::unique_ptr<Gang>(new Gang);
                bool isGang = true;
                line++;
                while(isGang){
                    file.getline(inputBuffer,sizeof(inputBuffer));
                    input = inputBuffer;
                    if(input == "EndGang"){
                        isGang = false;
                    }
                    else {
                        myGang->pushMonster(createCard(input ,line));
                    }
                    line++;
                }
                this->m_deck.push(std::move(myGang));
            }
            else{
                this->m_deck.push(createCard(input , line));
                line++;
            }
        }
        this->m_rounds =0 ;

        if(this->m_deck.size() < 5)
        {
            throw(DeckFileInvalidSize());
        }
        initializeLeaderboard();
    }
    else
    {
        throw(DeckFileNotFound());
    }

}


int Mtmchkin::getNumberOfRounds() const
{
    return this->m_rounds;
}
std::unique_ptr<Player> Mtmchkin::createPlayer(const std::string &type, const std::string &name)
{
    if(type == "Rogue")
    {
        return std::move(std::unique_ptr<Player>(new Rogue(name)));
    }
    if(type == "Fighter")
    {
        return std::move(std::unique_ptr<Player>(new Fighter(name)));
    }
    if(type == "Wizard")
    {
        return std::move(std::unique_ptr<Player>(new Wizard(name)));
    }
    return std::unique_ptr<Player>{};
}

std::unique_ptr<Card> Mtmchkin::createCard(const std::string &type, int line)
{
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

bool Mtmchkin::isGameOver() const
{
    for(unsigned int i = 0; i < this->m_leaderBoard.size() && !this->m_leaderBoard.empty();i++)
    {
        if(!this->m_leaderBoard[i]->wonGame()&& !this->m_leaderBoard[i]->isKnockedOut())
        {
            return false;
        }
    }
    return true;
}

bool Mtmchkin::checkAlpta(std::string name)
{
    for(unsigned int i = 0; i <name.length();i++){
        if(!std::isalpha(name[i])){
            return false;
        }
    }
    return true;
}
std::unique_ptr<Player> Mtmchkin::createPlayer2(){
    std::string name;
    std::string job;
    bool isName = false;

    while(!isName){
        std::cin >> name;
        std::cin >> job;
        std::cin.ignore();

        if(name.length() >15){
            printInvalidName();
            continue;
        }
        isName = checkAlpta(name);
        if(!isName){
            printInvalidName();
            continue;
        }
        if(job == "Rogue" || job =="Wizard" || job == "Fighter"){
            return std::move(createPlayer(job , name));
        }
        else{
            printInvalidClass();
            isName = false;
            continue;
        }
    }
    return std::unique_ptr<Player>();
}
void Mtmchkin::initializeLeaderboard()
{

    std::string tempInputName;
    std::string tempInputType;

    int size = 1;
    do
    {
        printEnterTeamSizeMessage();
        try
        {
            std::getline(std::cin, tempInputName,'\n');
            size =std::stoi(tempInputName);
        }
        catch(std::exception &e)
        {
            printInvalidTeamSize();
            continue;
        }
        if(size < 2 || size >6)
        {
            printInvalidTeamSize();
        }
    }while(size < 2 || size >6);

    this->m_start =  0;
    this->m_end = size-1;
    for (int i = 0; i < size; ++i) {
        printInsertPlayerMessage();
        this->m_leaderBoard.push_back(std::move(createPlayer2()));
    }

}



void Mtmchkin::playRound() {
    this->m_rounds++;
    printRoundStartMessage(this->m_rounds);
    int end = m_end;
    for(int i = this->m_start; i<=end; i++)
    {
        if(isGameOver())
        {
            return;
        }
        printTurnStartMessage(m_leaderBoard[m_start].get()->getName());
        m_deck.front()->applyEncounter(*m_leaderBoard[m_start]);

        if(m_leaderBoard[m_start]->wonGame())
        {
            m_start++;
        }
        else
        {
            for(int k=m_start; k<m_end; k++)
            {
                m_leaderBoard[k].swap( m_leaderBoard[k+1]);
            }
            if(m_leaderBoard[m_end]->isKnockedOut())
            {
                m_end--;
            }
        }

        std::unique_ptr<Card> tempCard = std::move(m_deck.front());
        m_deck.pop();
        m_deck.push(std::move(tempCard));
    }
    if(isGameOver())
    {
        printGameEndMessage();
    }
}

void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    for (unsigned int i = 0; i < this->m_leaderBoard.size(); i++)
    {
        printPlayerLeaderBoard(i+1,*m_leaderBoard[i]);
    }
}
