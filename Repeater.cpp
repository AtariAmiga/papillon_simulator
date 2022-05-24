#include "Message.h"
#include "Repeater.h"
#include "World.h"
#include "Location.h"

#include <iostream>

Repeater::Repeater(const char *name, struct World* owner, float x, float y) {
    this->_location = new Location(x, y);
    this->name = name;
    this->worldOwner = owner;
}

std::ostream& operator<<(std::ostream& os, const Repeater* repeater) {
    return os << "Repeater '" << repeater->name << "'" << std::endl;
}

void Repeater::runOneStep() {
    while( ! messageList.empty() ) {
        Message* message = messageList.front();
        messageList.pop_front();

        Message* clone = message->cloneAndIncrement(this->_location);

        std::cout << "'" <<  this->name << "' repeating: " << message << std::endl;
        this->worldOwner->queueMessage(clone);
    }
}

