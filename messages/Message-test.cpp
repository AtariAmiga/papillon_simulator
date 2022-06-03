#include "catch2/catch_test_macros.hpp"
#include <memory>
#include <cstring>

#include "Message.h"
#include "../world/Location.h"

TEST_CASE( "Message" ) {
    auto l = std::make_unique<Location>(5, 6);
    auto m = std::make_unique<Message>(*l, "1.2" );

    REQUIRE("1.2" == m->messageUniqueId());
}