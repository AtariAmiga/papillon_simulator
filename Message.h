#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED

#include <iostream>

class Location;

class Message {
private:
    Location* _emittedLocation;
    const char* _emitterName;
    const char* _text;
    const char* _recipientName;
    int _hopsCount;

public:
    Message(Location* location, const char *emitterName, const char* text, const char* recipientName);
    Message* cloneAndIncrement(struct Location* emitterLocation) const;

    const char* recipientName() const { return _recipientName; };
    const Location* emittedLocation() const { return _emittedLocation; }

    friend std::ostream& operator<<(std::ostream& os,  const Message* message);
};

std::ostream& operator<<(std::ostream& os,  const Message* message);

#endif