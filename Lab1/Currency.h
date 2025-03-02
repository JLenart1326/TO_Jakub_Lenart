#pragma once
#include <string>
#include <iostream>

using namespace std;

class Currency {
private:
    string name;
    string code;
    double exchangeRate;

public:
    Currency();
    Currency(string name, string code, double exchangeRate);
    Currency(const Currency& other);
    ~Currency();

    string getName() const;
    void setName(string name);
    string getCode() const;
    void setCode(string code);
    double getExchangeRate() const;
    void setExchangeRate(double exchangeRate);
    bool equals(const Currency& other);
};
