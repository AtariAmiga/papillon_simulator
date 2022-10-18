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

        clockDriftFuture.setCurrentTime((time_t) 160);

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
        for( int t = 1; t <= 85; t++ ) {
            for( Clock* clock: clocks ) {
                clock->updateTime(1000);
            }

            // http://archive.nitjsr.ac.in/course_assignment/CS02CS802%20Distributed%20Operating%20System%20(DOS)Unit-3%20Synchronization.pdf
            // todo: After a machine broadcasts its time, it starts a local timer to collect all other broadcasts that arrive
            //      during some interval. When all the broadcasts arrive, an algorithm is run to compute a new time from them.
            // todo: asserts
            if( true ) {
                for( Clock* c1: clocks ) {
                    for( Clock* c2: clocks ) {
                        if( c1 != c2 )
                            c1->syncTime(c2->currentTime());
                    }
                }
                for( Clock* c1: clocks ) {
                    c1->syncTimeStop();
                }
            }

            printf("%d\t", t);
            time_t min = LLONG_MAX;
            time_t max = 0;
            for( Clock* clock: clocks ) {
                time_t tm = clock->currentTime();
                min = std::min(min, tm);
                max = std::max(max, tm);
                printf("%d ", tm);
            }
            printf("\t%d\n", max - min);
        }
    }
}