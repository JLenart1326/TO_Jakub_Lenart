#pragma once
#include "Currency.h"

class Exchange
{
public:
	static double exchange(const Currency& c1, const Currency& c2, double amount);
};

