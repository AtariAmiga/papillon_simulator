#ifndef REPEATER_H_INCLUDED
#define REPEATER_H_INCLUDED

#include "World.h"

struct Repeater {
    struct Location* location;
    char* name;
    struct World* owner;
};

struct Repeater* Repeater_new(char *name, struct World* owner, float x, float y);
void Repeater_println(struct Repeater* self);
void Repeater_receive_message(struct Repeater* self, struct Message* message);

#endif
