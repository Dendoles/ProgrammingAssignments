// T_ClassesHandsOn.cpp

#include <iostream>
#include "Player.h"

int main()
{
    Player* pPlayer{nullptr};
    pPlayer = new Player("Boomer", 69);
    pPlayer->PrintInfo();
    pPlayer->AddPoints(1);
    pPlayer->PrintInfo();


    delete pPlayer;
    pPlayer = nullptr;

    std::cout << std::to_string(int(pPlayer)) << std::endl;

}