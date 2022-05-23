#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED

class Location;

class Message {
public:
    Location* emittedLocation;
    const char* emitterName;
    const char* text;
    const char* recipientName;
    int hopsCount;

    Message(Location* location, const char *emitterName, const char* text, const char* recipientName);
    Message* cloneAndIncrement(struct Location* emitterLocation) const;
    void println() const;
};

#endif