#include "CurrencyExchangeInterface.h"

CurrencyExchangeInterface::CurrencyExchangeInterface()
{
    cout << "CurrencyExchangeInterface instances created" << endl;
}

CurrencyExchangeInterface* CurrencyExchangeInterface::getInstance() {
    if (instance == nullptr) {
        instance = new CurrencyExchangeInterface();
    }
    return instance;
}

void CurrencyExchangeInterface::runUserInterface(CurrencyCollection* collection) {
    if (collection == nullptr) {
        cout << "Collection initialization went wrong" << endl;
        return;
    }
    int choice;
    string fromCode, toCode;
    double amount;
    Exchange exchangeSystem;

    while (true) {
        cout << "\n======= Currency Exchange System =======" << endl;
        cout << "1. View available currencies" << endl;
        cout << "2. Exchange currency" << endl;
        cout << "3. Check exchange rate" << endl;
        cout << "4. Exit" << endl;
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            collection->print();
            break;
        }

        case 2: {
            cout << "Enter currency code to exchange(e.g. EUR):";
            cin >> fromCode;
            cout << "Enter the final currency code (e.g. USD):";
            cin >> toCode;
            cout << "Enter the amount to exchange:";
            cin >> amount;

            Currency* fromCurrency = collection->get(fromCode);
            Currency* toCurrency = collection->get(toCode);

            if (fromCurrency && toCurrency) {
                double exchangedAmount = exchangeSystem.exchange(*fromCurrency, *toCurrency, amount);
                cout << "Exchanged " << amount << " " << fromCode << " for " << exchangedAmount << " " << toCode << endl;
            }
            else {
                cout << "Error: One of the specified currencies not found!" << endl;
            }
            break;
        }

        case 3: {
            cout << "Enter currency code:";
            cin >> fromCode;
            Currency* currency = collection->get(fromCode);

            if (currency) {
                cout << "Exchange rate for " << fromCode << ": " << currency->getExchangeRate() << " PLN" << endl;
            }
            else {
                cout << "Error: Currency not found!" << endl;
            }
            break;
        }

        case 4: {
            cout << "Closing the currency exchange system..." << endl;
            delete collection;
            return;
        }

        default:
            cout << "Invalid option. Please try again!" << endl;
        }
    }
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

        CurrencyExchangeInterface::runUserInterface(collection);
    }
    else {
        cout << "Failed to fetch data." << endl;
    }
}

