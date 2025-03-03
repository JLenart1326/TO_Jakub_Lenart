#include "CurrencyExchangeInterface.h"

CurrencyExchangeInterface::CurrencyExchangeInterface()
{
    cout << "Utworzono instancje CurrencyExchangeInterface" << endl;
}

CurrencyExchangeInterface* CurrencyExchangeInterface::getInstance() {
    if (instance == nullptr) {
        instance = new CurrencyExchangeInterface();
    }
    return instance;
}

void CurrencyExchangeInterface::init()
{
    string apiUrl = "https://api.nbp.pl/api/exchangerates/tables/a/";
    RestDataProvider provider(apiUrl);
    vector<unsigned char> rawData = provider.getData();

    if (!rawData.empty()) {
        CurrencyCollection* collection = new CurrencyCollection(DataEncoder::encode(rawData));
        if (collection == nullptr) {
            cout << "Collection not initialized" << endl;
            return;
        }
        Currency* baseCurrency = new Currency("Złoty", "PLN", 1.0);
        collection->add(baseCurrency);
    }
    else {
        cout << "Nie udalo sie pobrac danych." << endl;
    }
}
