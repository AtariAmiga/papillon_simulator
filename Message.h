#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED

#include "Location.h"

#include <iostream>
#include <memory>

class Location;

class Message {
private:
    Location _emittedLocation;
    const char* _emitterName;
    const char* _text;
    const char* _recipientName;
    int _hopsCount;
    std::string _messageUniqueId;

public:
    Message(const Location& location, const char *emitterName, const char *text, const char *recipientName,
            std::string messageUniqueId);
    std::shared_ptr<Message> cloneAndIncrement(const Location& emitterLocation) const;

    const char* recipientName() const { return _recipientName; };
    const Location& emittedLocation() const { return _emittedLocation; }
    std::string messageUniqueId() const { return _messageUniqueId; }

    friend std::ostream& operator<<(std::ostream& os, const std::shared_ptr<Message>& message);
};

std::ostream& operator<<(std::ostream& os,  const std::shared_ptr<Message>& m);

#endif