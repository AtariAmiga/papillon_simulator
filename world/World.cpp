#include "World.h"
#include "../messages/TextMessage.h"
#include "../nodes/Terminal.h"
#include "../nodes/Repeater.h"
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

std::shared_ptr<Terminal> World::newTerminal(const char* name, float x, float y) {
    std::shared_ptr<Terminal> terminal(new Terminal(name, x, y));
    _communicationNodeList.push_front(terminal);
    return terminal;
}

std::shared_ptr<Repeater> World::newRepeater(const char* name, float x, float y) {
    std::shared_ptr<Repeater> repeater(new Repeater(name, x, y));
    _communicationNodeList.push_front(repeater);
    return repeater;
}

void World::simulateTime(int dtInMs) {
    _exactClock.updateTime(dtInMs);
    for(const auto& node: _communicationNodeList) {
        node->simulateTime(dtInMs);
    }
}

void World::runOneStep() {
    logger.updateTime(_exactClock.toTime());
    logger << "'" << _name << "' processing:" << std::endl;

    logger.stepIn();

    // Transmit
    logger << "transmitting:" << std::endl;
    logger.stepIn();
    while( ! _messageList.empty() ) {
        auto message = _messageList.front();
        _messageList.pop_front();

        logger << message << " -> " << std::endl;
        logger.stepIn();
        for(const auto& node : _communicationNodeList) {
            float d = locationDistance(message->emittedLocation(), node->location());
            if (0.0f < d && d < SIGNAL_RANGE_IN_M) {
                logger << node << " d=" << d << std::endl;
                node->receiveMessage(message);
            }
        }
        logger.stepOut();
    }
    logger.stepOut();

    // Compute
    logger << "computing:" << std::endl;
    logger.stepIn();
    for( const auto& node: _communicationNodeList) {
        std::list<std::shared_ptr<TextMessage>> list;
        node->runOneStep(list);
        _messageList.insert(_messageList.end(), list.begin(), list.end());
    }
    logger.stepOut();

    logger.stepOut();
}