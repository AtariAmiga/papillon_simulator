#ifndef TERMINAL_H_INCLUDED
#define TERMINAL_H_INCLUDED

#include "World.h"

struct Terminal {
    char* name;
    struct World* owner;
};

struct Terminal* Terminal_new(char *name, struct World* owner);
void Terminal_println(struct Terminal* this);
void Terminal_send_message(struct Terminal* this, const char* text, struct Terminal* recipient);

#endif