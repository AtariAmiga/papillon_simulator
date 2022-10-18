#include "catch2/catch_test_macros.hpp"
#include <memory>
#include <cstring>

#include "Clock.h"

TEST_CASE( "Clock" ) {
    Clock clockNoDrift(0, 0);
    Clock clockDriftFuture(0, 5);
    Clock clockDriftPast(0, -6);

    SECTION("drifting") {
        REQUIRE(10 == clockNoDrift.updateTime(10));
        REQUIRE(10 == clockDriftFuture.updateTime(10));
        REQUIRE(9 == clockDriftPast.updateTime(10));

        REQUIRE(60 == clockNoDrift.updateTime(50));
        REQUIRE(63 == clockDriftFuture.updateTime(50));
        REQUIRE(56 == clockDriftPast.updateTime(50));

        REQUIRE(160 == clockNoDrift.updateTime(100));
        REQUIRE(168 == clockDriftFuture.updateTime(100));
        REQUIRE(150 == clockDriftPast.updateTime(100));
    }

    SECTION("syncing time") {
        REQUIRE(168 == clockDriftFuture.updateTime(160));

        clockDriftFuture.syncTime((time_t) 160);

        REQUIRE(160 == clockDriftFuture.currentTime());
    }

    SECTION("syncing between nodes") {
        // Same as in Clock sync.xls
        Clock a(0, -0.1);
        Clock b(0, -0.2);
        Clock c(0, 0);
        Clock d(0, 0.2);
        Clock e(0, 0.3);

        Clock* clocks[] = {&a, &b, &c, &d, &e};
        for( int t = 1; t < 10; t++ ) {
            printf("\n");
            for( Clock* clock: clocks ) {
                clock->updateTime(1000);
            }

            printf("%d\t", t);
            for( Clock* clock: clocks ) {
                printf("%d ", clock->currentTime());
            }
        }
    }
}