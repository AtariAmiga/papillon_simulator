#include "Message.h"
#include "Location.h"

#include <iostream>

Message::Message(Location* location, const char* emitterName, const char* text, const char* recipientName) {
    _emittedLocation = location->clone();
    this->_emitterName = emitterName;
    this->_text = text;
    _recipientName = recipientName;
    this->_hopsCount = 0;
}

Message* Message::cloneAndIncrement(Location* emitterLocation) const {
    auto* clone = new Message(emitterLocation->clone(), this->_emitterName, this->_text, _recipientName);

    clone->_hopsCount = this->_hopsCount + 1;

    return clone;
}

std::ostream& operator<<(std::ostream &os, const Message* message) {
    return os << "Message " << message->_emittedLocation << ": "
              << message->_emitterName << " '" << message->_text << "' " << message->_recipientName << " (hops: " << message->_hopsCount << ")";
}

