#include "Terminal.h"
#include "../world/World.h"
#include "../messages/TextMessage.h"
#include "../world/Location.h"

#include <cstring>
#include <iostream>
#include <cassert>
#include <memory>

Terminal::Terminal(const char *name, float x, float y) :
        CommunicationNode(name, x, y)
{
}

std::shared_ptr<TextMessage> Terminal::emitMessage(const char* text, const char* recipient) {
    assert(text != nullptr);
    assert(recipient != nullptr);

    std::string messageUniqueId = nextMessageUniqueId();
            
    auto message = std::make_shared<TextMessage>(_location, _name, text, recipient, messageUniqueId);

    return message;
}

std::string Terminal::nextMessageUniqueId() {
    return std::to_string(_nodeUniqueID) + "." + std::to_string(_nextMessageNum++);
}

std::list<std::shared_ptr<TextMessage>> Terminal::runOneStep() {
    std::list<std::shared_ptr<TextMessage>> list;

    while( ! _messageList.empty() ) {
        auto message = _messageList.front();
        _messageList.pop_front();

        if(strcmp(message->recipientName(), _name) == 0 ) {
            if( _receivedMessageIds.count(message->messageUniqueId()) == 0) {
                std::cout << _nodeClock << " '" << _name << "' received: " << message << std::endl;
                _receivedMessageIds.insert(message->messageUniqueId());
            }
        }
    }

    return list;
}
