#include "Terminal.h"
#include "World.h"
#include "Message.h"
#include "Location.h"

#include <cstring>
#include <iostream>
#include <cassert>
#include <memory>

Terminal::Terminal(const char* name, World* owner, float x, float y):
        CommunicationNode(name, owner, x, y)
{
}

void Terminal::sendMessage(const char* text, const char* recipient) const {
    assert(text != nullptr);
    assert(recipient != nullptr);

    std::string messageUniqueId = std::to_string(_nodeUniqueID) + "." + std::to_string(_nextMessageNum);
            
    auto message = std::make_shared<Message>(_location, _name, text, recipient, messageUniqueId);

    _worldOwner->queueMessage(message);
}

void Terminal::runOneStep(int dtInMs) {
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
}
