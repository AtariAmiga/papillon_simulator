#include <catch2/catch_test_macros.hpp>
#include <io.h>
#include "catch2/catch_approx.hpp"
using namespace Catch::literals;

#include "Location.h"

TEST_CASE( "Location" ) {
    const Location* l1 = new Location(-10.0f, -5.0f);
    const Location* l2 = new Location(7.0f, 9.0f);

    REQUIRE( locationDistance(l1, l2) ==  Catch::Approx(22.02271).epsilon(0.000001) );

    char string[500]; // todo: tool!
    memset( string, 0, 500); // todo: tool!
    setbuf(stdout, string); // todo: tool!

    l1->print();
    l2->print();

    setbuf(stdout,NULL); // todo: tool!

    REQUIRE( strcmp(string, "(-10, -5)(7, 9)") == 0 );
}