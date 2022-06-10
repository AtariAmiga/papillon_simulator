#include "../messages/TextMessage.h"
#include "Repeater.h"
#include "../world/World.h"

#include <iostream>

Repeater::Repeater(const char *name, float x, float y) :
        CommunicationNode(name, x, y)
{
}

void Repeater::runOneStep(std::list<std::shared_ptr<TextMessage>> &emittedMessageList) {
    if( ! _messageReceivedList.empty() )
        std::cout << "'" << _name << "' " << _nodeClock << " processing:" << std::endl;

    while( ! _messageReceivedList.empty() ) {
        auto message = _messageReceivedList.front();
        _messageReceivedList.pop_front();

        int count = _forwardedMessageCount[message->messageUniqueId()];

        if( count < 1 ) { // todo: when should it repeat the message, and when not?
            auto clone = message->cloneAndIncrement(_location);

            std::cout << "\trepeating: " << message << std::endl;
            emittedMessageList.push_front(clone);

            _forwardedMessageCount[message->messageUniqueId()] = count + 1;
        } else {
            std::cout << "\tNOT repeating (already: " << count << " times): " << message << std::endl;
        }
    }
}

