#include "World.h"
#include "Message.h"
#include "Terminal.h"
#include "Repeater.h"
#include "Location.h"

#include <iostream>

const float SIGNAL_RANGE_IN_M = 1000.0f;


World::World(const char *name) {
    this->_name = name;
}

struct Terminal* World::newTerminal(const char* name, float x, float y) {
    auto* emitter = new Terminal(name, this, x, y);
    this->communicationNodeList.push_front(emitter);
    return emitter;
}

struct Repeater* World::newRepeater(const char* name, float x, float y) {
    auto repeater = new Repeater(name, this, x, y);
    this->communicationNodeList.push_front(repeater);
    return repeater;
}

void World::queueMessage(Message* message) {
    this->messageList.push_front( message );
}

void World::runOneStep() {
    while( ! messageList.empty() ) {
        Message* message = messageList.front();
        messageList.pop_front();

        for(const auto& node : this->communicationNodeList) {
            float d = locationDistance(message->emittedLocation, node->location);
            std::cout << "'" << this->_name << " " << message->emittedLocation << " -> " << node->location << " d = " << d << " ";
            if (0.0f < d && d < SIGNAL_RANGE_IN_M) {
                std::cout << " SENT" << std::endl;
                node->receiveMessage(message);
            } else {
                std::cout << " same place or too far" << std::endl;
            }
        }
    }

    for(const auto& node: this->communicationNodeList) {
        node->runOneStep();
    }
}

std::ostream& operator<<(std::ostream &os, const World* world) {
    return os << "World '" << world->_name << "'" << std::endl;
}