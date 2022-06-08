
#include "Player.h"



static const int MAX_LEVEL = 10 ;
static const int DEFULT_FORCE = 5;

Player::Player(const char *name, int maxHP, int force) {
    m_name = new char[strlen(name) + 1];
    strcpy(m_name, name);
    m_HP = 0;
    m_maxHP = 0;
    m_force=DEFULT_FORCE;
    if(maxHP>0){
        m_maxHP = maxHP;
        m_HP = maxHP;
    }
    if(force>0){
        m_force = force;
    }
    m_level = 1;
    m_coins =0;
}

Player::Player(const Player& p1){
    m_name = new char[strlen(p1.m_name) + 1];
    strcpy(m_name, p1.m_name);
    m_maxHP = p1.m_maxHP;
    m_HP = p1.m_HP;
    m_force = p1.m_force;
    m_level = p1.m_level;
    m_coins =p1.m_coins;

}


Player::~Player(){
    delete[] m_name;
}


Player& Player::operator=(const Player& p2) {

    delete[] m_name;
    m_name = new char[strlen(p2.m_name) + 1];
    strcpy(m_name, p2.m_name);
    m_level = p2.m_level;
    m_force = p2.m_force;
    m_maxHP = p2.m_maxHP;
    m_HP = p2.m_HP;
    m_coins = p2.m_coins;
    return *this;                              
}


void Player::printInfo() const {
    printPlayerInfo(this->m_name,this->m_level,this->m_force , this->m_HP , this->m_coins);
}
void Player::levelUp() {
    if(this->m_level<MAX_LEVEL){
        this->m_level++;
    }
}

int Player::getLevel() const{
    return this->m_level;
}

void Player::buff(int amount) {
   
    if(amount >0){
        this->m_force+=amount;
    }
}

void Player::heal(int amount) {
    if(amount >0){
        if(amount + this->m_HP >=this->m_maxHP){
            this->m_HP = this->m_maxHP;
        }
        else{
            this->m_HP += amount;
        }
    }
}

void Player::damage(int amount) {
    if(amount >= 0){
        this->m_HP -= amount;
        if(this->m_HP <0){
            this->m_HP = 0;
        }
    }
}


void Player::addCoins(int amount) {
    if(amount >0){
        this->m_coins += amount;
    }
}

int Player::getAttackStrength() const{
    return this->m_level+this->m_force;
}

bool Player::isKnockedOut() const {
    if(this->m_HP==0) {
        return true;
    }
    return false;
}

bool Player::pay(int amount) {
    if(amount <0){
        return true;
    }
    if(this->m_coins-amount>=0) {
        this->m_coins -= amount;
        return true;
    }
    return false;
}