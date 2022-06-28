#include "catch2/catch_test_macros.hpp"
#include <cstring>

# include "Repeater.h"

TEST_CASE( "Repeater" ) {
    SchedulerConfiguration sc;
    auto r = Repeater("R", 2, 3, sc, 0);
    REQUIRE( strcmp( "R", r.name() ) == 0 );
}