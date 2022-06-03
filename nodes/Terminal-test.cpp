#include "catch2/catch_test_macros.hpp"
#include <memory>
#include <cstring>

#include "Terminal.h"

TEST_CASE( "Terminal" ) {
    auto t = std::make_shared<Terminal>( "T", 1, 2 );

    REQUIRE( strcmp("T", t->name()) == 0 );
}
