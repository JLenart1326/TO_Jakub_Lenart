#include "Currency.h"

Currency::Currency() : name(""), code(""), exchangeRate(0.0) 
{
}

Currency::Currency(string name, string code, double exchangeRate)
    : name(name), code(code), exchangeRate(exchangeRate) {
}
Currency::Currency(const Currency& other)
{
    this->setName(other.getName());
    this->setCode(other.getCode());
    this->setExchangeRate(other.getExchangeRate());
}
Currency::~Currency()
{
}

string Currency::getName() const {
    return this->name;
}
void Currency::setName(string name) 
{
    this->name = name;
}
string Currency::getCode() const {
    return this->code;
}
void Currency::setCode(string code)
{
    this->code = code;
}
double Currency::getExchangeRate() const {
    return this->exchangeRate;
}
void Currency::setExchangeRate(double exchangeRate)
{
    this->exchangeRate = exchangeRate;
}

bool Currency::equals(const Currency& other)
{
    return this->code == other.getCode();
}