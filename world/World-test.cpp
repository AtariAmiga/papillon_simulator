#include "catch2/catch_test_macros.hpp"
#include <cstring>

#include "World.h"
#include "../nodes/Terminal.h"

TEST_CASE( "World" ) {
    SECTION("instanciation") {
        auto r = World("W");
        REQUIRE(strcmp("W", r.name()) == 0);
    }

    SECTION("find talking slot") {
        World w("W");

        w.addCommunicationNode( new Terminal("A", 0.0, 0.0, 0) );
        w.addCommunicationNode( new Terminal("B", 0.0, 0.0, 0) );
        w.addCommunicationNode( new Terminal("C", 0.0, 0.0, 0) );
        w.addCommunicationNode( new Terminal("D", 0.0, 0.0, 0) );

        // todo: have them emit message so they can find an empty taking slot
        for(time_t n = 0; n < 50; n++ ) {
            w.simulateTime(10);
            w.runOneStep();
        }
    }
}