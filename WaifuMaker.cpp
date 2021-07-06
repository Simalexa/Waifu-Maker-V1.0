// WaifuMaker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Waifu.h"

int main()
{
    MW M;
    struct Waifu *W;
    W = NULL;
    int b = -1;
    std::cout << "0 : Exit" << std::endl << "1 : Show standart Waifu" << std::endl << "2 : Choose Waifu" << std::endl << "3 : Create new Waifu" << std::endl << "4 : Edit Waifu"<<std::endl;
    while (b != 0)
    {
        std::cout << "Print comand: ";
        std::cin >> b;
        if(b == 1)
            M.ListOfWaifu();
        if(b == 2)
            M.SelectWaifu(W);
        if (b == 3)
            M.CreateWaifu(W);
        if (b == 4)
            M.ChangeWaifu(W);
    }
}