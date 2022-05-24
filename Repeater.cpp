#include "Message.h"
#include "Repeater.h"
#include "World.h"
#include "Location.h"

#include <iostream>

Repeater::Repeater(const char *name, struct World* owner, float x, float y):
        CommunicationNode(name, owner, x, y)
{
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

