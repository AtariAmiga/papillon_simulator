#include "catch2/catch_test_macros.hpp"

#include "NodeScheduler.h"
#include "../world/Location.h"

TEST_CASE( "NodeScheduler" ) {
    auto m = NodeScheduler(100, 50, 1, 10);
    //---------------------------------------------
    // Cycle 1
    //---------------------------------------------
    REQUIRE( LISTENING == m.updateTime(0) );  //  0
    REQUIRE( TALKING   == m.updateTime(10) ); //  1
    REQUIRE( LISTENING == m.updateTime(10) ); //  2
    REQUIRE( LISTENING == m.updateTime(10) ); //  3
    REQUIRE( LISTENING == m.updateTime(10) ); //  4
    REQUIRE( LISTENING == m.updateTime(10) ); //  5
    REQUIRE( LISTENING == m.updateTime(10) ); //  6
    REQUIRE( LISTENING == m.updateTime(10) ); //  7
    REQUIRE( LISTENING == m.updateTime(10) ); //  8
    REQUIRE( LISTENING == m.updateTime(10) ); //  9
    REQUIRE( SLEEPING  == m.updateTime(10) ); // 10
    REQUIRE( SLEEPING  == m.updateTime(10) ); // 11
    REQUIRE( SLEEPING  == m.updateTime(10) ); // 12
    REQUIRE( SLEEPING  == m.updateTime(10) ); // 13
    REQUIRE( SLEEPING  == m.updateTime(10) ); // 14
    //---------------------------------------------
    // Cycle 2
    //---------------------------------------------
    REQUIRE( LISTENING == m.updateTime(10) ); // 15
    REQUIRE( TALKING   == m.updateTime(10) ); // 16
    REQUIRE( LISTENING == m.updateTime(10) ); // 17
    REQUIRE( LISTENING == m.updateTime(10) ); // 18
    REQUIRE( LISTENING == m.updateTime(10) ); // 19
    REQUIRE( LISTENING == m.updateTime(10) ); // 20
    REQUIRE( LISTENING == m.updateTime(10) ); // 21
    REQUIRE( LISTENING == m.updateTime(10) ); // 22
    REQUIRE( LISTENING == m.updateTime(10) ); // 23
    REQUIRE( LISTENING == m.updateTime(10) ); // 24
    REQUIRE( SLEEPING  == m.updateTime(10) ); // 25
    // etc.
}
