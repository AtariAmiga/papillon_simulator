#include "catch2/catch_test_macros.hpp"

#include "NodeScheduler.h"
#include "NodeState.h"
#include "../RandomGenerator.h"

#include <list>
#include <memory>

TEST_CASE( "NodeScheduler" ) {
    SECTION("talk slot") {
        SchedulerConfiguration sc;
        auto m = NodeScheduler(sc, 1);
        REQUIRE(LISTENING == m.getState(0));
        REQUIRE(TALKING == m.getState(10));
        REQUIRE(LISTENING == m.getState(20));

        m.changeToNextTalkSlot(1);
        REQUIRE( 2 == m.talkTimeSlot() );
        REQUIRE(LISTENING == m.getState(0));
        REQUIRE(LISTENING == m.getState(10));
        REQUIRE(TALKING == m.getState(20));
        REQUIRE(LISTENING == m.getState(30));
    }
    SECTION("cycling") {
        SchedulerConfiguration sc;
        auto m = NodeScheduler(sc, 1);
        time_t time = 0;
        //---------------------------------------------
        // Cycle 1
        //---------------------------------------------
        REQUIRE(LISTENING == m.getState(time += 0));  // 0
        REQUIRE(TALKING == m.getState(time += 10)); //   1
        REQUIRE(LISTENING == m.getState(time += 10)); // 2
        REQUIRE(LISTENING == m.getState(time += 10)); // 3
        REQUIRE(LISTENING == m.getState(time += 10)); // 4
        REQUIRE(LISTENING == m.getState(time += 10)); // 5
        REQUIRE(LISTENING == m.getState(time += 10)); // 6
        REQUIRE(LISTENING == m.getState(time += 10)); // 7
        REQUIRE(LISTENING == m.getState(time += 10)); // 8
        REQUIRE(LISTENING == m.getState(time += 10)); // 9
        REQUIRE(SLEEPING == m.getState(time += 10)); // 10
        REQUIRE(SLEEPING == m.getState(time += 10)); // 11
        REQUIRE(SLEEPING == m.getState(time += 10)); // 12
        REQUIRE(SLEEPING == m.getState(time += 10)); // 13
        REQUIRE(SLEEPING == m.getState(time += 10)); // 14
        //---------------------------------------------
        // Cycle 2
        //---------------------------------------------
        REQUIRE(LISTENING == m.getState(time += 10)); // 15
        REQUIRE(TALKING == m.getState(time += 10)); //   16
        REQUIRE(LISTENING == m.getState(time += 10)); // 17
        REQUIRE(LISTENING == m.getState(time += 10)); // 18
        REQUIRE(LISTENING == m.getState(time += 10)); // 19
        REQUIRE(LISTENING == m.getState(time += 10)); // 20
        REQUIRE(LISTENING == m.getState(time += 10)); // 21
        REQUIRE(LISTENING == m.getState(time += 10)); // 22
        REQUIRE(LISTENING == m.getState(time += 10)); // 23
        REQUIRE(LISTENING == m.getState(time += 10)); // 24
        REQUIRE(SLEEPING == m.getState(time += 10)); //  25
        // etc.
    }
}
