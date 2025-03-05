#include "CurrencyCollection.h"

CurrencyCollection::CurrencyCollection(vector<Currency*> currencies)
{
	this->currencyCollection = currencies;
}

CurrencyCollection::CurrencyCollection(const CurrencyCollection& other)
{
	for (Currency* currency : other.currencyCollection) {
		this->currencyCollection.push_back(new Currency(*currency));
	}
}

CurrencyCollection::~CurrencyCollection()
{
	for (Currency* currency: this->currencyCollection) {
		delete currency;
		currency = nullptr;
	}
	this->currencyCollection.clear();
}

void CurrencyCollection::add(Currency* newCurrency)
{
	if (newCurrency != nullptr) {
		this->currencyCollection.push_back(newCurrency);
	}
	else {
		cout << "Invalid Currency" << endl;
	}
}

void CurrencyCollection::print()
{
	if (this->currencyCollection.size() != 0) {
		for (int i = this->currencyCollection.size(); i--; i > 0) {
			cout << "Name: " << (this->currencyCollection.at(i))->getName() << "   |||   Code: " << (this->currencyCollection.at(i))->getCode() << "   |||   Rate: " << (this->currencyCollection.at(i))->getExchangeRate() << endl;
		}
	}
	else {
		cout << "Collection is empty!" << endl;
	}
}

Currency* CurrencyCollection::get(string code)
{
	for (Currency* currency : this->currencyCollection) {
		if (currency->getCode() == code) {
			return currency;  
		}
	}
	return nullptr;  
}

void CurrencyCollection::set(string code, double newRate)
{
	for (Currency* currency : this->currencyCollection) {
		if (currency->getCode() == code) {
			currency->setExchangeRate(newRate);
			return;
		}
	}
	cout << "Currency with code " << code << " not found!" << endl;
}

Currency* CurrencyCollection::remove(string code)
{
	for (vector<Currency*>::iterator it = this->currencyCollection.begin(); it != this->currencyCollection.end(); ++it) {
		if ((*it)->getCode() == code) {
			Currency* removedCurrency = *it;  
			this->currencyCollection.erase(it); 
			return removedCurrency; 
		}
	}
	return nullptr; 
}

