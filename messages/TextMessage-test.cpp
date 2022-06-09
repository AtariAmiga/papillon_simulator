#include "catch2/catch_test_macros.hpp"
#include <memory>
#include <cstring>

#include "TextMessage.h"
#include "../world/Location.h"

TEST_CASE( "TextMessage" ) {
    auto l = Location(1, 2);
    auto m = TextMessage(l, "Emitter", "TextMessage", "Recipient", "1.2");

    REQUIRE( "1.2" == m.messageUniqueId() );
    REQUIRE( strcmp("Recipient", m.recipientName()) == 0 );
}
