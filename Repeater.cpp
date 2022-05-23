#include "Message.h"
#include "Repeater.h"
#include "World.h"
#include "Location.h"

#include <iostream>
#include <cassert>

Repeater::Repeater(const char *name, struct World* owner, float x, float y) {
    this->location = new Location(x, y);
    this->name = name;
    this->worldOwner = owner;
}

void Repeater::println() const {
    std::cout << "Repeater '" << this->name << "'" << std::endl;
}

void Repeater::receiveMessage(Message& message) {
    std::cout << "'" <<  this->name << " received: ";
    message.println();
    std::cout << std::endl;

    messageList.push_front(message);
}

void Repeater::runOneStep() {
    while( ! messageList.empty() ) {
        Message& message = messageList.front();
        messageList.pop_front();

        Message* clone = message.cloneAndIncrement(this->location);
        this->worldOwner->queueMessage(clone);
    }
}

