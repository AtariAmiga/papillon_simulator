#include <catch2/catch_test_macros.hpp>
#include <memory>
#include <cstring>

#include "Message.h"
#include "Location.h"

TEST_CASE( "Message" ) {
    auto l = std::make_unique<Location>(1, 2);
    auto m = std::make_unique<Message>(*l, "Emitter", "Message", "Recipient", "1.2");

    REQUIRE( "1.2" == m->messageUniqueId() );
    REQUIRE( strcmp("Recipient", m->recipientName()) == 0 );
}
