#include "World.h"
#include "Message.h"
#include "Terminal.h"
#include "Repeater.h"
#include "Location.h"

#include <iostream>

const float SIGNAL_RANGE_IN_M = 1000.0f;


World::World(const char *name) {
    _name = name;
}

struct Terminal* World::newTerminal(const char* name, float x, float y) {
    auto* emitter = new Terminal(name, this, x, y);
    _communicationNodeList.push_front(emitter);
    return emitter;
}

struct Repeater* World::newRepeater(const char* name, float x, float y) {
    auto repeater = new Repeater(name, this, x, y);
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
            std::cout << "'" << _name << "' " << message->emittedLocation() << " -> " << node->location() << " d = " << d << " " << message;
            if (0.0f < d && d < SIGNAL_RANGE_IN_M) {
                std::cout << " SENT" << std::endl;
                node->receiveMessage(message);
            } else {
                std::cout << " same place or too far" << std::endl;
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