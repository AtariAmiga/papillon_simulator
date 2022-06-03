#include "Message.h"

Message::Message(const Location &location, std::string messageUniqueId)
    : _emittedLocation(location),
      _messageUniqueId(messageUniqueId)
{
}
