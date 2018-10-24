#include <cstdio>
#include <algorithm>

#include "ip_filter.h"

bool operator < (const ip_t &first, const ip_t &second)
{
    int fDigit = 0;
    int sDigit = 0;

    for (decltype(first.size()) i = 0; i < first.size() && i < second.size() && fDigit == sDigit; ++i)
    {
        fDigit = std::stoi(first[i]);
        sDigit = std::stoi(second[i]);
    };

    return fDigit > sDigit;
}

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
    for(auto ip_part = ip.cbegin(); ip_part != ip.cend(); ++ip_part)
    {
        if (ip_part != ip.cbegin())
        {
            std::putchar('.');
        }
        std::printf("%s", ip_part->c_str());
    }
}

void printIp(const ip_vector_t &ipVector)
{
    for(const auto &ip : ipVector)
    {
        printIp(ip);
        std::putchar('\n');
    }
}

void filterAnyAndPrint(const ip_vector_t &ipVector, int arg)
{
    if (arg > 255)
    {
        return;
    }

    for (const auto &ip : ipVector)
    {
        if (std::any_of(ip.begin(), ip.end(), [=](const std::string &i)
            {return stoi(i) == arg;}))
        {
            printIp(ip);
            std::putchar('\n');
        }
    }

    return;
}
