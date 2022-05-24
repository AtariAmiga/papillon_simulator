#include "Message.h"
#include "Location.h"

#include <iostream>

Message::Message(Location* location, const char* emitterName, const char* text, const char* recipientName) {
    this->emittedLocation = location->clone();
    this->emitterName = emitterName;
    this->text = text;
    this->recipientName = recipientName;
    this->hopsCount = 0;
}

Message* Message::cloneAndIncrement(Location* emitterLocation) const {
    auto* clone = new Message(emitterLocation->clone(), this->emitterName, this->text, this->recipientName);

    clone->hopsCount = this->hopsCount + 1;

    return clone;
}

std::ostream& operator<<(std::ostream &os, const Message* message) {
    return os << "Message " << message->emittedLocation << ": "
        << message->emitterName << " '" << message->text << "' " << message->recipientName;
}

