#include "catch2/catch_test_macros.hpp"

#include "Logger.h"

#include <iostream>

TEST_CASE( "Logger" ) {
    Logger l(std::cout);
    l << "hello ";
    l << "world" << std::endl;
    l << "Hello ";
    l << "World" << std::endl;

    l.updateTime(1);

    l << "HELLO ";
    l << "WORLD" << std::endl;
}
