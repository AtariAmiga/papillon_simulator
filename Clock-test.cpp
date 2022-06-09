#include "catch2/catch_test_macros.hpp"
#include <memory>
#include <cstring>

#include "Clock.h"

TEST_CASE( "Clock" ) {
    Clock clockNoDrift(0, 0);
    Clock clockDriftFuture(0, 5);
    Clock clockDriftPast(0, -6);

    REQUIRE(10 == clockNoDrift.updateTime(10) );
    REQUIRE(10 == clockDriftFuture.updateTime(10) );
    REQUIRE(9 == clockDriftPast.updateTime(10) );

    REQUIRE(60 == clockNoDrift.updateTime(50) );
    REQUIRE(63 == clockDriftFuture.updateTime(50) );
    REQUIRE(56 == clockDriftPast.updateTime(50) );

    REQUIRE(160 == clockNoDrift.updateTime(100) );
    REQUIRE(168 == clockDriftFuture.updateTime(100) );
    REQUIRE(150 == clockDriftPast.updateTime(100) );
}
