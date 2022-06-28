#include "catch2/catch_test_macros.hpp"
#include "CommunicationNode.h"

TEST_CASE( "CommunicationNode" ) {
    SECTION("instanciation") {
        class Node : public CommunicationNode {
        public:
            explicit Node(const char *name)
                    : CommunicationNode(name, 0, 0, 0) {}

            void runOneStep(std::list<std::shared_ptr<TextMessage>> &emittedMessageList) override {
            }
        };

        Node node("N");
    }
}
