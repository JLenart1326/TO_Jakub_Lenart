#include "RestDataProvider.h"

vector<unsigned char> RestDataProvider::getData()
{
    std::vector<unsigned char> data;
    CURL* curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "Błąd cURL: " << curl_easy_strerror(res) << std::endl;
        }
        curl_easy_cleanup(curl);
    }
    return data;
}

size_t RestDataProvider::writeCallback(void* contents, size_t size, size_t nmemb, void* userData)
{
    size_t totalSize = size * nmemb;
    std::vector<unsigned char>* data = static_cast<std::vector<unsigned char>*>(userData);
    data->insert(data->end(), (unsigned char*)contents, (unsigned char*)contents + totalSize);
    return totalSize;
}
