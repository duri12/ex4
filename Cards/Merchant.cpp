#include "Merchant.h"

Merchant::Merchant():Card("Merchant"){}

void Merchant::applyEncounter(Player &player) const
{
    printMerchantInitialMessageForInteractiveEncounter(std::cout
                                                       ,player.getName(),player.getCoins());
    std::string tempInput = "";
    int input=0;
    do{
        try{
            std::getline(std::cin, tempInput,'\n');
            input =std::stoi(tempInput);
        }
        catch(std::exception e){
            printInvalidInput();
        }
    }
    while (input != healthPotion && input != forceBoost && input != leave);
    if (input == forceBoost) {
        if (player.pay(10)) {
            player.buff(1);
            printMerchantSummary(std::cout, player.getName(), forceBoost, 10);
        } else {
            printMerchantInsufficientCoins(std::cout);
        }
    } else if (input == healthPotion) {
        if (player.pay(5)) {
            player.heal(1);
            printMerchantSummary(std::cout, player.getName(), healthPotion, 5);
        } else {
            printMerchantInsufficientCoins(std::cout);
        }
    }
    else if (input == leave)
    {
        printMerchantSummary(std::cout , player.getName(),leave,leave);
    }

}