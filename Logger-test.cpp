#include "catch2/catch_test_macros.hpp"

#include "Logger.h"

#include <iostream>

TEST_CASE( "Logger" ) {
    Logger l(std::cout);
    l << "hello";
    l << "world";
}
