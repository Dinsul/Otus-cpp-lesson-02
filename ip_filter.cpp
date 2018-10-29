#include <cstdio>
#include <algorithm>

#include "ip_filter.h"

std::vector<std::string> split(const std::string &str, char separator)
{
    std::vector<std::string> retValue;

    std::string::size_type start = 0;
    std::string::size_type stop  = str.find_first_of(separator);

    while(stop != std::string::npos)
    {
        retValue.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop  = str.find_first_of(separator, start);
    }

    retValue.push_back(str.substr(start));

    return retValue;
}

inline void printIp(const ip_t &ip)
{
    std::printf("%d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
}

void printIp(const ip_vector_t &ipVector)
{
    for(const auto &ip : ipVector)
    {
        printIp(ip);
    }
}

void filterAnyAndPrint(const ip_vector_t &ipVector, int arg)
{
    for (const auto &ip : ipVector)
    {
        if (std::any_of(ip.begin(), ip.end(), [=](int i){return i == arg;}))
        {
            printIp(ip);
        }
    }
}
