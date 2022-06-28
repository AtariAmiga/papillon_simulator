#include "World.h"
#include "../messages/TextMessage.h"
#include "../nodes/Terminal.h"
#include "Location.h"
#include "../Logger.h"

#include <iostream>
#include <memory>

const float SIGNAL_RANGE_IN_M = 1000.0f;

World::World(const char* name):
        _exactClock(0, 0),
        _name(name)
{
}


void World::addCommunicationNode(CommunicationNode* node) {
    _communicationNodeList.push_front(std::shared_ptr<CommunicationNode>(node));
}

time_t World::simulateTime(int dtInMs) {
    auto t = _exactClock.updateTime(dtInMs);
    for(const auto& node: _communicationNodeList) {
        node->simulateTime(dtInMs);
    }
    return t;
}

void World::runOneStep() {
    logger.updateTime(_exactClock.toTime());

    logger << "'" << _name << "' processing:" << std::endl;
    logger.stepIn();

    // Compute first, so messages can be emitted then transmitted in the same timeslot
    // so that nodes can change talk slot if they receive a message while they
    // are in the talking state
    logger << "computing:" << std::endl;
    logger.stepIn();
    for( const auto& node: _communicationNodeList) {
        std::list<std::shared_ptr<TextMessage>> list;
        node->runOneStep(list);
        _messageList.insert(_messageList.end(), list.begin(), list.end());
    }
    logger.stepOut();

    // Transmit
    if( ! _messageList.empty() ) {
        logger << "transmitting:" << std::endl;
        logger.stepIn();
        while (!_messageList.empty()) {
            auto message = _messageList.front();
            _messageList.pop_front();

            logger << message << " -> " << std::endl;
            logger.stepIn();
            for (const auto &node: _communicationNodeList) {
                float d = locationDistance(message->emittedLocation(), node->location());
                if (0.0f < d && d < SIGNAL_RANGE_IN_M) {
                    logger << node << " d=" << d << std::endl;
                    node->receiveMessage(message);
                }
            }
            logger.stepOut();
        }
        logger.stepOut();
    }

    logger.stepOut();
}