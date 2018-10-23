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

inline void printIp(ip_t ip)
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

void printIp(ip_vector_t ipVector)
{
    for(const auto &ip : ipVector)
    {
        printIp(ip);
        std::putchar('\n');
    }
}

void filterAndPrint(ip_vector_t ipVector, int arg0, int arg1, int arg2, int arg3)
{
    for(const auto &ip : ipVector)
    {
        if (  (arg0 > 255 || ip[0].compare(std::to_string(arg0)) == 0)
              && (arg1 > 255 || ip[1].compare(std::to_string(arg1)) == 0)
              && (arg2 > 255 || ip[2].compare(std::to_string(arg2)) == 0)
              && (arg3 > 255 || ip[3].compare(std::to_string(arg3)) == 0) )
        {
            printIp(ip);
            std::putchar('\n');
        }
    }

    return;
}

void filterAnyAndPrint(ip_vector_t ipVector, int arg)
{
    if (arg > 255)
    {
        return;
    }

    for(const auto &ip : ipVector)
    {
        if ( std::any_of(ip.begin(), ip.end(), [=](const std::string &i)
        {return i.compare(std::to_string(arg)) == 0;}))
        {
            printIp(ip);
            std::putchar('\n');
        }
    }

    return;
}

//bool operator <(const ip_t &first, const ip_t &second)
//{
//    int cmpRes = 0;

//    for (decltype(first.size()) i = 0; i < first.size() && i < second.size() && cmpRes == 0; ++i)
//    {
//        cmpRes = first[i].compare(second[i]);
//    };

//    return cmpRes > 0;
//}

bool operator <(const ip_t &first, const ip_t &second)
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
