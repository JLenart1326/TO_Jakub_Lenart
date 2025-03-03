#pragma once
#include "IRemoteDataProvider.h"
#include <iostream>
#include <curl/curl.h>  // Biblioteka cURL do pobierania danych

class RestDataProvider : public IRemoteDataProvider
{
private:
	string url;

    // Funkcja callback dla cURL – zapisuje pobrane dane do wektora bajtów
    static size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userData);
public:
    // Konstruktor przyjmuje URL
    RestDataProvider(const std::string& apiUrl) : url(apiUrl) {}

	vector<unsigned char> getData() override;
};
