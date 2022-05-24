#include "Terminal.h"
#include "World.h"
#include "Message.h"
#include "Location.h"

#include <cstring>
#include <iostream>
#include <cassert>

Terminal::Terminal(const char* name, struct World* owner, float x, float y) {
    this->_location = new Location(x, y);
    this->name = name;
    this->worldOwner = owner;
}

std::ostream& operator<<(std::ostream& os, const Terminal* terminal) {
    return os << "Terminal '" << terminal->name << "'" << std::endl;
}

void Terminal::sendMessage(const char* text, const char* recipient) const {
    assert(text != nullptr);
    assert(recipient != nullptr);

    auto message = new Message(this->_location, this->name, text, recipient);

    this->worldOwner->queueMessage(message);
}

void Terminal::runOneStep() {
    while( ! messageList.empty() ) {
        Message* message = messageList.front();
        messageList.pop_front();

        if(strcmp(message->recipientName(), this->name) == 0 )
            std::cout << "'" <<  this->name << "' received: " << message << std::endl;
    }
}
