
#include "Player.h"
#include "../utilities.h"


static const int MAX_LEVEL = 10 ;
static const int DEFAULT_FORCE = 5;
static const int DEFAULT_COINS = 10;


Player::Player(const std::string &name, const std::string & job, int maxHP, int force) {
    m_name = name;
    m_HP = 0;
    m_job = job;
    m_maxHP = 0;
    m_force=DEFAULT_FORCE;
    if(maxHP>0){
        m_maxHP = maxHP;
        m_HP = maxHP;
    }
    if(force>0){
        m_force = force;
    }
    m_level = 1;
    m_coins =DEFAULT_COINS;
}

Player::Player(const Player& p1){
    m_name = p1.m_name;
    m_maxHP = p1.m_maxHP;
    m_HP = p1.m_HP;
    m_force = p1.m_force;
    m_level = p1.m_level;
    m_coins =p1.m_coins;
    m_job = p1.m_job;

}



Player& Player::operator=(const Player& p2) {

    m_name = p2.m_name;
    m_level = p2.m_level;
    m_force = p2.m_force;
    m_job = p2.m_job;
    m_maxHP = p2.m_maxHP;
    m_HP = p2.m_HP;
    m_coins = p2.m_coins;
    return *this;                              
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

void Player::weaker(int num){
    if(this->m_force -num >= 0){
        this->m_force-=num;
    }
}

void Player::addCoins(int amount) {
    if(amount >0){
        this->m_coins += amount;
    }
}
bool Player::wonGame() const {
    return (m_level==10);
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

std::ostream &Player::printBase(std::ostream& os) const {
    printPlayerDetails(os,m_name,
                       m_job,m_level,m_force,m_HP,m_coins);
    return os;
}

std::ostream &operator<<(std::ostream &os, const Player & p1) {
    return p1.printBase(os);
}

int Player::getCoins() const {
    return this->m_coins;
}

std::string Player::getName() const {
    return this->m_name;
}

int Player::getHP() const {
    return this->m_HP;
}
