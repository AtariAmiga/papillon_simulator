#ifndef TEXT_MESSAGE_H_INCLUDED
#define TEXT_MESSAGE_H_INCLUDED

#include "Location.h"
#include "Message.h"

#include <iostream>
#include <memory>

class Location;

class TextMessage : public Message {
private:
    Location _emittedLocation;
    const char* _emitterName;
    const char* _text;
    const char* _recipientName;
    int _hopsCount;
    std::string _messageUniqueId;

public:
    TextMessage(const Location& location, const char *emitterName, const char *text, const char *recipientName,
                std::string messageUniqueId);
    std::shared_ptr<TextMessage> cloneAndIncrement(const Location& emitterLocation) const;

    const char* recipientName() const { return _recipientName; };
    const Location& emittedLocation() const { return _emittedLocation; }
    std::string messageUniqueId() const { return _messageUniqueId; }

    friend std::ostream& operator<<(std::ostream& os, const std::shared_ptr<TextMessage>& message);
};

std::ostream& operator<<(std::ostream& os,  const std::shared_ptr<TextMessage>& m);

#endif // TEXT_MESSAGE_H_INCLUDED