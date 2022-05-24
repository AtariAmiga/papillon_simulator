#include "Terminal.h"
#include "World.h"
#include "Message.h"
#include "Location.h"

#include <cstring>
#include <iostream>
#include <cassert>

Terminal::Terminal(const char* name, struct World* owner, float x, float y) {
    this->_location = new Location(x, y);
    this->_name = name;
    this->_worldOwner = owner;
}

std::ostream& operator<<(std::ostream& os, const Terminal* terminal) {
    return os << "Terminal '" << terminal->_name << "'" << std::endl;
}

void Terminal::sendMessage(const char* text, const char* recipient) const {
    assert(text != nullptr);
    assert(recipient != nullptr);

    auto message = new Message(this->_location, this->_name, text, recipient);

    this->_worldOwner->queueMessage(message);
}

void Terminal::runOneStep() {
    while( ! _messageList.empty() ) {
        Message* message = _messageList.front();
        _messageList.pop_front();

        if(strcmp(message->recipientName(), this->_name) == 0 )
            std::cout << "'" << this->_name << "' received: " << message << std::endl;
    }
}
