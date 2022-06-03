//
// Created by Vincent Agami on 03/06/2022.
//

#include "Message.h"

Message::Message(const Location &location, std::string messageUniqueId)
    : _emittedLocation(location),
      _messageUniqueId(messageUniqueId)
{
}
