#include "Terminal.h"
#include "World.h"
#include "Message.h"
#include "Location.h"

#include <cstring>
#include <iostream>
#include <assert.h>

Terminal::Terminal(const char* name, struct World* owner, float x, float y) {
    this->location = new Location(x, y);
    this->name = name;
    this->owner = owner;
}

void Terminal::println() const {
    std::cout << "Terminal '" << this->name << "'" << std::endl;
}

void Terminal::sendMessage(const char* text, const char* recipient) const {
    assert(text != nullptr);
    assert(recipient != nullptr);

    auto message = new Message(this->location, this->name, text, recipient);

    this->owner->queueMessage(message);
}

void Terminal::receiveMessage(struct Message* message) const {
    assert(message != nullptr);

    if(strcmp(message->recipientName, this->name) == 0 ) { // todo: should not process now. Should queue it, then process it when runOneStep is called
        std::cout << "'" <<  this->name << " received: ";
        message->println();
        std::cout << std::endl;
    }
}

