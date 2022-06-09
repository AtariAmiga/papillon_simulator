#include "catch2/catch_test_macros.hpp"
#include <cstring>
#include <random>
#include <iostream>

#include "RandomGenerator.h"

TEST_CASE( "RandomGenerator" ) {
    RandomGenerator rg1(0, 1);
    for( int n = 0; n < 10; n++ ) {
        double r = rg1.get();
        std::cout << r << std::endl;
        REQUIRE( (0 <= r) & (r <= 1) );
    }

    RandomGenerator rg2(-5, -1);
    for( int n = 0; n < 10; n++ ) {
        double r = rg2.get();
        std::cout << r << std::endl;
        REQUIRE( (-5 <= r) & (r <= -1) );
    }
}