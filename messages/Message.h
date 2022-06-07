#ifndef MESSAGE_H
#define MESSAGE_H

#include "../world/Location.h"

class Message {
protected:

    Location _emittedLocation;
    int _hopsCount{};
    std::string _messageUniqueId;

public:
    const Location& emittedLocation() const { return _emittedLocation; }
    std::string messageUniqueId() const { return _messageUniqueId; }

    explicit Message(const Location &location, std::string string);
};


#endif // MESSAGE_H
