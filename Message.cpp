#include "Message.h"
#include "Location.h"

#include <iostream>

Message::Message(Location *location, const char *emitterName, const char *text, const char *recipientName, std::string messageUniqueId) {
    _emittedLocation = location->clone();
    _emitterName = emitterName;
    _text = text;
    _recipientName = recipientName;
    _hopsCount = 0;
    _messageUniqueId = messageUniqueId;
}

Message* Message::cloneAndIncrement(Location* emitterLocation) const {
    auto* clone = new Message(emitterLocation->clone(), _emitterName, _text, _recipientName, _messageUniqueId);

    clone->_hopsCount = _hopsCount + 1;

    return clone;
}

std::ostream& operator<<(std::ostream &os, const Message* m) {
    return os << "Message " << m->_messageUniqueId << " " << m->_emittedLocation << ": "
              << m->_emitterName << " '" << m->_text << "' " << m->_recipientName << " (hops: " << m->_hopsCount << ")";
}

