#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED

#include "Terminal.h"

struct Message {
    const struct Terminal* emitter;
    const char* text;
    const char* recipientName;
};

struct Message* Message_new(struct Terminal* emitter, const char* text, const char* recipientName);
void Message_println(struct Message* this);

#endif