#include "catch2/catch_test_macros.hpp"
#include <cstring>

# include "Repeater.h"

TEST_CASE( "Repeater" ) {
    auto r = Repeater( "R", 2, 3 );
    REQUIRE( strcmp( "R", r.name() ) == 0 );
}