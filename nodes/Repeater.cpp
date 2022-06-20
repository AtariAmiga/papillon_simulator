#include "../messages/TextMessage.h"
#include "Repeater.h"
#include "../world/World.h"
#include "../Logger.h"

#include <iostream>

Repeater::Repeater(const char *name, float x, float y) :
        CommunicationNode(name, x, y)
{
}

void Repeater::runOneStep(std::list<std::shared_ptr<TextMessage>> &emittedMessageList) {
    if( ! _messageReceivedList.empty() )
        logger << "'" << _name << "' " << _nodeClock << " processing:" << std::endl;

    logger.stepIn();
    while( ! _messageReceivedList.empty() ) {
        auto message = _messageReceivedList.front();
        _messageReceivedList.pop_front();

        int count = _forwardedMessageCount[message->messageUniqueId()];

        if( count < 1 ) { // todo: when should it repeat the message, and when not?
            auto clone = message->cloneAndIncrement(_location);

            logger << "repeating: " << message << std::endl;
            emittedMessageList.push_front(clone);

            _forwardedMessageCount[message->messageUniqueId()] = count + 1;
        } else {
            logger << "NOT repeating (already: " << count << " times): " << message << std::endl;
        }
    }
    logger.stepOut();
}

