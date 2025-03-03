#pragma once
#include "ICollectionManager.h"
#include "Currency.h"
#include <vector>

class CurrencyCollection : public ICollectionManager
{
private:
	vector<Currency*> currencyStack;

public:
	CurrencyCollection(vector<Currency*> currencies);

	//TODO
	//dopisać konstruktor kopiujący, dopisać destruktor z deletem najpierw każdej monety
	//dokonczyc implementacje reszty rzeczy z managera
	//dorobic menu uzytkownika
	//dorobic logike exchange

	void add(Currency* newCurrency) override;
	void print() override;
	Currency* get(string code) override;
	void set(string code, double newRate) override;
	Currency* remove(string code) override;
};

