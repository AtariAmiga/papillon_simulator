#include "catch2/catch_test_macros.hpp"

#include "NodeScheduler.h"
#include "NodeState.h"
#include "../RandomGenerator.h"

#include <list>
#include <memory>

TEST_CASE( "NodeScheduler" ) {
    SECTION("find talk slot") {
        // todo: transform this algorithm experimentation in real testable code
        RandomGenerator rg_0_3(0, 3);

        class Node {
        public:
            explicit Node(const char *name, const SchedulerConfiguration& sc, int talkTimeSlot)
                : _name(name), _scheduler(sc, talkTimeSlot), _receivedMsg(0)
            {}

            const char *_name;
            NodeScheduler _scheduler;
            int _receivedMsg;

            static void print(time_t timestamp, std::list<Node>& nodes) {
                for (Node& node: nodes) {
                    auto &state = node._scheduler.getState(timestamp);
                    std::cout << "'" << node._name << "' " << state << " " << node._scheduler.talkTimeSlot() << " ";
                    std::cout << "#" << node._receivedMsg << "\t";
                }
                std::cout << std::endl << std::flush;
            }
        };

        SchedulerConfiguration sc;
        std::list<Node> nodes{Node("A", sc, 0), Node("B", sc, 0), Node("C", sc, 0), Node("D", sc, 0)};
        for( time_t timestamp = 0; timestamp < 500; timestamp += 10 ) {
            // Nodes always emit messages when they are allowed to talk
            for (const Node& node: nodes) {
                auto &state = node._scheduler.getState(timestamp);

                if( state == TALKING ) {
                    for (Node& node2: nodes) {
                        if( node._name != node2._name ) {
                            node2._receivedMsg++;
                        }
                    }
                }
            }

            // Display current state
            std::cout << timestamp << "\t";
            Node::print( timestamp, nodes );

            // Algorithm to find a talking slot: randomly move (or not) to a next slot
            // if I am receiving a message while I am in a talking state
            for (Node& node: nodes) {
                auto &state = node._scheduler.getState(timestamp);

                if( state == TALKING ) {
                    if( node._receivedMsg ) {
                        // If all nodes start at 0, all talk at the same time, increasing talk slot by one will not work
                        // hence some random like decisions
                        node._scheduler.changeToNextTalkSlot((int) rg_0_3.get());
                    }
                }
                if( state != SLEEPING )
                    node._receivedMsg = 0; // Messages are processed
            }

            // Display next state
            std::cout << "\t";
            Node::print( timestamp, nodes );
        }
    }
    SECTION("cycling") {
        SchedulerConfiguration sc;
        auto m = NodeScheduler(sc, 1);
        time_t time = 0;
        //---------------------------------------------
        // Cycle 1
        //---------------------------------------------
        REQUIRE(LISTENING == m.getState(time += 0));  // 0
        REQUIRE(TALKING == m.getState(time += 10)); //   1
        REQUIRE(LISTENING == m.getState(time += 10)); // 2
        REQUIRE(LISTENING == m.getState(time += 10)); // 3
        REQUIRE(LISTENING == m.getState(time += 10)); // 4
        REQUIRE(LISTENING == m.getState(time += 10)); // 5
        REQUIRE(LISTENING == m.getState(time += 10)); // 6
        REQUIRE(LISTENING == m.getState(time += 10)); // 7
        REQUIRE(LISTENING == m.getState(time += 10)); // 8
        REQUIRE(LISTENING == m.getState(time += 10)); // 9
        REQUIRE(SLEEPING == m.getState(time += 10)); // 10
        REQUIRE(SLEEPING == m.getState(time += 10)); // 11
        REQUIRE(SLEEPING == m.getState(time += 10)); // 12
        REQUIRE(SLEEPING == m.getState(time += 10)); // 13
        REQUIRE(SLEEPING == m.getState(time += 10)); // 14
        //---------------------------------------------
        // Cycle 2
        //---------------------------------------------
        REQUIRE(LISTENING == m.getState(time += 10)); // 15
        REQUIRE(TALKING == m.getState(time += 10)); //   16
        REQUIRE(LISTENING == m.getState(time += 10)); // 17
        REQUIRE(LISTENING == m.getState(time += 10)); // 18
        REQUIRE(LISTENING == m.getState(time += 10)); // 19
        REQUIRE(LISTENING == m.getState(time += 10)); // 20
        REQUIRE(LISTENING == m.getState(time += 10)); // 21
        REQUIRE(LISTENING == m.getState(time += 10)); // 22
        REQUIRE(LISTENING == m.getState(time += 10)); // 23
        REQUIRE(LISTENING == m.getState(time += 10)); // 24
        REQUIRE(SLEEPING == m.getState(time += 10)); //  25
        // etc.
    }
}