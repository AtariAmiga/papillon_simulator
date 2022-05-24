#include "Message.h"
#include "Location.h"

#include <iostream>

Message::Message(Location* location, const char* emitterName, const char* text, const char* recipientName) {
    _emittedLocation = location->clone();
    this->emitterName = emitterName;
    this->text = text;
    _recipientName = recipientName;
    this->hopsCount = 0;
}

Message* Message::cloneAndIncrement(Location* emitterLocation) const {
    auto* clone = new Message(emitterLocation->clone(), this->emitterName, this->text, _recipientName);

    clone->hopsCount = this->hopsCount + 1;

    return clone;
}

std::ostream& operator<<(std::ostream &os, const Message* message) {
    return os << "Message " << message->_emittedLocation << ": "
        << message->emitterName << " '" << message->text << "' " << message->_recipientName << " (hops: " << message->hopsCount << ")";
}

