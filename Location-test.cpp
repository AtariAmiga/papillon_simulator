#include <catch2/catch_test_macros.hpp>
#include "catch2/catch_approx.hpp"
using namespace Catch::literals;

extern "C" {
#include "Location.h"
}

TEST_CASE( "Location" ) {
    struct Location* l1 = Location_new(-10.0f, -5.0f);
    struct Location* l2 = Location_new(7.0f, 9.0f);

    REQUIRE( distance(l1, l2) ==  Catch::Approx(22.02271).epsilon(0.000001) );
}