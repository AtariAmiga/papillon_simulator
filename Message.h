#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED

#include "Location.h"

struct Message {
    struct Location* emittedLocation;
    const char* emitterName;
    const char* text;
    const char* recipientName;
    int hopsCount;
};

struct Message* Message_new(struct Location* location, const char *emitterName, const char* text, const char* recipientName);
struct Message* Message_clone_and_increment(struct Message* self, struct Location* emitterLocation);
void Message_println(struct Message* self);

#endif