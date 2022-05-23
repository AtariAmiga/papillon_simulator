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
    this->terminalList.push_front(emitter);
    return emitter;
}

struct Repeater* World::newRepeater(const char* name, float x, float y) {
    auto repeater = new Repeater(name, this, x, y);
    this->repeaterList.push_front(repeater);
    return repeater;
}

void World::queueMessage(Message* message) {
    this->messageList.push_front( message );
}

void World::runOneStep() {
    while( ! messageList.empty() ) {
        Message* message = messageList.front();
        messageList.pop_front();

        std::cout << "'" << this->_name << "' processing: " << message << std::endl;

        // todo: do better? 0.0f < d means that emitter should not receive its own emitted messages (unless comes back later after being repeated)
        // Terminals
        for(const auto& terminal : this->terminalList) {
            float d = locationDistance(message->emittedLocation, terminal->location);
            if(0.0f < d && d < SIGNAL_RANGE_IN_M)
                terminal->receiveMessage(message);
        }

        // Repeaters todo: same code for Repeater and Terminal!
        for(const auto& repeater : this->repeaterList) {
            float d = locationDistance(message->emittedLocation, repeater->location);
            if(0.0f < d && d < SIGNAL_RANGE_IN_M)
                repeater->receiveMessage(message);
        }
    }
}

std::ostream& operator<<(std::ostream &os, const World* world) {
    return os << "World '" << world->_name << "'" << std::endl;
}