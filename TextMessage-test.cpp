#include <catch2/catch_test_macros.hpp>
#include <memory>
#include <cstring>

#include "TextMessage.h"
#include "Location.h"

TEST_CASE( "TextMessage" ) {
    auto l = std::make_unique<Location>(1, 2);
    auto m = std::make_unique<TextMessage>(*l, "Emitter", "TextMessage", "Recipient", "1.2");

    REQUIRE( "1.2" == m->messageUniqueId() );
    REQUIRE( strcmp("Recipient", m->recipientName()) == 0 );
}
