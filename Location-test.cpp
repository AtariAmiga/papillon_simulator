#include <catch2/catch_test_macros.hpp>
#include <memory>
#include "catch2/catch_approx.hpp"
using namespace Catch::literals;

#include "Location.h"

TEST_CASE( "Location" ) {
    auto l1 = std::make_unique<Location>( -10.0f, -5.0f );
    auto l2 = std::make_unique<Location>(7.0f, 9.0f);

    // todo: voir si on peut faire mieux que *l1.get() etc.
    REQUIRE( locationDistance(*l1.get(), *l2.get()) ==  Catch::Approx(22.02271).epsilon(0.000001) );

    // todo: REQUIRE( strcmp(string, "(-10, -5)(7, 9)") == 0 );
}