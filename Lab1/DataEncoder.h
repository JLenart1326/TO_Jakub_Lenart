#pragma once
#include <string>
#include <vector>
#include "Currency.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

class DataEncoder
{
public:
	static vector<Currency*> encode(const vector<unsigned char>& data);
};

