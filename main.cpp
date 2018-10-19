#include <iostream>
#include <algorithm>

#include "ip_filter.h"

int main()
{
    try
    {
        ip_vector_t ip_pool;

        for(std::string line; std::getline(std::cin, line);)
        {
            auto splittedLine = split(line, '\t');
            ip_pool.push_back(split(splittedLine.at(0), '.'));
        }

        // reverse lexicographically sort
        std::sort(ip_pool.begin(), ip_pool.end(), std::greater<ip_t>());

        printIp(ip_pool);

        // filter by first byte and output
        filterAndPrint(ip_pool, 1);

        // filter by first and second bytes and output
        filterAndPrint(ip_pool, 46, 70);

        // filter by any byte and output
        filterAnyAndPrint(ip_pool, 46);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
