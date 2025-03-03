#include "DataEncoder.h"

vector<Currency*> DataEncoder::encode(const vector<unsigned char>& data)
{
    vector<Currency*> currencies;

    try {
        json jsonData = json::parse(string(data.begin(), data.end()));
        for (const auto& table : jsonData) {
            for (const auto& rate : table["rates"]) {
                string currencyName = rate["currency"];
                string currencyCode = rate["code"];
                double exchangeRate = rate["mid"];

                // Tworzymy obiekt klasy `Currency`
                Currency* new_currency = new Currency(currencyName, currencyCode, exchangeRate);
                currencies.push_back(new_currency);
            }
        }
    }
    catch (const json::exception& e) {
        cerr << "Błąd parsowania JSON: " << e.what() << endl;
    }

    return currencies;
}
