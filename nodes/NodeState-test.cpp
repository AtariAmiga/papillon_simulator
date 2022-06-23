#include "catch2/catch_test_macros.hpp"

#include "NodeState.h"

TEST_CASE( "NodeState" ) {
    REQUIRE(LISTENING == LISTENING);
    REQUIRE(TALKING == TALKING);
    REQUIRE(SLEEPING == SLEEPING);

    REQUIRE(LISTENING != TALKING);
    REQUIRE(TALKING != SLEEPING);
    REQUIRE(SLEEPING != LISTENING);
}
