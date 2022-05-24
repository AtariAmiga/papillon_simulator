#include "Message.h"
#include "Repeater.h"
#include "World.h"
#include "Location.h"

#include <iostream>

Repeater::Repeater(const char *name, struct World* owner, float x, float y) {
    this->_location = new Location(x, y);
    this->_name = name;
    this->_worldOwner = owner;
}

std::ostream& operator<<(std::ostream& os, const Repeater* repeater) {
    return os << "Repeater '" << repeater->_name << "'" << std::endl;
}

void Repeater::runOneStep() {
    while( ! _messageList.empty() ) {
        Message* message = _messageList.front();
        _messageList.pop_front();

        Message* clone = message->cloneAndIncrement(this->_location);

        std::cout << "'" << this->_name << "' repeating: " << message << std::endl;
        this->_worldOwner->queueMessage(clone);
    }
}

