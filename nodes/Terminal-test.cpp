#include "catch2/catch_test_macros.hpp"
#include <memory>
#include <cstring>

#include "Terminal.h"

TEST_CASE( "Terminal" ) {
    auto t = Terminal("T", 1, 2, 0);

    REQUIRE( strcmp("T", t.name()) == 0 );
}
