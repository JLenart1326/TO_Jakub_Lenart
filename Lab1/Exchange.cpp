#include "Exchange.h"

double Exchange::exchange(const Currency& c1, const Currency& c2, double amount)
{
    double amountInPLN = amount * c1.getExchangeRate();

    double convertedAmount = amountInPLN / c2.getExchangeRate();

    return convertedAmount;
}
