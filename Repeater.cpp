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

        int count = _forwardedMessageCount[message->messageUniqueId()];

        if( count < 1 ) { // todo: when should it repeat the message, and when not?
            Message *clone = message->cloneAndIncrement(_location);

            std::cout << "'" << _name << "' repeating: " << message << std::endl;
            _worldOwner->queueMessage(clone);

            _forwardedMessageCount[message->messageUniqueId()] = count + 1;
        } else {
//            std::cout << "'" << _name << "' NOT repeating: " << message << std::endl;
        }
    }
}

