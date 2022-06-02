#include "Terminal.h"
#include "World.h"
#include "Message.h"
#include "Location.h"

#include <cstring>
#include <iostream>
#include <cassert>
#include <memory>

Terminal::Terminal(const char *name, float x, float y) :
        CommunicationNode(name, x, y)
{
}

std::shared_ptr<Message> Terminal::emitMessage(const char* text, const char* recipient) const {
    assert(text != nullptr);
    assert(recipient != nullptr);

    std::string messageUniqueId = std::to_string(_nodeUniqueID) + "." + std::to_string(_nextMessageNum);
            
    auto message = std::make_shared<Message>(_location, _name, text, recipient, messageUniqueId);

    return message;
}

std::list<std::shared_ptr<Message>> Terminal::runOneStep(int dtInMs) {
    std::list<std::shared_ptr<Message>> list;

    _nodeTime += dtInMs;

    while( ! _messageList.empty() ) {
        auto message = _messageList.front();
        _messageList.pop_front();

        if(strcmp(message->recipientName(), _name) == 0 ) {
            if( _receivedMessageIds.count(message->messageUniqueId()) == 0) {
                std::cout << "'" << _name << "' received: " << message << std::endl;
                _receivedMessageIds.insert(message->messageUniqueId());
            }
        }
    }

    return list;
}
