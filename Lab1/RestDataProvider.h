#pragma once
#include "IRemoteDataProvider.h"
#include <iostream>
#include <curl/curl.h> 

class RestDataProvider : public IRemoteDataProvider
{
private:
	string url;

    static size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userData);
public:
    RestDataProvider(const std::string& apiUrl) : url(apiUrl) {}

	vector<unsigned char> getData() override;
};
