#include "Message.h"
#include "Repeater.h"
#include "World.h"

#include <iostream>

Repeater::Repeater(const char *name, float x, float y) :
        CommunicationNode(name, x, y)
{
}

std::list<std::shared_ptr<Message>> Repeater::runOneStep(int dtInMs) {
    std::list<std::shared_ptr<Message>> list;

    _nodeTime += dtInMs;

    while( ! _messageList.empty() ) {
        auto message = _messageList.front();
        _messageList.pop_front();

        int count = _forwardedMessageCount[message->messageUniqueId()];

        if( count < 1 ) { // todo: when should it repeat the message, and when not?
            auto clone = message->cloneAndIncrement(_location);

            std::cout << "'" << _name << "' repeating: " << message << std::endl;
            list.push_front(clone);

            _forwardedMessageCount[message->messageUniqueId()] = count + 1;
        } else {
//            std::cout << "'" << _name << "' NOT repeating: " << message << std::endl;
        }
    }
    return list;
}

