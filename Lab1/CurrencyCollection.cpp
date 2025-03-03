#include "CurrencyCollection.h"

CurrencyCollection::CurrencyCollection(vector<Currency*> currencies)
{
	this->currencyStack = currencies;
}

void CurrencyCollection::add(Currency* newCurrency)
{
	if (newCurrency != nullptr) {
		this->currencyStack.push_back(newCurrency);
	}
	else {
		cout << "Invalid Currency" << endl;
	}
}

void CurrencyCollection::print()
{
	if (this->currencyStack.size() != 0) {
		cout << currencyStack.size() << endl;
		for (int i = this->currencyStack.size(); i--; i > 0) {
			cout << "Name: " << (this->currencyStack.at(i))->getName() << " Code: " << (this->currencyStack.at(i))->getCode() << " Rate: " << (this->currencyStack.at(i))->getExchangeRate() << endl;
		}
	}
	else {
		cout << "Collection is empty!" << endl;
	}
}

Currency* CurrencyCollection::get(string code)
{
	return nullptr;
}

void CurrencyCollection::set(string code, double newRate)
{
}

Currency* CurrencyCollection::remove(string code)
{
	return nullptr;
}
