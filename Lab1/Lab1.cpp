#include "CurrencyExchangeInterface.h"

CurrencyExchangeInterface* CurrencyExchangeInterface::instance = nullptr;

int main()
{
    CurrencyExchangeInterface* mainInterface = CurrencyExchangeInterface::getInstance();
    mainInterface->init();
    
    return 0;
}

