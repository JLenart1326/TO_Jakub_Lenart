// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "CurrencyExchangeInterface.h"

CurrencyExchangeInterface* CurrencyExchangeInterface::instance = nullptr;

int main()
{
    CurrencyExchangeInterface* mainInterface = CurrencyExchangeInterface::getInstance();
    mainInterface->init();
    
    return 0;
}

