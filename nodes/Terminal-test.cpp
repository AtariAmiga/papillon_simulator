#include "catch2/catch_test_macros.hpp"
#include <memory>
#include <cstring>

#include "Terminal.h"

TEST_CASE( "Terminal" ) {
    SchedulerConfiguration sc;
    auto t = Terminal("T", 1, 2, sc, 0);

    REQUIRE( strcmp("T", t.name()) == 0 );
}
