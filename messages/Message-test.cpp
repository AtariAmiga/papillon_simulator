#include "catch2/catch_test_macros.hpp"
#include <memory>
#include <cstring>

#include "Message.h"

TEST_CASE( "Message" ) {
    auto l = Location(5, 6);
    auto m = Message(l, "1.2" );

    REQUIRE("1.2" == m.messageUniqueId());
}