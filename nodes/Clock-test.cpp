#include "catch2/catch_test_macros.hpp"
#include <memory>
#include <cstring>

#include "Clock.h"

TEST_CASE( "Clock" ) {
    // todo: use this
    //    std::random_device rd;
    //    std::mt19937 mt(rd());
    //    std::uniform_real_distribution<double> dist(-5.0, 5.0);


    Clock c(0, 0);
    REQUIRE( 1 == c.updateTime(1) );
    REQUIRE( 2 == c.updateTime(1) );
    REQUIRE( 12 == c.updateTime(10) );

    Clock cd(0, 5);
    REQUIRE( 10 == cd.updateTime(10) );
    REQUIRE( 60 == cd.updateTime(50) );
    REQUIRE( 160 == cd.updateTime(100) );
}
