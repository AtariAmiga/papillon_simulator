#include "Message.h"
#include "Repeater.h"
#include "World.h"
#include "Location.h"

#include <iostream>

Repeater::Repeater(const char *name, struct World* owner, float x, float y) {
    _location = new Location(x, y);
    _name = name;
    _worldOwner = owner;
}

std::ostream& operator<<(std::ostream& os, const Repeater* repeater) {
    return os << "Repeater '" << repeater->_name << "'" << std::endl;
}

void Repeater::runOneStep() {
    while( ! _messageList.empty() ) {
        Message* message = _messageList.front();
        _messageList.pop_front();

        Message* clone = message->cloneAndIncrement(_location);

        std::cout << "'" << _name << "' repeating: " << message << std::endl;
        _worldOwner->queueMessage(clone);
    }
}

