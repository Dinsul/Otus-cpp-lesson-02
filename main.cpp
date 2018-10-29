#include <iostream>
#include <algorithm>

#include "ip_filter.h"

int main()
{
    try
    {
        std::vector<ip_t> ip_pool;

        ip_pool.reserve(1500);

        for(std::string line; std::getline(std::cin, line);)
        {
            auto splittedLine = split(line, '\t');
            ip_t newIp;

            for (auto node : split(splittedLine.at(0), '.'))
            {
                newIp.push_back(std::stoi(node));
            }

            ip_pool.push_back(newIp);
        }

        // reverse lexicographically sort
         std::sort(ip_pool.begin(), ip_pool.end(), std::greater<ip_t>());

        printIp(ip_pool);

        // filter by first byte and output
        printIp(ip_pool, 1);

        // filter by first and second bytes and output
        printIp(ip_pool, 70, 46);

        // filter by any byte and output
        filterAnyAndPrint(ip_pool, 46);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;

        return 1;
    }

    return 0;
}
