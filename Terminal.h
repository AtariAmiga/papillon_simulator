#ifndef TERMINAL_H_INCLUDED
#define TERMINAL_H_INCLUDED

#include "World.h"
#include "Message.h"

struct Terminal {
    char* name;
    struct World* owner;
};

struct Terminal* Terminal_new(char *name, struct World* owner);
void Terminal_println(struct Terminal* this);
void Terminal_send_message(struct Terminal* this, const char* text, const char* recipient);
void Terminal_receive_message(struct Terminal* this, struct Message* message);

#endif