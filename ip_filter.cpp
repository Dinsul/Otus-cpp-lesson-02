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

void printIp(ip_vector_t ipVector)
{
    for(const auto &ip : ipVector)
    {
        for(auto ip_part = ip.cbegin(); ip_part != ip.cend(); ++ip_part)
        {
            if (ip_part != ip.cbegin())
            {
                std::putchar('.');
            }
            std::printf("%s", ip_part->c_str());
        }
        std::putchar('\n');
    }
}
