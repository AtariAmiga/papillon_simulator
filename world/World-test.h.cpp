#include "catch2/catch_test_macros.hpp"
#include <cstring>

#include "World.h"

TEST_CASE( "World" ) {
    auto r = std::make_unique<World>( "W" );
    REQUIRE( strcmp( "W", r->name() ) == 0 );
}