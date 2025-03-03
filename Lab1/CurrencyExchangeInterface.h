#pragma once
#include "CurrencyCollection.h"
#include "Exchange.h"
#include "DataEncoder.h"
#include "RestDataProvider.h"

class CurrencyExchangeInterface
{
private:
    static CurrencyExchangeInterface* instance;

    CurrencyExchangeInterface();
public:
    CurrencyExchangeInterface(const CurrencyExchangeInterface&) = delete;
    CurrencyExchangeInterface& operator=(const CurrencyExchangeInterface&) = delete;

    static CurrencyExchangeInterface* getInstance();
    static void init();
};

