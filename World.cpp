#include "World.h"
#include "Message.h"
#include "Terminal.h"
#include "Repeater.h"
#include "Location.h"

#include <iostream>
#include <memory>

const float SIGNAL_RANGE_IN_M = 1000.0f;


World::World(const char *name) {
    _name = name;
}

std::shared_ptr<Terminal> World::newTerminal(const char* name, float x, float y) {
    std::shared_ptr<Terminal> terminal(new Terminal(name, this, x, y));
    _communicationNodeList.push_front(terminal);
    return terminal;
}

std::shared_ptr<Repeater> World::newRepeater(const char* name, float x, float y) {
    std::shared_ptr<Repeater> repeater( new Repeater(name, this, x, y));
    _communicationNodeList.push_front(repeater);
    return repeater;
}

void World::queueMessage(Message* message) {
    _messageList.push_front(message );
}

void World::runOneStep() {
    while( ! _messageList.empty() ) {
        Message* message = _messageList.front();
        _messageList.pop_front();

        for(const auto& node : _communicationNodeList) {
            float d = locationDistance(message->emittedLocation(), node->location());
            if (0.0f < d && d < SIGNAL_RANGE_IN_M) {
                std::cout << "'" << _name << "' " << message << " -> " << node << " d=" << d << std::endl;
                node->receiveMessage(message);
            }
        }
    }

    for(const auto& node: _communicationNodeList) {
        node->runOneStep();
    }
}

std::ostream& operator<<(std::ostream &os, const World* world) {
    return os << "World '" << world->_name << "'" << std::endl;
}