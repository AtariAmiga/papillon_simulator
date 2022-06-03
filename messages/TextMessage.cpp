#include "TextMessage.h"
#include "../world/Location.h"

#include <iostream>

TextMessage::TextMessage(const Location& location, const char *emitterName, const char *text, const char *recipientName, std::string messageUniqueId)
    : Message(location, messageUniqueId)
{
    _emitterName = emitterName;
    _text = text;
    _recipientName = recipientName;
    _hopsCount = 0;
}

std::shared_ptr<TextMessage> TextMessage::cloneAndIncrement(const Location& emitterLocation) const {
    auto clone = std::make_shared<TextMessage>(emitterLocation, _emitterName, _text, _recipientName, _messageUniqueId);

    clone->_hopsCount = _hopsCount + 1;

    return clone;
}

std::ostream& operator<<(std::ostream &os, const std::shared_ptr<TextMessage>& m) {
    return os << "{" << m->_emittedLocation << ": " << "Msg " << m->_messageUniqueId << " "
              << m->_emitterName << " '" << m->_text << "' > " << m->_recipientName << " hops: " << m->_hopsCount << "}";
}

