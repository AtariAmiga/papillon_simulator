#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED

#include "Emitter.h"

struct Message {
    const struct Emitter* emitter;
    const char* text;
    struct Emitter* recipient;
};

struct Message* Message_new(struct Emitter* emitter, const char* text, struct Emitter* recipient);

#endif