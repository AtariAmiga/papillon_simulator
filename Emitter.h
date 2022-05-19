#ifndef EMITTER_H_INCLUDED
#define EMITTER_H_INCLUDED

#include "World.h"

struct Emitter {
    char* name;
    struct World* owner;
};

struct Emitter* Emitter_new(char *name, struct World* owner);
void Emitter_println(struct Emitter* this);
void Emitter_send_message(struct Emitter* this, const char* text, struct Emitter* recipient);

#endif