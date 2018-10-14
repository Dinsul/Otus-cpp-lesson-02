#include "ip_filter.h"

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
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
