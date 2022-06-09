#include "catch2/catch_test_macros.hpp"
#include <cstring>

#include "World.h"

TEST_CASE( "World" ) {
    auto r = World( "W" );
    REQUIRE( strcmp( "W", r.name() ) == 0 );
}