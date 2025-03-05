#pragma once
#include "ICollectionManager.h"
#include "Currency.h"
#include <vector>

class CurrencyCollection : public ICollectionManager
{
private:
	vector<Currency*> currencyCollection;

public:
	CurrencyCollection(vector<Currency*> currencies);
	CurrencyCollection(const CurrencyCollection& other);
	~CurrencyCollection();

	void add(Currency* newCurrency) override;
	void print() override;
	Currency* get(string code) override;
	void set(string code, double newRate) override;
	Currency* remove(string code) override;
};

