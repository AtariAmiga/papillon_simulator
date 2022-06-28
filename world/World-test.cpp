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

        SchedulerConfiguration sc;
        auto *a = new Terminal("A", 0.0, 0.0, sc, 0);
        auto *b = new Terminal("B", 1.0, 0.0, sc, 0);
        auto *c = new Terminal("C", 1.0, 1.0, sc, 0);
        auto *d = new Terminal("D", 0.0, 1.0, sc, 0);
        Terminal* terminals[] = {a, b, c, d};
        for( auto t : terminals )
            w.addCommunicationNode(t);

        // todo: have them emit message so they can find an empty taking slot
        for(time_t n = 0; n < 50; n++ ) {
            std::string time = std::to_string(n);

            for( auto t : terminals ) {
                for( auto tDest : terminals ) {
                    if( t != tDest)
                        if( t->messagesToEmit() < 3 )
                            t->newMessage(("message " + time).data(), tDest->name());
                }
            }

            w.simulateTime(10);
            w.runOneStep();
        }
    }
}