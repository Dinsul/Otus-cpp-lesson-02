#define BOOST_TEST_MODULE test_main

#include <boost/test/unit_test.hpp>

#include "ip_filter.h"

BOOST_AUTO_TEST_SUITE(test_suite_ip_filter)

BOOST_AUTO_TEST_CASE(test_split)
{
    auto runRes   = split("", '.');
    auto rightRes = std::vector<std::string>({""});

    BOOST_CHECK(runRes == rightRes);

    runRes   = split("..", '.');
    rightRes = std::vector<std::string>({"", "", ""});

    BOOST_CHECK(runRes == rightRes);

    runRes   = split("11.", '.');
    rightRes = std::vector<std::string>({"11", ""});

    BOOST_CHECK(runRes == rightRes);

    runRes   = split("11", '.');
    rightRes = std::vector<std::string>({"11"});

    BOOST_CHECK(runRes == rightRes);

    runRes   = split(".22", '.');
    rightRes = std::vector<std::string>({"", "22"});

    BOOST_CHECK(runRes == rightRes);

    runRes   = split("11.22", '.');
    rightRes = std::vector<std::string>({"11", "22"});

    BOOST_CHECK(runRes == rightRes);
}

//BOOST_AUTO_TEST_CASE(test_version_valid)
//{
//    BOOST_CHECK(version() > 0);

//}

BOOST_AUTO_TEST_SUITE_END()
