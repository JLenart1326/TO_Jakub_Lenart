#pragma once
#include <vector>

using namespace std;

class IRemoteDataProvider
{
public:
	virtual vector<unsigned char> getData() = 0;
	virtual ~IRemoteDataProvider() = default;
};

