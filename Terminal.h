#ifndef TERMINAL_H_INCLUDED
#define TERMINAL_H_INCLUDED

#include "World.h"
#include "Message.h"
#include "Location.h"

struct Terminal {
    struct Location* location;
    char* name;
    struct World* owner;
};

struct Terminal* Terminal_new(char *name, struct World* owner, float x, float y);
void Terminal_println(struct Terminal* self);
void Terminal_sendMessage(struct Terminal* self, const char* text, const char* recipient);
void Terminal_receiveMessage(struct Terminal* self, struct Message* message);

#endif