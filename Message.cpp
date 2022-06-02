#include "Message.h"
#include "Location.h"

#include <iostream>

Message::Message(const Location& location, const char *emitterName, const char *text, const char *recipientName, std::string messageUniqueId)
    : _emittedLocation(location)
{
    _emitterName = emitterName;
    _text = text;
    _recipientName = recipientName;
    _hopsCount = 0;
    _messageUniqueId = messageUniqueId;
}

std::shared_ptr<Message> Message::cloneAndIncrement(const Location& emitterLocation) const {
    auto clone = std::make_shared<Message>(emitterLocation, _emitterName, _text, _recipientName, _messageUniqueId);

    clone->_hopsCount = _hopsCount + 1;

    return clone;
}

std::ostream& operator<<(std::ostream &os, const std::shared_ptr<Message>& m) {
    return os << "{" << m->_emittedLocation << ": " << "Msg " << m->_messageUniqueId << " "
              << m->_emitterName << " '" << m->_text << "' > " << m->_recipientName << " hops: " << m->_hopsCount << "}";
}

