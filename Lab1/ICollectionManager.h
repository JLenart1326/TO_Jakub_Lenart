#pragma once
#include "Currency.h"

class ICollectionManager
{
public:
	virtual void add(Currency* newCurrency) = 0;
	virtual Currency* get(string code) = 0;
	virtual void set(string code, double newRate) = 0;
	virtual Currency* remove(string code) = 0;
	virtual void print() = 0;
	virtual ~ICollectionManager() = default;
};

