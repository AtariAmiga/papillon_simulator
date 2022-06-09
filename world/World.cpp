#include "World.h"
#include "../messages/TextMessage.h"
#include "../nodes/Terminal.h"
#include "../nodes/Repeater.h"
#include "Location.h"

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

void World::queueMessage(const std::shared_ptr<TextMessage>& message) {
    _messageList.push_front(message );
}

void World::simulateTime(int dtInMs) {
    _exactClock.updateTime(dtInMs);
    for(const auto& node: _communicationNodeList) {
        node->simulateTime(dtInMs);
    }
}

void World::runOneStep() {
    // Transmit
    std::cout << _exactClock << std::endl;
    while( ! _messageList.empty() ) {
        auto message = _messageList.front();
        _messageList.pop_front();

        std::cout << "'" << _name << "' " << message << " -> " << std::endl;
        for(const auto& node : _communicationNodeList) {
            float d = locationDistance(message->emittedLocation(), node->location());
            if (0.0f < d && d < SIGNAL_RANGE_IN_M) {
                std::cout << "\t" << node << " d=" << d << std::endl;
                node->receiveMessage(message);
            }
        }
    }

    // Compute
    for(const auto& node: _communicationNodeList) {
        auto list = node->runOneStep();
        _messageList.insert(_messageList.end(), list.begin(), list.end());
    }
}